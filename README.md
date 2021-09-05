# sparse-matrix-addition

I have used the triplet representation of sparse matrix. It will have row, col and value.

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

The normal matrix addition of same dimension(200*200) took  *0.001687 seconds* to complete.

## Conclusions
we can see that the matrix with less number of sparsity value takes less amount of time to complete its execution. As the sparsity increases the execution time also increases. So it is good to use the triplet representation of matrix to do the addition when the sparsity value is less. As it takes less amount of time to complete its execution.
