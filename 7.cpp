#include <bits/stdc++.h>
using namespace std;
int main()
{
     int lock = 0;
     bool locked_T1 = false, locked_T2 = false;
     while (1)
     {
         int choice;
         if (!locked_T1)
         {
             cout << "Transaction T1 wants to Lock Data Object ?" << endl;
             cout << "1. Yes" << endl;
             cout << "2. No" << endl;
             cin >> choice;
             if (!lock && choice == 1)
             {
                 lock = 1;
                 locked_T1 = true;
                 cout << "T1 has been given the Lock for the Data Object" << endl;
             }
             else if (lock)
                 cout << "\nData Object is Already Locked by " << (locked_T1 ? "T1" : "T2") << endl
             << endl;
         }
         if (!locked_T2)
         {
             cout << "Transaction T2 wants to Lock Data Object ?" << endl;
             cout << "1. Yes" << endl;
             cout << "2. No" << endl;
             cin >> choice;
             if (!lock && choice == 1)
             {
                 lock = 1;
                 locked_T2 = true;
                 cout << "T2 has been given the Lock for the Data Object" << endl;
             }
             else if (lock)
                cout << "\nData Object is Already Locked by " << (locked_T1 ? "T1" : "T2") << endl << endl;
         }
         if (lock)
         {
             if (locked_T1)
             {
                 cout << "Transaction T1 wants to Release the Lock on Data Object?" << endl;
                 cout << "1. Yes" << endl;
                 cout << "2. No" << endl;
                 cin >> choice;
                 if (choice == 1)
                 {
                     lock = 0, locked_T1 = false;
                     cout << "The Lock on Data Object has been released by T1 !" << endl;
                 }
             }
             else
             {
                 cout << "Transaction T2 wants to Release the Lock on Data Object?" << endl;
                 cout << "1. Yes" << endl;
                 cout << "2. No" << endl;
                 cin >> choice;
                 if (choice == 1)
                 {
                     lock = 0, locked_T2 = false;
                     cout << "The Lock on Data Object has been released by T2 !" << endl;
                 }
             }
         }
     }
     return 0;
}