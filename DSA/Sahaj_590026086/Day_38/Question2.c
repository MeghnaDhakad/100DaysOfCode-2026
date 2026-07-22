#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter the number of elements you want to enter:");
    scanf("%d", &n);
    int result[n];
    int queue[n];
    int front=0, rear=-1;
    for (int i=0;i<n;i++){
        queue[++rear]=i;
    }
    for (int card=1;card<=n;card++){
        int idx=queue[front++];
        result[idx]=card;
        if (front<=rear){
            queue[++rear]=queue[front++];
        }
    }

    printf("[");
    for (int i=0;i<n;i++){
        printf("%d", result[i]);
        if (i<n-1)
            printf(", ");
    }
    printf("]\n");
    return 0;
}
