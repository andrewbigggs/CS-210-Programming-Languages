#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Invester {
protected:
   mutable double initInvestment, monthlyDeposit, annualInterestRate;
   mutable int numYears, numMonths;

   mutable vector<double> annualClosingBalanceList;
   mutable vector<double> annualClosingBalanceList_w_monthly;
   mutable vector<double> annualInterestList;
   mutable vector<double> annualInterestList_w_monthly;
   mutable vector<double> monthlyOpeningBalanceList;
   mutable vector<double> monthlyOpeningBalanceList_w_monthly;

public:
   // setter methods
   void setInitInvestment(double amount) { initInvestment = amount; }
   void setMonthlyDeposit(double amount) { monthlyDeposit = amount; }
   void setAnnualInterestRate(double amount) { annualInterestRate = amount; }
   void setNumYearsAndMonths(int amount) { numYears = amount; numMonths = amount * 12; }
   void setMonthOpenAndYearCloseBalances() { // Populates opening and closing balance vectors
      double balance;
      balance = initInvestment;
      int i;
      for (i = 0; i < numMonths; ++i) {
         monthlyOpeningBalanceList.push_back(balance);
         balance += ((balance) * ((annualInterestRate/100)/12));
         if ((i + 1) % 12 == 0) {
            annualClosingBalanceList.push_back(balance);
         }
      }
   }
   void setMonthOpenAndYearCloseBalances(const double& deposit) { // Populates opening and closing balance vectors
      double balance;
      balance = initInvestment;
      int i;
      for (i = 0; i < numMonths; ++i) {
         monthlyOpeningBalanceList_w_monthly.push_back(balance);
         if (i > 0) {
         balance += deposit;
         }
         balance += ((balance) * ((this->annualInterestRate/100)/12));
         if ((i + 1) % 12 == 0) {
            annualClosingBalanceList_w_monthly.push_back(balance);
         }
      }
   }
   void setAnnualInterests() { // Populates annual interests vectors
      double interest, interest_w_monthly;
      double priorYearsInterest = 0;
      double priorYearsInterest_w_monthly = 0;
      annualInterestList.resize(numYears);
      annualInterestList_w_monthly.resize(numYears);
      int i;
      for (i = 0; i < numYears; ++i) {
         if (i > 0) {
            priorYearsInterest += annualInterestList.at(i - 1);
            priorYearsInterest_w_monthly += annualInterestList_w_monthly.at(i - 1);
         }

         interest = annualClosingBalanceList.at(i) - initInvestment - priorYearsInterest;
         interest_w_monthly = annualClosingBalanceList_w_monthly.at(i) - initInvestment - 
         (monthlyDeposit * i * 12) - priorYearsInterest_w_monthly;

         annualInterestList.at(i) = interest;
         annualInterestList_w_monthly.at(i) = interest_w_monthly;
      }
   }
   // getter methods
   int getNumYears() {
      return numYears;
   }
   int getNumMonths() {
      return numMonths;
   }
   double getInitInvestment() {
      return initInvestment;
   }
   double getMonthlyDeposit() {
      return monthlyDeposit;
   }
   double getAnnualInterestRate() {
      return annualInterestRate;
   }
   double getSumOpeningAndDeposit(int index) { // Account total before this month's interest
      double sum;
      sum = this->monthlyOpeningBalanceList.at(index) + this->monthlyDeposit;
      return sum;
   }
   // Prompt for info
   void userPrompt() {
      double userDouble;
      int userInt;

      cout << "|||Enter Initial Investment Amount, Monthly Deposit,|||" << endl;
      cout << "|||Annual Interest Rate(0-100), and Number of Years |||" << endl;
      cout << "|||-------------------------------------------------|||" << endl;
      cout << "|||Initial Investment Amount: ";
      cin.clear();
      cin >> userDouble;
      this->initInvestment = abs(userDouble);
      if (cin.fail()) {
         cout << "Invalid Entry.";
      }
      cout << "|||Monthly Deposit: ";
      cin >> userDouble;
      this->monthlyDeposit = abs(userDouble);

      cout << "|||Annual Interest Rate(0-100): ";
      cin >> userDouble;
      this->annualInterestRate = abs(userDouble);
      if (cin.fail()) {
         cout << "Invalid Entry";
         return;
      } 
      cout << "|||Number of Years: ";
      cin >> userInt;
      this->numYears = abs(userInt);
      if (cin.fail()) {
         cout << "Invalid Entry";
         return;
         cin.clear();
      }
   }
   // Display info
   void displayInfo() {
      
   }
   // Display annual totals and interests without monthly contribution
   void displayAnnualNumbers() {
      setMonthOpenAndYearCloseBalances();
      int i;
      for (i = 0; i < 5; ++i) {
         cout << endl;
      }
      cout << "|||    Balance and Interest Without Additional Monthly Deposits    |||" << endl;
      cout << "|||----------------------------------------------------------------|||" << endl;
      cout << "||| Year       Year End Balance        Year End Earned Interest    |||" << endl;
      cout << "|||----------------------------------------------------------------|||" << endl;
      for (i = 0; i < numYears; ++i) {
         cout << "||| " << setprecision(2) << setw(11) << left << i + 1;
         cout << setw(23) << left << annualClosingBalanceList.at(i);
         cout << setw(28) << left << annualInterestList.at(i) << "|||";
      }
   }
   // Display annual totals and interests with monthly contribution
   void displayAnnualNumbersWithMonthly() {
      setMonthOpenAndYearCloseBalances(monthlyDeposit);
      int i;
      for (i = 0; i < 5; ++i) {
         cout << endl;
      }
      cout << "|||    Balance and Interest Without Additional Monthly Deposits    |||" << endl;
      cout << "|||----------------------------------------------------------------|||" << endl;
      cout << "||| Year       Year End Balance        Year End Earned Interest    |||" << endl;
      cout << "|||----------------------------------------------------------------|||" << endl;
      for (i = 0; i < numYears; ++i) {
         cout << "||| " << setprecision(2) << setw(11) << left << i + 1;
         cout << setw(23) << left << annualClosingBalanceList.at(i);
         cout << setw(28) << left << annualInterestList.at(i) << "|||";
      }
   }
};
