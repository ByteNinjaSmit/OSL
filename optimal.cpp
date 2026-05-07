#include <stdio.h>
int main() {
    int frames[10], pages[50];
    int n, f, i, j, k, pos, faults = 0;
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
    }
    for(i = 0; i < n; i++) {
        int found = 0;
        // Check if page is already in frames
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        // If not found → Page Fault
        if(!found) {
            if(i < f) {
                frames[i] = pages[i];
            } else {
                int farthest = -1;
                pos = -1;
                // Find page with farthest future use
                for(j = 0; j < f; j++) {
                    int found_future = 0;
                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {
                            if(k > farthest) {
                                farthest = k;
                                pos = j;
                            }
                            found_future = 1;
                            break;
                        }
                    }
                    // If page not found in future
                    if(!found_future) {
                        pos = j;
                        break;
                    }
                }
                frames[pos] = pages[i];
            }
            faults++;
        }
    }
    printf("Total Page Faults (Optimal) = %d\n", faults);
    return 0;
}