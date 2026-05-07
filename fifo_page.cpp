#include <stdio.h>
int main() {
int frames[10], pages[30];
int n, f, i, j, k, pos, faults = 0;
printf("Enter number of pages: ");
scanf("%d", &n);
printf("Enter page reference string: ");
for(i = 0; i < n; i++)
scanf("%d", &pages[i]);
printf("Enter number of frames: ");
scanf("%d", &f);
for(i = 0; i < f; i++)
frames[i] = -1;
pos = 0;
for(i = 0; i < n; i++) {
int found = 0;
for(j = 0; j < f; j++) {
if(frames[j] == pages[i]) {
found = 1;
break;
}
}
if(!found) {
frames[pos] = pages[i];
pos = (pos + 1) % f;
faults++;
}
}
printf("Total Page Faults = %d", faults);
return 0;
}