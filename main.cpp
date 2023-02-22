#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Invester.h"
#include "Invester.cpp"

using namespace std;

int main() {
   vector<double> monthlyOpening, annualClosing;
   Invester investNow;
   investNow.userPrompt();
   investNow.displayInfo();
   investNow.displayAnnualNumbers();
   if (investNow.getMonthlyDeposit() != 0) {
      // FIXME
   }

   return 0;
}