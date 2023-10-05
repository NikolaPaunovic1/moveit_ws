#!/usr/bin/env python
import rospy
from std_msgs.msg import Float64MultiArray
import socket


class WatchClient:
    def __init__(self, local_port=6000):
        self.client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.client.bind(("", local_port))  # Bind to the provided local port

        self.connection_str = "connect_watch"
        self.confirm_str = "confirm_connect_watch"

        self.data_list = []  # Store data here
        self.pub = rospy.Publisher('imu_data', Float64MultiArray, queue_size=10)

    def listen_for_connection(self):
        rospy.loginfo("Looking for connection")
        while not rospy.is_shutdown():
            data, addr = self.client.recvfrom(1024)  # Buffer size is 1024 bytes
            message_str = data.decode().strip()
            rospy.loginfo(message_str)

            if message_str == self.connection_str:
                self.connected_endpoint = addr

                confirm_bytes = self.confirm_str.encode()
                self.client.sendto(confirm_bytes, self.connected_endpoint)
                rospy.loginfo("Connection confirmed")
                break

    def listen_for_messages(self):
            
        rate = rospy.Rate(40) # 40hz
        while not rospy.is_shutdown():
            data, addr = self.client.recvfrom(1024)  # Buffer size is 1024 bytes
            message_str = data.decode().strip()
            message_elements = message_str.split(',')
            
            # Parsing the data as in the C# code and storing it in the list
            try:
                acc = [float(message_elements[i]) for i in range(0, 3)]
                gyr = [float(message_elements[i]) for i in range(4, 7)]
            except ValueError:
                rospy.logerr("Received invalid data: %s", message_str)
                continue  # Skip to the next loop iteration

            # Append data to list
            self.data_list.append((*acc, *gyr))  # Storing as a flat list

            if len(self.data_list) > 40 * 6:  # Each entry has now 8 elements, we want sequences of 40 entries
                self.data_list = self.data_list[20 * 6:]  # Remove first 20 entries (160 elements)

            if len(self.data_list) == 40 * 6:  # We now have a sequence of 40 entries
                msg = Float64MultiArray()
                msg.data = self.data_list  # This is now a flat list
                self.pub.publish(msg)
                rospy.loginfo("msg was published")

            rate.sleep()
            

if __name__ == '__main__':

    rospy.init_node('IMU_data_publisher', anonymous=True)
    try:
        watch_client = WatchClient()
        watch_client.listen_for_connection()
        watch_client.listen_for_messages()
    except rospy.ROSInterruptException:
        pass