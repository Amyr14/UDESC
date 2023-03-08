{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
module Lista2 where

pertence' x cont lista
  | lista !! cont == x = True
  | cont + 1 == length lista = False
  | otherwise = pertence' x (cont + 1) lista

pertence x = pertence' x 0

inversoLista' x y 0 = y ++ [head x]
inversoLista' x [] cont = inversoLista' x [last x] (cont - 1)
inversoLista' x y cont = inversoLista' x (y ++ [x !! cont]) (cont - 1)

inversoLista x = inversoLista' x [] (length x - 1)

nUltimos' n pos x [] = nUltimos' (n - 1) (pos - 1) x [x !! pos]
nUltimos' n pos x y
  | n == 1 || pos == 0 = x !! pos : y
  | otherwise = nUltimos' (n - 1) (pos - 1) x (x !! pos : y)

nUltimos 0 x = []
nUltimos 1 x = [last x]
nUltimos n x = nUltimos' n (length x - 1) x []

enesimo 0 (x : xs) = -1
enesimo n [] = -1
enesimo n (x : xs)
  | n == 1 = x
  | n < 0 = -1
  | otherwise = enesimo (n - 1) xs

repetir' 1 (x : xs) = x : xs
repetir' n (x : xs) = repetir' (n - 1) (x : (x : xs))

repetir 0 m = []
repetir n m = repetir' n [m]

menor [x] = x
menor (x : xs)
  | x >= head xs = menor xs
  | otherwise = menor (xs ++ [x])

rmvElem' n [] i key = i
rmvElem' n (x : xs) i key
  | key = rmvElem' n xs (i ++ [x]) True
  | n == x = rmvElem' n xs i True
  | otherwise = rmvElem' n xs (i ++ [x]) False

removerElem n (x : xs) =
  rmvElem' n (x : xs) [] False

ordenarLista [x] = [x]
ordenarLista (x : xs) =
  menor (x : xs) :
  ordenarLista (removerElem (menor (x : xs)) (x : xs))

insereElem n (x : xs)
  | pertence n (x : xs) = x : xs
  | otherwise = ordenarLista (n : (x : xs))

intercalacao (x : xs) (y : ys) =
  ordenarLista ((x : xs) ++ (y : ys))

intercessao (x : xs) (y : ys) =
  [a | a <- x : xs, b <- y : ys, a == b]

primeirosDuplas ((a, b) : xs) =
  [c | (c, d) <- (a, b) : xs]

somaDuplas ((a, b) : xs) =
  [c + d | (c, d) <- (a, b) : xs]

menoresDuplas ((a, b) : xs) =
  [(c, d) | (c, d) <- (a, b) : xs, c < d]

separarDuplas v (x : xs) =
  (menores, maiores)
  where
    menores = [a | a <- x : xs, a <= v]
    maiores = [a | a <- x : xs, a > v]

inversoDupla ((a, b) : xs) =
  [(b, a) | (a, b) <- (a, b) : xs]

simetrico ((a, b) : xs) =
  [c == d | (c, d) <- (a, b) : xs]

inverteDNA :: String -> String
inverteDNA [] = []
inverteDNA (x : xs)
  | x == 'A' = inverteDNA xs ++ ['T']
  | x == 'T' = inverteDNA xs ++ ['A']
  | x == 'C' = inverteDNA xs ++ ['G']
  | x == 'G' = inverteDNA xs ++ ['C']

mdc (a, 0) = a
mdc (a, b) = mdc (b, mod a b)

-- x é o valor do café, y é o valor pago
aux n
  | n > 50 = (50, a) : aux (n - 50 * a)
  | n < 50 && n >= 20 = (20, b) : aux (n - 20 * b)
  | n < 20 && n >= 10 = (10, c) : aux (n - 10 * c)
  | n < 10 && n >= 5 = (5, d) : aux (n - 5 * d)
  | n < 5 = []
  where
    a = n `div` 50
    b = n `div` 20
    c = n `div` 10
    d = n `div` 5

trocoCafe x y = aux (y - x)

magica' (x : xs) 1 = [x]
magica' (x : xs) n = repetir n x ++ magica' xs (n - 1)

magica xs =
  magica' xs (length xs) ++ tail (inversoLista (magica' xs (length xs)))

pares x =
  [(1, 2)]