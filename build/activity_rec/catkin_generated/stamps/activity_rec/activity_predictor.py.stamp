#!/usr/bin/env python

import torch
import rospy
from std_msgs.msg import Float64MultiArray
from torch.autograd import Variable
import torch.nn as nn

class LSTM(nn.Module):
    def __init__(self, input_size=6, hidden_dim=128, num_layers=1, output_dim=4):
        super().__init__()
        self.hidden_dim = hidden_dim
        self.num_layers = num_layers

        self.lstm = nn.LSTM(input_size, hidden_dim, num_layers, batch_first=True)

        self.fc1 = nn.Linear(hidden_dim, hidden_dim // 2)
        self.bn1 = nn.BatchNorm1d(hidden_dim // 2)  # Add batch normalization
        self.relu = nn.ReLU()
        self.dropout = nn.Dropout(0.5)

        self.fc2 = nn.Linear(hidden_dim // 2, output_dim)

    def forward(self, input):
        batch_size = input.size(0)
        h0 = torch.zeros(self.num_layers, batch_size, self.hidden_dim)
        c0 = torch.zeros(self.num_layers, batch_size, self.hidden_dim)

        lstm_out, _ = self.lstm(input, (h0, c0))

        out = self.fc1(lstm_out[:, -1, :])
        out = self.bn1(out)
        out = self.relu(out)
        out = self.dropout(out)

        out = self.fc2(out)

        return out

class ImuDataPredictor:

    def __init__(self, model_path):
        self.model = LSTM()  # Initialize your model with the required parameters
        checkpoint = torch.load(model_path, map_location='cpu') #trained on gpu but now use cpu
        self.model.load_state_dict(checkpoint)  # Load the weights
        self.model.eval()  # Set model to evaluation mode

        rospy.init_node('imu_data_predictor', anonymous=True)
        rospy.Subscriber('/imu_data', Float64MultiArray, self.callback)
        rospy.sleep(rospy.Duration(3))  # Sleep for 3 seconds
        rospy.loginfo("Activity Predictor has been initialized and started!")
        rospy.spin()  # Keep the node running until it's shutdown

    def callback(self, data):
        # Convert the received data to the appropriate shape
        data_array = torch.FloatTensor(data.data).view(1, 40, 6)
        
        # Make sure the data is in the correct format for the model
        data_array = Variable(data_array)

        # Perform prediction
        output = self.model(data_array)

        # Print or do something with the output
        rospy.loginfo(output)


if __name__ == '__main__':
    predictor = ImuDataPredictor("/home/nikola/Watch_Data/Models/model_nopreproc_fin_40.pt")
