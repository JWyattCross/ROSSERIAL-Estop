#!/usr/bin/env python

import rospy
from std_msgs.msg import Bool


#create publishers outside function
pub_j1 = rospy.Publisher('j1/e-stop', Bool, queue_size=10)#jackals
pub_j2 = rospy.Publisher('j2/e-stop', Bool, queue_size=10)
pub_h1 = rospy.Publisher('h1/e-stop', Bool, queue_size=10) #huskies
pub_h2 = rospy.Publisher('h2/e-stop', Bool, queue_size=10)
pub_ld1 = rospy.Publisher('ld1/e-stop', Bool, queue_size=10) #ld is little dog from unitree
#pub_xx = rospy.Publisher('xx/e-stop', Bool, queue_size=10)


def pushed_callback(msg):
    if msg.data:
        pub_j1.publish(True)
        pub_j2.publish(True)
        pub_h1.publish(True)
        pub_h2.publish(True)
        pub_ld1.publish(True)
    else:
        pub_j1.publish(False)
        pub_j2.publish(False)
        pub_h1.publish(False)
        pub_h2.publish(False)
        pub_ld1.publish(False)


def pushed_subscriber():
    rospy.init_node('pushed_subscriber', anonymous=True)
    rospy.Subscriber('pushed', Bool, pushed_callback)
    rospy.spin()


if __name__ == '__main__':
    pushed_subscriber()






#call with: $ rosrun <package_name> pushed_publisher.py
