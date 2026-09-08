#include <stdio.h>
#include <stdlib.h>

// Function to transpose the matrix
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    // Number of rows in the transposed matrix
    *returnSize = *matrixColSize;
    // Allocate memory for column sizes of the transposed matrix
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    // Every row in the transposed matrix has 'matrixSize' columns
    for (int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = matrixSize;
    }
    // Allocate memory for the transposed matrix
    int **result = (int**)malloc((*returnSize) * sizeof(int*));
    for (int i = 0; i < *returnSize; i++)
    {
        result[i] = (int*)malloc(matrixSize * sizeof(int));
    }
    // Copy elements in transposed positions
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
    // Return the transposed matrix
    return result;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
