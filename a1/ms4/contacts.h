/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 1
Milestone: 1
----------------------------------------------*/
//Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};
struct Numbers {
	char cell[21];
	char home[21];
	char business[21];
};
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};
void getName (struct Name *pname);
void getAddress (struct Address *paddr);
void getNumbers (struct Numbers *pnum);
void getContact (struct Contact *pcont);
void printAddress (struct Address *paddr);
void printNumbers (struct Numbers *pnum);
