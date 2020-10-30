#Imports------------------------------------------------------------------------------------------#
import math
import numeros_aleatorios as numeros
import estatisticas_mm2
from prettytable import PrettyTable

#Variaveis----------------------------------------------------------------------------------------#
#Variaveis de Chegada
variaveis_chegada = ["expo", 1, 10, 3, 6, 9, 5]
#variaveis_chegada[0] = Tipo de Distribuicao (deter, norm, unif, expo)
#variaveis_chegada[1] = Lambda para distribuicao exponencial
#variaveis_chegada[2] = Media para distribuicao normal
#variaveis_chegada[3] = Desvio padrao para distribuicao normal
#variaveis_chegada[4] = Valor inferior para distribuicao uniforme
#variaveis_chegada[5] = Valor superior para distribuicao uniforme
#variaveis_chegada[6] = Valor para tempo deterministico

#Variaveis de Servico
variaveis_servico = ["expo", 1, 10, 3, 6, 9, 5]
#variaveis_servico[0] = Tipo de Distribuicao (deter, norm, unif, expo)
#variaveis_servico[1] = Lambda para distribuicao exponencial
#variaveis_servico[2] = Media para distribuicao normal
#variaveis_servico[3] = Desvio padrao para distribuicao normal
#variaveis_servico[4] = Valor inferior para distribuicao uniforme
#variaveis_servico[5] = Valor superior para distribuicao uniforme
#variaveis_servico[6] = Valor para tempo deterministico

#Outras Variaveis
#ES1 = Estado do servidor 1
#ES2 = Estado do servidor 2
#TF = Tamanho da fila
#TR = Tempo do relogio da simulacao
#TS = Tempo de servico
#TEC = Tempo de intervalo para a proxima chegada
#HC = Tempo de ocorrencia do proximo evento de chegada
#HS1 = Tempo de ocorrencia do proximo evento de saida do servidor 1
#HS2 = Tempo de ocorrencia do proximo evento de saida do servidor 2
limite_fila = math.inf
numero_eventos = 20
tempos_servico1 = []
tempos_servico2 = []
tempo_ocioso1 = 0
tempo_ocioso2 = 0

#Funcoes------------------------------------------------------------------------------------------#
def evento_chegada(es1,es2,tf,tr,hc,hs1,hs2):
        #Variaveis------------------------------#
        global variaveis_chegada
        global variaveis_servico
        global tempos_servico1
        global tempos_servico2
        global tempo_ocioso1
        global tempo_ocioso2
        
        tec = 0
        ts = 0
        tr = hc
        #---------------------------------------#

        if (es1 == 0):
                es1 = 1
                ts = numeros.geracao_tempo(variaveis_servico)
                hs1 = tr + ts
                tempos_servico1.append(ts)
                
        elif (es2 == 0):
                es2 = 1                
                ts = numeros.geracao_tempo(variaveis_servico)
                hs2 = tr + ts
                tempos_servico2.append(ts)
                
        else:
                tf = tf + 1

        tec = numeros.geracao_tempo(variaveis_chegada)
        hc = tr + tec

        return es1,es2,tf,tr,hc,hs1,hs2
        
def evento_saida(es1,es2,tf,tr,hc,hs1,hs2):
        #Variaveis------------------------------#
        global variaveis_chegada
        global variaveis_servico
        ts = 0
        #---------------------------------------#
        if(hs1<hs2):
                tr = hs1

                if (tf > 0):
                        tf = tf - 1
                        ts = numeros.geracao_tempo(variaveis_servico)
                        hs1 = tr + ts
                        tempos_servico1.append(ts)
                else:
                        es1 = 0
                        hs1 = 999999
        elif(hs1==hs2):
                tr = hs1

                if (tf > 0):
                        tf = tf - 1
                        ts = numeros.geracao_tempo(variaveis_servico)
                        hs1 = tr + ts
                        tempos_servico1.append(ts)
                else:
                        es1 = 0
                        hs1 = 999999
                        es2 = 0
                        hs2 = 999999
        else:
                tr = hs2

                if (tf > 0):
                        tf = tf - 1
                        ts = numeros.geracao_tempo(variaveis_servico)
                        hs2 = tr + ts
                        tempos_servico2.append(ts)
                else:
                        es2 = 0
                        hs2 = 999999

        return es1, es2,tf,tr,hc,hs1, hs2

def simulacao(simu):
        #Variaveis------------------------------#
        global numero_eventos
        global limite_fila
        global tempos_servico1
        global tempos_servico2
        global tempo_ocioso1
        global tempo_ocioso2 
        i = 0
        es1 = 0
        es2 = 0                
        tr = 0
        tf = 0
        hc = 0
        hs1 = 999999
        hs2 = 999999
        pessoa = 0
        pessoas_na_fila = 0
        tempo_ocioso1 = 0
        tempo_ocioso2 = 0
        tempos_servico1 = []
        tempos_servico2 = []
        tempos_espera = []
        numeros.iniciar_seed = True
        tabela1 = PrettyTable(['simulacao '+str(simu), 'ES1', 'ES2', 'TF', 'TR', 'HC', 'HS1', 'HS2'])
        #---------------------------------------#

        numeros.print_variaveis()

        while (i < numero_eventos):
                if (hc < hs1) and (hc < hs2)  and (tf < limite_fila):
                        #Processamento de Evento de Chegada
                        es1,es2,tf,tr,hc,hs1,hs2 = evento_chegada(es1,es2,tf,tr,hc,hs1,hs2)
                        if (tf > 0): #Se a fila nao esta vazia
                                tempos_espera.append(hc) #Indica o tempo de entrada da pessoa
                                pessoas_na_fila = pessoas_na_fila + 1
                        
                else:
                        #Processamento de Evento de Saida
                        if(pessoas_na_fila > 0): #Deve-se primeiro tratar uma pessoa da fila antes de gerar outro evento de saida
                                if (hs2 >= hs1):
                                        tempos_espera[pessoa] = hs1 - tempos_espera[pessoa] #Calcula a diferenca entre a entrada e a saida da pessoa
                                else:
                                        tempos_espera[pessoa] = hs2 - tempos_espera[pessoa] #Calcula a diferenca entre a entrada e a saida da pessoa
                                                                        
                                        #Com a diferenca calculada tem-se o tempo de espera da pessoa
                                pessoa = pessoa + 1 #Muda para fazer o calculo para a proxima pessoa que sair
                                pessoas_na_fila = pessoas_na_fila - 1
                        es1,es2,tf,tr,hc,hs1,hs2 = evento_saida(es1, es2,tf,tr,hc,hs1, hs2)
 
                tabela1.add_row([i, es1, es2, tf, tr, hc, hs1, hs2])
                
                i = i + 1

        print (tabela1)
        #Remove as pessoas que nao esperaram na fila, deixando somente os tempos de quem esperou
        for i in range(pessoa,len(tempos_espera)):
                tempos_espera[i] = tr - tempos_espera[i]
        tempos_espera = [x for x in tempos_espera if x > 0]

        tempo_ocioso1 = tr - sum(tempos_servico1)
        tempo_ocioso2 = tr - sum(tempos_servico2)
        
        return estatisticas_mm2.resultados(tr, tempos_servico1, tempos_servico2, tempos_espera, tempo_ocioso1, tempo_ocioso2)

def set_variaveis_globais(lf, ne):
        #Variaveis------------------------------#
        global limite_fila
        global numero_eventos
        #---------------------------------------#
        limite_fila = int(lf)
        numero_eventos = int(ne)

def set_variaveis_chegada(v0,v1,v2,v3,v4,v5,v6):
        #Variaveis------------------------------#
        global variaveis_chegada
        #---------------------------------------#
        variaveis_chegada[0] = v0
        variaveis_chegada[1] = float(v1)
        variaveis_chegada[2] = float(v2)
        variaveis_chegada[3] = float(v3)
        variaveis_chegada[4] = float(v4)
        variaveis_chegada[5] = float(v5)
        variaveis_chegada[6] = float(v6)

def set_variaveis_servico(v0,v1,v2,v3,v4,v5,v6):
        #Variaveis------------------------------#
        global variaveis_servico
        #---------------------------------------#
        variaveis_servico[0] = v0
        variaveis_servico[1] = float(v1)
        variaveis_servico[2] = float(v2)
        variaveis_servico[3] = float(v3)
        variaveis_servico[4] = float(v4)
        variaveis_servico[5] = float(v5)
        variaveis_servico[6] = float(v6)

def print_variaveis_globais(numero_simulacoes, alfa):
        print("\nMM2 - Variaveis de Globais:")
        tabela1 = PrettyTable(['Limite da Fila', 'Numero de Eventos', 'Numero de Simulacoes', 'Alfa'])
        tabela1.add_row([limite_fila, numero_eventos, numero_simulacoes, alfa])
        print (tabela1)

def print_variaveis_chegada():
        print("\nMM2 - Variaveis de Chegada:")
        tabela1 = PrettyTable(['Tipo de Dist.', 'Lambda (Expo)', 'Media (Norm)', 'Desvio P. (Norm)', 'Inf. (Unif)', 'Sup. (Unif)', 'Temp. (Deter)'])
        tabela1.add_row([variaveis_chegada[0],variaveis_chegada[1],variaveis_chegada[2],variaveis_chegada[3],variaveis_chegada[4],variaveis_chegada[5],variaveis_chegada[6]])
        print (tabela1)

def print_variaveis_servico():
        print("\nMM2 - Variaveis de Servico:")
        tabela1 = PrettyTable(['Tipo de Dist.', 'Lambda (Expo)', 'Media (Norm)', 'Desvio P. (Norm)', 'Inf. (Unif)', 'Sup. (Unif)', 'Temp. (Deter)'])
        tabela1.add_row([variaveis_servico[0],variaveis_servico[1],variaveis_servico[2],variaveis_servico[3],variaveis_servico[4],variaveis_servico[5],variaveis_servico[6]])
        print (tabela1)








