# sparse-matrix-addition

I have used the triplet representation of sparse matrix. It will have row, col and value.
In our code the sparsity value represents the total number of non zero elements.
If sparsity value is 0.1 and total matrix size is 10, then 0.1 *10 = 1. There will be 1 non zero elements present in the matrix.


## Sparse Matrix Addition Result
The table given below shows the run time required to add two matrix of dimension 200*200 with different sparsity value.

| Sparsity Value(sp)|Runtime(seconds)|
------------------------|-----------------| 
0.1 | 0.00047 |  
0.2 | 0.00095 |  
0.3 | 0.001555 |  
0.4 | 0.002 |  
0.5 | 0.002589 |  
0.6 | 0.002999 |  
0.7 | 0.003481 |  
0.8 | 0.003996 |  
0.9 | 0.004717 |   

The normal matrix addition of same dimension(200*200) took  **0.001687 seconds** to complete.

## Conclusions
we can see that the matrix with less number of sparsity value takes less amount of time to complete its execution. As the sparsity increases the execution time also increases. So it is good to use the triplet representation of matrix to do the addition when the sparsity value is less and matrix size is big. As it takes less amount of time to complete its execution.

It is not a good idea to use the triplet representation of martix to do addition when the sparsity value is high or matrix size is less. As it might take more time to complete its execution as compared to normal/usual way of martix addition.

## Drawbacks of the Above Code
* When we use builtin rand() functions, there are chances to overlap the rows and columns values. So I have use custom method to check. It makes the code slow to generate the random matrix.
* Improvements can be done on the logic/algorithm.


