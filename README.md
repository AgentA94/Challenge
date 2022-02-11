# Challenge

This project is for the CAN message processing challenge.
Below is an overview for my approach to the project as well as instructions on how to compile and use the project.



Solving the problem:

My first step when looking at this problem was deciding between using C or C++ to solve this problem.
I decided to use C++ for this problem as is handles strings better than C and that is how I was going to extract the data.
I used the iostream and fstream C++ libraries to process the input data as well as output the processed data.
The first step in the program is to request the user to provide the file location of the provided .asc file to be processed.
After receiving the file location, the program opens it, if the program successfully opens the file the program creates four .csv output files.
One for each wheel.
I chose .csv files for the output as they are an easy file type to plot with other programs. 
After generating the output files the program loops through the input file line by line and searches for the provided message identifier for the wheel angles. 
Whenever a line is found to have the message identifier, the time stamp, wheel angle data, and axle location data are parsed and written into strings.
The position of this data is the same every time so the position of where to grab the data is hard coded.
It is important to note that the angle data is written in two bytes with the higher order data being in the 2nd byte and the lower order data in the first byte.
Next the angle data is converted from a string in hexidecimal to an integer value using the stoi function using base 16.
Next the integer angle data is converted to degrees using the 1/256 deg/bit scaling and the -125 degree offset.
Finally we use an if statement to compare the axle location data with the known wheel positions to tell which wheel the data is for and then the angle data and time stamp are written into the corresponding .csv file.


Plotting:

After the data is parsed into separate .csv files a python script is used to plot the data for each wheel.
The plots are generated using a python library called plotly. 
The script generates four plots, one for each wheel with the x axis being time and the y axis being the angle in degrees.
Plotly creates these scripts in browser windows.


C++ file setup and compilation:

I used the TDM-gcc windows C++ compiler for windows to compile my source file.
Use the following link and choose the MinGW-w64 based compiler.
The link to download this compiler is here: https://jmeubank.github.io/tdm-gcc/
The installer automatically sets up the path for the compiler.
When ready to compile the source file, use the command prompt and enter the cd command and change the path to the location of the source file.
When directory is set up correctly, use the following command to compile the file "g++ source.cpp -o challenge".
This will create an executable from the code and it will be named challenge.exe

Python setup and compilation:

I used the latest version of python3 which is python3.10.2 for the python script.
Use the following link to download the windows64 installer for the latest python version.
https://www.python.org/downloads/release/python-3102/
After installing the latest version of python you may need to add python to the path in your environment variables.
If your install did not come with pip you can install it using the following command int the command window "python get-pip.py".
Once pip is installed the plotly and pandas packages need to be installed using pip.
The commands are "pip install pandas" and "pip install plotly==5.6.0".

Execution of the code:

In the command prompt change the directory to the location of the challenge.exe file. 
When in the correct location in the command prompt enter the name of the executable in this case challenge.
You will then be prompted to enter the full file path of the .asc CAN log file.
Enter the full path of the file and press enter.
The code will execute and the four .csv files will be outputted. 
After the .csv files are generated, in the command prompt input dataPlot.py to run the plotting script.
After the plotting script is run four graphs will open in the browser with the data for each wheel.
