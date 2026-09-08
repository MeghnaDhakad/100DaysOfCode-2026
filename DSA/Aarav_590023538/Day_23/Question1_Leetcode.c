#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort (Ascending Order)
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    // Sort both the greed factors and cookie sizes
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int child = 0;   // Pointer for children
    int cookie = 0;  // Pointer for cookies

    // Traverse both arrays using two pointers
    while (child < gSize && cookie < sSize)
    {
        // If the current cookie satisfies the current child
        if (s[cookie] >= g[child])
        {
            child++;   // Move to the next child
        }
        // Move to the next cookie
        cookie++;
    }

    // Number of satisfied children
    return child;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
