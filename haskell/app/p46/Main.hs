module Main where

import Data.Numbers.Primes

--oddNotPrimeUpper :: Integer -> [Integer]
--oddNotPrimeUpper n = filter (\x -> x `notElem` primesUpper n) (drop 1 (take (fromInteger n::Int) odds))

odds :: [Integer]
odds = oddsInner 0
    where 
        oddsInner :: Integer -> [Integer]
        oddsInner i = (2 * i + 1):oddsInner (i+1)

--primesUpper :: Integer -> [Integer]
--primesUpper n = _primesUpper 0 n [2..n]
--    
--_primesUpper :: Integer -> Integer -> [Integer] -> [Integer]
--_primesUpper i n list = 
--    if li * li <= n then _primesUpper (i + 1) n filtered else list
--    where 
--        li = list !! (fromInteger i :: Int)
--        filtered = delete li list
--
--delete :: Integer -> [Integer] -> [Integer]
--delete n = filter (\x -> x `rem` n /= 0 || x == n)

doubleSquareList :: [Integer]
doubleSquareList = map (\x -> 2 * x * x) [1..]

test :: Integer
test = _test (drop 1 odds)

_test :: [Integer] -> Integer
_test (n:ns) = if result then _test ns else n
    where 
        list = takeWhile (> 0) (map (\x -> n - x) primes)
        result = or (map (`elem` takeWhile (< n) doubleSquareList) list) || isPrime n

main :: IO ()
main = do
    print test
