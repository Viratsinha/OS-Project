
import java.util.Scanner;
import java.lang.*;
import java.lang.Math;

class JobDetails{
	char processName[]=new char[20];
	
	int processId;
	int arrivalTime;
	int burstTime;
char student[]= new char[100]; 
char faculty[]= new char[100];	
	

public static void main(String[]args)
{
	int total_query, map;
	System.out.println("Welcome, Mr. Sudhesh\n");
	System.out.println("Enter the total number of process to handle: ");
	Scanner s = new Scanner(System.in);
	total_query= s.nextInt();
	
	for(int i=0; i<total_query; i++){
		System.out.println("Query Type (1 for faculty and 2 for Student): ");
		Scanner s1 = new Scanner(System.in);
		map = s1.nextInt();
		if(map==1){

		}

	}
}	
}
