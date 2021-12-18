#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdexcept>
using namespace std;
#ifndef INTERESTCALCULATOR_H
#define INTERESTCALCULATOR_H

	double initialInvestmentAmount = 0.0;
	double monthlyDeposit = 0.0;
	double annualInterest = 0.0;
	double totalDeposit;
	double totalClose;
	int numYears = 0;
	int numMonths = 0;

bool isNumeric(string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false; //when one non numeric value is found, return false
	return true;
}

void SetInitialInvestmentAmount() {
	std::cin >> initialInvestmentAmount;
	while (!cin) // or if(cin.fail())
	{
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		cout << "Please enter numeric value" << endl;
		std::cin >> initialInvestmentAmount;// next, request user reinput
		while (initialInvestmentAmount < 0) // or if(cin.fail())
		{
			// user didn't input a number
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			cout << "Please enter a number greater than 0" << endl;
			std::cin >> initialInvestmentAmount;// next, request user reinput
		}
	}
}

double GetInitialInvestmentAmount() { return initialInvestmentAmount; }

void SetMonthlyDeposit(){ 
	std::cin >> monthlyDeposit;
	while (!cin) // or if(cin.fail())
	{
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		cout << "Please enter numeric value" << endl;
		std::cin >> monthlyDeposit;// next, request user reinput
		while (monthlyDeposit < 0) // or if(cin.fail())
		{
			// user didn't input a number
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			cout << "Please enter a number greater than 0" << endl;
			std::cin >> monthlyDeposit;// next, request user reinput
		}
	}
}

double GetMonthlyDeposit() { return monthlyDeposit; }

void SetAnnualInterest() { 
	std::cin >> annualInterest;
	while (!cin) // or if(cin.fail())
	{
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		cout << "Please enter numeric value" << endl;
		std::cin >> annualInterest;// next, request user reinput
		while (annualInterest < 0) // or if(cin.fail())
		{
			// user didn't input a number
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			cout << "Please enter a number greater than 0" << endl;
			std::cin >> annualInterest;// next, request user reinput
		}
	}
}

double GetAnnualInterest() { return annualInterest; }

void SetNumYears() {
	std::cin >> numYears;
	while (!cin) // or if(cin.fail())
	{
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		cout << "Please enter numeric value" << endl;
		std::cin >> numYears;// next, request user reinput
		while (numYears < 0) // or if(cin.fail())
		{
			// user didn't input a number
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			cout << "Please enter a number greater than 0" << endl;
			std::cin >> numYears;// next, request user reinput
		}
	}
}

int GetNumYears() { return numYears; }

void PrintDataYearly();
void PrintDataMonthly();
void PrintMenu();

void GetUserInput() { // get initial values
	cout << "*********************************" << endl;
	cout << "********** Data Input ***********" << endl;
	cout << "Initial investment Amount :" << endl;
	SetInitialInvestmentAmount();
	cout << "Monthly Deposit:" << endl;
	SetMonthlyDeposit();
	cout << "Annual Interest" << endl;
	SetAnnualInterest();
	cout << "Number of Years:" << endl;
	SetNumYears();
	cout << "Press any key to continue . . ." << endl;
	_getch();
	//test code
	cout << "initial investment amount entered: " << GetInitialInvestmentAmount() << endl;
	cout << "Monthly deposit amount entered: " << GetMonthlyDeposit() << endl;
	cout << "Annual interest amount entered: " << GetAnnualInterest() << endl;
	cout << "Number of years amount entered: " << GetNumYears() << endl;
}

void PrintMenu() {
		bool menu = true;
		int choice;
		cout << "***************************************" << endl;
		cout << "*1 - Change initial investment amount *" << endl;
		cout << "*2 - Change monthly deposit           *" << endl;
		cout << "*3 - Change interest rate             *" << endl;
		cout << "*4 - Change number of years           *" << endl;
		cout << "*5 - Print monthly data table         *" << endl;
		cout << "*6 - Quit                             *" << endl;
		cout << "***************************************" << endl;
		while (menu)
		{
			cin >> choice;

			switch (choice)
			{
			case 1:
				SetInitialInvestmentAmount();
				PrintDataYearly();
				break;
			case 2:
				SetMonthlyDeposit();
				PrintDataYearly();
				break;
			case 3:
				SetAnnualInterest();
				PrintDataYearly();
				break;
			case 4:
				SetNumYears();
				PrintDataYearly();
				break;
			case 5:
				PrintDataMonthly();
				break;
			case 6:
				exit(0);
			default:
				cout << "Your selection must be between 1 and 6!\n";
			}
		}
}


void PrintDataYearly() {
	cout << endl;
	cout << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(55) << "" << endl; //prints a line to separate the column headers from data
	cout << setfill(' ');
	cout << "Year     Year End Balance      Year End Earned Interest" << endl; //column headers
	cout << fixed << setprecision(2); // rounds decimals to the nearest cent
	totalClose = initialInvestmentAmount;
	cout << setfill('-') << setw(55) << "" << endl; //prints a line to separate the column headers from data
	cout << setfill(' ');
	for (int i = 1; i < numYears + 1; ++i) {

		cout << setw(5) << left << i;
		totalDeposit = (12 * monthlyDeposit) + totalClose;
		totalClose = (totalDeposit * (annualInterest / 100)) + totalDeposit;
		cout << setw(10) << right << "$" << totalClose;
		cout << setw(12) << right << "$" << totalClose - totalDeposit << endl;
		totalDeposit = totalClose;
	}
	cout << endl;

	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(55) << "" << endl; //prints a line to separate the column headers from data
	cout << setfill(' ');
	cout << "Year     Year End Balance      Year End Earned Interest" << endl; //column headers
	totalClose = initialInvestmentAmount;
	cout << setfill('-') << setw(55) << "" << endl; //prints a line to separate the column headers from data
	cout << setfill(' ');
	for (int i = 1; i < numYears + 1; ++i) {

		cout << setw(5) << left << i;
		totalDeposit = totalClose;
		totalClose = (totalDeposit * (annualInterest / 100)) + totalDeposit;
		cout << setw(10) << right << "$" << totalClose;
		cout << setw(12) << right << "$" << totalClose - totalDeposit << endl;
		totalDeposit = totalClose;
	}
	cout << endl;
	PrintMenu();
}

void PrintDataMonthly() {
	cout << endl;
	cout << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(55) << "" << endl; //prints a line to separate the column headers from data
	cout << setfill(' ');
	cout << "Month     Month End Balance      Month End Earned Interest" << endl; //column headers
	cout << fixed << setprecision(2); // rounds decimals to the nearest cent
	totalClose = initialInvestmentAmount;
	cout << setfill('-') << setw(55) << "" << endl; //prints a line to separate the column headers from data
	cout << setfill(' ');
	numMonths = numYears * 12;
	for (int i = 1; i < numMonths + 1; ++i) {

		cout << setw(5) << left << i;
		totalDeposit = monthlyDeposit + totalClose;
		totalClose = (totalDeposit * ((annualInterest / 100)) / 12) + totalDeposit;
		cout << setw(10) << right << "$" << totalClose;
		cout << setw(12) << right << "$" << totalClose - totalDeposit << endl;
		totalDeposit = totalClose;
	}
	cout << endl;

	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(55) << "" << endl; //prints a line to separate the column headers from data
	cout << setfill(' ');
	cout << "Month     Month End Balance      Month End Earned Interest" << endl; //column headers
	totalClose = initialInvestmentAmount;
	cout << setfill('-') << setw(55) << "" << endl; //prints a line to separate the column headers from data
	cout << setfill(' ');
	for (int i = 1; i < numMonths + 1; ++i) {

		cout << setw(5) << left << i;
		totalDeposit = totalClose;
		totalClose = (totalDeposit * ((annualInterest / 100)) / 12) + totalDeposit;
		cout << setw(10) << right << "$" << totalClose;
		cout << setw(12) << right << "$" << totalClose - totalDeposit << endl;
		totalDeposit = totalClose;
	}
	cout << endl;
	PrintMenu();
};

#endif