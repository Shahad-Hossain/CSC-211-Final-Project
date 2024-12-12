#include "AllPurchases.h"

void AllPurchases::loadPurchases(const string &filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Could not open " << filename << " for reading purchases.\n";
        return;
    }

    purchase_list.clear();
    bool isHeader = true;
    string line;
    while (getline(inFile, line)) {
        if (isHeader) {
            isHeader = false;
            continue;
        }
        stringstream ss(line);
        int acc;
        string it, d;
        double amt;

        ss >> acc;
        ss.ignore();
        getline(ss, it, ',');
        getline(ss, d, ',');
        ss >> amt;

        purchase_list.push_back(purchase(acc, it, d, amt));
    }

    inFile.close();
    cout << "Purchase data loaded from " << filename << endl;
}

void AllPurchases::saveToFile(const string &filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Could not open " << filename << " for writing purchases.\n";
        return;
    }

    // Write header
    outFile << "AccountNum,Item,Date,Amount\n";
    for (auto &p : purchase_list) {
        outFile << p.getAccountNum() << ","
                << p.getItem() << ","
                << p.getDate() << ","
                << p.getAmount() << "\n";
    }

    outFile.close();
    cout << "Purchase data saved to " << filename << endl;
}

void AllPurchases::addNewPurchase(int account_num, const string &item, const string &date, double amount) {
    purchase_list.push_back(purchase(account_num, item, date, amount));
    cout << "Purchase added successfully.\n";
}

void AllPurchases::addMultiplePurchasesRecursive(int count, int account_num) {
    if (count <= 0) return;
    string it, d;
    double amt;
    cout << "Enter item name: ";
    getline(cin, it);
    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, d);
    cout << "Enter amount: ";
    cin >> amt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    addNewPurchase(account_num, it, d, amt);

    addMultiplePurchasesRecursive(count - 1, account_num);
}

void AllPurchases::addMultiplePurchases(int count, int account_num) {
    addMultiplePurchasesRecursive(count, account_num);
}

void AllPurchases::printPurchasesForCustomer(int account_num) {
    cout << "Purchases for account #" << account_num << ":\n";
    cout << left << setw(20) << "Item" << setw(15) << "Date" << setw(10) << "Amount" << "\n";
    cout << string(50, '-') << "\n";

    bool found = false;
    for (auto &p : purchase_list) {
        if (p.getAccountNum() == account_num) {
            found = true;
            cout << left << setw(20) << p.getItem() << setw(15) << p.getDate() << setw(10) << p.getAmount() << "\n";
        }
    }
    if (!found) {
        cout << "No purchases found for this account.\n";
    }
}

double AllPurchases::getTotalSpendForCustomer(int account_num) {
    double total = 0.0;
    for (auto &purchase : purchase_list) {
        if (purchase.getAccountNum() == account_num) {
            total += purchase.getAmount();
        }
    }
    return total;
}