#include <stdio.h>

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count[2] = {0, 0};
    
    for (int i = 0; i < studentsSize; i++) {
        count[students[i]]++;
    }
    
    for (int i = 0; i < sandwichesSize; i++) {
        if (count[sandwiches[i]] == 0) {
            return sandwichesSize - i;
        }
        count[sandwiches[i]]--;
    }
    
    return 0;
}

int main() {
    int students1[] = {1, 1, 0, 0};
    int sandwiches1[] = {0, 1, 0, 1};
    int size1 = sizeof(students1) / sizeof(students1[0]);
    printf("Example 1 Output: %d\n", countStudents(students1, size1, sandwiches1, size1));

    int students2[] = {1, 1, 1, 0, 0, 1};
    int sandwiches2[] = {1, 0, 0, 0, 1, 1};
    int size2 = sizeof(students2) / sizeof(students2[0]);
    printf("Example 2 Output: %d\n", countStudents(students2, size2, sandwiches2, size2));

    return 0;
}