 
#include<stdio.h>
int main()
{
int process,resource,instance,j,i,k=0,count1=0,count2=0;
int avail[10] , max[10][10], allot[10][10],need[10][10],completed[10];
printf("Enter No. of Process: ");
scanf("%d",&process);
printf("Enter No. of Resources: ");
scanf("%d",&resource);
for(i=0;i<process;i++)
completed[i]=0;
printf("Enter No. of Available Instances: ");
for(i=0;i<resource;i++)
{
 scanf("%d",&instance);
 avail[i]=instance;
}
printf("Enter Maximum No. of instances of resources that a Process need:\n");
for(i=0;i<process;i++)
{
printf(" For P[%d]\t",i);
for(j=0;j<resource;j++)
{
 scanf("%d",&instance);
 max[i][j]=instance;
}
}
printf("Enter no. of instances already allocated to process of a resource:\n");
 for(i=0;i<process;i++)
 {
 printf(" For P[%d]\t",i);
 for(j=0;j<resource;j++)
{
 scanf("%d",&instance);
 allot[i][j]=instance;
 need[i][j]=max[i][j]-allot[i][j]; //calculating Need of each process
} }
 printf("\n Safe Sequence is:- \t");
 while(count1!=process)
 {
 count2=count1;
 for(i=0;i<process;i++)
         {
 for(j=0;j<resource;j++)
{
 if(need[i][j]<=avail[j])
 {
k++;
 }
}
if(k==resource && completed[i]==0 )
{
 printf("P[%d]\t",i);
 completed[i]=1;
 for(j=0;j<resource;j++)
 {
 avail[j]=avail[j]+allot[i][j];
 }
 count1++;
 }
k=0; }
if(count1==count2)
{
printf("\t Stop ..After this.....Deadlock \n");
break;

}
}
 return 0;
}

