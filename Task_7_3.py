import numpy as np
import time
import math


class motor:

    def __init__(self):
        self.speed = 0
        self.direction = 0

    def changeSpeed(self, w):
        
        if( w > 0 ):
            self.direction = 1
        else:
            self.direction = 0
            w *= -1

        if( w > 255 ):
            w = 255

        

class Motors:

    def __init__(self):
        self.motor1 = motor()
        self.motor2 = motor()
        self.motor3 = motor()

    def changSpeeds(self, w1, w2, w3):
        
        self.motor1.changeSpeed(w1)

        self.motor2.changeSpeed(w2)

        self.motor3.changeSpeed(w3)



        
        
        
class Robot:

    def __init__(self):
        self.Ws = Motors()
        self.Vx = 0
        self.Vy = 0
        self.w = 0
        self.Vgx = 0
        self.Vgy = 0
        self.Wg = 0
        self.kin = np.array( [[-np.sin(30 * (np.pi/180)), -np.sin(150* (np.pi/180)), -np.sin(270* (np.pi/180))], [np.cos(30* (np.pi/180)), np.cos(150* (np.pi/180)), np.cos(270* (np.pi/180))], [1, 1, 1]] )
        
    def reverse_kin(self, vx, vy, w):

        self.Vx = vx
        self.Vy = vy
        self.w = w

        elements = np.array( [self.Vx, self.Vy, self.w] )
        
        rev_kin = np.linalg.pinv(self.kin)

        ws = rev_kin @ elements
        
    def forward_kin(self, m1, m2, m3):
        
        self.Ws.motor1 = m1
        self.Ws.motor2 = m2
        self.Ws.motor3 = m3

        elements = np.array( [self.Ws.motor1, self.Ws.motor2, self.Ws.motor3] )
        xyw = self.kin @ elements
    




class PID():
    def __init__(self, Kp = 1, Ki = 1, Kd = 1):
        self.Kp = Kp
        self.Ki = Ki
        self.Kd = Kd

        self.proportional = 0
        self.derivative = 0
        self.integral = 0

        self.__Target = 0

        self.Prev_Time = 0
        self.dt = 0

        self.error = 0
        self.prev_error = 0

    def Set_Target_Distance(self, target):
        self.__Target = target

    def update(self, Distance):
        self.error = self.__Target - Distance
        
        self.dt = 0.1

        self.proportional = self.Kp * self.error
        self.derivative = self.Kd * ((self.error - self.prev_error) / (self.dt ))
        self.integral += self.Ki * self.error * (self.dt) 
        self.prev_error = self.error

        return self.proportional + self.derivative + self.integral, self.dt
    

#Target distance is ten meters
Target_x = 10
Target_y = 10
pos_x = 0
pos_y = 0

d_robot = Robot()

pid = PID(1, 1, 0.01)



while(pos_x*pos_x + pos_y*pos_y < Target_x*Target_x+Target_y*Target_y ):
    """
    From the output of the PID controler find the respective speed
    Calculate the distance moved by integrating the speed over the time passed
    Use this distance as input to the next iteration of the PID control 
      """

    pid.Set_Target_Distance(Target_x)
    vx, dt = pid.update(pos_x)
    pos_x += vx * dt
    
    pid.Set_Target_Distance(Target_y)
    vy, dt = pid.update(pos_y)
    pos_y += vy * dt
    
    d_robot.reverse_kin(vx, vy, math.tan(pos_y/ pos_x))


    
