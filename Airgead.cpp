#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include "Airgead.h"

using namespace std;

//Default Constructor
Investment::Investment() {
	this->m_initIinvest = 0.00;
	this->m_monthDeposit = 0.00;
	this->m_apr = 0.00;
	this->m_numYears = 0;
	this->m_intEarned = 0.00;
	this->m_total = 0.00;
}

//Overloaded Constructor
Investment::Investment(double t_firstDep, double t_monthContrib, double t_interest, int t_years) {
	this->m_initIinvest = t_firstDep;
	this->m_monthDeposit = t_monthContrib;
	this->m_apr = t_interest;
	this->m_numYears = t_years;
	this->m_intEarned = 0.00;
	this->m_total = this->m_initIinvest;
}

//Calculate and set the total and interest earned.
double Investment::calcTotal(bool t_monthlyDeposit) {
	double monthlyInterest = ((this->getApr() / 100) / 12.0);
	double mnthIntAmt = 0.0;

	if (t_monthlyDeposit == true) {
		mnthIntAmt = (this->m_total + this->getDeposit()) * monthlyInterest;
		
		this->m_intEarned = this->m_intEarned + mnthIntAmt;
		this->m_total = this->m_total + this->getDeposit();
		this->m_total = this->m_total + (this->m_total * monthlyInterest);
	}
	else {
		this->m_intEarned = this->m_intEarned + (this->m_total * monthlyInterest);
		this->m_total = (this->m_total + (this->m_total * monthlyInterest));
	}

	return this->m_total;
}

//Accessor Method
void Investment::initTotal(double t_newTotal) {

	this->m_total = t_newTotal;

}

//Accessor Method
double Investment::getIntEarned() {

	return this->m_intEarned;

}

//Accessor Method
void Investment::setIntEarned(double t_interest) {

	this->m_intEarned = t_interest;

}

//Accessor Method
void Investment::setInvest(double t_investAmt) {

	this->m_initIinvest = t_investAmt;

}

//Accessor Method
double Investment::getInvest() {

	return this->m_initIinvest;

}

//Accessor Method
void Investment::setDeposit(double t_depositAmt) {

	this->m_monthDeposit = t_depositAmt;

}

//Accessor Method
double Investment::getDeposit() {

	return this->m_monthDeposit;

}

//Accessor Method
void Investment::setApr(double t_newApr) {

	this->m_apr = t_newApr;

}

//Accessor Method
double Investment::getApr() {

	return this->m_apr;

}

//Accessor Method
void Investment::setYears(int t_numYears) {

	this->m_numYears = t_numYears;

}

//Accessor Method
int Investment::getYears() {

	return this->m_numYears;

}

void Investment::printReport() {

	double tempTotal = 0.0;

	cout << fixed;
	cout << setprecision(2);
	cout << "     Balance and Interest Without Additional Monthly Payments     " << endl;
	cout << "==================================================================" << endl;
	cout << "     Year       Year End Balance      Year End Earned Interest    " << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (int i = 1; i <= this->getYears(); i++) {

		this->setIntEarned(0);
		
		for (int i = 0; i < 12; i++) {

			tempTotal = this->calcTotal(false);

		}

		cout << right << setw(8) << i;
		cout << right << setw(15) << "$" << (tempTotal);
		cout << right << setw(20) << "$" << (this->getIntEarned()) << endl << endl;

	}

	system("pause");
	this->m_total = this->m_initIinvest;

	cout << fixed;
	cout << setprecision(2);
	cout << "      Balance and Interest With Additional Monthly Payments       " << endl;
	cout << "==================================================================" << endl;
	cout << "     Year       Year End Balance      Year End Earned Interest    " << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (int i = 1; i <= this->getYears(); i++) {

		this->setIntEarned(0);
		
		for (int i = 0; i < 12; i++) {

			tempTotal = this->calcTotal(true);

		}

		cout << right << setw(8) << i;
		cout << right << setw(15) << "$" << (tempTotal);
		cout << right << setw(20) << "$" << (this->getIntEarned()) << endl << endl;

	}

}

//Input Data
void Investment::inputData() {

	double newInvestAmt;
	double newMonthlyDepst;
	double newApr;
	int newYears;

	cout << "***********************************" << endl;
	cout << "************Data Input*************" << endl;
	
	cout << "Initial Investment Amount: ";
	while (!(cin >> newInvestAmt)) {
		cin.clear();
		cin.ignore(128, '\n');
		cout << "ERROR: Invalid input value." << endl;
		cout << "Initial Investment Amount: ";
	}
	
	cout << "Monthly Deposit: ";
	while (!(cin >> newMonthlyDepst)) {
		cin.clear();
		cin.ignore(128, '\n');
		cout << "ERROR: Invalid input value." << endl;
		cout << "Monthly Deposit: ";
	}
	
	cout << "Annual Interest: ";
	while (!(cin >> newApr)) {
		cin.clear();
		cin.ignore(128, '\n');
		cout << "ERROR: Invalid input value." << endl;
		cout << "Annual Interest: ";
	}
	
	cout << "Number of Years: ";
	while (!(cin >> newYears)) {
		cin.clear();
		cin.ignore(128, '\n');
		cout << "ERROR: Invalid input value." << endl;
		cout << "Number of Years: ";
	}
	
	cout << endl;

	this->setInvest(newInvestAmt);
	this->initTotal(newInvestAmt);
	this->setDeposit(newMonthlyDepst);
	this->setApr(newApr);
	this->setYears(newYears);

};