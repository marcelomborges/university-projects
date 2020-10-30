module STACK (STACK, push, pop, top, empty, isEmpty) where
data STACK a = STK [a]deriving (Show)

push :: a -> STACK a -> STACK a
push x (STK xs) = STK (x:xs)

pop :: STACK a -> STACK a
pop (STK (_:xs)) = STK xs
pop _ = error "STACK.pop: empty stack"

top :: STACK a -> a
top (STK (x:_)) = x
top (STK []) = error "STACK.top: empty stack"

empty :: STACK a
empty = STK []

isEmpty :: STACK a -> Bool
isEmpty (STK []) = True
isEmpty (STK _) = False
