------------------------------------
-- Programa: Trabalho 01          --
-- Aluno: Marcelo Mendonca Borges --
-- Matricula: 11611BCC020         --
------------------------------------

--Trabalho 01: Produção de Um Recibo Fiscal em um Supermercado-----------------------------------------------
import Control.Monad --Import relacionado a implementacao com o Scanner

type Nome = String
type Preco = Int
type CodBar = Int
type BaseDeDados = [(CodBar,Nome,Preco)]
type ListaDeCodigos = [CodBar]
type Recibo = [(Nome,Preco)]

-------------------------------------------------------------------------------------------------------------

listaDeProdutos :: BaseDeDados
listaDeProdutos = [ (1234, "Oleo DoBom, 1l " , 195),
                    (4756, "Chocolate Cazzeiro, 250g " , 180),
                    (3216, "Arroz DoBom, 5Kg ", 213),
                    (5823, "Balas Pedregulho, 1Kg " , 379),
                    (4719, "Queijo Mineirim, 1Kg " , 449),
                    (6832, "Iogurte Maravilha, 1Kg " , 499),
                    (1112, "Rapadura QuebraDente, 1Kg ", 80),
                    (1111, "Sal Donorte, 1Kg ", 221),
                    (1113, "Cafe DoBom, 1Kg ", 285),
                    (1115, "Biscoito Bibi, 1Kg ", 80),
                    (3814, "Sorvete QGelo, 1l ", 695)]

tamLinha :: Int
tamLinha = 40

-------------------------------------------------------------------------------------------------------------

obtemCodigo :: (CodBar,Nome,Preco) -> CodBar
obtemCodigo (x,_,_) = x

obtemNome :: (CodBar,Nome,Preco) -> Nome
obtemNome (_,y,_) = y

obtemPreco :: (CodBar,Nome,Preco) -> Preco
obtemPreco (_,_,z) = z

obtemNomeEPreco :: (CodBar,Nome,Preco) -> (Nome,Preco)
obtemNomeEPreco (_,y,z) = (y,z)

obtemPrecoAlt :: (Nome,Preco) -> Preco
obtemPrecoAlt (_,y) = y

obtemEnesimaTupla :: Int -> (CodBar,Nome,Preco)
obtemEnesimaTupla x = listaDeProdutos !! x

-------------------------------------------------------------------------------------------------------------

formataCentavos :: Preco -> String
formataCentavos x = show(div x 100) ++ "." ++ show(rem x 100)

formataLinha :: (Nome,Preco) -> String
formataLinha (nome,preco) = nome ++ (replicate (tamLinha - (length (nome ++ " $" ++ formataCentavos preco))) '.') ++ " $" ++ formataCentavos preco ++ "\n"

formataLinhas :: [(Nome,Preco)] -> String
formataLinhas [] = []
formataLinhas (x:y) = formataLinha x ++ formataLinhas y

geraTotal :: Recibo -> Preco
geraTotal [] = 0
geraTotal (x:y) = obtemPrecoAlt x + geraTotal y

formataTotal :: Preco -> String
formataTotal total = "Total " ++ (replicate (tamLinha - (length ("Total " ++ " $" ++ formataCentavos total))) '.') ++ " $" ++ formataCentavos total ++ "\n"

formataRecibo :: Recibo -> String
formataRecibo recibo = formataLinhas recibo ++ formataTotal(geraTotal recibo)

-------------------------------------------------------------------------------------------------------------

achaAuxiliar :: BaseDeDados -> CodBar -> Int -> (Nome,Preco)
achaAuxiliar listaDeProdutos codigo 10
             |(codigo == obtemCodigo(last listaDeProdutos)) = obtemNomeEPreco(obtemEnesimaTupla 10)
             |otherwise = ("Item Desconhecido",0)
achaAuxiliar listaDeprodutos codigo x
             |(codigo == obtemCodigo(obtemEnesimaTupla x)) = obtemNomeEPreco(obtemEnesimaTupla x)
             |otherwise = achaAuxiliar listaDeProdutos codigo (x+1)

acha :: BaseDeDados -> CodBar -> (Nome,Preco)
acha listaDeProdutos codigo = achaAuxiliar listaDeProdutos codigo 0

achaItem :: CodBar -> (Nome,Preco)

achaItem codigo = acha listaDeProdutos codigo

-------------------------------------------------------------------------------------------------------------

listaDeCodigos :: ListaDeCodigos
listaDeCodigos = [1234,4756,3216,5823,4719,6832,1112,1111,1113,1115,3814] --Lista com todos os codigos dos produtos para facilitar os testes

fazRecibo :: ListaDeCodigos -> Recibo
fazRecibo [] = []
fazRecibo (x:y) = [achaItem x] ++ fazRecibo y

geraRecibo :: ListaDeCodigos -> String
geraRecibo lc = formataRecibo( fazRecibo lc)

--Essa funcao eh a que deve ser chamada
principal :: ListaDeCodigos -> IO()
principal lc = putStrLn("\nSupermercado do Marcelinho\n" ++ geraRecibo lc)

-------------------------------------------------------------------------------------------------------------
--Funcoes relacionadas a implementacao com o Scanner

--Transforma uma string em um inteiro
readInt :: String -> Int
readInt string = read string

--Percorre a string transformando os numeros da string em inteiros e os concatenando em uma lista de codigos
--O n representa a posicao atual na string
--Inicia com n=0 e uma string de numeros separados por o caracter espaco (" ")
geraCodigos :: Int -> String -> [Int]
geraCodigos n string
               |(n > (length string - 1)) = []
               |((string !! n) == ' ') = geraCodigos (n+1) string
               |otherwise = [readInt (geraStringNumeros n (contador n 0 string) string)] ++ geraCodigos (n+(contador n 0 string)) string

--Essa funcao obtem a substring que sera convertida em inteiro pegando cada char da string e concatenando para formar uma nova string
--Inicia com n na posicao atual da string e c eh um contador gerado pela funcao abaixo
geraStringNumeros :: Int -> Int -> String -> String
geraStringNumeros n c string
                         |(c==0) = []
                         |otherwise = [(string !! n)] ++ geraStringNumeros (n+1) (c-1) string

--Essa funcao recebe a posicao atual na string e percorre ate um proximo espaco incrementando um contador
--Depois ela retorna o valor do contador indicando o tamanho da substring
--Inicia com n na posicao atual da string e o contador c=0
contador :: Int -> Int -> String -> Int
contador n c string
                  |((n == (length string - 1)) && ((string !! n) /= ' ')) = 1
                  |(n == (length string - 1)) = 0
                  |((string !! n) == ' ') = 0
                  |otherwise = contador (n+1) (c+1) string + 1

--Essa funcao eh a principal da implementacao com o scanner
--Considera-se um scanner que le o codigo, coloca um espaco (" ") no final e "pressiona ENTER"
--Cria um loop que vai lendo cada codigo e adicionando no arquivo, ate que o 0 seja digitado para encerrar-lo
--Apos isso ocorre a leitura do arquivo obtendo a string de numeros separados por espaco (" ")
--Depois disso essa string eh aplicada na funcao geraCodigos que a converte em uma lista de codigos
--Por fim a lista de codigos eh aplicada na funcal "principal do programa"
main = do
        putStrLn ("-> Programa Inicializado.\n")
        putStrLn ("Escaneie o codigo (com espaco no final) ou digite 0 para encerrar:")
        writeFile "trabalho01.txt" "" --Cria um arquivo com o nome do primeiro argumento e inicializa ele com o segundo argumento
        let loop = do --Inicio do loop
               putStr("\nEscaneie o codigo: ")
               name <- getLine --Leitura do que foi escrito ("semelhante ao scanf")
               if (name == "0")
                 then (putStrLn "\n-> Gerando recibo...")
                 else (appendFile "trabalho01.txt" name) --Concatenacao do que foi obtido na leitura do "getLine"
               when (name /= "0") loop --Condicao de parada do loop
        loop --Fim do loop
        conteudo <- readFile "trabalho01.txt" --Leitura da string no arquivo
        principal (geraCodigos 0 conteudo) --Obtendo a lista de codigos com "geraCodigos" e aplicando essa lista na funcao "principal"
        putStrLn ("-> Programa Encerrado.\n")
