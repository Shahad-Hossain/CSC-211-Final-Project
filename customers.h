#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <limits>
using namespace std;

class customer {
private:
    string first_name;
    string last_name;
    int account_num;
    string street_address;
    string city;
    string state;
    int zipcode;
    string phone_num;

public:
    // Default constructor
    customer() : account_num(0), zipcode(0) {}

    // Constructor to initialize customer data
    customer(string f_name, string l_name, int acc_num, string address, string c, string s, int zip, string phone)
        : first_name(f_name), last_name(l_name), account_num(acc_num), street_address(address), city(c), state(s), zipcode(zip), phone_num(phone) {}

    // Copy constructor
    customer(const customer &cst) {
        first_name = cst.first_name;
        last_name = cst.last_name;
        account_num = cst.account_num;
        street_address = cst.street_address;
        city = cst.city;
        state = cst.state;
        zipcode = cst.zipcode;
        phone_num = cst.phone_num;
    }

    // Overloaded assignment operator
    customer& operator=(const customer &cst) {
        if (this != &cst) {
            first_name = cst.first_name;
            last_name = cst.last_name;
            account_num = cst.account_num;
            street_address = cst.street_address;
            city = cst.city;
            state = cst.state;
            zipcode = cst.zipcode;
            phone_num = cst.phone_num;
        }
        return *this;
    }

    // Destructor
    ~customer() {}

    // Getter functions
    string getFirstName() const { return first_name; }
    string getLastName() const { return last_name; }
    int getAccountNum() const { return account_num; }
    string getStreetAddress() const { return street_address; }
    string getCity() const { return city; }
    string getState() const { return state; }
    int getZipcode() const { return zipcode; }
    string getPhoneNum() const { return phone_num; }

    // Setter functions
    void setFirstName(const string &fn) { first_name = fn; }
    void setLastName(const string &ln) { last_name = ln; }
    void setAccountNum(int acc) { account_num = acc; }
    void setStreetAddress(const string &addr) { street_address = addr; }
    void setCity(const string &c) { city = c; }
    void setState(const string &s) { state = s; }
    void setZipcode(int z) { zipcode = z; }
    void setPhoneNum(const string &ph) { phone_num = ph; }
};

class AllCustomers {
private:
    //vector of all customers
    vector<customer> customer_list;

    // Recursive function for adding multiple customers
    void addMultipleCustomersRecursive(int count);

public:
    //Normal default constructors and deconstructors no special input provided
    AllCustomers() {}
    ~AllCustomers() {}

    void printAllCustomers();
    void orderAndSort(bool ascending, int opt);
    void printSpecificCustomer(int account_num);

    void addNewCustomer(string first_name, string last_name, int account_num, string street_address, string city, string state, int zipcode, string phone_num);
    void addMultipleCustomers(int customer_amount);

    void updateAccountInformation(int account_num);
    void deleteCustomer(int account_num);

    void saveToFile(const string &filename);
    void loadCustomers(const string &filename);

    int getSize() const { return (int)customer_list.size(); }
    int findCustomerIndexByAccount(int account_num);

    // Getter for read-only access if needed
    const vector<customer>& getAllCustomers() const { return customer_list; }
};

#endif