#include<stdio.h>

void instruct(){
	printf("\nWelcome, please follow these instruction for proper functioning of the program"
			"\n**>Enter time in 2400 hours format. example for 10:30 am enter 1030"
			"\n**>Enter Query arrival times in ascending order, i.e., in real time arrival manner\n"
			"\nAll Time units are in minutes. \n\n"
			);
}

 main(){
 	instruct();
	input();
	merger();
	roundRobin();
	printer();
}
