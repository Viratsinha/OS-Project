#include<stdio.h>
#include<stdlib.h>
int Roundrobin();
int main()
{  // Tat= turnaroundtime 
	
 while(1){
	int entry;
  printf("\n Choose what you are : \n1.press 1 for Faculty \t2.press 2 for Student \t3.press 3 for Exit\n");
  scanf("%d",&entry);
  switch(entry){
  	case 1:
  		printf("\n\t\t For Faculty Queries: ");
  		Roundrobin();
  		break;
  	case 2:
  		printf("\n\t\t For Student Queries:");
  		Roundrobin();
  		break;
  	case 3:
  		printf("\nProgram has been terminated ");
  		exit(0);
		break;
  	default:
  		printf("\n You have pressed the Wrong key!!");
  		break;
  }
}
}
int Roundrobin(){
  	int x,n,time,remainingtime,flagbit=0,timequantum;
  	int waitingtime=0,TaT=0;
  	int arrivaltime[100],bursttime[100],runtime[100];
	printf("\nEnter Total Request:\t ");
  	scanf("%d",&n);
  	while(n<=0){
  		printf("Request cannot be less than 1 \nEnter again");
  		scanf("%d",&n);
	  }
  	remainingtime=n;
  	for(x=0;x<n;x++)
  	{
  		printf("\nRequest Number %d :",x+1);
    	printf("\nEnter Arrival Time and Burst Time of Request: \n");
    	scanf("%d",&arrivaltime[x]);
    	scanf("%d",&bursttime[x]);
    	runtime[x]=bursttime[x];
  	}
  	printf("\n Enter the time quantum : \t");
  	scanf("%d",&timequantum);
  	while(timequantum<=0){
  		printf("The Time Quantum can not be less than 1 \nTry again\n Please Enter the timequantum again");
  		scanf("%d",&timequantum);
	  }
  	printf("\n\nRequest\t|Turnaround Time|Waiting Time\n\n");
  	for(time=0,x=0;remainingtime!=0;)
  	{
    	if(runtime[x]<=timequantum && runtime[x]>0)
    	{
      	time+=runtime[x];
      	runtime[x]=0;
      	flagbit=1;
    	}
    	else if(runtime[x]>0)
    	{
      	runtime[x]-=timequantum;
      	time+=timequantum;
    	}
    	if(runtime[x]==0 && flagbit==1)
    	{
      	remainingtime--;
      	printf("P[%d]\t|\t%d\t|\t%d\n",x+1,time-arrivaltime[x],time-arrivaltime[x]-bursttime[x]);
      	waitingtime+=time-arrivaltime[x]-bursttime[x];
      	TaT+=time-arrivaltime[x];
      	flagbit=0;
    	}
    	if(x==n-1)
      	x=0;
    	else if(arrivaltime[x+1]<=time)
      	x++;
    	else
      	x=0;
  	}
  	printf("\nThe Average Waiting Time= %f\n",waitingtime*1.0/n);
  	printf("The Avg Turnaround Time = %f",TaT*1.0/n);
  	return 0;
}



