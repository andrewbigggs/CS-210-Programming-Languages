using namespace std;

#ifndef INVESTER_H
#define INVESTER_H

void setInitInvestment(double amount);
void setMonthlyDeposit(double amount);
void setAnnualInterestRate(double amount);
void setNumYearsAndMonths(int amount);
void setMonthOpenAndYearCloseBalances();
void setMonthOpenAndYearCloseBalances(const double& deposit);
void setAnnualInterests();
int getNumYears();
int getNumMonths();
double getInitInvestment();
double getMonthlyDeposit();
double getAnnualInterestRate();
double getSumOpeningAndDeposit(int index);
void userPrompt();
void displayInfo();
void displayAnnualNumbers();
void displayAnnualNumbersWithDeposit();

#endif // INVESTER_H
