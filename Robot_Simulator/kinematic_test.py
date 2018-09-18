# -*- coding: utf-8 -*-
"""
Desktop-Bot Init

This initializes the Desktop-Bot.
"""

from pybotics import Robot
from pybotics import Link
from pybotics.kinematic_chain import MDHKinematicChain
from pybotics import Tool
from pybotics.geometry import *

import numpy as np

link_lengths = np.array([2,2,2,2,2])

# DH Table
# ALPHA     A   THETA   D
kinematic_chain = MDHKinematicChain(\
                  np.array([\
                     np.pi/2,  0,                  0,   link_lengths[0],\
                     0,        link_lengths[1],    0,   0,\
                     np.pi/2,  0,                  0,   link_lengths[2],\
                     np.pi/2,  0,                  0,   link_lengths[3],\
                     np.pi/2,  0,                  0,   0,\
                     np.pi/2,  0,                  0,   link_lengths[4]\
                     ])\
                  )

# Initialize Robot
tool = Tool()
tool.position = [0,0,0]
world_frame = vector_2_matrix([0,0,0,0,0,0])
random_state = None

robot = Robot(kinematic_chain,tool,world_frame,random_state)

# set joint limits
joint_min = [-np.pi, -np.pi, -np.pi, -np.pi, -np.pi, -np.pi]
joint_max = [np.pi,  np.pi,  np.pi,  np.pi,  np.pi,  np.pi]
robot.joint_limits = np.ndarray(shape=(2,6),buffer=np.array([joint_min,joint_max]))

# set current joint position 
init_position = [0,0,0,0,0,0]
robot.joints = init_position

# Sart doing some simulations
# Move tool 1 unit in x direction
currentPose = robot.fk(robot.joints)
transX = translation_matrix([1,0,0])
newPose = np.matmul(currentPose,transX)

# get joint angles needed for translation
newJointAngles = robot.ik(newPose)
newJointAnglesDeg = np.rad2deg(newJointAngles)