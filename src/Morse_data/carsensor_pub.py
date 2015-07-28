import sys
from laserscanner import *

import logging; logger = logging.getLogger("morse.builder." + __name__)
import math
from morse.builder.creator import SensorCreator, bpymorse
from morse.builder.blenderobjects import *
from carsensor import *
from std_msgs.msg import Float64MultiArray
from morse.middleware.ros import ROSPublisher, mathutils


class Carsensor(SensorCreator):
    def __init__(self, name=None):
        SensorCreator.__init__(self, name, "carsensor.Carsensor", "Carsensor")
        mesh = Cube("CarCube")
        mesh.scale = (.04, .04, .02)
        mesh.color(.8, .3, .1)
        self.append(mesh)

class CarsensorPublisher(ROSPublisher):
    """ Publish the wheel speed of the car. """
    ros_class = Carsensor
    

    def default(self, ci='unused'):
        arrayList = []
        arrayList.append(self.data['w_fl'])
        arrayList.append(self.data['w_fr'])
        arrayList.append(self.data['w_rl'])
        arrayList.append(self.data['w_rr'])
        dim = MultiArrayDimension()
        dim.size = len(arrayList)
        dim.label = 'carsensor'
        dim.stride = len(arrayList)
 

        carsensor = Float64MultiArray()
        carsensor.header = self.get_ros_header()
        carsensor.data = arrayList
        carsensor.layout.dim.append(dim)
        carsensor.layout.data_offset = 0
        self.publish(carsensor)
