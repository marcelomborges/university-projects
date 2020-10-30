------------------------------------
-- Programa: Aula Pratica 09      --
-- Aluno: Marcelo Mendonca Borges --
-- Data: 07/06/2017               --
------------------------------------

data Dia = Dom | Seg | Ter | Qua | Qui | Sex | Sab

finalDeSemana :: Dia -> Bool
finalDeSemana Sab = True
finalDeSemana Dom = True
finalDeSemana _ = False

----------------------------------------------------------------------------------------------

{-
data Est = Primavera | Outono | Inverno | Verao

instance Eq Est
 where (==) Verao Verao = True
       (==) Inverno Inverno = True
       (==) Primavera Primavera = True
       (==) Outono Outono = True
       (==) _ _ = False
-}

--ou

data Est = Primavera | Outono | Inverno | Verao
     deriving Eq

tempo :: Est -> String
tempo s
      |(s == Verao) = "quente"
      |otherwise = "frio"

----------------------------------------------------------------------------------------------

{-
data Pessoa = Ind Nome Sobrenome AnoNascimento
     deriving (Show)

type Nome = String
type Sobrenome = String
type AnoNascimento = Int

p1,p2,p3::Pessoa
p1 = Ind "Stephen" "Hawking" 1942
p2 = Ind "Albert" "Einstein" 1879
p3 = Ind "Isaac" "Newton" 1643

primeiroNome :: Pessoa -> String
primeiroNome (Ind pNome _ _ ) = pNome

ultimoNome :: Pessoa -> String
ultimoNome (Ind _ uNome _ ) = uNome

anoNascimento :: Pessoa -> Int
anoNascimento (Ind _ _ vAno ) = vAno
-}

data Pessoa = Ind { primNome :: String, ultNome :: String, anoNasc :: Int }
              deriving (Show)

p4::Pessoa
p4 = Ind {primNome="Stephen", ultNome="Hawking", anoNasc=1942}

----------------------------------------------------------------------------------------------

data Forma = Circulo Float Float Float | Retangulo Float Float Float Float
             deriving Show
area :: Forma -> Float
area (Circulo _ _ r) = pi * r ^ 2

----------------------------------------------------------------------------------------------

data Expr = Lit Int | Add Expr Expr | Sub Expr Expr

eval::Expr->Int
eval (Lit n) = n
eval (Add e1 e2) = (eval e1) + (eval e2)
eval (Sub e1 e2) = (eval e1) - (eval e2)

----------------------------------------------------------------------------------------------

{-
data Lista a = Nil | Cons a (Lista a)
     deriving (Show)
-}

data Lista a = Nil | Cons a (Lista a)

tam :: (Lista a) -> Int
tam Nil = 0
tam (Cons cabeca cauda) = 1 + tam cauda

--tam (Cons 1 (Cons 2 (Cons 3 Nil)))
--3
