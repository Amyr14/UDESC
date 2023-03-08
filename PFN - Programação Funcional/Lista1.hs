module Lista1 where
  
ehTriangulo a b c =
  a + b > c
    && a + c > b
    && c + b > a

tipoTriangulo a b c
  | a == b && a == c = "equilatero"
  | a == b && a /= c || c == a && c /= b || c == b && c /= a = "isosceles"
  | otherwise = "escaleno"

triangulo a b c
  | ehTriangulo a b c = tipoTriangulo a b c 
  | otherwise = "nao eh um triangulo" 

armSoma 0 b = b
armSoma a b
  | even a = armSoma (a - 2) (b + a)
  | otherwise = armSoma (a - 1) b

somaPares n = armSoma n 0

somaPot2m m 0 = m
somaPot2m m n = (m * 2 ^ n) + somaPot2m m (n - 1)


primo' 1 n = True
primo' x n 
  | even n = False
  | mod n x == 0 = False
  | otherwise = primo' (x - 2) n

primo 0 = False
primo 1 = False 
primo 2 = True 
primo n = primo' (n - 2) n


seriePI n = seriePI' 1 n

seriePI' x n =
  if n < x + 2
    then
      if n < x
        then 0
        else 4 / x
    else (4 / x - 4 / (x + 2)) + seriePI' (x + 4) n
    