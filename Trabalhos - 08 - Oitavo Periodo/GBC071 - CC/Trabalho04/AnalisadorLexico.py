#!/usr/bin/python3

import sys
import numpy

header = ['estado','final','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','=','>','<','+','-','*','/','(',')',';']

retornos = []
retornos.append(['11','op_aritmetico','+']) 
retornos.append(['12','op_aritmetico','-'])
retornos.append(['13','op_aritmetico','*'])
retornos.append(['14','op_aritmetico','/'])
retornos.append(['15','pontuacao','('])
retornos.append(['16','pontuacao',')'])
retornos.append(['17','pontuacao',';'])
retornos.append(['18','id','nulo'])
retornos.append(['26','enquanto','nulo'])
retornos.append(['29','fim','nulo'])
retornos.append(['36','inicio','nulo'])
retornos.append(['37','int','nulo'])
retornos.append(['45','programa','nulo'])
retornos.append(['47','se','nulo'])
retornos.append(['49','atribuicao','nulo'])
retornos.append(['50','op_relacional','=='])
retornos.append(['51','op_relacional','>'])
retornos.append(['52','op_relacional','>='])
retornos.append(['53','op_relacional','<'])
retornos.append(['54','op_relacional','<='])
retornos.append(['55','op_relacional','<>'])

class Token():
	def __init__(self,tipo,atributo,linha,coluna):
		self.tipo = tipo
		self.linha = linha
		self.coluna = coluna
		self.atributo = atributo

	def imprimirValor(self):
		print(self.tipo,self.atributo,self.linha,self.coluna)

class TabelaSimbolos():
	def __init__(self):
		self.tabelaSimbolos = []

	def adicionarElemento(self,valor):
		for i in range(0,len(self.tabelaSimbolos)):
			if self.st[i] == valor:
				return i
		self.tabelaSimbolos.append(valor)
		return (len(self.tabelaSimbolos) - 1)

class TabelaTransicoes():
	def __init__(self, data_path):
		self.tabelaTransicoes = numpy.loadtxt(data_path, delimiter=',')
		self.estadoFinais = []

		for i in range(0, 56):
			if(str(int(self.tabelaTransicoes[i][1])) == '1'):
				self.estadoFinais.insert(i,1)
			elif(str(int(self.tabelaTransicoes[i][1])) == '2'):
				self.estadoFinais.insert(i,2)
			else:
				self.estadoFinais.insert(i,0)

	def move(self,estado,cabeca):
		indice = 0
		for i in range(0, len(header)):
			if(header[i]==cabeca):
				indice = i

		return self.tabelaTransicoes[int(estado)][indice]
	
	def final(self,estado):
		if self.estadoFinais[int(estado)] >= 1:
			return self.estadoFinais[int(estado)]
		return False

	def recuperarEstado(self,estado):
		for i in range(0, len(retornos)):
			if (int(estado) == int(retornos[i][0])):
				return [retornos[i][1], retornos[i][2]]


class Analisador():
	def __init__(self, caminhoArquivo):
		self.codigoFonte = caminhoArquivo
		self.tabelaTransicoes = TabelaTransicoes("./Tabelas/TabelaTransicoes.csv")
		self.tabelaSimbolos = TabelaSimbolos()
		self.bufferEntrada = []

	def criacaoToken(self,nome,valorAtributo,linha,coluna):
		if (str(nome) == "id"):
			posicaoTabela = self.tabelaSimbolos.adicionarElemento(valorAtributo)
			token = Token(nome,posicaoTabela,linha,coluna)
		else:
			token = Token(nome,valorAtributo,linha,coluna)
		return token

	def analiseLexica(self):
		tokens = []
		arquivo = open(self.codigoFonte, "r")
		self.buffer = arquivo.read()

		comecoLexema = 0
		finalLexema = 0
		estadoAtual = 0
		linha = 1
		coluna = 1

		for i in range(0, len(self.buffer)):
			cabeca = self.buffer[i]
			print("cabeca = " + str(cabeca))
			print("estado = " + str(estadoAtual))

			if (cabeca == " ") or (cabeca == "\t"):
				coluna += 1
				continue
			if (cabeca == "\n"):
				coluna = 1
				linha += 1
				continue
			if (comecoLexema == 0):
				comecoLexema = i

			estadoAtual = self.tabelaTransicoes.move(estadoAtual, cabeca)
			if(self.tabelaTransicoes.final(estadoAtual) == 1):
				finalLexema=coluna
				info = self.tabelaTransicoes.recuperarEstado(estadoAtual)
				lexema = self.criacaoToken(info[0],info[1],linha,comecoLexema)
				lexema.imprimirValor()
				tokens.append(lexema)
				estadoAtual = 0
					
			elif(self.tabelaTransicoes.final(estadoAtual) == 2):
				finalLexema=coluna
				print(estadoAtual)
				info = self.tabelaTransicoes.recuperarEstado(estadoAtual)
				print(info)
				if(info[1] == 'nulo'):
					lexema = self.criacaoToken(info[0],self.buffer[comecoLexema:coluna + 1].replace(" ","").replace("\n","").replace("\t",""),linha,comecoLexema)
				else:
					lexema = self.criacaoToken(info[0],info[1],linha,comecoLexema)
				
				lexema.imprimirValor()
				print(self.tabelaSimbolos.tabelaSimbolos[0])
				tokens.append(lexema)
				estadoAtual = 0
			
			


		return tokens
