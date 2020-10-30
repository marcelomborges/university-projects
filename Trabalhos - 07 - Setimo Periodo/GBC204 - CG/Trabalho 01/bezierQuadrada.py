import sys,pygame,numpy
from pygame import gfxdraw

pygame.init()
screen = pygame.display.set_mode((400,400))
screen.fill((0,0,0))
pygame.display.flip()
white=(255,255,255)

def bezierQuadrada(ponto_inicial,ponto_controle,ponto_final):
        for t in numpy.arange(0,1,0.001):
                um_menos_t = 1-t
                um_menos_t_2 = um_menos_t*um_menos_t
                t2 = t*t
                x = um_menos_t_2 * ponto_inicial[0] + (2*um_menos_t)*t*ponto_controle[0] + t2*ponto_final[0]
                y = um_menos_t_2 * ponto_inicial[1] + (2*um_menos_t)*t*ponto_controle[1] + t2*ponto_final[1]
                x = int(numpy.floor(x))
                y = int(numpy.floor(y))
                screen.set_at((x,y), white)
                pygame.display.flip()

#bezierQuadrada(ponto inicial, ponto de controle, ponto final)
bezierQuadrada((100,100),(100,200),(300,300))

while 1:
        for event in pygame.event.get():
                if event.type == pygame.QUIT: sys.exit()