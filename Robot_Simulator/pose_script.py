# -*- coding: utf-8 -*-
"""
Created on Wed Sep 19 23:18:15 2018

@author: David
"""
from ServoDriver import *
from DTRobot import *

COM = 4

serv = ServoDriver(COM)
rob = DTRobot('config.ini')

#serv.setPose([0, 0, 0, 0, 0, 0])
#input("Press Enter to continue...")


serv.setPose(rob.robot.joints)
input("Press Enter to continue...")

while(1):
    currentPose = rob.robot.fk(rob.robot.joints)
    trans = translation_matrix([0,-0.1,0])
    newPose = np.matmul(trans,currentPose)
    
    print(currentPose)
    print(trans)
    print(newPose)
    
    input("Press Enter to continue...")
    
    newJointAngles = rob.robot.ik(newPose)
    print(newJointAngles)
    input("Press Enter to continue...")
    
    serv.setPose(newJointAngles)

    rob.robot.joints = newJointAngles


input("Press Enter to continue...")

serv.ser.close()