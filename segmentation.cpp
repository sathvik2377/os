 
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int b[20],l[20],n,i,pa,s,a,d;
printf("\nProgram for segmentation");
printf("\nEnter the number of segments:");
scanf("%d",&n);
printf("\nEnter the base address and limit register:");
for(i=1;i<=n;i++)
{
scanf("%d",&b[i]);
scanf("%d",&l[i]);
}
printf("\nEnter the logical address:");
scanf("%d",&d);
printf("\nEnter segment number:");
scanf("%d",&s);
for(i=1;i<=n;i++)
{
if(i==s)
{
if(d<l[i])
{
pa=b[i]+d;
a=b[i];
printf("\nPageNo.\t BaseAdd. PhysicalAdd. \n %d \t %d \t %d\n",s,a,pa);
exit(0);
}
else
{
printf("\nPage size exceeds");
exit(0);
}
}
}
printf("\nInvalid segment");
return 0;
}

