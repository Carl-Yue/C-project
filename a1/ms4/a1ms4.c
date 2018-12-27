//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "contacts.h"

int main (void){

	printf("Contact Management System\n");
	printf("-------------------------\n");
	struct Contact cont;
	getName(&(cont.name));
	getAddress(&(cont.address));
	getNumbers(&(cont.numbers));
	printf("\n");
	printf("Contact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n",cont.name.firstName);
	printf("Middle initial(s): %s\n",cont.name.middleInitial);
	printf("Last name: %s\n",cont.name.lastName);
	printf("\n");
	printAddress(&(cont.address));
	printNumbers(&(cont.numbers));

	printf("Structure test for Contact using functions done!\n");
	return 0;

}
