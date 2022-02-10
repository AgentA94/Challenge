#include <iostream>
#include <fstream>


using namespace std;

//constants for indentifiying the wheel angle message as well as the wheel positions.
static const string identifierMessage = "18F00B80x", frontLeft = "00", frontRight = "01", backLeft = "10", backRight = "11";

int main()
{
    //string variables for the storing the filename, data lines, wheel identification string and angle data string.
    string filename,datalineCAN, strIdentWheel, strAngleData, strTimeStamp;
    string firstLine = "time,angle";

    //variables for storing angle data;
    int angleData;
    float convertedAngleData;
    
    //file streams for input file and the four output files.
    ifstream dataCAN;
    ofstream angleDataFL, angleDataFR, angleDataBL, angleDataBR;
    
    
    //Prompt user for the input file name and open the file location.
    cout << "Enter the full file path of test data: "; 
    cin >> filename;
    dataCAN.open (filename);

    //Check if input file was successfully opened.
    if(dataCAN.is_open()){
            //Open file locations for output data
            angleDataFL.open("FrontLeftAngleData.csv");
            angleDataFR.open("FrontRightAngleData.csv");
            angleDataBL.open("BackLeftAngleData.csv");
            angleDataBR.open("BackRightAngleData.csv");    
            
            angleDataFL << firstLine << endl;
            angleDataFR << firstLine << endl;
            angleDataBL << firstLine << endl;
            angleDataBR << firstLine << endl;
        
        //Read all lines in the input file
        while(getline(dataCAN,datalineCAN)){
            //Check for the message identifier in each line.
            size_t found = datalineCAN.find(identifierMessage);
            
            //if the message identifier is found
            if(found != string::npos){
                //Positions of the data are constant for line and are therefore hard coded.
                //Grab the relevant data from the lines.
                strTimeStamp = datalineCAN.substr(1,9);
                strAngleData =  datalineCAN.substr(43,2) + datalineCAN.substr(40,2);
                strIdentWheel = datalineCAN.substr(46,2);
                
                //Convert the hex string data to integer data.
                angleData = stoi(strAngleData, 0, 16);
                
                //Perform message conversion and store in a float for data precision.
                convertedAngleData = (angleData/256.0) - 125;

                //Check the wheel identifier data to determine which output file to write the data into.
                if(strIdentWheel == frontLeft){
                    angleDataFL << strTimeStamp << ","  << convertedAngleData << endl;
                }
                else if(strIdentWheel == frontRight){
                    angleDataFR << strTimeStamp << "," << convertedAngleData << endl;
                }
                else if(strIdentWheel == backLeft){
                    angleDataBL << strTimeStamp << "," << convertedAngleData << endl;
                }
                else if(strIdentWheel == backRight){
                    angleDataBR << strTimeStamp << "," << convertedAngleData << endl;
                }
            }
        }
    }
	else{
		cout << "File not found";
	}
}
