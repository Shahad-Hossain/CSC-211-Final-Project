#ifndef PURCHASES_H
#define PURCHASES_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

class purchase {
private:
    int account_num;
    string item;
    string date;
    double amount;

public:
    purchase() : account_num(0), amount(0.0) {}
    purchase(int acc, const string &it, const string &d, double amt)
        : account_num(acc), item(it), date(d), amount(amt) {}

    // Getters
    int getAccountNum() const { return account_num; }
    string getItem() const { return item; }
    string getDate() const { return date; }
    double getAmount() const { return amount; }

    // Setters
    void setAccountNum(int acc) { account_num = acc; }
    void setItem(const string &it) { item = it; }
    void setDate(const string &d) { date = d; }
    void setAmount(double amt) { amount = amt; }
};

class AllPurchases {
private:
    //vector of all purchases the customer did
    vector<purchase> purchase_list;

    // Recursive function to add multiple purchases
    void addMultiplePurchasesRecursive(int count, int account_num);

public:
    //Default constructors and deconstructors
    AllPurchases() {}
    ~AllPurchases() {}

    void loadPurchases(const string &filename);
    void saveToFile(const string &filename);

    void addNewPurchase(int account_num, const string &item, const string &date, double amount);
    void addMultiplePurchases(int count, int account_num);

    void printPurchasesForCustomer(int account_num);
    double getTotalSpendForCustomer(int account_num);

    const vector<purchase>& getAllPurchases() const { return purchase_list; }
};

#endif