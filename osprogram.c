#include<stdio.h>
#include<stdlib.h>

int main()
{
 
 while(1){
	int details;
  printf("\n Choose what you are : \n1.press 1 for Faculty \t2.press 2 for Student \t3.press 3 for Exit\n");
  scanf("%d",&details);
  switch(details){
  	case 1:
  		printf("\n\t\t For Faculty Queries: ");
  		
  		break;
  	case 2:
  		printf("\n\t\t For Student Queries:");
  		
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


