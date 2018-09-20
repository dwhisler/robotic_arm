
import serial
import numpy as np

class ServoDriver():

    def __init__(self, com):
        cal = [[115, 550], [115, 560], [106, 515], [110, 533], [108, 512], [125, 541], [110, 320]]
        ser = serial.Serial('COM' + str(com), 9600)

    def writeServo(joint, angle):
        pwm = self.cal[port][0] + int((angle / (np.pi/3)) * (self.cal[port][1] - self.cal[port][0]))
        self.ser.write((str(port).zfill(2) + str(pwm).zfill(4)).encode('utf-8'))