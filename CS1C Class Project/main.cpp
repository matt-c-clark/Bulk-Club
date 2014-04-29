/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#include "member.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <limits>
#include "RuntimeException.h"
using namespace std;

#define INTERFACE 1


int validInt(int, int);
int getReportType(const vector<const char*> &);

const int maxWidth = 80;
enum  {PURCHASE_BY_DAY = 1, PURCHASE_BY_ITEM, PURCHASE_BY_MEMBER,
		TOTAL_SALES, QUANTATIES, REBATES, DUES_PAID,
		MEMBERSHIP_EXPIRTATIONS, UPGRADES, DOWNGRADES, MODIFY_MEMBERS,
		EXIT};

int main()
{
    member m;

    cout << m.toString() << "\n";

    string name = "Matt";

    date d(1, 21, 2001);

    member m1(name, 11111, true, d, 1000, 100);

    cout << m1.toString() << "\n";
    
#if INTERFACE
	int menuChoice;
	int filterType;
	
    vector<const char*> menuOptions;

    menuOptions.push_back("View Purchases for given day");
    menuOptions.push_back("View Purchases for given item");
    menuOptions.push_back("View Purchases for given member");
    menuOptions.push_back("View Total Sales");
    menuOptions.push_back("View Quantity of Items Sold");
    menuOptions.push_back("View Member Rebate Report");
    menuOptions.push_back("View Membership Dues Paid");
    menuOptions.push_back("View Membership Expirations");
    menuOptions.push_back("Check for Membership Upgrades");
    menuOptions.push_back("Check for Membership Downgrades");
    menuOptions.push_back("Add/Delete/Edit Members");
    menuOptions.push_back("Exit");

	vector<const char*> reportType;

    reportType.push_back("Basic Members Only");
    reportType.push_back("Preferred Members Only");
    reportType.push_back("All members");

    vector<const char*> modifyType;

    modifyType.push_back("Add");
    modifyType.push_back("Delete");
    modifyType.push_back("Modify");
    modifyType.push_back("Exit");

	bool exit = false;

	//output welcome statement
	cout << setfill('*')  << setw(maxWidth) <<"*" << endl
	     << setw(maxWidth/3) << "| " << setw(2) << setfill(' ') <<""
		 << "BULK CLUB MANAGER SUITE "
		 << setw(2) << setfill(' ') <<""
		 << left <<setfill('*')
		 << setw(maxWidth/3)<< " |" << endl
		 <<setfill('*')  << setw(maxWidth) <<"*" << endl << endl;

	cout << "Welcome to the Bulk Club Manager Suite. " << endl;
	cout << "What would you like to do?" << endl;

	do
	{
		// OUTPUT - Display menu options stored in menuOptions and prompt
	    //          for input
		for (unsigned int i = 0; i < menuOptions.size(); i++)
		{
            cout << i + 1 << ". "<< menuOptions.at(i) << endl;
		}

		cout << "\nPlease enter your choice: ";

		// INPUT/OUTPUT - Call validInt function to accept valid input
		//		          Returns into menuChoice integer variable

		menuChoice = validInt(1, menuOptions.size());

		cout <<  endl << menuOptions[menuChoice-1] << endl << endl;

		if (menuChoice != PURCHASE_BY_MEMBER && menuChoice != REBATES &&
				menuChoice != UPGRADES && menuChoice != DOWNGRADES
				&& menuChoice !=EXIT )
		{
            cout << reportType[(filterType = getReportType(reportType) - 1)]
                 << endl << endl;
		}

		switch(menuChoice)
		{
			case PURCHASE_BY_DAY:
				cout << "Please choose day to view sales report for";
				break;
			case PURCHASE_BY_ITEM:
				cout << "Enter Item Name: ";
				break;
			case PURCHASE_BY_MEMBER:
				cout << "Search by Member Name or Number?";
				cout << "1. Member Name" << endl;
				cout << "2. Member Number" << endl;
				cout << "3. Exit" << endl;
				break;
			case TOTAL_SALES:
				cout << "Printing total sales";
				break;
			case QUANTATIES:
				cout << "Printing quantities of items sold ";
				break;
			case REBATES:
				cout << "Printing rebate information for Preferred"
				        "Members ";
				break;
			case DUES_PAID:
				cout << "Printing membership dues  ";
				break;
			case MEMBERSHIP_EXPIRTATIONS:
				cout << "Enter month to check for membership expirations";
				break;
			case UPGRADES:
				cout << "Checking for members that would benefit from an"
				        "upgrade";
				break;
			case DOWNGRADES:
				cout << "Checking for members that would benefit from an"
				        "upgrade";
				break;
			case MODIFY_MEMBERS:  // Handle logic
				cout << "What would you like to do?" << endl;
				for (unsigned int i = 0; i < modifyType.size(); i++)
				{
                    cout << i+1 << ". "<< modifyType.at(i) << endl;
				}

				menuChoice = validInt(1, 4);
				cout << "You have chosen " << modifyType[menuChoice -1] << endl;
				break;
			case EXIT:
				cout << "Goodbye";
				exit = true;
				break;
		}
		cout << endl;
	} while (!exit);
#endif
	return 0;
}


int validInt(int lowerB, int upperB)
{
	string buff;
	int choice;

	while (getline(cin, buff))
	{
		stringstream ss(buff);
		if (ss >> choice && (choice >= lowerB) && (choice <= upperB))
		{
			if(ss.eof())
				break;
		}
		cout << "Invalid Input, please try again: ";
	}
	return choice;
}


int stringToInt(string input)
{
	int rtn;
	istringstream convert(input);
	try
	{
		convert >> rtn;
		throw RuntimeException("*** Please Enter an Integer ***");
	}
	catch(RuntimeException& err)
	{
		cout << err.getMessage() << endl;
	}
	return rtn;
}

int getReportType(const vector<const char*> &)
{
	cout << "Please Specify Report Type  " << endl;
	cout << "1. Basic Only" << endl;
	cout << "2. Preferred Only" << endl;
	cout << "3. Both" << endl;
	cout << "Report Type: ";
	return(validInt(1,3));
}
