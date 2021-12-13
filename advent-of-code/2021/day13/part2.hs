#!/usr/bin/env runhaskell
import Data.Char
import Data.List
import System.IO

parseNumbers :: String -> Int -> (Int, Int)
parseNumbers (',':cs) acc = (read cs, acc)
parseNumbers (c:cs) acc = parseNumbers cs $ acc * 10 + digitToInt c

parsePoint :: String -> (Int, Int)
parsePoint s = parseNumbers s 0

readPoints :: IO [(Int, Int)]
readPoints = do
  line <- getLine
  if null line
    then return []
    else do
      ps <- readPoints
      return $ parsePoint line : ps

parseCoord :: String -> (Bool, Int)
parseCoord ('x':(_:s)) = (True, read s)
parseCoord ('y':(_:s)) = (False, read s)

parseInstruction :: String -> (Bool, Int)
parseInstruction s = parseCoord $ words s !! 2

readInstructions :: IO [(Bool, Int)]
readInstructions = do
  eof <- isEOF
  if eof
    then return []
    else do
      line <- getLine; is <- readInstructions
      return $ parseInstruction line : is

fold :: [(Int, Int)] -> (Bool, Int) -> [(Int, Int)]
fold [] _ = []
fold (p@(_,x):ps) (i@(True, n)) | x < n = p : fold ps i
fold ((y,x):ps) (i@(True, n)) = (y,2*n-x) : fold ps i
fold (p@(y,_):ps) (i@(_, n)) | y < n = p : fold ps i
fold ((y,x):ps) (i@(_, n)) = (2*n-y,x) : fold ps i

foldAll :: [(Int, Int)] -> [(Bool, Int)] -> [(Int, Int)]
foldAll ps [] = ps
foldAll ps (i:is) = foldAll (nub $ fold ps i) is

printChars :: Int -> Int -> [(Int, Int)] -> IO ()
printChars _ _ [] = do putChar '\n'
printChars r c ps@((y,_):_) | r < y = do putChar '\n'; printChars (r + 1) 0 ps
printChars r c ps@((_,x):_) | c < x = do putChar ' '; printChars r (c + 1) ps
printChars r c (_:ps) = do putChar '#'; printChars r (c + 1) ps
                                
main = do
  ps <- readPoints; is <- readInstructions
  printChars 0 0 $ sort $ foldAll ps is
