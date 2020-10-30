#! /usr/bin/env python3
'''
PyMaze driver class. Makes use of the maze class to parse program arguments.
@author: Paul Miller (github.com/138paulmiller)
adapted by Dino Franklin
'''

import os, sys, random, time, threading
import maze_gbc063 as maze
import gbc063


# defalt ANSI settings from user
COLOR_DEFAULT = u'\u001b[0m'
# foreground colors (text)
COLOR_BLACK = u'\u001b[30m'
COLOR_RED =  u'\u001b[31m'
COLOR_GREEN = u'\u001b[32m'
COLOR_YELLOW = u'\u001b[33m'
COLOR_BLUE  =u'\u001b[34m'
COLOR_MAGENTA = u'\u001b[35m'
COLOR_CYAN = u'\u001b[36m'
COLOR_WHITE = u'\u001b[37m'
# background colors 
COLOR_BG_BLACK = u'\u001b[40m'
COLOR_BG_RED =	u'\u001b[41m'
COLOR_BG_GREEN =  u'\u001b[42m'
COLOR_BG_YELLOW = u'\u001b[43m'
COLOR_BG_BLUE = u'\u001b[44m'
COLOR_BG_MAGENTA =  u'\u001b[45m'
COLOR_BG_CYAN = u'\u001b[46m'
COLOR_BG_WHITE= u'\u001b[47m'


def play_maze(maze_obj, limit,tinkle):
	
	#clear the screen clear if linux, cls if windows
	os.system('clear' if os.name!='nt' else 'cls')	
	
	# mostra o labirinto
	print(maze_obj.to_str())	
	
	current = (0,0)
	# em (0,0) pergunta para o labirinto acoes possiveis
	info = maze_obj.move(current)
	current = info[1]
	options = info[2]
		
	move = 0
	temperatura = 1000

	# sai qdo atinge o max de passos ou chega no objetivo
	while not (move > limit) and not maze_obj.is_done():
		action = gbc063.algoritmo(current, options, temperatura)
		temperatura = action[1]
		time.sleep(tinkle)
		info = maze_obj.move(action[0])
		current = info[1]
		options = info[2]
		# update maze based on algoritmo feedback
		move += 1

	distancia = gbc063.distanciaManhattan(current)
	# saindo
	if (move < limit) and (current == (9,9)):
		print('-> Distancia ate o objetivo: {0}'.format(distancia))
		print(' -> O objetivo foi atingido com ',move,' movimentos');
		print(' -> Solucao (',len(maze_obj.path),' passos)')
		print(' -> Solucao {0}'.format(maze_obj.path))
		print(' -> Ponto final: {0}'.format(current))
	elif (current != (9,9)):
		print('-> Distancia ate o objetivo: {0}'.format(distancia))
		print(' -> O melhor objetivo local foi atingido com ',move,' movimentos');
		print(' -> Solucao otima local (',len(maze_obj.path),' passos)')
		print(' -> Solucao {0}'.format(maze_obj.path))
		print(' -> Ponto final: {0}'.format(current))
	else:
		print('O objetivo nao foi atingido em ',move,' movimentos.');
		

def main():

	# set opcoes
	clock = 0.1
	seed = random.random()*10000		
	width = 10 	#20
	height = 10 	#12
	limite = 1000
	is_block = True
	is_color = True
	block_symbol = u'\u2588'#unicode FullBlock
	block_symbols = {
		'start' : u'O',
		'end' : u'X',
		'wall_v' : block_symbol, 
		'wall_h' : block_symbol,
		'wall_c' : block_symbol,
		'visited' : block_symbol,
	}
	color_symbols = {
		'empty_color' : COLOR_DEFAULT,
		'visited_color' : COLOR_WHITE,   # incluido
		'wall_color' : COLOR_BLUE,
		'head_color' : COLOR_RED,
		'tail_color' : COLOR_CYAN,
		'start_bg_color' : COLOR_BG_YELLOW,
		'end_bg_color' : COLOR_BG_YELLOW,
		# if color, full block for player too
		'head' : block_symbol,
		'tail' : block_symbol,
		'visited' : block_symbol,   # incluido
	}
	#default symbols (not unicode or ANSI coloring)
	symbols = {
		# default symbols
		'start' : 'S',
		'end' : 'X',
		'wall_v'  : '|',
		'wall_h' : '-',
		'wall_c' : '+',
		'head' :  '#',
		'tail' : 'o',	
		'empty' : ' ',
		'visited' : 'v',
	}

	# se quiser desenho em blocos - necessario monospaced font
	# se  nao, comente com #
	symbols.update(block_symbols)
	symbols.update(color_symbols)
				
	# cria o labirinto
	maze_obj = maze.Maze(width, height, seed, symbols)

	# usa seu algoritmo (gbc063) para sair do labirinto
	play_maze(maze_obj,limite,clock)


# main
if __name__ == '__main__':
	main() 
