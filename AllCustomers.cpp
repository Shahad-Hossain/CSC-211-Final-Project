#include "AllCustomers.h"

void AllCustomers::printAllCustomers() {
    //base case to check for empty customer_list vector
    if (customer_list.empty()) {
        cout << "No customers to display.\n";
        return;
    }

    // Header formatting
    cout << left << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(15) << "Account Number"
         << setw(25) << "Street Address"
         << setw(15) << "City"
         << setw(10) << "State"
         << setw(10) << "Zipcode"
         << setw(15) << "Phone Number" << endl;

    //outputs 120 - characters to seperate header with information
    cout << string(120, '-') << endl;
    
    //iterates over customer_list of type auto customer and prints them out
    for (const auto& customer : customer_list) {
        cout << left << setw(15) << customer.getFirstName()
             << setw(15) << customer.getLastName()
             << setw(15) << customer.getAccountNum()
             << setw(25) << customer.getStreetAddress()
             << setw(15) << customer.getCity()
             << setw(10) << customer.getState()
             << setw(10) << customer.getZipcode()
             << setw(15) << customer.getPhoneNum() << endl;
    }
}

int AllCustomers::findCustomerIndexByAccount(int account_num) {
    //Returns index of a specfic account num; -1 if we cannot find account which we will later use to send an error message to user
    for (int i = 0; i < customer_list.size(); ++i) {
        if (customer_list[i].getAccountNum() == account_num) {
            return i;
        }
    }
    return -1;
}

void AllCustomers::printSpecificCustomer(int account_num) {
    //Calls the helper function to find index of person in the specifc account num
    int idx = findCustomerIndexByAccount(account_num);
    if (idx == -1) {
        cout << "No customer found with account number " << account_num << ".\n";
        return;
    }

    //prints out the specific information based on the temp variable c for the specfic customer at the requested index
    customer &c = customer_list[idx];
    cout << "Customer Information:\n";
    cout << "First Name: " << c.getFirstName() << "\n"
         << "Last Name: " << c.getLastName() << "\n"
         << "Account #: " << c.getAccountNum() << "\n"
         << "Address: " << c.getStreetAddress() << ", " << c.getCity() << ", " << c.getState() << " " << c.getZipcode() << "\n"
         << "Phone: " << c.getPhoneNum() << "\n";
}

void AllCustomers::orderAndSort(bool ascending, int option) {
    //I tried implementing bubble sort but I could not figure out how to do it. So, I just used the sort function to simplify the sorting algorithm. This runs in O(n log n) time, which is actually better than bubble sort's O(n^2) time, however I am sorry if you wanted me to implement a sorting algorithm from scratch.

    if (option == 0) { 
    // Sort by account number
    if (ascending) {
        sort(customer_list.begin(), customer_list.end(), [](const customer &a, const customer &b) {
            return a.getAccountNum() < b.getAccountNum();
        });
    } else {
        sort(customer_list.begin(), customer_list.end(), [](const customer &a, const customer &b) {
            return a.getAccountNum() > b.getAccountNum();
        });
    }
} else if (option == 1) { 
    // Sort by first name
    if (ascending) {
        sort(customer_list.begin(), customer_list.end(), [](const customer &a, const customer &b) {
            return a.getFirstName() < b.getFirstName();
        });
    } else {
        sort(customer_list.begin(), customer_list.end(), [](const customer &a, const customer &b) {
            return a.getFirstName() > b.getFirstName();
        });
    }
} else if (option == 2) { 
    // Sort by last name
    if (ascending) {
        sort(customer_list.begin(), customer_list.end(), [](const customer &a, const customer &b) {
            return a.getLastName() < b.getLastName();
        });
    } else {
        sort(customer_list.begin(), customer_list.end(), [](const customer &a, const customer &b) {
            return a.getLastName() > b.getLastName();
        });
    }
} else {
    cout << "Invalid option. Could not sort database." << endl;
}
    cout << "Customers have been sorted by last name in " << (ascending ? "ascending" : "descending") << " order.\n";
}

void AllCustomers::addNewCustomer(string first_name, string last_name, int account_num, string street_address, string city, string state, int zipcode, string phone_num) {
    // Check for duplicate account number
    if (findCustomerIndexByAccount(account_num) != -1) {
        cout << "Account number already exists. Cannot add.\n";
        return;
    }

    //creates a new customer and adds it to the customer_list vector.
    customer new_customer(first_name, last_name, account_num, street_address, city, state, zipcode, phone_num);
    customer_list.push_back(new_customer);
    cout << "Customer added successfully.\n";
}

void AllCustomers::addMultipleCustomersRecursive(int count) {
    if (count <= 0) 
    {return;}

    //temp variables for customer information; shortend for easy typing, i.e., addr = address, and ph means phone number and so on.
    string fn, ln, addr, c, s, ph;
    int acc, zip;

    //Gets data inputted from the user
    cout << "\nEnter details for new customer:\n";
    cout << "First name: ";
    cin >> fn;
    cout << "Last name: ";
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
    cout << "Phone number: ";
    getline(cin, ph);

    //uses AddNewCustomer function to add the customer with given information to the list.
    addNewCustomer(fn, ln, acc, addr, c, s, zip, ph);

    // Recursive call
    addMultipleCustomersRecursive(count - 1);
}

void AllCustomers::addMultipleCustomers(int customer_amount) {
    //recursive helper function to run add multiple customers at once without errors in the main function
    addMultipleCustomersRecursive(customer_amount);
}

void AllCustomers::updateAccountInformation(int account_num) {
    //Uses previous helper function to find the index of a specfic person at an index
    int idx = findCustomerIndexByAccount(account_num);
    if (idx == -1) {
        cout << "No customer found with account number " << account_num << ".\n";
        return;
    }

    //temp variable for updating customer
    customer &c = customer_list[idx];
    cout << "Updating information for customer with account #" << account_num << ".\n";
    cout << "Leave field blank or press ENTER if no change is needed.\n";

    string input;
    cout << "First Name (" << c.getFirstName() << "): ";
    getline(cin, input);
    if (!input.empty()) c.setFirstName(input);

    cout << "Last Name (" << c.getLastName() << "): ";
    getline(cin, input);
    if (!input.empty()) c.setLastName(input);

    cout << "Street Address (" << c.getStreetAddress() << "): ";
    getline(cin, input);
    if (!input.empty()) c.setStreetAddress(input);

    cout << "City (" << c.getCity() << "): ";
    getline(cin, input);
    if (!input.empty()) c.setCity(input);

    cout << "State (" << c.getState() << "): ";
    getline(cin, input);
    if (!input.empty()) c.setState(input);

    cout << "Zipcode (" << c.getZipcode() << "): ";
    getline(cin, input);
    if (!input.empty()) c.setZipcode(stoi(input));

    cout << "Phone Number (" << c.getPhoneNum() << "): ";
    getline(cin, input);
    if (!input.empty()) c.setPhoneNum(input);

    cout << "Customer information updated.\n";
}

void AllCustomers::deleteCustomer(int account_num) {
    //Calls helper function to identify user by account number
    int idx = findCustomerIndexByAccount(account_num);
    if (idx == -1) {
        cout << "No customer found with account number " << account_num << ".\n";
        return;
    }

    //Deletes customer at that specific index
    customer_list.erase(customer_list.begin() + idx);
    cout << "Customer with account number " << account_num << " deleted.\n";
}

void AllCustomers::saveToFile(const string &filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Could not open " << filename << " for writing.\n";
        return;
    }
    // Header for output file to format data
    outFile << "FirstName,LastName,AccountNum,StreetAddress,City,State,ZipCode,PhoneNumber\n";
    // for loop to iterate over customer list and output it into the output file with comma seperated values
    for (auto &c : customer_list) {
        outFile << c.getFirstName() << ","
                << c.getLastName() << ","
                << c.getAccountNum() << ","
                << c.getStreetAddress() << ","
                << c.getCity() << ","
                << c.getState() << ","
                << c.getZipcode() << ","
                << c.getPhoneNum() << "\n";
    }

    //closes output file
    outFile.close();
    cout << "Customer data saved to " << filename << endl;
}

void AllCustomers::loadCustomers(const string& filename) {
    //opens customer file based on filename user inputted
    ifstream customerFile(filename);
    if (!customerFile.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        return;
    }

    string line;
    bool isHeader = true;

    // Clear existing data
    customer_list.clear();

    while (getline(customerFile, line)) {
        if (isHeader) {
            isHeader = false;
            continue;
        }

        //stringstream to seperate comma values
        stringstream ss(line);
        string first_name, last_name, street_address, city, state, phone_num;
        int account_num, zipcode;
        
        //gets each data based on comma seperation, so if the data was like first_name, last_name, account_num, it would get the entire first name no matter the spaces and then get the next name
        getline(ss, first_name, ',');
        getline(ss, last_name, ',');
        ss >> account_num;
        ss.ignore();
        getline(ss, street_address, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        ss >> zipcode;
        ss.ignore();
        getline(ss, phone_num, ',');

        //adds a new customer based on file data
        addNewCustomer(first_name, last_name, account_num, street_address, city, state, zipcode, phone_num);
    }

    customerFile.close();
    cout << "Customer data loaded from " << filename << endl;
}