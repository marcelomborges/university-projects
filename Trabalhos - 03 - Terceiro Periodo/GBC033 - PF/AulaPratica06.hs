------------------------------------
-- Programa: Aula Pratica 06      --
-- Aluno: Marcelo Mendonca Borges --
-- Data: 02/06/2017               --
------------------------------------

produto :: Num t => [t] -> t
produto [x] = x
produto (x:xs) = x * produto xs

iguais :: Eq t => t -> t -> t -> Bool
iguais n m p = (n == m) && (m == p)

tamanho :: [t] -> Int
tamanho [] = 0
tamanho (x:xs) = 1 + tamanho xs

f :: Num a => a -> [t] -> [t] -> (a, [t])
f x y z = (x + 1, y ++ z)

rep :: (Num a, Eq a)  => a -> b -> [b]

rep 0 ch = []
rep n ch = ch : rep (n-1) ch
