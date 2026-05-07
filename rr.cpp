#include <stdio.h>
int main() {
    int n, i, time = 0, remain, tq;
    int bt[20], rt[20];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;
    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    for(time = 0, i = 0; remain != 0;) {
        if(rt[i] <= tq && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            printf("P%d finished at time %d\n", i+1, time);
            remain--;
        }
        else if(rt[i] > 0) {
            rt[i] -= tq;
            time += tq;
        }
        if(i == n-1)
            i = 0;
        else
            i++;
    }
    return 0;
}