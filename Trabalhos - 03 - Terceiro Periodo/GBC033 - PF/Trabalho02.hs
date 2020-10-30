------------------------------------
-- Programa: Trabalho 02          --
-- Aluno: Marcelo Mendonca Borges --
-- Matricula: 11611BCC020         --
------------------------------------

--Trabalho 02: Producao de um Recibo Fiscal em um Supermercado utilizando Funcoes de Alta Ordem--------------

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
formataLinhas xs = foldl1 (++) (map formataLinha xs)

geraTotal :: Recibo -> Preco
geraTotal xs = foldl1 (+) (map obtemPrecoAlt xs)

formataTotal :: Preco -> String
formataTotal total = "Total " ++ (replicate (tamLinha - (length ("Total " ++ " $" ++ formataCentavos total))) '.') ++ " $" ++ formataCentavos total ++ "\n"

formataRecibo :: Recibo -> String
formataRecibo recibo = formataLinhas recibo ++ formataTotal(geraTotal recibo)

-------------------------------------------------------------------------------------------------------------
comparaCodigos :: CodBar -> (CodBar,Nome,Preco) -> Bool
comparaCodigos cod1 (cod2,_,_)
                             |(cod1 == cod2) = True
                             |otherwise = False

achaAuxiliar :: BaseDeDados -> CodBar -> [(CodBar,Nome,Preco)]
achaAuxiliar listaDeProdutos codigo = filter (comparaCodigos codigo) listaDeProdutos

acha :: BaseDeDados -> CodBar -> (Nome,Preco)
acha listaDeProdutos codigo = obtemNomeEPreco(head(achaAuxiliar listaDeProdutos codigo))

achaItem :: CodBar -> (Nome,Preco)
achaItem codigo = acha listaDeProdutos codigo

-------------------------------------------------------------------------------------------------------------

listaDeCodigos :: ListaDeCodigos
listaDeCodigos = [1234,4756,3216,5823,4719,6832,1112,1111,1113,1115,3814] --Lista com todos os codigos dos produtos para facilitar os testes

fazRecibo :: ListaDeCodigos -> Recibo
fazRecibo xs = map achaItem xs

geraRecibo :: ListaDeCodigos -> String
geraRecibo lc = formataRecibo(fazRecibo lc)

--Essa funcao eh a que deve ser chamada
principal :: ListaDeCodigos -> IO()
principal lc = putStrLn("\nSupermercado do Marcelinho\n" ++ geraRecibo lc)
