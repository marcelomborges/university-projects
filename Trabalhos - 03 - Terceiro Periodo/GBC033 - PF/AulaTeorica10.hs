import STACK

size :: STACK a -> Int
size s
     |(isEmpty s) = 0
     |otherwise = 1 + size (pop s)

--Exemplos de Chamada:
--empty = STK []
--push 1 empty = STK [1]
--push 2 (push 1 empty) = STK [2,1]
--isEmpty (pop (pop (push 1 (push 2 empty))) = True
--pop empty = *** Exception: STACK.pop: empty stack
--size (push 1 (push 2 (push 3 (push 4 empty))))
