#include <stdio.h>
int main() {
    int n, i, j;
    int bt[20], wt[20], tat[20], p[20], pr[20];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst Time and Priority:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &bt[i], &pr[i]);
        p[i] = i + 1;
    }
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(pr[i] > pr[j]) {
                int temp;
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
    printf("\nProcess Priority BT WT TAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t %d %d %d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    }
    return 0;
}