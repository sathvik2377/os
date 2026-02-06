 
#include <stdio.h>
#include <stdlib.h>
int main()
{
int p[10],st[10],bt[10],wt[10],tat[10],n,tq;
int i,count=0,temp,sq=0;
float avgwt=0.0,avgtat=0.0;
printf("Enter number of processes:  ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter process number:\t");
scanf("%d",&p[i]);
printf("Enter burst time:\t");
scanf("%d",&bt[i]);
st[i]=bt[i];
}
printf("Enter time quantum:");
scanf("%d",&tq);
while(1)
{
for(i=0,count=0;i<n;i++)
{
temp=tq;
if(st[i]==0)
{
count++;
continue;
}
if(st[i]>tq)
st[i]=st[i]-tq;
else
if(st[i]>=0)
{
temp=st[i];
st[i]=0;
}
sq=sq+temp;
tat[i]=sq;
}
if(n==count)
break;
}
for(i=0;i<n;i++)
{
wt[i]=tat[i]-bt[i];
avgwt=avgwt+wt[i];
avgtat=avgtat+tat[i];
}
printf("P_NO\t B_Time\t W_Time\t TAT\n");
for(i=0;i<n;i++)
printf("%d\t %d\t %d\t %d\t\n",i+1,bt[i],wt[i],tat[i]);
printf("Avg waiting time is %f\n Avg TAT is %f\n",avgwt/n,avgtat/n);
}

