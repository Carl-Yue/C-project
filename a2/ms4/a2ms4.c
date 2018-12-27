#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void printSectionHeader(const char*);

int main(void){
	
	ContactManagerSystem();

	return 0;
}

void printSectionHeader(const char* testName){
	printf("\n");
	printf("------------------------------------------");
	printf("Testing: %s\n",testName);
	printf("------------------------------------------");
}
