#include <stdio.h>

int main() 
{
    int n;
    scanf("%d",&n);
    int deck[1000];
    int size=0;
    for (int card=n;card>=1;card--) 
    {
        if(size>0) 
        {

            int last=deck[size-1];
            for (int i=size-1;i>0;i--)
                deck[i]=deck[i-1];
            deck[0]=last;
        }

    for (int i = size; i > 0; i--)
            deck[i] = deck[i - 1];  
        deck[0]=card;
        size++;
    }
    printf("[");
    for (int i=0;i<size;i++) 
    {
        printf("%d",deck[i]);
        if (i!=size-1)
            printf(", ");
    }
    printf("]");
    return 0;
}