#pragma once
#include <iostream>
using namespace std;
#ifndef HEADER_H
#define HEADER_H
double initialInvestmentAmount = 0.0;
double monthlyDeposit = 0.0;
double annualInterest = 0.0;
double totalDeposit;
double totalClose;
int numYears = 0;
int numMonths = 0;

void SetInitialInvestmentAmount(){std::cin >> initialInvestmentAmount;}
double GetInitialInvestmentAmount() { return initialInvestmentAmount; }
void SetMonthlyDeposit(){ std::cin >> monthlyDeposit;}
double GetMonthlyDeposit() { return monthlyDeposit; }
void SetAnnualInterest() { std::cin >> annualInterest; }
double GetAnnualInterest() { return annualInterest; }
void SetNumYears() { std::cin >> numYears; }

void GetUserInput() {
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
}


#endif