#include<stdio.h>
#include<stdlib.h>
struct job{
	int processId;
	int ArrivalTime;
	int BurstTime;
	int CompletionTime;
	int rbt;
}Faculty[100],Student[100],minutes[100];

int n, fc=0, sc=0, mc=0;
int Timequantum;

void roundRobinscheduling(){
	int time= minutes[0].ArrivalTime, mark=0, cc=0, i, rc;
	while(time!=120 && cc!=mc){
		for(i=0; i<=mark; i++){
			if(minutes[i].rbt > Timequantum){
				time += Timequantum;
				minutes[i].rbt -= Timequantum;
			}
			else if(minutes[i].rbt <=Timequantum && minutes[i].rbt !=0){
				time += minutes[i].rbt;
				minutes[i].rbt =0;
				minutes[i].CompletionTime = time;
				cc++;
			}
			else;
		}
		int start = mark+1;
		for(rc= start; rc<mc; rc++){
			if(minutes[rc].ArrivalTime <= time){
				mark++;
			}
		}
	}	
}
// fc = facultycount
// sc = studentcount
// ifc = number of facult count
// isc = number of student count 
// mc = minutescount
void mergingfunction(){
	int isc=0, ifc= 0, min, flag;
	if( fc!=0  && sc!=0){
		while(isc<sc && ifc<fc){
			if(Faculty[ifc].ArrivalTime == Student[isc].ArrivalTime){
				minutes[mc] = Faculty[ifc];
				mc++;
				ifc++;
				minutes[mc]= Student[isc];
				mc++;
				isc++;
			}
			else if(Faculty[ifc].ArrivalTime < Student[isc].ArrivalTime){
				minutes[mc]= Faculty[ifc];
				mc++;
				ifc++;
			}
			else if(Faculty[ifc].ArrivalTime > Student[isc].ArrivalTime){
				minutes[mc]= Student[isc];
				mc++;
				isc++;
			}
			else;
		}
		if(mc != (fc+sc)){
			if(fc!=ifc){
				while(ifc!=fc){
					minutes[mc]= Faculty[ifc];
					mc++;
					ifc++;
				}
			}
			else if(sc!=isc){
				while(isc!=sc){
					minutes[mc]= Student[isc];
					mc++;
					isc++;
				}
			}
		}
	}
	else if(fc==0){
		while(isc!=sc){
			minutes[mc]= Student[isc];
			mc++;
			isc++;
		}
	}
	else if(sc==0){
		while(ifc!=fc){
			minutes[mc]= Faculty[ifc];
			mc++;
			ifc++;
		}
	}
	else {
		printf("\n There are no valid Jobs available\n");
	}
}

void Display(){
	int i=0, total=0, sum=0; 
	double average;
	printf("\nSummary for the Execution\n");
	printf("\nQuery ID\tArrival Time\tRessolving Time\tCompletion Time\tTurn Around Time\tWaiting Time");
	for(i; i<mc; i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",
		minutes[i].processId, (minutes[i].ArrivalTime+1000), minutes[i].BurstTime, (minutes[i].CompletionTime+1000), (minutes[i].CompletionTime-minutes[i].ArrivalTime), ((minutes[i].CompletionTime-minutes[i].ArrivalTime)- minutes[i].BurstTime));
		total= minutes[i].CompletionTime;
		sum+= (minutes[i].CompletionTime-minutes[i].ArrivalTime);
	}
	average = sum/mc;
	printf("\n\nTotal time Spent for all queries: %d", total);
	printf("\nAverage query time: %lf", average);
	printf("\nProcess Execution Complete");
}

void inputs(){
	int jobType,  i, t;
	printf("Enter total no of queries: "); scanf("%d", &n);
	if(n==0) { printf("\n No queries\n"); }
	else{
		printf("\nEnter Timequantum for each Process: "); scanf("%d", &Timequantum);
		printf("\nEnter 1 for faculty and 2 for student\n");
		for(i=0; i<n; i++){
			printf("\nJob Type (1/2): \n press 1 for Faculty: \n press 2 for student : \n"); scanf("%d", &jobType);
			if(jobType==1){
				printf("Query Id: "); scanf("%d", &Faculty[fc].processId);
				printf("Arrival Time: "); scanf("%d", &t);
				if(t<1000 || t>1200){
					printf("\nEnter Correct time");
					inputs();
				}
				else{Faculty[fc].ArrivalTime= t-1000;}
				printf("Resolving Time: "); scanf("%d", &Faculty[fc].BurstTime);	 Faculty[fc].rbt= Faculty[fc].BurstTime; 
				fc++;
			} else{
				printf("Query Id: "); scanf("%d", &Student[sc].processId);
				printf("Arrival Time: "); scanf("%d", &t); 
				if(t<1000 || t>1200){
					printf("\nEnter Correct time \n");
					inputs();
				}
				else {Student[sc].ArrivalTime= t-1000; }
				printf("Resolving Time: "); scanf("%d", &Student[sc].BurstTime);	 Student[sc].rbt= Student[sc].BurstTime;
				sc++;
			}
		}
	}
}

void instruction(){
	printf("\n Hello this is Sudhesh Sharma!! \n please follow these instruction for proper functioning of the program"
			"\n**>Enter the time in 2400 hours format. example for 10:10 am enter 1010"
			"\n**>Enter the Query arrival times in ascending order that is in real time arrival manner"
			"\nAll Time units used here are in minutes. \n\n"
			);
}

 main(){
 	instruction();
	inputs();
	mergingfunction();
	roundRobinscheduling();
	Display();
}
