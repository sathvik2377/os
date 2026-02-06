 
#include <stdio.h>

int main() {
    int pages[50], frames[10], recent[10];
    int n, f, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (int i = 0; i < f; i++) {
        frames[i] = -1;
        recent[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                recent[j] = i;
                found = 1;
                break;
            }
        }

        if (!found) {
            int lru = 0;
            for (int j = 1; j < f; j++)
                if (recent[j] < recent[lru])
                    lru = j;

            frames[lru] = pages[i];
            recent[lru] = i;
            faults++;
        }
    }

    printf("Total Page Faults (LRU) = %d\n", faults);
    return 0;
}
