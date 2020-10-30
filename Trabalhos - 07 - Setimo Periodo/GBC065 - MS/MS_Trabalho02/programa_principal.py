#cd \"Projetos da Faculdade"\"Projeto - 07 - Academia (2019-1)"

#Imports------------------------------------------------------------------------------------------#
import math
import modelo_mm1
import modelo_mm2
import numeros_aleatorios as numeros
import estatisticas_mm1
import estatisticas_mm2
from prettytable import PrettyTable

#Variaveis----------------------------------------------------------------------------------------#
programa = True
modelo = "mm1"
numero_simulacoes = 10
alfa = 0.05

#Funcoes------------------------------------------------------------------------------------------#
def print_modelo():
        tabela1 = PrettyTable(['Modelo de Fila'])
        tabela1.add_row([modelo])
        print (tabela1)

def menu():
        print("\nLista de Comandos:--------------------------------------------------------------------------------------------")
        print("Comando 1) sair: Encerra o programa")
        print("Comando 2) set_modelo: Define o modelo de fila a ser utilizado")
        print("     Argumento 1: Modelo da fila (mm1 ou mm2)")
        print("Comando 3) set_variaveis_globais: Define as variaveis globais do programa para os dois modelos de fila")
        print("     Argumento 1: Limite da fila (int)")
        print("     Argumento 2: Numero de eventos (int)")
        print("     Argumento 3: Numero de simulacoes por evento (int)")
        print("     Argumento 4: Valor do Alfa (float)")
        print("Comando 4) set_variaveis_chegada: Define as variaveis das chegadas do programa para os dois modelos de fila")
        print("     Argumento 1: Tipo de distribuicao (deter, norm, unif, expo)")
        print("     Argumento 2: Lambda para distribuicao exponencial")
        print("     Argumento 3: Media para distribuicao normal")
        print("     Argumento 4: Desvio padrao para distribuicao normal")
        print("     Argumento 5: Valor inferior para distribuicao uniforme")
        print("     Argumento 6: Valor superior para distribuicao uniforme")
        print("     Argumento 7: Valor para tempo deterministico")
        print("Comando 5) set_variaveis_servico: Define as variaveis do servico do programa para os dois modelos de fila")
        print("     Argumento 1: Tipo de distribuicao (deter, norm, unif, expo)")
        print("     Argumento 2: Lambda para distribuicao exponencial")
        print("     Argumento 3: Media para distribuicao normal")
        print("     Argumento 4: Desvio padrao para distribuicao normal")
        print("     Argumento 5: Valor inferior para distribuicao uniforme")
        print("     Argumento 6: Valor superior para distribuicao uniforme")
        print("     Argumento 7: Valor para tempo deterministico")
        print("Comando 6) set_variaveis_numeros: Define as variaveis para geracao de numeros aleatorios")
        print("     Argumento 1: Valor para a semente do programa (Seed) (int)")
        print("     Argumento 2: Valor \"a\" para geracao de numeros (int)")
        print("     Argumento 3: Valor \"b\" para geracao de numeros (int)")
        print("     Argumento 4: Valor \"m\" sendo o mod para geracao de numeros (de preferencia 2^k) (int)")
        print("Comando 7) executar: Executa o programa considerando o modelo de fila escolhido")
        print("Comando 8) comandos: Apresenta a lista de comandos do simulador")
        print("--------------------------------------------------------------------------------------------------------------\n")

while programa:
        resposta = input("\nsimulador ("+modelo+"): ")
        info = resposta.split(' ')
        resultado = []

        if (resposta == "sair"):
                programa = False
                break

        elif(info[0] == "set_modelo"):
                #info[1] = Modelo de fila (mm1, mm2)
                modelo = info[1]
                print_modelo()

        elif (info[0] == "set_variaveis_globais"):
                #info[1] = Limite da fila
                #info[2] = Numero de eventos
                #info[3] = Numero de simulacoes por evento
                #info[4] = Valor do Alfa
                modelo_mm1.set_variaveis_globais(info[1], info[2])
                modelo_mm2.set_variaveis_globais(info[1], info[2])
                modelo_mm1.print_variaveis_globais(numero_simulacoes, alfa)
                modelo_mm2.print_variaveis_globais(numero_simulacoes, alfa)
                numero_simulacoes = int(info[3])
                alfa = float(info[4])

        elif (info[0] == "set_variaveis_chegada"):
                #info[1] = Tipo de distribuicao (deter, norm, unif, expo)
                #info[2] = Lambda para distribuicao exponencial
                #info[3] = Media para distribuicao normal
                #info[4] = Desvio padrao para distribuicao normal
                #info[5] = Valor inferior para distribuicao uniforme
                #info[6] = Valor superior para distribuicao uniforme
                #info[7] = Valor para tempo deterministico
                modelo_mm1.set_variaveis_chegada(info[1],info[2],info[3],info[4],info[5],info[6],info[7])
                modelo_mm2.set_variaveis_chegada(info[1],info[2],info[3],info[4],info[5],info[6],info[7])
                modelo_mm1.print_variaveis_chegada()
                modelo_mm2.print_variaveis_chegada()

        elif (info[0] == "set_variaveis_servico"):
                #info[1] = Tipo de distribuicao (deter, norm, unif, expo)
                #info[2] = Lambda para distribuicao exponencial
                #info[3] = Media para distribuicao normal
                #info[4] = Desvio padrao para distribuicao normal
                #info[5] = Valor inferior para distribuicao uniforme
                #info[6] = Valor superior para distribuicao uniforme
                #info[7] = Valor para tempo deterministico
                modelo_mm1.set_variaveis_servico(info[1],info[2],info[3],info[4],info[5],info[6],info[7])
                modelo_mm2.set_variaveis_servico(info[1],info[2],info[3],info[4],info[5],info[6],info[7])
                modelo_mm1.print_variaveis_servico()
                modelo_mm2.print_variaveis_servico()

        elif (info[0] == "set_variaveis_numeros"):
                #info[1] = Valor para a semente do programa (Seed) (int)
                #info[2] = Valor "a" para geracao de numeros (int)
                #info[3] = Valor "b" para geracao de numeros (int)
                #info[4] = Valor "m" sendo o mod para geracao de numeros (de preferencia 2^k) (int)
                numeros.set_variaveis(info[1],info[2],info[3],info[4])
                numeros.print_variaveis()

        elif (resposta == "executar"):
                print_modelo()

                if (modelo == "mm1"):
                        modelo_mm1.print_variaveis_globais(numero_simulacoes, alfa)
                        modelo_mm1.print_variaveis_chegada()
                        modelo_mm1.print_variaveis_servico()
                        for i in range(numero_simulacoes):
                                print("\nSIMULACAO",i,":----------------------------------------------------------------------------------------")
                                print("")
                                resultado.append(modelo_mm1.simulacao(i))
                        estatisticas_mm1.calculo_simulacoes(resultado, alfa)
                elif (modelo == "mm2") :
                        modelo_mm2.print_variaveis_globais(numero_simulacoes, alfa)
                        modelo_mm2.print_variaveis_chegada()
                        modelo_mm2.print_variaveis_servico()
                        for i in range(numero_simulacoes):
                                print("\nSIMULACAO",i,":----------------------------------------------------------------------------------------")
                                print("")
                                resultado.append(modelo_mm2.simulacao(i))
                        estatisticas_mm2.calculo_simulacoes(resultado, alfa)
                else :
                        print ("-> ERRO: Modelo desconhecido\n")


        elif (resposta == "comandos"):
                menu()

        else : 
                print ("-> ERRO: Comando desconhecido\n")
