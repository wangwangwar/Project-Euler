module P32(
    tuples,
    result
    ) where

import Data.List
import qualified Data.Set as Set

stringToInteger :: String -> Integer
stringToInteger s = read s :: Integer

toIntegerTuple :: (String, String, String) -> (Integer, Integer, Integer)
toIntegerTuple (s1, s2, s3) = (stringToInteger s1, stringToInteger s2, stringToInteger s3)


-- Divide to 2-3-4 parts
splitTo234 :: String -> (String, String, String)
splitTo234 s = (part1, part2, part3) where
    (part1, left) = splitAt 2 s
    (part2, part3) = splitAt 3 left

splitTo144 :: String -> (String, String, String)
splitTo144 s = (part1, part2, part3) where
    (part1, left) = splitAt 1 s
    (part2, part3) = splitAt 4 left

integer234Tuple = map (toIntegerTuple . splitTo234) (permutations "123456789")
integer144Tuple = map (toIntegerTuple . splitTo144) (permutations "123456789")

tuples = filter (\(x, y, z) -> x * y == z) (integer234Tuple ++ integer144Tuple)
products :: [Integer] 
products = map (\(_, _, x) -> x) tuples
result = sum ((Set.toList . Set.fromList) products)
