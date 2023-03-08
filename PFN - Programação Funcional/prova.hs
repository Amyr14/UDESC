
{-# OPTIONS_GHC -Wno-incomplete-patterns #-}

--Questão 1)
maioresMenores :: Ord a => [a] -> a -> ([a], [a])
maioresMenores [] y = ([], [])
maioresMenores (x : xs) y =
  (menor, maior)
  where
    menor = [a | a <- x : xs, a < y]
    maior = [a | a <- x : xs, a > y]

--Questão 2)
marcar :: [Char] -> Char -> [Char]
marcar [] c = []
marcar (x : xs) c
  | x == c = '*' : marcar xs c
  | otherwise = x : marcar xs c

--Questão 3)
inserir :: Ord a => a -> [a] -> [a]
inserir x (y : ys) =
  (menor ++ [x]) ++ maior
  where
    menor = [a | a <- y : ys, a < x]
    maior = [a | a <- y : ys, a > x]

--Questão 4)
intercalacao :: Ord a => [a] -> [a] -> [a]
intercalacao [] (y : ys) = y : ys
intercalacao (x : xs) [] = x : xs
intercalacao (x : xs) (y : ys)
  | x <= y = x : intercalacao xs (y : ys)
  | x > y = y : intercalacao (x : xs) ys

--Questão 5)
contaPalavras :: (Num a) => [Char] -> a
contaPalavras [] = 1
contaPalavras (' ' : xs) = 1 + contaPalavras xs
contaPalavras (x : xs) = contaPalavras xs

--Questão 6)
data Arvore a =
   Folha
  | Galho a (Arvore a) (Arvore a)
  deriving (Show)

mapArv :: (a -> b) -> Arvore a -> Arvore b
mapArv fun Folha = Folha
mapArv fun (Galho a b c) =
  Galho (fun a) (mapArv fun b) (mapArv fun c)
