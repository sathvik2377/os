
#include <stdio.h>
#include <limits.h>

int main() {
    int n,i,t=0,done=0,smallest,finish;
    int p[10],at[10],bt[10],rt[10],pr[10],wt[10],tat[10];
    float avgwt=0,avgtat=0;

    printf("Enter no of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        printf("Enter process number: ");
        scanf("%d",&p[i]);
        printf("Enter arrival time: ");
        scanf("%d",&at[i]);
        printf("Enter burst time: ");
        scanf("%d",&bt[i]);
        printf("Enter priority: ");
        scanf("%d",&pr[i]);
        rt[i]=bt[i];
    }

    pr[9]=INT_MAX;   // sentinel

    for(t=0; done<n; t++) {
        smallest=9;
        for(i=0;i<n;i++)
            if(at[i]<=t && pr[i]<pr[smallest] && rt[i]>0)
                smallest=i;

        rt[smallest]--;

        if(rt[smallest]==0) {
            done++;
            finish=t+1;
            tat[smallest]=finish-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];
            avgwt+=wt[smallest];
            avgtat+=tat[smallest];
        }
    }

    printf("\nP_No\tB_Time\tW_Time\tTAT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);

    printf("\nAvg waiting time = %.2f", avgwt/n);
    printf("\nAvg TAT time = %.2f", avgtat/n);
}
