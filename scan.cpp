#include <stdlib.h>
int main() {
    int n, i, head, total = 0, disk_size = 199;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter requests:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf("Enter head position: ");
    scanf("%d", &head);
    // Simple sorting
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
    // Move right
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            total += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }
    // Go to end
    total += abs(head - disk_size);
    head = disk_size;
    // Move left
    for(i = n-1; i >= 0; i--) {
        if(req[i] < head) {
            total += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }
    printf("\nTotal Head Movement = %d\n", total);
    return 0;
}