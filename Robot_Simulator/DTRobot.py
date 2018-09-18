# -*- coding: utf-8 -*-
"""
DesktopBot Class
Class for simulated and physical robot implementation

Created on Mon Sep 17 08:28:05 2018

@author: amar bhatt
"""

from pybotics import Robot
from pybotics.kinematic_chain import MDHKinematicChain
from pybotics import Tool
from pybotics.geometry import *
import configparser
import os

import numpy as np

class DTRobot():
    """ Desktop Robot Class """
    kinematic_chain = []
    home_position = []
    dof = 0
    world_frame = []
    
    
    def __init__(self, config_file):
        
        if not os.path.isfile(config_file):
            print('INVALID CONFIG FILE: '+config_file)
            return
        
              
        configReader = configparser.ConfigParser()
        configReader.read(config_file)
        
        self.kinematic_chain = MDHKinematicChain(np.array(eval(configReader['KINEMATICS']['DH'])))
        self.world_frame = vector_2_matrix(eval(configReader['DEFAULTS']['WORLD_FRAME']))
        self.home_position = eval(configReader['DEFAULTS']['HOME_POSITION'])
        self.dof = eval(configReader['KINEMATICS']['DOF'])
        
        self.robot = Robot(self.kinematic_chain,None,self.world_frame,None)
        
        joint_min = eval(configReader['LIMITS']['JOINT_MIN'])
        joint_max = eval(configReader['LIMITS']['JOINT_MAX'])
        
        self.robot.joint_limits = np.ndarray(shape=(2,len(joint_min)),buffer=np.array([joint_min,joint_max]))
        self.robot.joints = self.home_position