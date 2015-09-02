#!/usr/bin/env python

#Current Up To Date Usable Node
# Every python controller needs these lines
import roslib 
roslib.load_manifest('wheelchair_controller')
import rospy
from std_msgs.msg import UInt16
from sensor_msgs.msg import Joy
# The velocity command message

class controller:
	def __init__(self):
		
		self.forward_true = 1
		self.forward_false = 2
		self.reverse_true = 3
		self.reverse_false = 4
		self.left_true = 5
		self.left_false = 6
		self.right_true = 7
		self.right_false = 8
		self.fifth_switch_true = 9
		self.fifth_switch_false = 10
		self.kill_switch_true = 11
		self.kill_switch_false =12
		
		#Subscribes to /basescan
		print "start Init"
		self.joy_sub = rospy.Subscriber("/joy",Joy,self.joy_callback)
		self.bool_pub = rospy.Publisher('/bool', UInt16, queue_size=3)
		print "End Init"

	def joy_callback(self, joy_values): 
		self.axes = joy_values.axes
		self.buttons = joy_values.buttons

		if (self.buttons[13] == 1 or self.axes[1] > .2):
			self.bool_pub.publish(self.forward_true)
		if (self.buttons[13] == 0 and self.axes[1] < .2):
			self.bool_pub.publish(self.forward_false)

		if (self.buttons[14] == 1 or self.axes[1] < -.2):
			self.bool_pub.publish(self.reverse_true)
		if (self.buttons[14] == 0 and self.axes[1] > -.2):
			self.bool_pub.publish(self.reverse_false)
	
		if (self.buttons[11] == 1 or self.axes[0] > .2):
			self.bool_pub.publish(self.left_true)
		if (self.buttons[11] == 0 and self.axes[0] < .2):
			self.bool_pub.publish(self.left_false)
		
		if (self.buttons[12] == 1 or self.axes[0] < -.2):
			self.bool_pub.publish(self.right_true)
		if (self.buttons[12] == 0 and self.axes[0] > -.2):
			self.bool_pub.publish(self.right_false)

		if (self.buttons[4] == 1):
			self.bool_pub.publish(self.fifth_switch_true)
		if (self.buttons[4] == 0):
			self.bool_pub.publish(self.fifth_switch_false)
		
		if ((self.buttons[5] == 1) or (self.axes[5] < .8)):
			self.bool_pub.publish(self.kill_switch_true)
		if ((self.buttons[5] == 0) and (self.axes[5] >.8)):
			self.bool_pub.publish(self.kill_switch_false)

if __name__ == '__main__':
	rospy.init_node('chiron_controller',log_level=rospy.DEBUG)
	controller = controller()
	rospy.spin()
