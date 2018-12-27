#include "contacts.h"

void clearKeyboard (void);
void pause (void);
int getInt (void);
int getIntInRange (int, int);
int yes (void);
int menu (void);
void ContactManagerSystem (void);
void getTenDigitPhone (char[]);
int findContactIndex(const struct Contact[], int, const char[]);
void displayContactHeader(void);
void displayContactFooter(int);
void displayContact(const struct Contact *);
void displayContacts(const struct Contact[], int);
void searchContacts(const struct Contact[], int);
void addContact(struct Contact[], int);
void updateContact(struct Contact[], int);
void deleteContact(struct Contact[], int);
void sortContacts(struct Contact[], int);
