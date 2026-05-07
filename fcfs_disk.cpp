#include <stdio.h>
int main() {
    int n, i, head, total = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("\nGantt Chart:\n%d", head);
    for(i = 0; i < n; i++) {
        total += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }
    printf("\n\nTotal Head Movement = %d\n", total);
    return 0;
}