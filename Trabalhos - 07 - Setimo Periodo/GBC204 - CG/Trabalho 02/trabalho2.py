import sys
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import pywavefront
from pywavefront import visualization
import math

obj = []

g_RotateX = 0.0
g_RotateSpeed = 0.007
xOrigin = 0.0
g_RotateSpeedI =0.075
g_RotateY=0.0
yOrigin=0.0
g_RotateSpeedY = 0.08
g_RotateSpeedYI =0.05
def display():
    global obj
   
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)

    
    visualization.draw(obj)
    
    glutSwapBuffers()
    return



def mouseMove(x, y):
    global xOrigin
    global yOrigin
    global g_RotateSpeed
    global g_RotateSpeedI
    global g_RotateSpeedY
    glMatrixMode(GL_PROJECTION)
    deltaAngle = x - xOrigin
    deltaAngleY = y -yOrigin
    xOrigin = x
   
    if deltaAngle < 0:
      deltaAngle = deltaAngle + 360
      g_RotateX = deltaAngle*g_RotateSpeed 
      glRotatef(-g_RotateX,0.0,1.0,0.0)
    elif deltaAngle >360:
      deltaAngle = deltaAngle - 360
      g_RotateX = deltaAngle*g_RotateSpeedI
      glRotatef(g_RotateX,0.0,1.0,0.0)
    else:
      g_RotateX = deltaAngle*g_RotateSpeedI
      glRotatef(g_RotateX,0.0,1.0,0.0)
    
    glutPostRedisplay()
def keyboard(key, xx, yy):
  global angle
  
  glMatrixMode(GL_MODELVIEW)
  if ord(key) == ord('a'):  
    glTranslatef(0.1,0.0,0.0)
    glutPostRedisplay()

  if ord(key) == ord('d'): 
    glTranslatef(-0.1,0.0,0.0)
    glutPostRedisplay()

  if ord(key) == ord('w'):  
    glTranslatef(0.0,0.0,0.1)
    glutPostRedisplay()

  if ord(key) == ord('s'):  
    glTranslatef(0.0,0.0,-0.1)
    glutPostRedisplay()
  if ord(key) == ord(' '):#space
    glTranslatef(0.0,-0.1,0.0)
    glutPostRedisplay()
  if ord(key) == 50:  #2  
    glTranslatef(0.0,0.1,0.0)
    glutPostRedisplay()
  return

glutInit(sys.argv)
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
glutInitWindowSize(1900,1000)
glutCreateWindow("Sala de Cafe")
glutDisplayFunc(display) 
glClearColor(0.0,0.0,0.0,0.0) # cor de fundo 
	
glShadeModel(GL_SMOOTH)
glEnable(GL_CULL_FACE)
glEnable(GL_DEPTH_TEST)
lightZeroPosition = [15.,4.,-20.,1.]
lightZeroColor = [1,0.8,0.4,1] 
lightSpecular = [0.5,0.5,0.5,0.5]
lightAmbiente = [0.0,0.0,0.0,1]
glLightfv(GL_LIGHT0, GL_POSITION, lightZeroPosition)
glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColor)
glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular)
glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbiente)
glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.05)
glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.06)
glEnable(GL_LIGHT0)  
glEnable(GL_LIGHTING)
#glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightZeroColor)
    
glutDisplayFunc(display)
glMatrixMode(GL_PROJECTION)
gluPerspective(30.,1.,0.1,80.)
glMatrixMode(GL_MODELVIEW)
gluLookAt(0,0,10,
          0,0,0,
          0,1,0)
		  
obj = pywavefront.Wavefront('rosquinhaTrab.obj')
glutDisplayFunc(display)
glutKeyboardFunc(keyboard)
glutMotionFunc(mouseMove)
glutMainLoop()