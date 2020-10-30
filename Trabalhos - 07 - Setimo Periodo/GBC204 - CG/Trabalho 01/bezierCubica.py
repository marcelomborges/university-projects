import sys,pygame,numpy
from pygame import gfxdraw

pygame.init()
screen = pygame.display.set_mode((400,400))
screen.fill((0,0,0))
pygame.display.flip()
white=(255,255,255)

def bezierCubica(p1,p2,p3,p4):
        for t in numpy.arange(0,1,0.001):
                um_menos_t = 1-t
                um_menos_t_2 = um_menos_t*um_menos_t
                um_menos_t_3 = um_menos_t_2*um_menos_t
                t2 = t*t
                t3 = t2*t
                x = um_menos_t_3 * p1[0] + ((3*um_menos_t_2)*t*p2[0]) + (3*um_menos_t*t2*p3[0]) + t3*p4[0]
                y = um_menos_t_3 * p1[1] + ((3*um_menos_t_2)*t*p2[1]) + (3*um_menos_t*t2*p3[1]) + t3*p4[1]
                x = int(numpy.floor(x))
                y = int(numpy.floor(y))
                screen.set_at((x,y), white)
                pygame.display.flip()

#bezierCubica(ponto inicial, ponto de controle 1, ponto de controle 2, ponto final)
bezierCubica((100,100),(100,200),(300,200),(300,300))

while 1:
        for event in pygame.event.get():
                if event.type == pygame.QUIT: sys.exit()