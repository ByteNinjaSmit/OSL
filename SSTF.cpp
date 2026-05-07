#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, head, total = 0, min, index;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n], done[n];
    printf("Enter requests:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
        done[i] = 0;
    }
    printf("Enter head position: ");
    scanf("%d", &head);
    for (i = 0; i < n; i++)
    {
        min = 9999;
        for (j = 0; j < n; j++)
        {
            if (!done[j] && abs(head - req[j]) < min)
            {
                min = abs(head - req[j]);
                index = j;
            }
        }
        done[index] = 1;
        total += min;
        head = req[index];
        printf(" -> %d", head);
    }
    printf("\nTotal Head Movement = %d\n", total);
    return 0;
}