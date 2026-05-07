#include <stdio.h>
int main() {
    int frames[10], pages[50], time[10];
    int n, f, i, j, k, pos, faults = 0, counter = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &f);
    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }
    for(i = 0; i < n; i++) {
        int found = 0;
        // Check if page is already in frames
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }
        // If not found → Page Fault
        if(!found) {
            if(i < f) {
                frames[i] = pages[i];
                counter++;
                time[i] = counter;
            } else {
                // Find least recently used page
                int min = time[0];
                pos = 0;
                for(j = 1; j < f; j++) {
                    if(time[j] < min) {
                        min = time[j];
                        pos = j;
                    }
                }
                frames[pos] = pages[i];
                counter++;
                time[pos] = counter;
            }
            faults++;
        }
    }
    printf("Total Page Faults (LRU) = %d\n", faults);
    return 0;
}