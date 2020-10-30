------------------------------------
-- Programa: Aula Pratica 07      --
-- Aluno: Marcelo Mendonca Borges --
-- Data: 09/06/2017               --
------------------------------------

data Hora = AM Int Int | PM Int Int
           deriving (Show, Eq)

totalHoras :: Hora -> Int
totalHoras (AM h m)
                 |((h>=0)&&(h<=11)) = h
                 |otherwise = error "Horas para AM devem estar entre 0 e 11"
totalHoras (PM h m)
                 |((h>=0)&&(h<=11)) = h+12
                 |otherwise = error "Horas para PM devem estar entre 0 e 11"

totalMinutos :: Hora -> Int
totalMinutos (AM h m) = h*60 + m
totalMinutos (PM h m) = (h+12)*60 + m

totalSegundos :: Hora -> Int
totalSegundos (AM h m) = h*3060 + m*60
totalSegundos (PM h m) = (h+12)*3600 + m*60

instance Ord Hora
   where (>) (PM _ _) (AM _ _) = True
         (>) (AM _ _) (PM _ _) = False
         (>) (AM x y) (AM z w)
                             |(x > z) = True
                             |((x == z)&&(y > w)) = True
                             |otherwise = False
         (>) (PM x y) (PM z w)
                             |(x > z) = True
                             |((x == z)&&(y > w)) = True
                             |otherwise = False
         (<) (PM _ _) (AM _ _) = False
         (<) (AM _ _) (PM _ _) = True
         (<) (AM x y) (AM z w)
                             |(x < z) = True
                             |((x == z)&&(y < w)) = True
                             |otherwise = False
         (<) (PM x y) (PM z w)
                             |(x < z) = True
                             |((x == z)&&(y < w)) = True
                             |otherwise = False
