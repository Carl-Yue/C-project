#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "contacts.h"

void getName (struct Name *pname){

	char name_M[2];
	printf("Please enter the contact's first name: ");
	scanf("%30s",(*pname).firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("%1s",name_M);
	if(name_M[0]=='y'){
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s",(*pname).middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf("%35s",(*pname).lastName);
}

void getAddress (struct Address *paddr){

	char apartment_n[2];
	printf("Please enter the contact's street number: ");
	scanf("%d",&(*paddr).streetNumber);
	printf("Please enter the contact's street name: ");
	scanf("%40s",(*paddr).street);
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%1s",apartment_n);
	if(apartment_n[0] == 'y'){
		printf("Please enter the contact's apartment number: ");
		scanf("%d",&(*paddr).apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]",(*paddr).postalCode);
	printf("Please enter the contact's city: ");
	scanf("%40s",(*paddr).city);

}

void printAddress (struct Address *paddr){
	printf("Address Details\n");
	printf("Street number: %d\n",(*paddr).streetNumber);
	printf("Street name: %s\n",(*paddr).street);
	printf("Apartment: %d\n",(*paddr).apartmentNumber);
	printf("Postal code: %s\n",(*paddr).postalCode);
	printf("City: %s\n",(*paddr).city);
	printf("\n");
}

void getNumbers (struct Numbers *pnum){

	char cell_n[2];
	char home_n[2];
	char business_n[2];
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("%1s",cell_n);
	if(cell_n[0]=='Y'){
		printf("Please enter the contact's cell phone number: ");
		scanf("%20s",(*pnum).cell);
	}
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("%1s",home_n);
	if(home_n[0]=='Y'){
		printf("Please enter the contact's home phone number: ");
		scanf("%20s",(*pnum).home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("%1s",business_n);
	if(business_n[0]=='Y'){
		printf("Please enter the contact's business phone number: ");
		scanf("%20s",(*pnum).business);
	}
}

void printNumbers (struct Numbers *pnum){

	printf("Phone Numbers:\n");
	printf("Cell phone number: %s\n",(*pnum).cell);
	printf("Home phone number: %s\n",(*pnum).home);
	printf("Business phone number: %s\n",(*pnum).business);
	printf("\n");
}
