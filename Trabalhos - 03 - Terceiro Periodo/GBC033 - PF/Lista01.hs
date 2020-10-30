--------------------------------------
-- Programa: Lista de Exercicios 01 --
-- Aluno: Marcelo Mendonca Borges   --
-- Data: 05/05/2017                 --
--------------------------------------

------------ Exercicio 01 ------------
triplo :: Double -> Double
triplo x = 3*x

------------ Exercicio 02 ------------
maiorDeTres :: Double -> Double -> Double -> Double
maiorDeTres a b c = if(a>=b) && (a>=c)
                     then a
                     else if (b>=c)
                           then b
                           else c

------------ Exercicio 03 ------------
s :: Int -> Int
s n = sum[1..n]

------------ Exercicio 04 ------------
nEsimoTermoPA :: Integer -> Integer -> Integer -> Integer
nEsimoTermoPA n primeiro razao
                |n==1 = primeiro
                |n>1 = nEsimoTermoPA (n-1) (primeiro+razao) razao

------------ Exercicio 05 ------------
nEsimoTermoPG :: Integer -> Integer -> Integer -> Integer
nEsimoTermoPG n primeiro razao
                |n==1 = primeiro
                |n>1 = nEsimoTermoPG (n-1) (primeiro*razao) razao

------------ Exercicio 06 ------------
nPrimeirosPA :: Integer -> Integer -> Integer -> [Integer]
nPrimeirosPA n primeiro razao
               |n==1 = [primeiro]
               |n>1 = (primeiro: nPrimeirosPA (n-1) (primeiro+razao) razao)

------------ Exercicio 07 ------------
nPrimeirosPG :: Integer -> Integer -> Integer -> [Integer]
nPrimeirosPG n primeiro razao
               |n==1 = [primeiro]
               |n>1 = (primeiro: nPrimeirosPG (n-1) (primeiro*razao) razao)

------------ Exercicio 08 ------------
nEsimoFib :: Integer -> Integer
nEsimoFib n
          |n==1 = 1
          |n==2 = 1
          |n>2 = nEsimoFib(n-1) + nEsimoFib(n-2)

------------ Exercicio 09 ------------
bissexto :: Int -> Bool
bissexto x
           |(x `mod` 4)==0  && not((x `mod` 100)==0) = True
           |(x `mod` 400)==0 = True
           |otherwise = False

------------ Exercicio 10 ------------
primo :: Int -> Bool
primo x
      |(x < 1) = error "-> Entrada eh menor do que 1."
      |(x == 1) = False
      |(x > 1) = primoAux x 2

primoAux :: Int -> Int -> Bool
primoAux x y
           |(y == x) = True
           |((mod x y) == 0) = False
           |otherwise = primoAux x (y+1)

------------ Exercicio 11 ------------
letraMaiuscula :: Char -> Bool
letraMaiuscula letra = if((letra >= 'A') && (letra <= 'Z'))
                         then True
                         else False

------------ Exercicio 12 ------------
letraMinuscula :: Char -> Bool
letraMinuscula letra = if((letra >= 'a') && (letra <= 'z'))
                         then True
                         else False

------------ Exercicio 13 ------------
digito :: Char -> Bool
digito char = if((char >= '0')&&(char <= '9'))
                  then True
                  else False

------------ Exercicio 14 ------------
repete :: String -> Int -> String
repete string n
              |(n == 0) = []
              |otherwise = string ++ repete string (n-1)

------------ Exercicio 15 ------------
espacos :: Int -> String
espacos n
        |(n < 0) = error "->Valor de entrada invalido."
        |(n == 0) = []
        |otherwise = " " ++ espacos (n-1)

------------ Exercicio 16 ------------
insere_brancos :: Int -> String -> String
insere_brancos n string
      |((n - (length string)) > 0) = (espacos (n - (length string))) ++ string
      |otherwise = string

------------ Exercicio 17 ------------
maior :: (Int, Int, Int) -> Int
maior (x, y, z)
             |((x > y) && (x > z)) = x
             |(y > z) = y
             |otherwise = z

menor :: (Int, Int, Int) -> Int
menor (x, y, z)
             |((x < y) && (x < z)) = x
             |(y < z) = y
             |otherwise = z

menorEMaior :: Int -> Int -> Int -> (Int, Int)
menorEMaior x y z = (menor(x,y,z), maior(x,y,z))

------------ Exercicio 18 ------------
mdc :: Int -> Int -> Int
mdc x y
      |(x == y) = x
      |(y > x) = mdc y x
      |otherwise = mdc (x-y) y

------------ Exercicio 19 ------------
tresCrescentes :: Int -> Int -> Int -> (Int, Int, Int)
tresCrescentes x y z
                   |((x < y) && (x < z) && (y < z)) = (x,y,z)
                   |((x < y) && (x < z) && (z < y)) = (x,z,y)
                   |((y < z) && (x < z)) = (y,x,z)
                   |((y < z) && (z < x)) = (y,z,x)
                   |(x < y) = (z,x,y)
                   |otherwise = (z,y,x)

------------ Exercicio 20 ------------
type Ponto = (Float,Float)
type Reta1 = (Float,Float)

retaPorPontos :: Ponto -> Ponto -> (Float,Float)
retaPorPontos (a,b) (c,d) = ((b-d)/(a-c), (b-(((b-d)/(a-c))*a)))

------------ Exercicio 21 ------------
--type Ponto = (Float,Float)
type Reta2 = (Ponto,Ponto)

retaVertical :: Reta2 -> Bool
retaVertical ((a,b),(c,d)) = if ((a == c) && (b /= d))
                                then True
                                else False

retaHorizontal :: Reta2 -> Bool
retaHorizontal ((a,b),(c,d)) = if ((b == d) && (a /= c))
                                then True
                                else False

------------ Exercicio 22 ------------


------------ Exercicio 23 ------------
pontoPorOrdenada :: Float -> Reta1 -> Ponto
pontoPorOrdenada y (a,b) = (((y-b)/a), y)
