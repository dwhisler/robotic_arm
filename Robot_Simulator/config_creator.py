# -*- coding: utf-8 -*-
"""
Configuration File Creator

Created on Mon Sep 17 20:49:12 2018

@author: bhatt
"""

import configparser
import os
import numpy as np
configfile_name = "config.ini"

cfgfile = open(configfile_name,'w')

config = configparser.ConfigParser()
config['KINEMATICS'] = {'DH': [
                                [np.pi/2,     0,   0,   2],
                                [0,           2,   0,   0],
                                [np.pi/2,     0,   0,   2],
                                [np.pi/2,     0,   0,   2],
                                [np.pi/2,     0,   0,   0],
                                [0,           0,   0,   2]
                             ],
                        'DOF': '6'}
config['LIMITS'] = {'JOINT_MIN': [-np.pi,-np.pi,-np.pi,-np.pi,-np.pi,-np.pi],
                    'JOINT_MAX': [np.pi,np.pi,np.pi,np.pi,np.pi,np.pi]}
                    
config['DEFAULTS'] = {'WORLD_FRAME': [0, 0, 0, 0, 0, 0],
                      'TOOL_POSITION': [0, 0, 0],
                      'HOME_POSITION': [0, 0, 0, 0, 0, 0]}
                         

            
config.write(cfgfile)
cfgfile.close()
