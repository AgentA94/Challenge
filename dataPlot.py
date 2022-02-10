import pandas as pd
import plotly.express as px

data = pd.read_csv('FrontLeftAngleData.csv')
fig = px.line(data, x = 'time', y = 'angle', title = 'Front Left Wheel Angle')
fig.show()

data = pd.read_csv('FrontRightAngleData.csv')
fig = px.line(data, x = 'time', y = 'angle', title = 'Front Right Wheel Angle')
fig.show()

data = pd.read_csv('BackLeftAngleData.csv')
fig = px.line(data, x = 'time', y = 'angle', title = 'Back Left Wheel Angle')
fig.show()

data = pd.read_csv('BackRightAngleData.csv')
fig = px.line(data, x = 'time', y = 'angle', title = 'Back Right Wheel Angle')
fig.show()
