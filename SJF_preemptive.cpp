

#include <stdio.h>
#include <limits.h>

int main() {
    int n, t = 0, done = 0, i, min, finish;
    int at[10], bt[10], rt[10], wt[10], tat[10];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("AT & BT of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    rt[9] = INT_MAX;

    for(t = 0; done < n; t++) {
        min = 9;
        for(i = 0; i < n; i++)
            if(at[i] <= t && rt[i] < rt[min] && rt[i] > 0)
                min = i;

        rt[min]--;

        if(rt[min] == 0) {
            done++;
            finish = t + 1;
            tat[min] = finish - at[min];
            wt[min] = tat[min] - bt[min];
            awt += wt[min];
            atat += tat[min];
        }
    }

    printf("\nP\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\n", i+1, wt[i], tat[i]);

    printf("\nAvg WT = %.2f", awt/n);
    printf("\nAvg TAT = %.2f", atat/n);

    return 0;
}
