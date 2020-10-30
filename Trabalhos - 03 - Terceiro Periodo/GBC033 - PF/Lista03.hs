--------------------------------------
-- Programa: Lista de Exercicios 02 --
-- Aluno: Marcelo Mendonca Borges   --
-- Data: --/--/2017                 --
--------------------------------------

------------ Exercicio 01 ------------
deriv :: Fractional a => (a -> a) -> a -> a -> a
deriv f dx = \x -> (f(x + dx) - f(x)) / dx

------------ Exercicio 02 ------------
data NomeP = Nome String deriving (Show)
data SobreNomeP = SobreNome String deriving (Show) type NomeCompleto = (NomeP,SobreNomeP)

------------ Exercicio 03 ------------
data Exp a = Val a -- um numero
      | Neg (Exp a)
      | Add (Exp a) (Exp a) -- soma de duas expressoes
      | Sub (Exp a) (Exp a) -- subtracao
      | Mul (Exp a) (Exp a) -- multiplicacao
      | Div (Exp a) (Exp a) -- divisao
avalia :: Fractional a => Exp a -> a
avalia (Val x) = x
avalia (Neg exp) = - (avalia exp)
avalia (Add exp1 exp2) = (avalia exp1) + (avalia exp2)
avalia (Sub exp1 exp2) = (avalia exp1) - (avalia exp2)
avalia (Mul exp1 exp2) = (avalia exp1) * (avalia exp2)
avalia (Div exp1 exp2) = (avalia exp1) / (avalia exp2)

data LL = Latitude Int Int Int
          | Longitude Int Int Int deriving (Eq)

instance Show LL where
              show (Latitude a b c) = "Lat " ++ show a ++"°" ++ show b ++"'"++ show c ++"''"

type PosicaoLocal = (String, LL, LL) type Cidades = [PosicaoLocal]

c1,c2::PosicaoLocal
c1 = ("Brasilia", Latitude (-15) 46 47, Longitude 47 55 47)
c2 = ("Uberlandia", Latitude (-18) 55 07, Longitude 48 16 38)
eLat::PosicaoLocal->(String,LL)
eLat (p,(Latitude a b c),(Longitude x y z)) = (p,(Latitude a b c))
