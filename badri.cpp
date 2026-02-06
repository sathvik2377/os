#include<stdio.h>
int main(){
	int i ,j,k,n,temp;
	int p[10], bt[10], wt[10], tat[10];
	float avgwt , avgtat;
	
	printf("enter no. of process:\t");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter process number:\t");
		scanf("%d", &p[i]);
		printf("enter burst time:\t");
		scanf("%d",&bt[i]);
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(bt[i]<bt[j]){
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				
				k=p[i];
				p[i]=p[j];
				p[j]=k;
			}
		}
	}
	
	avgwt = wt[0]=0;
	avgtat = tat[0]=bt[0];
	
	for(i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=wt[i]+bt[i];
		avgwt=avgwt+wt[i];
		avgtat=avgtat+tat[i];
	}
	printf("P_NO\t B_time\t W_time\t TAT\n");
	for(i=0;i<n;i++){
		printf("\n %d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
	}
	
	printf("\n Avg waiting time=%f\n",avgwt/n);
	printf("avg turnaroundtime=%f\n", avgtat/n);
}
