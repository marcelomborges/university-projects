----------------------------------------------
-- Programa: Prova 03 Programacao Funcional --
-- Aluno: Marcelo Mendonca Borges           --
-- Matricula: 11611BCC020                   --
----------------------------------------------
import System.IO

----- Questao 04 ----------------------------------------------------------------------------------

explode :: Int -> [Int]
explode  n = reverse (map (`mod` 10) (takeWhile (> 0) (iterate (`div` 10) n)))

----- Questao 05 ----------------------------------------------------------------------------------

data Complexo = Complex (Float, Float)
     deriving (Eq, Show)

instance Num Complexo
     where (+) (Complex (a, b)) (Complex (c, d)) = Complex (a+c, b+d)
           (-) (Complex (a, b)) (Complex (c, d)) = Complex (a-c, b-d)

----- Questao 06 ----------------------------------------------------------------------------------

data Motorista = Driver String Int Int
      deriving (Show, Read)

mainEscrita :: IO()
mainEscrita = hSetBuffering stdout NoBuffering >>
              putStr ("Digite o numero de dados de Motorista voce deseja armazenar: ") >>
              getLine >>=
              \quantidade -> dadosMotorista (read quantidade) "dados.dat"

dadosMotorista :: Int -> String -> IO()
dadosMotorista quantidade nomeArquivo = openFile nomeArquivo WriteMode >>=
                                        \handleArquivo -> hFlush handleArquivo >>
                                        escreveDadosMotorista quantidade handleArquivo >>
                                        hClose handleArquivo

escreveDadosMotorista :: Int -> Handle -> IO()
escreveDadosMotorista quantidade handleArquivo
     |(quantidade == 0) = return ()
     |otherwise = putStr ("Digite o sexo do motorista (M ou F): ") >>
                  getLine >>=
                  \sexo -> putStr ("Digite o ano de nascimento do Motorista: ") >>
                  getLine >>=
                  \ano -> putStr ("Digite o codigo de registro do Motorista: ") >>
                  getLine >>=
                  \registro -> putStrLn("") >>
                  hPutStrLn handleArquivo (show (Driver sexo (read ano) (read registro))) >>
                  escreveDadosMotorista (quantidade-1) handleArquivo

ehMulher :: Motorista -> Bool
ehMulher (Driver sexo ano registro)
                 |(head(sexo) == 'F') = True
                 |otherwise = False

porcentagemMulheres :: IO ()
porcentagemMulheres = openFile "dados.dat" ReadMode >>=
                      \handleArquivo -> hFlush stdout >>
                      leDadosMotorista 0 0 handleArquivo >>
                      hClose handleArquivo

leDadosMotorista :: Float -> Float -> Handle -> IO()
leDadosMotorista quantidadeMulheres quantidadeMotoristas handleArquivo = 
    do 
      x <- hIsEOF handleArquivo
      if (x)
      then putStrLn(show(quantidadeMulheres / quantidadeMotoristas))
      else
        do y <- hGetLine handleArquivo
           if (ehMulher(read y))
           then leDadosMotorista (quantidadeMulheres+1) (quantidadeMotoristas+1) handleArquivo
           else leDadosMotorista quantidadeMulheres  (quantidadeMotoristas+1) handleArquivo
                               

 