 
#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (int i = 0; i < f; i++)
        frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int index = -1, farthest = i + 1;

            for (int j = 0; j < f; j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frames[j] == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            index = j;
                        }
                        break;
                    }
                }
                if (k == n) {
                    index = j;
                    break;
                }
            }

            if (index == -1)
                index = 0;

            frames[index] = pages[i];
            faults++;
        }
    }

    printf("Total Page Faults (Optimal) = %d\n", faults);
    return 0;
}
