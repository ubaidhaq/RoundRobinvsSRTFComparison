#include<stdio.h>

int main()
{
    int waitingTime[100],burstTime[100],remaningTime[100];
    int turnAroundTime[100];
    int x=0;
    int quantum=0;
    int total=0;
    int rp = 10;
    int time=0;
	float sumTr=0,sumW=0;
    float avgTr,avgW;
	FILE *fptr;
    fptr=fopen("input(10).txt","r+");

   //Taking the processes from the file
   for(x=0;x<10;x++)
    {
        fscanf(fptr,"%d",&burstTime[x]);
		printf("\nP%d: %d",x+1,burstTime[x]);
        remaningTime[x]=burstTime[x];
        waitingTime[x]=0;
    }
	
	//Asking for the time quantum from the user 
    printf("\n\nEnter Quantum: ");
    scanf("%d",&quantum);

	x=0;
	
    printf("Process Execution Order | Remaining Time | Waiting Time\n");
    
	//Executing the loop untill all the processes are executed 
	while(rp!=0)
    {
        if(remaningTime[x]>quantum)
        {
        	//Calculating the remaining time for each process after the execution of the particular time quantum
            remaningTime[x]=remaningTime[x]-quantum;
            printf("P%d",x+1);
            printf("\t\t\t|\t%d",remaningTime[x]);
            
			//Calculating the waiting time 
            waitingTime[x]=time;
            time+=quantum;
            printf("\t  |\t%d\n",waitingTime[x]);

        }
        else if(remaningTime[x]<=quantum && remaningTime[x]>=0)
        {
            time+=remaningTime[x];
            remaningTime[x]=remaningTime[x]-remaningTime[x];
            printf("P%d",x+1);
            printf("\t\t\t|\t%d",remaningTime[x]);
            waitingTime[x]=time-quantum;
            printf("\t  |\t%d\n",waitingTime[x]);
            rp--;
		}

        x++;
        if(x==10)
        {
        	x=0;
        }
	}

    for(x=0;x<10;x++)
    {
        turnAroundTime[x]=burstTime[x]+waitingTime[x];
        sumTr+=turnAroundTime[x];//Calculating the sum of the turnaround time
        sumW+=waitingTime[x];//Calculating the sum of the waiting time
    }

	//Calculating the average of waiting time and turnaround time
    avgTr=sumTr/10;
	avgW=sumW/10;

    printf("\nAverage Turn Around Time: %.2f\n",avgTr);
    printf("\nAverage Waiting Around Time: %.2f\n",avgW);

    return 0;
}
