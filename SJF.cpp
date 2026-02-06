#include <stdio.h>
int main()
{
int i,j,k,n,temp;
int p[10],bt[10],wt[10],tat[10];
float avgtat,avgwt;
printf("Enter no of processes: \t");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter process number :\t");
scanf("%d",&p[i]);
printf("Enter burst time \t");
scanf("%d",&bt[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<i;j++)
{
if(bt[i]<bt[j])
{
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
k=p[i];
p[i]=p[j];
p[j]=k;
}
}
}
avgwt=wt[0]=0;
avgtat=tat[0]=bt[0];
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tat[i]=wt[i]+bt[i];
avgwt=avgwt+wt[i];
avgtat=avgtat+tat[i];
}
printf("P_No\tB_time\tW_time\tTAT\n");
for(i=0;i<n;i++) {
	printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
}
printf("\nAvg waiting time=%f\n", avgwt/n);
printf("Avg TAT =%f\n", avgtat/n);
}


