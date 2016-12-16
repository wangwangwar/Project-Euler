module Main where

import Data.List

iter :: Integer -> Integer
iter start = if yes start then start else iter (start + 1)

yes :: Integer -> Bool
yes num = _yes num [2..6]

_yes :: Integer -> [Integer] -> Bool
_yes num multiples = and (map (\x -> sort (show num) == sort (show (num * x))) multiples)

main :: IO ()
main = do
    print (iter 10)
