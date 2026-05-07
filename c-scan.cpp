#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i, head, total = 0, disk_size = 199;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    // Sorting requests
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
        }
            }
    }
    printf("\nGantt Chart:\n%d", head);
    // Move right side
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            total += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }
    // Go to end of disk
    total += abs(head - disk_size);
    head = disk_size;
    // Jump to start (0)
    total += disk_size;
    head = 0;
    // Move again from start
    for(i = 0; i < n; i++) {
        if(req[i] < disk_size) {
            total += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }
    printf("\nTotal Head Movement = %d\n", total);
    return 0;
}