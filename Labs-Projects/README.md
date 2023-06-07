# Lab5-haskell
Implement QuickSort and MergeSort algorithms using Haskell and your favorite second programming language. Run your programs on a random input of 1,000 numbers to ensure they sort correctly. Next, run each program on two input sequences: 1, 2, 3, ..., 1,000,000 in sorted order, and 1,000,000; 999,999; ...; 1 in reverse sorted order. Incorporate timing mechanisms into your code to time the sortings. If 1,000,000 isn’t large enough to see any differences, expand the sorting range.

Evaluate your results:
Which program was faster on the sorted input? 
Was it also faster on the input that was presented in reverse sorted order?
Code readability:
Clarity, organization, comments and documentation.
Modularity:
Use of functions or modules that perform specific tasks and can be easily reused or modified.
Maintainability:
Ease of modification and ability to handle changing requirements or edge cases.
Explain your results:
Were the results as expected? 
Summarize the languages used for sorting, what are the differences and similarities.
What would be your choice if the task of implementing Merge Sort will be given again with any language of your choice?



Quick sort inside of Haskell:

Your implementation of both QuickSort and MergeSort in Haskell is indeed efficient and makes good use of list comprehensions. In the QuickSort implementation, list comprehensions are used to create the smallArray and largeArray partitions, which is a concise and expressive way to handle the partitioning step.

However, there are alternative implementations of QuickSort that can further optimize performance by minimizing the number of list concatenations or using other partitioning strategies. The current implementation has a worst-case time complexity of O(n^2) in cases where the input is already sorted or reverse sorted. A different partitioning strategy, such as choosing a random pivot or the median of three, can help improve the worst-case performance.

For the MergeSort implementation, your use of list comprehensions is limited, but that's expected since the algorithm relies on merging sorted sublists. The implementation is efficient and takes advantage of Haskell's lazy evaluation and pattern matching.

Overall, both implementations are well-written and make good use of Haskell's features. While there may be room for optimization, especially for the QuickSort algorithm, your current implementation meets the assignment requirements and should perform well on the provided input data.

