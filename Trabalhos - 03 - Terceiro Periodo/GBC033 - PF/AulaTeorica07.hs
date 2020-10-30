------------------------------------
-- Programa: Aula Teorica 07      --
-- Aluno: Marcelo Mendonca Borges --
-- Data: 31/05/2017               --
------------------------------------

------- Modulos Importados ---------
--import Data.Char

----------- Exercicio 01 -----------
-- () :: String -> Float -> Float -> Float
-- \(nome,peso,altura) -> peso/(altura*altura)
-- (\(nome,peso,altura) -> peso/(altura*altura)) ("Marcelo", 85.5, 1.85)

----------- Exercicio 02 -----------
-- () :: Int -> Bool
-- \x -> (mod x 3) == 0
-- filter (\x -> (mod x 3) == 0) [1,2,3,4,5,6,7,8,9]

----------- Exercicio 03 -----------
-- () :: FUNCAO(a) -> FUNCAO(a) -> a
-- \f g valor -> (f(g(valor)))
-- (\f g valor -> (f(g(valor)))) (\x -> x+1) (\y -> y-1) 10 = 10

----------- Exercicio 04 -----------
-- map (toUpper.head) ["maria","jose","silva"] = "MSJ"
-- (not.odd.length)"felicidade" = True
-- (isLetter.head.head.reverse) ["maria","silva","pereira"] = True
-- (even.(\x -> x*2+3).(\x -> div x 2).snd) (9+4,9-4) = False

----------- Exercicio 05 -----------
-- ('c':) = coloca 'c' na cabeca de uma lista de caracteres
-- \lista -> ('c':lista)
-- ('c':"arro") = "carro"

-- (:"fim") = colocar "fim" como a cauda de um caracter
-- \caracter = (caracter:"fim")
-- (:"fim") 'a' = "afim"

-- (==2) = verifica se o valor de entrada eh igual a 2
-- \x -> (x == 2)
-- (==2) 2 = True

-- (++"\n") = concatena "\n" a direita de uma lista de caracteres
-- \string -> string ++ "\n"
-- (++"\n") "pula_linha" = "pula_linha\n"

-- (^3) = eleva um numero a 3
-- \numero -> numero^3
-- (^3) 2 = 8

-- (3^) = eleva 3 a um numero
-- \numero -> 3^numero
-- (3^) 2 = 9

-- (`elem` "AEIOU") = verifica se um caracter esta presente na string "AEIOU"
-- \caracter = elem caracter "AEIOU" ou caracter `elem` "AEIOU"
-- (`elem` "AEIOU") 'A' = True

----------- Exercicio 06 -----------
-- resultado = 23

----------- Exercicio 07 -----------
-- \x y z = x*y*z
