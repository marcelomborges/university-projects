------------------------------------
-- Programa: Aula Pratica 03      --
-- Aluno: Marcelo Mendonca Borges --
-- Data: 26/04/2017 e 28/04/2017  --
------------------------------------

----------- Exercicio 01 (Pagina: 33) ------------
{-
ou :: Bool -> Bool -> Bool
   True ou var1 = True
   False ou var2 = var2

ou' :: Bool -> Bool -> Bool
   True ou' _ = True
   _ ou' True = True
   _ ou' _ = False

ou'' :: Bool -> Bool -> Bool
   False ou'' False = False
   _ ou'' _ = True
-}

----------- Exercicio 02 (Pagina: 34) ------------

----------- Exercicio 03 (Pagina: 34) ------------

----------- Exercicio 04 (Pagina: 35) ------------

----------- Exercicio 05 (Pagina: 35) ------------

----------- Exercicio 06 (Pagina: 58) ------------

----------- Exercicio "O Dia da Semana" ----------
type Dia = Int
type Mes = Int
type Ano = Int
type Data = (Dia,Mes,Ano)


bissexto :: Int -> Bool
bissexto x
           |(x `mod` 4)==0  && not((x `mod` 100)==0) = True
           |(x `mod` 400)==0 = True
           |otherwise = False

numDeDiasEmCadaMesDeUmAno :: Ano -> [Int]
numDeDiasEmCadaMesDeUmAno ano =
                                [31,feb,31,30,31,30,31,31,30,31,30,31]
                                where feb
                                         |bissexto ano = 29
                                         |otherwise = 28

numDeDiasEmCadaMesDeUmAno1 :: Ano -> [Int]
numDeDiasEmCadaMesDeUmAno1 ano =
                              if (bissexto ano)
                                    then [31,29,31,30,31,30,31,31,30,31,30,31]
                                    else [31,28,31,30,31,30,31,31,30,31,30,31]

numDeDiasEmCadaMesDeUmAno2 :: Ano -> [Int]
numDeDiasEmCadaMesDeUmAno2 ano = [31,(if (bissexto ano) then 29 else 28),31,30,31,30,31,31,30,31,30,31]

numDeDiasEmCadaMesDeUmAno3 :: Ano -> [Int]
numDeDiasEmCadaMesDeUmAno3 ano = let feb = if (bissexto ano) then 29 else 28 
                                 in [31,feb,31,30,31,30,31,31,30,31,30,31]

numDeDias :: Data -> Int
numDeDias (dia,mes,ano) =
                          dia -- dias deste mes
                          + sum(take (mes-1) (numDeDiasEmCadaMesDeUmAno ano))
                          + (ano-2001)*365 + (ano-2001)`div`4

nomeDoDia :: Int -> String
nomeDoDia x =
              case x of
                   0 -> "Domingo"
                   1 -> "Segunda"
                   2 -> "Terca"
                   3 -> "Quarta"
                   4 -> "Quinta"
                   5 -> "Sexta"
                   6 -> "Sabado"

diaDaSemana :: Data -> String
diaDaSemana (dia,mes,ano) =
                            nomeDoDia (numDeDias (dia,mes,ano) `mod` 7)
