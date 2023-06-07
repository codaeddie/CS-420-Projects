module Main (main) where

import System.Random (randomRIO)
import Control.Monad (replicateM)
import Data.List (sort)
import System.CPUTime (getCPUTime)

quickSort :: (Ord a) => [a] -> [a]
quickSort [] = []
quickSort (h:t) =
    let smallArray = quickSort [a | a <- t, a <= h]
        largeArray = quickSort [a | a <- t, a > h]
    in  smallArray ++ [h] ++ largeArray

mergeSort :: (Ord a) => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = merge (mergeSort firstHalf) (mergeSort secondHalf)
  where
    (firstHalf, secondHalf) = splitAt (length xs `div` 2) xs

    merge :: (Ord a) => [a] -> [a] -> [a]
    merge xs [] = xs
    merge [] ys = ys
    merge (x:xs) (y:ys)
      | x <= y    = x : merge xs (y:ys)
      | otherwise = y : merge (x:xs) ys

generateRandomList :: Int -> IO [Int]
generateRandomList n = replicateM n (randomRIO (-100000, 100000))

timeAction :: IO a -> IO (a, Double)
timeAction action = do
    startTime <- getCPUTime
    result <- action
    endTime <- getCPUTime
    let duration = fromIntegral (endTime - startTime) / (10 ^ (12 :: Int))
    return (result, duration)

runAndPrint :: (Show a, Ord a) => String -> ([a] -> [a]) -> [a] -> IO ()
runAndPrint name sortFunction input = do
    time <- timeAction (return $ sortFunction input)
    putStrLn $ name ++ " took " ++ show (snd time) ++ " seconds."

main :: IO ()
main = do
    putStrLn "Generating test data..."
    testData <- generateRandomList 1000
    let sortedData = sort testData
    let reverseSortedData = reverse sortedData

    let testString = "the quick brown fox jumps over the lazy dog"
    let stringData = sort testString
    let sortedChars = sort stringData
    let sortedString = sort $ map (\c -> [c]) stringData

    putStrLn "\nRunning QuickSort..."
    runAndPrint "QuickSort on random data" quickSort testData
    runAndPrint "QuickSort on sorted data" quickSort sortedData
    runAndPrint "QuickSort on reverse sorted data" quickSort reverseSortedData
    runAndPrint "QuickSort on string data" quickSort stringData

    putStrLn "\nRunning MergeSort..."
    runAndPrint "MergeSort on random data" mergeSort testData
    runAndPrint "MergeSort on sorted data" mergeSort sortedData
    runAndPrint "MergeSort on reverse sorted data" mergeSort reverseSortedData
    runAndPrint "MergeSort on string data" mergeSort stringData

    putStrLn "\nUnsorted string data: the quick brown fox jumps over the lazy dog"
    putStrLn "\nSorted string data:"
    putStrLn $ concat sortedString