import math
from xml.etree.ElementInclude import include


from math import *
v1 = [1 ,0 ,40]
v2 = [2 ,1 ,0]

a = math.acos((v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2])/(math.sqrt(math.pow(v1[0],2)+math.pow(v1[1],2)+math.pow(v1[2],2))*math.sqrt(math.pow(v2[0],2)+math.pow(v2[1],2)+math.pow(v2[2],2))))
#acos(a)
print (math.degrees(a))