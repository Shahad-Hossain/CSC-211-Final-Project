#include "AllCustomers.h"

void AllCustomers::printAllCustomers() {
    if (customer_list.empty()) {
        cout << "No customers to display.\n";
        return;
    }

    // Print header
    cout << left << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(15) << "Account Number"
         << setw(25) << "Street Address"
         << setw(15) << "City"
         << setw(10) << "State"
         << setw(10) << "Zipcode"
         << setw(15) << "Phone Number" << endl;

    cout << string(120, '-') << endl;

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
    for (int i = 0; i < customer_list.size(); ++i) {
        if (customer_list[i].getAccountNum() == account_num) {
            return i;
        }
    }
    return -1;
}

void AllCustomers::printSpecificCustomer(int account_num) {
    int idx = findCustomerIndexByAccount(account_num);
    if (idx == -1) {
        cout << "No customer found with account number " << account_num << ".\n";
        return;
    }

    customer &c = customer_list[idx];
    cout << "Customer Information:\n";
    cout << "First Name: " << c.getFirstName() << "\n"
         << "Last Name: " << c.getLastName() << "\n"
         << "Account #: " << c.getAccountNum() << "\n"
         << "Address: " << c.getStreetAddress() << ", " << c.getCity() << ", " << c.getState() << " " << c.getZipcode() << "\n"
         << "Phone: " << c.getPhoneNum() << "\n";
}

void AllCustomers::orderAndSort(bool ascending) {
    // Sort by last name as an example
    if (ascending) {
        sort(customer_list.begin(), customer_list.end(), [](const customer &a, const customer &b){
            return a.getLastName() < b.getLastName();
        });
    } else {
        sort(customer_list.begin(), customer_list.end(), [](const customer &a, const customer &b){
            return a.getLastName() > b.getLastName();
        });
    }
    cout << "Customers have been sorted by last name in " << (ascending ? "ascending" : "descending") << " order.\n";
}

void AllCustomers::addNewCustomer(string first_name, string last_name, int account_num, string street_address, string city, string state, int zipcode, string phone_num) {
    // Check for duplicate account number
    if (findCustomerIndexByAccount(account_num) != -1) {
        cout << "Account number already exists. Cannot add.\n";
        return;
    }

    customer new_customer(first_name, last_name, account_num, street_address, city, state, zipcode, phone_num);
    customer_list.push_back(new_customer);
    cout << "Customer added successfully.\n";
}

void AllCustomers::addMultipleCustomersRecursive(int count) {
    if (count <= 0) return;

    string first_name, last_name, addr, c, s, ph;
    int acc, zip;

    cout << "\nEnter details for new customer:\n";
    cout << "First name: ";
    cin >> first_name;
    cout << "Last name: ";
    cin >> last_name;
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

    addNewCustomer(first_name, last_name, acc, addr, c, s, zip, ph);

    // Recursive call
    addMultipleCustomersRecursive(count - 1);
}

void AllCustomers::addMultipleCustomers(int customer_amount) {
    addMultipleCustomersRecursive(customer_amount);
}

void AllCustomers::updateAccountInformation(int account_num) {
    int idx = findCustomerIndexByAccount(account_num);
    if (idx == -1) {
        cout << "No customer found with account number " << account_num << ".\n";
        return;
    }

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
    int idx = findCustomerIndexByAccount(account_num);
    if (idx == -1) {
        cout << "No customer found with account number " << account_num << ".\n";
        return;
    }
    customer_list.erase(customer_list.begin() + idx);
    cout << "Customer with account number " << account_num << " deleted.\n";
}

void AllCustomers::saveToFile(const string &filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Could not open " << filename << " for writing.\n";
        return;
    }
    // Header
    outFile << "FirstName,LastName,AccountNum,StreetAddress,City,State,ZipCode,PhoneNumber\n";
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
    outFile.close();
    cout << "Customer data saved to " << filename << endl;
}

void AllCustomers::loadCustomers(const string& filename) {
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

        stringstream ss(line);
        string first_name, last_name, street_address, city, state, phone_num;
        int account_num, zipcode;

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

        addNewCustomer(first_name, last_name, account_num, street_address, city, state, zipcode, phone_num);
    }

    customerFile.close();
    cout << "Customer data loaded from " << filename << endl;
}