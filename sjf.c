#include<stdio.h>

int main()
{
    int burstTime[100],process[100],waitingTime[100],turnAroundTime[100],arrivalTime[100];
    int x,y,pos,temp;
    float sumTr=0,sumW=0;
    float avgTr,avgW;
    FILE *fptr;
    fptr=fopen("input(10).txt","r+");

	//Taking the process from the file 
    for(x=0;x<10;x++)
    {
        fscanf(fptr,"%d",&burstTime[x]);
		printf("\nP%d: %d",x+1,burstTime[x]);
        process[x]=x+1;
    }

	for(x=0;x<10;x++)
    {
        pos=x;
        for(y=x+1;y<10;y++)
        {
            if(burstTime[y]<burstTime[pos])
        	{
        		pos=y;
			}
        }

        temp=burstTime[x];
        burstTime[x]=burstTime[pos];
        burstTime[pos]=temp;

        temp=process[x];
        process[x]=process[pos];
        process[pos]=temp;
    }

    waitingTime[0]=0;

	//Calculating sum of the waiting time 
	for(x=1;x<10;x++)
    {
        waitingTime[x]=0;
        for(y=0;y<x;y++)
        {
        	waitingTime[x]+=burstTime[y];
		}    

        sumW+=waitingTime[x];
    }

    printf("\nProcess\t| Burst Time\t| Waiting Time\t| Turnaround Time");
    for(x=0;x<10;x++)
    {
    	//Calculating the sum of turnaround time 
        turnAroundTime[x]=burstTime[x]+waitingTime[x];
        sumTr+=turnAroundTime[x];
        printf("\n%d\t|\t%d\t|\t%d\t|\t%d",process[x],burstTime[x],waitingTime[x],turnAroundTime[x]);
    }
    
	//Calculating the averages 
    avgTr=sumTr/10;
	avgW=sumW/10;
	
	printf("\n\nAverage Turnaround Time=%.2f\n",avgTr);
    printf("\nAverage Waiting Time=%.2f\n",avgW);
}
