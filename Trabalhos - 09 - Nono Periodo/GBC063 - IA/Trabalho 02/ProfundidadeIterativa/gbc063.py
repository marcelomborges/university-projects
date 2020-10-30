#! /usr/bin/env python3

import random

up = None
root = None
passeiPor = []
limite = 25 #o limite é o mesmo estabelecido pelo run_labirinto, se for colocar ele em 1 vai ter q aumenta o limite no run labirinto
def algoritmo(posic, opcoes):
	global up
	global root
	global passeiPor
	global limite

	volta = False
	aux = None

	#se o posic está no root é pq o limite é muito pequeno é foi preciso aumenta ele, por isso volta a estrutura para seu modo inicial
	'''if root is not None and root.posic == posic and menorProfundidade(root, limite+1) == limite:
		limite = limite + 1
		root = None
		passeiPor = []
		up = None'''

	#posic = posição atual do boneco
	#opcoes = caminho q ele pode seguir, aqui inclui em voltar de onde ele veio
	#Acresenta posic na lista de passei por
	if posic not in passeiPor:
		passeiPor.append(posic)
	
	#retira das opcoes td os lugares ele passou por
	for x in passeiPor:
		if x in opcoes:
			opcoes.remove(x)
	
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
			if aux.profundidade > limite: #se a pronfudida do no é maior q o limite esse no n é adicionado na arvore
				volta = True
			else:
				up.adicionarFilho(aux)
	# ultima posic(up) recebe o no atual
	up = aux
	print(limite)
	if volta:
		#volta para o no anteiror 
		return aux.pai.posic
	#se tiver onde o boneco ir, ele segue me frente
	if len(opcoes) > 0:
		return opcoes[0]
	#caso contrario ele retorna para o pai dele
	else:
		if aux.pai is None:
			limite = limite + 1
			root = None
			passeiPor = []
			up = None
			return posic
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


def menorProfundidade(arv, menor):
	if len(arv.filhos) == 0:
		if arv.profundidade < menor:
			return arv.profundidade
		else:
			return menor
	else:
		for x in arv.filhos:
			return menorProfundidade(x,menor)


class Node:
	def __init__(self, posic, pai):
		global root
		if root is None:
			root = self
		self.posic = posic
		self.filhos = []
		if pai is None:
			self.profundidade = 1
		else:
			self.profundidade = pai.profundidade + 1
		self.pai = pai
		self.leaf = False
	

	def adicionarFilho(self, no):
		self.filhos.append(no)

			
