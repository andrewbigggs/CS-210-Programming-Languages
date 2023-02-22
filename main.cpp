#include "Starter Code.cpp"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {

   int userInput = 0;
   callProcedure("CountItems");
   while (userInput != 4)
      while (userInput != 1 && userInput != 2 && userInput != 3) {
         cout << "************************************************" << endl;
         cout << "Choose a menu item and enter its given integer.." << endl;
         cout << "1: Determine frequency of each item in the list " << endl;
         cout << "2: Determine frequency of a specific item" << endl;
         cout << "3: Display frequency of all items as a histogram" << endl;
         cout << "4: Quit program" << endl;
         cin >> userInput;
      }
      // Calls Python function to print each item and its frequency
      if (userInput == 1) {
         callProcedure("PrintItemFrequencies");
      }
      // Calls Python function to return the frequency of the specified item
      else if (userInput == 2) {
         string userItem;
         cout << "Enter the name of the item you wish to know the frequency of" << endl;
         cout << "(Make sure the first letter is capitalized. ie. 'Zucchini')" << endl;
         cin >> userItem;
         callIntFunc("GetSingleItemFrequency", userItem);
      }
      // Reads frequency.dat and prints a histogram illustrating frequency.dat
      else if (userInput == 3) {
         ifstream inFS;
         string itemName;
         int itemFreq;

         inFS.open("frequency.dat");
         while (!inFS.eof()) {
            inFS >> itemName;
            inFS >> itemFreq;
            cout << << setw(12) << left << itemName;
            int i;
            for (i = 0; i < itemFreq; ++i) {
               cout << "|";
            }
            cout << endl;
         }
         inFS.close();
      }

   cout << "Thank you for using this program. Goodbye" << endl;

return 0;
}
