import numpy
import AnalisadorLexico

data_path = "./codigo.txt"
data_path2 ="./Tabelas/TabelaTransicoes.csv"

compilador = AnalisadorLexico.Analisador(data_path)
tokens = compilador.analiseLexica()
print(tokens)

#tabela = AnalisadorLexico.TabelaTransicoes(data_path2)
#estado = tabela.recuperarEstado(18)
#print(str(estado))

        

		

