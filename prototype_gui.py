# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'prototype_gui.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtWidgets, QtGui, QtCore
from PyQt5.QtWidgets import QMainWindow, QApplication
import serial
import sys

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1429, 963)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.resetButton = QtWidgets.QPushButton(self.centralwidget)
        self.resetButton.setGeometry(QtCore.QRect(610, 40, 251, 71))
        font = QtGui.QFont()
        font.setPointSize(24)
        font.setBold(True)
        font.setWeight(75)
        self.resetButton.setFont(font)
        self.resetButton.setObjectName("resetButton")
        self.splitter = QtWidgets.QSplitter(self.centralwidget)
        self.splitter.setGeometry(QtCore.QRect(400, 160, 681, 521))
        self.splitter.setOrientation(QtCore.Qt.Vertical)
        self.splitter.setObjectName("splitter")
        self.J1_Slider = QtWidgets.QSlider(self.splitter)
        self.J1_Slider.setMinimum(0)
        self.J1_Slider.setMaximum(180)
        self.J1_Slider.setOrientation(QtCore.Qt.Horizontal)
        self.J1_Slider.setObjectName("J1_Slider")

        self.J1_Slider.valueChanged.connect(self.setJ1pos)

        self.J2_Slider = QtWidgets.QSlider(self.splitter)
        self.J2_Slider.setMinimum(0)
        self.J2_Slider.setMaximum(180)
        self.J2_Slider.setOrientation(QtCore.Qt.Horizontal)
        self.J2_Slider.setObjectName("J2_Slider")

        self.J2_Slider.valueChanged.connect(self.setJ2pos)

        self.J3_Slider = QtWidgets.QSlider(self.splitter)
        self.J3_Slider.setMinimum(0)
        self.J3_Slider.setMaximum(180)
        self.J3_Slider.setProperty("value", 100)
        self.J3_Slider.setOrientation(QtCore.Qt.Horizontal)
        self.J3_Slider.setObjectName("J3_Slider")

        self.J3_Slider.valueChanged.connect(self.setJ3pos)

        self.J4_Slider = QtWidgets.QSlider(self.splitter)
        self.J4_Slider.setMinimum(0)
        self.J4_Slider.setMaximum(180)
        self.J4_Slider.setOrientation(QtCore.Qt.Horizontal)
        self.J4_Slider.setObjectName("J4_Slider")

        self.J4_Slider.valueChanged.connect(self.setJ4pos)

        self.J5_Slider = QtWidgets.QSlider(self.splitter)
        self.J5_Slider.setMinimum(0)
        self.J5_Slider.setMaximum(180)
        self.J5_Slider.setOrientation(QtCore.Qt.Horizontal)
        self.J5_Slider.setObjectName("J5_Slider")

        self.J5_Slider.valueChanged.connect(self.setJ5pos)

        self.J6_Slider = QtWidgets.QSlider(self.splitter)
        self.J6_Slider.setMinimum(0)
        self.J6_Slider.setMaximum(180)
        self.J6_Slider.setOrientation(QtCore.Qt.Horizontal)
        self.J6_Slider.setObjectName("J6_Slider")

        self.J6_Slider.valueChanged.connect(self.setJ6pos)

        self.EE_Slider = QtWidgets.QSlider(self.splitter)
        self.EE_Slider.setMinimum(0)
        self.EE_Slider.setMaximum(180)
        self.EE_Slider.setOrientation(QtCore.Qt.Horizontal)
        self.EE_Slider.setObjectName("EE_Slider")

        self.EE_Slider.valueChanged.connect(self.setEEpos)

        self.layoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(320, 160, 51, 521))
        self.layoutWidget.setObjectName("layoutWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.layoutWidget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.label = QtWidgets.QLabel(self.layoutWidget)
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.verticalLayout.addWidget(self.label)
        self.label_2 = QtWidgets.QLabel(self.layoutWidget)
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_2.setFont(font)
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.verticalLayout.addWidget(self.label_2)
        self.label_3 = QtWidgets.QLabel(self.layoutWidget)
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_3.setFont(font)
        self.label_3.setAlignment(QtCore.Qt.AlignCenter)
        self.label_3.setObjectName("label_3")
        self.verticalLayout.addWidget(self.label_3)
        self.label_4 = QtWidgets.QLabel(self.layoutWidget)
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_4.setFont(font)
        self.label_4.setAlignment(QtCore.Qt.AlignCenter)
        self.label_4.setObjectName("label_4")
        self.verticalLayout.addWidget(self.label_4)
        self.label_5 = QtWidgets.QLabel(self.layoutWidget)
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_5.setFont(font)
        self.label_5.setAlignment(QtCore.Qt.AlignCenter)
        self.label_5.setObjectName("label_5")
        self.verticalLayout.addWidget(self.label_5)
        self.label_6 = QtWidgets.QLabel(self.layoutWidget)
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_6.setFont(font)
        self.label_6.setAlignment(QtCore.Qt.AlignCenter)
        self.label_6.setObjectName("label_6")
        self.verticalLayout.addWidget(self.label_6)
        self.label_7 = QtWidgets.QLabel(self.layoutWidget)
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_7.setFont(font)
        self.label_7.setAlignment(QtCore.Qt.AlignCenter)
        self.label_7.setObjectName("label_7")
        self.verticalLayout.addWidget(self.label_7)
        self.widget = QtWidgets.QWidget(self.centralwidget)
        self.widget.setGeometry(QtCore.QRect(1100, 160, 91, 521))
        self.widget.setObjectName("widget")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.widget)
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.J1_pos = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.J1_pos.setFont(font)
        self.J1_pos.setObjectName("J1_pos")
        self.verticalLayout_2.addWidget(self.J1_pos)
        self.J2_pos = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.J2_pos.setFont(font)
        self.J2_pos.setObjectName("J2_pos")
        self.verticalLayout_2.addWidget(self.J2_pos)
        self.J3_pos = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.J3_pos.setFont(font)
        self.J3_pos.setObjectName("J3_pos")
        self.verticalLayout_2.addWidget(self.J3_pos)
        self.J4_pos = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.J4_pos.setFont(font)
        self.J4_pos.setObjectName("J4_pos")
        self.verticalLayout_2.addWidget(self.J4_pos)
        self.J5_pos = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.J5_pos.setFont(font)
        self.J5_pos.setObjectName("J5_pos")
        self.verticalLayout_2.addWidget(self.J5_pos)
        self.J6_pos = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.J6_pos.setFont(font)
        self.J6_pos.setObjectName("J6_pos")
        self.verticalLayout_2.addWidget(self.J6_pos)
        self.EE_pos = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.EE_pos.setFont(font)
        self.EE_pos.setObjectName("EE_pos")
        self.verticalLayout_2.addWidget(self.EE_pos)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1429, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

        self.ser = serial.Serial('COM3', 9600)

        self.cal = [[115, 550], [115, 560], [106, 515], [110, 533], [108, 512], [125, 541], [110, 320]]

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.resetButton.setText(_translate("MainWindow", "Reset"))
        self.label.setText(_translate("MainWindow", "J1"))
        self.label_2.setText(_translate("MainWindow", "J2"))
        self.label_3.setText(_translate("MainWindow", "J3"))
        self.label_4.setText(_translate("MainWindow", "J4"))
        self.label_5.setText(_translate("MainWindow", "J5"))
        self.label_6.setText(_translate("MainWindow", "J6"))
        self.label_7.setText(_translate("MainWindow", "EE"))
        self.J1_pos.setText(_translate("MainWindow", ""))
        self.J2_pos.setText(_translate("MainWindow", ""))
        self.J3_pos.setText(_translate("MainWindow", ""))
        self.J4_pos.setText(_translate("MainWindow", ""))
        self.J5_pos.setText(_translate("MainWindow", ""))
        self.J6_pos.setText(_translate("MainWindow", ""))
        self.EE_pos.setText(_translate("MainWindow", ""))

    def writeServo(self, port, pos):
        pwm = self.cal[port][0] + int((pos/180)*(self.cal[port][1]-self.cal[port][0]))
        self.ser.write((str(port).zfill(2) + str(pwm).zfill(4)).encode('utf-8'))

    def setJ1pos(self):
        self.writeServo(0, self.J1_Slider.value())
        self.J1_pos.setText(str(self.J1_Slider.value()))

    def setJ2pos(self):
        self.writeServo(1, self.J2_Slider.value())
        self.J2_pos.setText(str(self.J2_Slider.value()))

    def setJ3pos(self):
        self.writeServo(2, self.J3_Slider.value())
        self.J3_pos.setText(str(self.J3_Slider.value()))

    def setJ4pos(self):
        self.writeServo(3, self.J4_Slider.value())
        self.J4_pos.setText(str(self.J4_Slider.value()))

    def setJ5pos(self):
        self.writeServo(4, self.J5_Slider.value())
        self.J5_pos.setText(str(self.J5_Slider.value()))

    def setJ6pos(self):
        self.writeServo(5, self.J6_Slider.value())
        self.J6_pos.setText(str(self.J6_Slider.value()))

    def setEEpos(self):
        self.writeServo(6, self.EE_Slider.value())
        self.EE_pos.setText(str(self.EE_Slider.value()))


if __name__ == '__main__':
    from prototype_gui import Ui_MainWindow

    app = QApplication(sys.argv)
    window = QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(window)

    window.show()

    sys.exit(app.exec_())
    ui.ser.close()