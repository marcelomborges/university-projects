import sys
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import pywavefront
from pywavefront import visualization
import math

obj = []

pos = [0.0,5.0,3.0] # posicao camera
front=[0.0,0.0,-1.0] # alvo, pra onde ela ta olhando
up = [0.0,1.0,0.0]  # vetor que define o tamanho do frustron
lastX=0.0
lastY=0.0
firstMouse = True
CameraSpeed = 0.1
mouseSensity = 0.5

pitch =0.0 # angulo vertical
yaw =0.0   # angulo horizontal

def cross(x,y): return [ x[1]*y[2] - x[2]*y[1], x[2]*y[0] - x[0]*y[2] , x[0]*y[1] - x[1]*y[1]] 

def display():
    global obj
   
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    gluLookAt(pos[0],pos[1],pos[2],
              pos[0]+front[0],pos[1]+front[1],pos[2]+front[2],
              up[0],up[1],up[2])
    visualization.draw(obj)
    
    glutSwapBuffers()
    return



def mouseMove(x, y):
    global lastX
    global lastY
    global mouseSensity
    global pitch
    global yaw
    global firstMouse
	
    if firstMouse:
      lastX = x
      lasty = y
      firstMouse = False
	
    dx = x - lastX 
    dy = lastY - y  # 0,0 é em cima da tela :)
    lastX = x
    lastY = y
    
    dx *= mouseSensity
    dy *= mouseSensity
	
    yaw += dx
    pitch += dy
	
	  
    if pitch > 89.0:
      pitch = 89.0
    elif pitch < -89.0:
      pitch = -89.0
	  
    #radianos
    rpitch = (math.pi * pitch)/180  
    ryaw = (math.pi*yaw)/180
	
    front[0] = math.cos(ryaw)* math.cos(rpitch) 
    front[1] = math.sin(rpitch)
    front[2] = math.cos(rpitch)*math.sin(ryaw)    	
	
    #normalizando
    n  = math.sqrt(front[0]*front[0] + front[1]*front[1]+front[2]*front[2])
    front[0]= front[0]/n
    front[1]= front[1]/n
    front[2]= front[2]/n
    
    glutPostRedisplay()
	
	
def keyboard(key, xx, yy):
  atY = pos[1]
  if ord(key) == ord('a'):  
    aux = cross(front,up)
    n  = math.sqrt(aux[0]*aux[0] + aux[1]*aux[1]+aux[2]*aux[2])
    aux[0]= aux[0]/n
    aux[1]= aux[1]/n
    aux[2]= aux[2]/n
    pos[0]-= aux[0]*CameraSpeed
    pos[1]-= aux[1]*CameraSpeed
    pos[2]-= aux[2]*CameraSpeed	
    pos[1] = atY
    glutPostRedisplay()

  if ord(key) == ord('d'): 
    aux = cross(front,up)
    n  = math.sqrt(aux[0]*aux[0] + aux[1]*aux[1]+aux[2]*aux[2])
    aux[0]= aux[0]/n
    aux[1]= aux[1]/n
    aux[2]= aux[2]/n
    pos[0]+= aux[0]*CameraSpeed
    pos[1]+= aux[1]*CameraSpeed
    pos[2]+= aux[2]*CameraSpeed	
    pos[1] = atY
    glutPostRedisplay()

  if ord(key) == ord('w'):  
    pos[0]+= front[0]*CameraSpeed
    pos[1]+= front[1]*CameraSpeed
    pos[2]+= front[2]*CameraSpeed
    
    pos[1] = atY
    glutPostRedisplay()

  if ord(key) == ord('s'):  
    pos[0]-= front[0]*CameraSpeed
    pos[1]-= front[1]*CameraSpeed
    pos[2]-= front[2]*CameraSpeed
    pos[1] = atY
    glutPostRedisplay()
  if ord(key) == ord(' '):#space
    pos[1]+=CameraSpeed
    glutPostRedisplay()
  if ord(key) == 50:  #2  
    pos[1]-=CameraSpeed
    glutPostRedisplay()
	


glutInit(sys.argv)
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
glutInitWindowSize(1900,1000)
glutCreateWindow("Sala de Cafe")
glutDisplayFunc(display) 
glClearColor(0.0,0.0,0.0,0.0) # cor de fundo 
	
glShadeModel(GL_SMOOTH)
glEnable(GL_CULL_FACE)
glEnable(GL_DEPTH_TEST)
lightZeroPosition = [0.,30.,-20.,20.]
lightZeroColor = [1,0.8,0.4,1] 
lightSpecular = [0.4,0.4,0.4,0.4]
lightAmbiente = [0.0,0.0,0.0,1]
glLightfv(GL_LIGHT0, GL_POSITION, lightZeroPosition)
glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColor)
glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular)
glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbiente)
glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.4)
glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.07)
glEnable(GL_LIGHT0)  
glEnable(GL_LIGHTING)
#glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightZeroColor)
    
glutDisplayFunc(display)
glMatrixMode(GL_PROJECTION)
gluPerspective(30.,1.,0.1,80.)
glMatrixMode(GL_MODELVIEW)
gluLookAt(pos[0],pos[1],pos[2],
              front[0]+pos[0],front[1]+pos[1],front[2]+pos[2],
              up[0],up[1],up[2])
			  

obj = pywavefront.Wavefront('rosquinhaTrab.obj')
glutDisplayFunc(display)
glutKeyboardFunc(keyboard)
glutPassiveMotionFunc(mouseMove)
glutMainLoop()