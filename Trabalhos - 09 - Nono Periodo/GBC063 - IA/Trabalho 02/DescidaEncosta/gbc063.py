#! /usr/bin/env python3

import random

def algoritmo(posic, opcoes):
	menorVizinho = posic
	menorDistancia = distanciaManhattan(posic)
	for x in opcoes:
		#percorre os vizinhos da posicao atual procurando uma distancia de Manhattan menor
		if distanciaManhattan(x) < menorDistancia:
			menorDistancia = distanciaManhattan(x)
			menorVizinho = x
	return menorVizinho

#calcula a distancia de Manhattan para uma dada posicao considerando o objetivo sendo (9,9)
def distanciaManhattan(posic):
	coluna = 9 - posic[0]
	linha = 9 - posic[1]
	return (coluna+linha)