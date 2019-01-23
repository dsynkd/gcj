{-# LANGUAGE TupleSections #-}

import Control.Applicative
import Control.Monad
import Data.List
import Text.Printf

isPalindrome n = let s = show n in s == reverse s
isFair n = isPalindrome n && isPalindrome (n*n)
main = do
	n <- readLn
	forM_ [1..n] $ \c -> do
		[a, b] <- map read . words <$> getLine
		printf "Case #%d: %d\n" (c :: Int) (length (takeWhile (<=b) [i*i | i <- [1..], isFair(i)]) - length (takeWhile (<a) [i*i | i <- [1..], isFair(i)]))
-- still too slow for lg2 input
