-------------------------------------
-- Aluno: Marcelo Mendonca Borges  --
-- Matricula: 11611BCC020          --
-- Data: 30/06/2017                --
-------------------------------------

type Pessoa = String
type Livro = String

type BaseDeDados = [(Pessoa,Livro)]

--livros :: BaseDeDados -> Pessoa -> [Livro]
--leitores :: BaseDeDados -> Livro -> [Pessoa]
--emprestado :: BaseDeDados -> Livro -> Bool

baseDeDadosTeste :: BaseDeDados
baseDeDadosTeste = [("pessoa1","livroA"),("pessoa1","livroB"),("pessoa2","livroB"),("pessoa2","livroC")]

--Implementacoes Recursivas--------------------------------------------------------------------------------
livros_recursivo :: BaseDeDados -> Pessoa -> [Livro]
livros_recursivo [] pessoa = []
livros_recursivo (x:xs) pessoa
                        |(pessoa == fst x) = [snd x] ++ livros_recursivo xs pessoa
                        |otherwise = livros_recursivo xs pessoa

leitores_recursivo :: BaseDeDados -> Livro -> [Pessoa]
leitores_recursivo [] livro = []
leitores_recursivo (x:xs) livro
                        |(livro == snd x) = [fst x] ++ leitores_recursivo xs livro
                        |otherwise = leitores_recursivo xs livro

emprestado_recursivo :: BaseDeDados -> Livro -> Bool
emprestado_recursivo [] livro = False
emprestado_recursivo (x:xs) livro
                        |(livro == snd x) = True
                        |otherwise = emprestado_recursivo xs livro

--Implementacoes por Compreensao---------------------------------------------------------------------------
livros_compreensao :: BaseDeDados -> Pessoa -> [Livro]
livros_compreensao dados pessoa = [snd x | x <- dados, (fst x == pessoa)]

leitores_compreensao :: BaseDeDados -> Livro -> [Pessoa]
leitores_compreensao dados livro = [fst x | x <- dados, (snd x == livro)]

emprestado_compreensao_aux :: [Bool] -> Bool
emprestado_compreensao_aux [] = False
emprestado_compreensao_aux (x:xs)
                             |(x == True) = True
                             |otherwise = emprestado_compreensao_aux xs

emprestado_compreensao :: BaseDeDados -> Livro -> Bool
emprestado_compreensao dados livro = emprestado_compreensao_aux [(snd x == livro) | x <- dados]

--Implementacoes por Funcoes De Ordem Superior------------------------------------------------------------

--FOS = Funcoes De Ordem Superior

livros_fos :: BaseDeDados -> Pessoa -> [Livro]
livros_fos dados pessoa = map (snd) (filter (\x -> fst x == pessoa) dados)

leitores_fos :: BaseDeDados -> Livro -> [Pessoa]
leitores_fos dados livro = map (fst) (filter (\x -> snd x == livro) dados)

emprestado_fos_aux :: [Bool] -> Bool
emprestado_fos_aux [] = False
emprestado_fos_aux (x:xs)
                   |(x == True) = True
                   |otherwise = emprestado_fos_aux xs

emprestado_fos :: BaseDeDados -> Livro -> Bool
emprestado_fos dados livro = emprestado_fos_aux (map (\x -> snd x == livro) dados)
