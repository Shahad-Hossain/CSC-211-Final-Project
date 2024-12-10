#include <iostream>
#include <string>
#include "AllCustomers.h"
#include "AllPurchases.h"
#include "AllCustomers.cpp"
#include "AllPurchases.cpp"
using namespace std;

int main()
{
    AllCustomers allCustomers;
    AllPurchases allPurchases;

    // On launch, load data from files
    // Adjust file names as needed
    string customerFile = "customers.txt";
    string purchaseFile = "purchases.txt";

    allCustomers.loadCustomers(customerFile);
    allPurchases.loadPurchases(purchaseFile);

    do
    {
        cout << "\n===== SHAHAD'S MICRO CENTER =====\n";
        cout << "1. Print all customers\n";
        cout << "2. Sort customers & print\n";
        cout << "3. Print specific customer info (with purchases)\n";
        cout << "4. Print total spend for a customer\n";
        cout << "5. Add a new customer\n";
        cout << "6. Add multiple customers (recursive)\n";
        cout << "7. Update a customer's information\n";
        cout << "8. Delete a customer\n";
        cout << "9. Add a new purchase for a customer\n";
        cout << "10. Add multiple new purchases (recursive)\n";
        cout << "11. Save data (customers & purchases)\n";
        cout << "12. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        // Validate input
        if (cin.fail())
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input! Please enter a number between 1 and 12." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clean up any extra input

        if (choice == 1)
        {
            allCustomers.printAllCustomers();
        }
        else if (choice == 2)
        {
            cout << "Enter 1 for ascending, 0 for descending: ";
            int asc;
            cin >> asc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allCustomers.orderAndSort(asc == 1);
            allCustomers.printAllCustomers();
        }
        else if (choice == 3)
        {
            cout << "Enter account number: ";
            int acc;
            cin >> acc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allCustomers.printSpecificCustomer(acc);
            allPurchases.printPurchasesForCustomer(acc);
        }
        else if (choice == 4)
        {
            cout << "Enter account number: ";
            int acc;
            cin >> acc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            double total = allPurchases.getTotalSpendForCustomer(acc);
            cout << "Total spend for account #" << acc << " is $" << total << "\n";
        }
        else if (choice == 5)
        {
            string fn, ln, addr, c, s, ph;
            int acc, zip;
            cout << "First Name: ";
            cin >> fn;
            cout << "Last Name: ";
            cin >> ln;
            cout << "Account #: ";
            cin >> acc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Street Address: ";
            getline(cin, addr);
            cout << "City: ";
            getline(cin, c);
            cout << "State: ";
            getline(cin, s);
            cout << "Zipcode: ";
            cin >> zip;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Phone Number: ";
            getline(cin, ph);
            allCustomers.addNewCustomer(fn, ln, acc, addr, c, s, zip, ph);
        }
        else if (choice == 6)
        {
            cout << "How many customers do you want to add? ";
            int amt;
            cin >> amt;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allCustomers.addMultipleCustomers(amt);
        }
        else if (choice == 7)
        {
            cout << "Enter account number to update: ";
            int acc;
            cin >> acc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allCustomers.updateAccountInformation(acc);
        }
        else if (choice == 8)
        {
            cout << "Enter account number to delete: ";
            int acc;
            cin >> acc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allCustomers.deleteCustomer(acc);
        }
        else if (choice == 9)
        {
            cout << "Enter account number for the purchase: ";
            int acc;
            cin >> acc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter item: ";
            string it;
            getline(cin, it);
            cout << "Enter date (DD-MM-YYYY): ";
            string d;
            getline(cin, d);
            cout << "Enter amount: ";
            double amt;
            cin >> amt;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allPurchases.addNewPurchase(acc, it, d, amt);
        }
        else if (choice == 10)
        {
            cout << "Enter account number for purchases: ";
            int acc;
            cin >> acc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "How many purchases do you want to add? ";
            int pcount;
            cin >> pcount;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allPurchases.addMultiplePurchases(pcount, acc);
        }
        else if (choice == 11)
        {
            cout << "Save over existing files or new files? (1=existing, 2=new): ";
            int opt;
            cin >> opt;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (opt == 2)
            {
                cout << "Enter new customer filename: ";
                getline(cin, customerFile);
                cout << "Enter new purchase filename: ";
                getline(cin, purchaseFile);
            }
            allCustomers.saveToFile(customerFile);
            allPurchases.saveToFile(purchaseFile);
        }
        else if (choice == 12)
        {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid option. Please enter a number between 1 and 12.\n";
        }
    } while (true);

    /* bool running = true;
    while (running) {
        cout << "\n===== SHAHAD'S MIRCO CENTER =====\n";
        cout << "1. Print all customers\n";
        cout << "2. Sort customers & print\n";
        cout << "3. Print specific customer info (with purchases)\n";
        cout << "4. Print total spend for a customer\n";
        cout << "5. Add a new customer\n";
        cout << "6. Add multiple customers (recursive)\n";
        cout << "7. Update a customer's information\n";
        cout << "8. Delete a customer\n";
        cout << "9. Add a new purchase for a customer\n";
        cout << "10. Add multiple new purchases (recursive)\n";
        cout << "11. Save data (customers & purchases)\n";
        cout << "12. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                allCustomers.printAllCustomers();
                break;
            }
            case 2: {
                cout << "Enter 1 for ascending, 0 for descending: ";
                int asc;
                cin >> asc;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                allCustomers.orderAndSort(asc == 1);
                allCustomers.printAllCustomers();
                break;
            }
            case 3: {
                cout << "Enter account number: ";
                int acc;
                cin >> acc;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                allCustomers.printSpecificCustomer(acc);
                allPurchases.printPurchasesForCustomer(acc);
                break;
            }
            case 4: {
                cout << "Enter account number: ";
                int acc;
                cin >> acc;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                double total = allPurchases.getTotalSpendForCustomer(acc);
                cout << "Total spend for account #" << acc << " is $" << total << "\n";
                break;
            }
            case 5: {
                string fn, ln, addr, c, s, ph;
                int acc, zip;
                cout << "First Name: ";
                cin >> fn;
                cout << "Last Name: ";
                cin >> ln;
                cout << "Account #: ";
                cin >> acc;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Street Address: ";
                getline(cin, addr);
                cout << "City: ";
                getline(cin, c);
                cout << "State: ";
                getline(cin, s);
                cout << "Zipcode: ";
                cin >> zip;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Phone Number: ";
                getline(cin, ph);
                allCustomers.addNewCustomer(fn, ln, acc, addr, c, s, zip, ph);
                break;
            }
            case 6: {
                cout << "How many customers do you want to add? ";
                int amt;
                cin >> amt;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                allCustomers.addMultipleCustomers(amt);
                break;
            }
            case 7: {
                cout << "Enter account number to update: ";
                int acc;
                cin >> acc;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                allCustomers.updateAccountInformation(acc);
                break;
            }
            case 8: {
                cout << "Enter account number to delete: ";
                int acc;
                cin >> acc;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                allCustomers.deleteCustomer(acc);
                break;
            }
            case 9: {
                cout << "Enter account number for the purchase: ";
                int acc;
                cin >> acc;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter item: ";
                string it;
                getline(cin, it);
                cout << "Enter date (DD-MM-YYYY): ";
                string d;
                getline(cin, d);
                cout << "Enter amount: ";
                double amt;
                cin >> amt;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                allPurchases.addNewPurchase(acc, it, d, amt);
                break;
            }
            case 10: {
                cout << "Enter account number for purchases: ";
                int acc;
                cin >> acc;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "How many purchases do you want to add? ";
                int pcount;
                cin >> pcount;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                allPurchases.addMultiplePurchases(pcount, acc);
                break;
            }
            case 11: {
                cout << "Save over existing files or new files? (1=existing, 2=new): ";
                int opt;
                cin >> opt;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (opt == 2) {
                    cout << "Enter new customer filename: ";
                    getline(cin, customerFile);
                    cout << "Enter new purchase filename: ";
                    getline(cin, purchaseFile);
                }
                allCustomers.saveToFile(customerFile);
                allPurchases.saveToFile(purchaseFile);
                break;
            }
            case 12: {
                running = false;
                break;
            }
            default:
                cout << "Invalid option.\n";
        }
    } */

    cout << "Exiting program.\n";
    return 0;
}