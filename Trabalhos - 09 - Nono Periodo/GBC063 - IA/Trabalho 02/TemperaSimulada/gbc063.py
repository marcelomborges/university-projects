#! /usr/bin/env python3

import random
import math
import time

def algoritmo(atual, opcoes, temperatura):
	T = funcaoTemperatura(temperatura, 0.99) #Aqui se define o fator de temperatura (valores utilizados 0.85 e 0.99)
	if T <= 0.00001:
		return [atual,T]
	proximo = opcoes[random.randint(0,len(opcoes)-1)]

	distanciaProximo = distanciaManhattan(proximo)
	distanciaAtual = distanciaManhattan(atual)
	deltaE = distanciaProximo - distanciaAtual

	if deltaE < 0:
		atual = proximo
	else:
		number = random.random()
		probabilidade = math.exp(deltaE/T)
		if number < probabilidade:
			atual = proximo
	
	return [atual, T]


#calcula a distancia de Manhattan para uma dada posicao considerando o objetivo sendo (9,9)
def distanciaManhattan(posic):
	coluna = 9 - posic[0]
	linha = 9 - posic[1]
	return (coluna+linha)

def funcaoTemperatura(T, fator):
	temp = T*fator
	return temp
