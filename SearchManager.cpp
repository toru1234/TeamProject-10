/*
John Dwyer
CIS 22C
Team 10 Project
2015-05-30
*/

#include "SearchManager.h"

void searchManager()
{
	char choice;
	bool quit = false;

	do {
		cout << "Please input the letter corresponding to the function you'd like to use from the list below.\n" << endl;
		cout << "A - Add New Website\n"
			 << "D - Delete Website\n"
			 << "S - Search for Website(s)\n"
			 << "L - List Websites\n" 
			 << "Q - Quit\n"<< endl;
		cin >> choice; 
		choice = toupper(choice);
		cout << endl;

		switch (choice)
		{
			case 'A': // add
				break;
			case 'D': // delete
				break;
			case 'S': // search
				caseSearch();
				break;
			case 'L': // list
				caseList();
				break;
			case 'Q': // quit
				quit = true;
				break;
			default: 
				cout << "Invalid input. ";
		}
	} while (!quit);
}

void caseSearch()
{
	char subChoice;
	bool invalid;

	do {
		invalid = false;
		cout << "Please select a search type from the options below.\n" << endl
			 << "N - Display website data for given domain name\n"
			 << "C - Display websites by country\n" 
			 << "R - Return to previous menu\n" << endl;
		cin >> subChoice;
		subChoice = toupper(subChoice);
		cout << endl;

		switch (subChoice)
		{
			case 'N': // domain name
				break;
			case 'C': // by country
				break;
			case 'R': // previous
				break;
			default:
				invalid = true;
				cout << endl << "Invalid input. ";
				break;
		}
	} while (invalid);
}

void caseList()
{
	int subChoice;
	bool invalid;

	do {
		invalid = false;
		cout << "Please select how to display the website data from the options below.\n" << endl;
		cout << "U - display unsorted\n"
			<< "P - display by domain name\n"
			<< "O - display by countries\n"
			<< "I - display special\n" 
			<< "R - Return to previous menu\n" << endl;
		cin >> subChoice;
		subChoice = toupper(subChoice);
		cout << endl;

		switch (subChoice)
		{
			case 'U': // unsorted
				break;
			case 'P': // alphabetical
				break;
			case 'O': // countries
				break;
			case 'I': // special
				break;
			case 'R': // previous
				return;
			default: 
				invalid = true;
				cout << "Invalid input. ";
				break;
		}
	} while (invalid);
}