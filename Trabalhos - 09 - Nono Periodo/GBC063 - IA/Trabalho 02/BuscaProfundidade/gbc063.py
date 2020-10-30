#! /usr/bin/env python3

import random

up = None
root = None
passeiPor = []

def algoritmo(posic, opcoes):
	#posic = posição atual do boneco
	#opcoes = caminho q ele pode seguir, aqui inclui em voltar de onde ele veio
	#Acresenta posic na lista de passei por
	if posic not in passeiPor:
		passeiPor.append(posic)
	
	#retira das opcoes td os lugares ele passou por
	for x in passeiPor:
		if x in opcoes:
			opcoes.remove(x)
	
	global up
	aux = None

	#testa se a arvore exite
	if root is None:
		#se ela n exitir cria uma nova arvore
		aux = Node(posic, None)
	else:
		#se ela exister, ve se posic já tem um nó e pega ele
		aux = elementoExiste(posic, root, [])
		if aux is None:
			#se Posic n tiver na arvore acresenta ele como filho da ultima posic
			aux = Node(posic, up)
			up.adicionarFilho(aux)
	# ultima posic(up) recebe o no atual
	up = aux
	#se tiver onde o boneco ir, ele segue me frente
	if len(opcoes) > 0:
		return opcoes[0]
	#caso contrario ele retorna para o pai dele
	else:
		return aux.pai.posic


def elementoExiste (posic, arvore, caminho):
    if posic == arvore.posic:
        return arvore
    for x in arvore.filhos:
        caminho.append(x)
    if len(caminho)>0:
        b = caminho.pop()
        if posic == b.posic:
	        return b
        else:
            return elementoExiste(posic, b, caminho)
    else:
        return None



class Node:
	def __init__(self, posic, pai):
		global root
		if root is None:
			root = self
		self.posic = posic
		self.filhos = []
		self.next = 0
		self.pai = pai
	

	def adicionarFilho(self, no):
		self.filhos.append(no)
			 
'''
#root = None


	global arvore
	aux = opicoes[random.randint(0,len(opicoes)-1)]
	noAux = Node(posic, opicoes)
	if noAux not in arvore:
		arvore.append(noAux)
	#print(arvore)
	return aux

#def DEPTH-LIMITED-SEARCH(posic, opicoes, limit):


def RECURSIVE-DLS (posic, estadoAnterior, opicoes, limit):
	for x in opicoes:
		if x is not estadoAnterior:'''
			
