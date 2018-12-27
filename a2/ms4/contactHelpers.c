#include <stdio.h>

#include <string.h>

#include "contactHelpers.h"

#define MAXCONTACTS 5

void clearKeyboard (void){
	while (getchar() !='\n');
}

void pause (void){
	//clearKeyboard();
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

int getInt (void){
	char NL='x';
	int Value = 0;

	do{//while(NL !='\n'){
		scanf(" %d%c",&Value,&NL);
		if(NL !='\n'){
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
		
		
	}while(NL != '\n');
	return Value;
}

int getIntInRange(int param1, int param2){
	
	int tstValue;
	do{
		tstValue=getInt();
		if(tstValue>param2||tstValue<param1){
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ",param1,param2);
		}
	}while(tstValue>param2||tstValue<param1);
	return tstValue;
}

int yes (void){
	char NL='x';
	char Yes;
	int theReturn;
	
	do{
	//while(NL !='\n'||(Yes!='Y' && Yes!='y' && Yes!='N' && Yes!='n')){
		scanf(" %c%c",&Yes,&NL);
		if(NL !='\n' || (Yes!='Y' && Yes!='y' && Yes!='N' && Yes!='n')){
			if(NL !='\n'){
				printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
				clearKeyboard();
			}
		}
	}while(NL !='\n' || (Yes!='Y' && Yes!='y' && Yes!='N' && Yes!='n'));
	
	if(Yes=='Y'||Yes=='y'){
		theReturn =  1;
	}else{
		theReturn =  0;
	}
	return theReturn;
}

int menu (void){

	int option;
		printf("Contact Management System\n");
		printf("-------------------------\n");
		printf("1. Display contacts\n");
		printf("2. Add a contact\n");
		printf("3. Update a contact\n");
		printf("4. Delete a contact\n");
		printf("5. Search contacts by cell phone number\n");
		printf("6. Sort contacts by cell phone number\n");
		printf("0. Exit\n");
		printf("\n");
		printf("Select an option:> ");
		option=getIntInRange(0,6);
	return option;
}

void ContactManagerSystem (void){
	int option;
	int exit=0;
	int size;
	struct Contact contacts[]=
	{{{"Rick",{'\0'},"Grimes"},
	  {11,"Trailer Park",0,"A7A 2J2","King City"},
	  {"4161112222","4162223333","4163334444"}},
	 {
	  {"Maggie","R.","Greene"},
	  {55, "Hightop House",0,"A9A 3K3", "Bolton"},
	  {"9051112222","9052223333","9053334444"}},
	 {
	  {"Morgan","A.","Jones"},
	  {77,"Cottage Lane",0,"C7C 9Q9","Peterborough"},
	  {"7051112222","7052223333","7053334444"}},
	 {
	  {"Sasha",{'\0'},"Williams"},
	  {55, "Hightop House",0,"A9A 3K3","Bolton"},
	  {"9052223333","9052223333","9054445555"}},
	 {
	  {{'\0'},{'\0'},{'\0'}},
	  {0,{'\0'},0,{'\0'},{'\0'}},
	  {{'\0'},{'\0'},{'\0'}}},
	};
	
	size=MAXCONTACTS;
	do{
		option=menu();
		switch (option){
			case 0:
				printf("\n");
				printf("Exit the program? (Y)es/(N)o: ");
				exit=yes();
				printf("\n");
				break;
			case 1:
				printf("\n");
				//printf("<<< Feature 1 is unavailable >>>\n");
				displayContacts(contacts,size);
				printf("\n");
				pause();
				printf("\n");
				//menu();
				break;
			case 2:
				printf("\n");
				//printf("<<< Feature 2 is unavailable >>>\n");
				addContact(contacts,size);
				printf("\n");
				pause();
				printf("\n");
				//menu();
				break;
			case 3:
				printf("\n");
				//printf("<<< Feature 3 is unavailable >>>\n");
				updateContact(contacts,size);
				pause();
				printf("\n");
				//menu();
				break;
			case 4:
				printf("\n");
				//printf("<<< Feature 4 is unavailable >>>\n");
				deleteContact(contacts,size);
				pause();
				printf("\n");
				//menu();
				break;
			case 5:
				printf("\n");
				//printf("<<< Feature 5 is unavailable >>>\n");
				searchContacts(contacts,size);
				pause();
				printf("\n");
				//menu();
				break;
			default:
				printf("\n");
				//printf("<<< Feature 6 is unavailable >>>\n");
				sortContacts(contacts,size);
				pause();
				printf("\n");
				//menu();
		}
	}while(option!=0 || exit==0);
	if(exit==1){
		printf("Contact Management System: terminated");
		printf("\n");
	}
}

void getTenDigitPhone(char telNum[]){
	int needInput=1;
	int length;

	while (needInput==1){
		scanf(" %20s",telNum);
		clearKeyboard();

		length=strlen(telNum);
		if (length==10){
			needInput=0;
		}else{
			printf("Enter a 10-digit phone number: ");
		}
	}
	return;
}

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]){
	int i;
	int result=-1;

	for(i=0;i<size;i++){
		if(strcmp(contacts[i].numbers.cell,cellNum)==0){
			result=i;
		}
	}
	return result;
}

void displayContactHeader(void){
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
	return;

}

void displayContactFooter(int size){

	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n",size);
	return;

}

void displayContact(const struct Contact *pcon){
	int length;

	length=strlen((*pcon).name.middleInitial);
	if(length>0){
		printf(" %s %s %s\n",(*pcon).name.firstName,(*pcon).name.middleInitial,(*pcon).name.lastName);
	}else{
		printf(" %s %s\n",(*pcon).name.firstName,(*pcon).name.lastName);
	}
	printf("    C: %-10s   H: %-10s   B: %-10s\n",(*pcon).numbers.cell,(*pcon).numbers.home,(*pcon).numbers.business);
	printf("       %d %s, ",(*pcon).address.streetNumber,(*pcon).address.street);
	if((*pcon).address.apartmentNumber>0){
		printf("Apt# %d, ",(*pcon).address.apartmentNumber);
	}
	printf("%s, %s\n", (*pcon).address.city,(*pcon).address.postalCode);
	return;
}

void displayContacts (const struct Contact contacts[], int size){
	int count=0;
	int i;

	displayContactHeader();
	for(i=0;i<size;i++){
		if(strlen(contacts[i].numbers.cell)>0){
			displayContact(&contacts[i]);
			count++;
		}
	}
	displayContactFooter(count);
	return;
}

void searchContacts (const struct Contact contacts[], int size){
	int result;
	char telNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);
	printf("\n");
	result=findContactIndex(contacts,size,telNum);
	if(result!=-1){
		displayContact(&contacts[result]);
	}else{
		printf("*** Contact NOT FOUND ***");
	}
	printf("\n");
	return;

}

void addContact(struct Contact contacts[], int size){
	int count=0;
	int i;
	
	for(i=0;i<size;i++){
		if(strlen(contacts[i].numbers.cell)==0){
			getContact(&contacts[i]);
			count++;
			printf("--- New contact added! ---");
		}
	}
	if(count==0){
		printf("*** ERROR: The contact list is full! ***");
	}
	return;
}

void updateContact(struct Contact contacts[], int size){
	int result;
	char telNum[20];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);
	result=findContactIndex(contacts,size,telNum);
	if(result==-1){
		printf("*** Contact NOT FOUND ***\n");
	}else{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contacts[result]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		if(yes()==1){
			getName(&contacts[result].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if(yes()==1){
			getAddress(&contacts[result].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		if(yes()==1){
			getNumbers(&contacts[result].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}
	return;
}

void deleteContact(struct Contact contacts[], int size){
	char telNum[20];
	int result;
	//int i;
	//int length;
	
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);
	result=findContactIndex(contacts,size,telNum);
	if(result==-1){
		printf("*** Contact NOT FOUND ***\n");
	}else{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contacts[result]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		if(yes()==1){
			//length=strlen(contacts[result].numbers.cell);
			//for(i=0;i<length;i++){
				//contacts[result].numbers.cell[i]='\0';
			//}
			contacts[result].numbers.cell[0]='\0';
			printf("--- Contact deleted! ---\n");
		}
	}
	return;
}

void sortContacts(struct Contact contacts[], int size){
	int i,j;
	char temp_cell[20];
	char temp_home[20];
	char temp_busi[20];
	char temp_fNam[31];
	char temp_mIni[7];
	char temp_lNam[36];
	int temp_sNum;
	char temp_stre[41];
	int temp_apar;
	char temp_post[8];
	char temp_city[41];


	for(i=size-1;i>0;i--){
		for(j=0;j<i;j++){
			if(strcmp(contacts[j].numbers.cell,contacts[j+1].numbers.cell)>0){
				strcpy(temp_cell, contacts[j].numbers.cell);
				strcpy(temp_home, contacts[j].numbers.home);
				strcpy(temp_busi, contacts[j].numbers.business);
				strcpy(temp_fNam, contacts[j].name.firstName);
				strcpy(temp_mIni, contacts[j].name.middleInitial);
				strcpy(temp_lNam, contacts[j].name.lastName);
				temp_sNum=contacts[j].address.streetNumber;
				strcpy(temp_stre, contacts[j].address.street);
				temp_apar=contacts[j].address.apartmentNumber;
				strcpy(temp_post, contacts[j].address.postalCode);
				strcpy(temp_city, contacts[j].address.city);
				strcpy(contacts[j].numbers.cell,contacts[j+1].numbers.cell);
				strcpy(contacts[j].numbers.home,contacts[j+1].numbers.home);
				strcpy(contacts[j].numbers.business,contacts[j+1].numbers.business);
				strcpy(contacts[j].name.firstName,contacts[j+1].name.firstName);
				strcpy(contacts[j].name.middleInitial,contacts[j+1].name.middleInitial);
				strcpy(contacts[j].name.lastName,contacts[j+1].name.lastName);
				contacts[j].address.streetNumber=contacts[j+1].address.streetNumber;
				strcpy(contacts[j].address.street,contacts[j+1].address.street);
				contacts[j].address.apartmentNumber=contacts[j+1].address.apartmentNumber;
				strcpy(contacts[j].address.postalCode,contacts[j+1].address.postalCode);
				strcpy(contacts[j].address.city,contacts[j+1].address.city);
				strcpy(contacts[j+1].numbers.cell, temp_cell);
				strcpy(contacts[j+1].numbers.home, temp_home);
				strcpy(contacts[j+1].numbers.business, temp_busi);
				strcpy(contacts[j+1].name.firstName, temp_fNam);
				strcpy(contacts[j+1].name.middleInitial, temp_mIni);
				strcpy(contacts[j+1].name.lastName, temp_lNam);
				contacts[j+1].address.streetNumber=temp_sNum;
				strcpy(contacts[j+1].address.street, temp_stre);
				contacts[j+1].address.apartmentNumber=temp_apar;
				strcpy(contacts[j+1].address.postalCode, temp_post);
				strcpy(contacts[j+1].address.city, temp_city);
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
	return;
}
