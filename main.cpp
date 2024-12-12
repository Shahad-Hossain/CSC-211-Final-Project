#include <iostream>
#include <string>
#include "customers.h"
#include "purchases.h"
#include "customers.cpp"
#include "purchases.cpp"
using namespace std;

int main()
{
    AllCustomers allCustomers;
    AllPurchases allPurchases;

    // customer and purchases data file
    string customerFile = "customers.txt";
    string purchaseFile = "purchases.txt";

    //calls the load customer and purchases function which gets the values from the file and enters in the customer and purchase information
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
            cin.clear();                                         
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 12." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        //prints all customers
        if (choice == 1)
        {
            allCustomers.printAllCustomers();
        }
        //sorting by user choice of first name, last name, and account number
        else if (choice == 2)
        {
            cout << "Enter 0 to sort by descending order, and 1 to sort by ascending order: ";
            int asc;
            cin >> asc;
            int opt;
            //cout << "Enter 0 to sort by first name, 1 for last name, 2 to sort by account number: ";
            cout << "Enter 0 to sort by account number, 1 to sort by first name, 2 to sort by last name: ";
            cin >> opt;
            //Checks for valid input
            if((asc == 0 || asc == 1) && (opt == 0 || opt == 1 || opt == 2))
            {
                //Sorts the customer list by the users choice
                allCustomers.orderAndSort(asc, opt);
                allCustomers.printAllCustomers();
            }
            else 
            {
                cout << "Please enter a valid number and try again" << endl;
            }
        }
        //Finds customer by account number
        else if (choice == 3)
        {
            cout << "Enter account number: ";
            int acc;
            cin >> acc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allCustomers.printSpecificCustomer(acc);
            allPurchases.printPurchasesForCustomer(acc);
        }
        //Finds purchases for a specific customer based on account number
        else if (choice == 4)
        {
            cout << "Enter account number: ";
            int acc;
            cin >> acc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            double total = allPurchases.getTotalSpendForCustomer(acc);
            cout << "Total spend for account #" << acc << " is $" << total << "\n";
        }
        //Adds a new customer based on information provided
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
        //uses a recursive algorithm to add multiple customers at once
        else if (choice == 6)
        {
            cout << "How many customers do you want to add? ";
            int amt;
            cin >> amt;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allCustomers.addMultipleCustomers(amt);
        }
        //updates user information based on account number
        else if (choice == 7)
        {
            allCustomers.printAllCustomers();
            cout << "Enter account number to update: ";
            int acc;
            cin >> acc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allCustomers.updateAccountInformation(acc);
        }
        //allows user to delete account via account number
        else if (choice == 8)
        {
            cout << "Enter account number to delete: ";
            int acc;
            cin >> acc;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allCustomers.deleteCustomer(acc);
        }
        //Entering account number to add a purchase to
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
        //Uses recursive algorithm to add multiple purchases
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
        //Saves changes done in the program to the existing files or a new file based on user choice
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

    cout << "Exiting program.\n";
    return 0;
}