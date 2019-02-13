#include<stdio.h>
#include "gcd.c"    // Your gcd() function gets included in the main program
#define TEST_SIZE 4

int avec_task1[] = {2, 3, 115, 900};  // input test vector for self-testing
int bvec_task1[] = {12, 3, 15, 1000}; // input test vector for self-testing
int cvec_task1[] = {2, 3, 5, 100};    // output test vector for self-testing

int avec_task2[] = {2, 3, -115, -900};  // input test vector for self-testing
int bvec_task2[] = {12, -3, 15, -1000}; // input test vector for self-testing
int cvec_task2[] = {2, 3, 5, 100};    // output test vector for self-testing

int main( )
{
	int a, b, c;
	printf("Enter two positive integers a and b:");
	scanf("%d %d", &a, &b);
	c = gcd(a, b);	// your gcd() function gets called
 	printf("GCD of %d and %d is %d\n", a, b, c);

	/*
	// Enable this part of the code to perform self-testing for Task 1	
	int i;
	for(i=0; i<TEST_SIZE; i++){	
		c = gcd(avec_task1[i], bvec_task1[i]);
		if(c != cvec_task1[i]){
			printf("Task1: Test fails at i=%d\n", i);
			break;
		} else printf("Passed\n");
	}
	*/
	
	/*
	// Enable this part of the code to perform self-testing for Task 2	
	int i;
	for(i=0; i<TEST_SIZE; i++){	
		c = gcd(avec_task2[i], bvec_task2[i]);
		if(c != cvec_task2[i]){
			printf("Task2: Test fails at i=%d\n", i);
			break;
		} else printf("Passed2\n");
	}*/
	
	
	return 0;
}
