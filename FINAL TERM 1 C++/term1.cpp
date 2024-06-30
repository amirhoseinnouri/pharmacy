#include <iostream>
#include <vector>
using namespace std;

struct Drug {
string name;
string manufacturer;
double price;
string expirationDate;
int quantity;
vector<string> conflictingDrugs; 
};

vector<Drug> drugs;

void addNewDrug() {
Drug newDrug;
cout << "Enter drug name: ";
cin >> newDrug.name;
cout << "Enter manufacturer name: ";
cin >> newDrug.manufacturer;
cout << "Enter price: ";
cin >> newDrug.price;
cout << "Enter expiration date: ";
cin >> newDrug.expirationDate;
cout << "Enter quantity: ";
cin >> newDrug.quantity;

cout << "Enter conflicting drugs (enter 'q' to finish):\n";
string conflictingDrug;
while (true) {
cin >> conflictingDrug;
if (conflictingDrug == "q") {
break;
}
newDrug.conflictingDrugs.push_back(conflictingDrug);
}

drugs.push_back(newDrug);
}

void editDrug() {
string drugName;
cout << "Enter the name of the drug you want to edit: ";
cin >> drugName;

for (auto & drug : drugs) {
if (drug.name == drugName) {
cout << "Enter new quantity: ";
cin >> drug.quantity;
cout << "Drug information updated successfully.\n";
return;
}
}

cout << "Drug not found.\n";
}

void sellDrug() {
string drugName;
cout << "Enter the name of the drug you want to sell: ";
cin >> drugName;

for (auto & drug : drugs) {
if (drug.name == drugName) {
int quantity;
cout << "Enter the quantity to sell: ";
cin >> quantity;

if (quantity > 0 && quantity <= drug.quantity) {
drug.quantity -= quantity;
cout << "darim . : " << drug.quantity << endl;
} else {
cout << "nadarim . \n";
}

return;
}
}

cout << "Drug not found.\n";
}

void deleteDrug() {
string drugName;
cout << " Enter the name of the drug you want to delete: ";
cin >> drugName;

for (auto it = drugs.begin(); it != drugs.end(); ++it) {
if (it->name == drugName) {
drugs.erase(it);
cout << "Drug deleted successfully.\n";
return;
}
}
cout << "Drug not found.\n";
}

void listExpiringDrugs() {
cout << "Expiring drugs within one week:" << endl;
for (const auto & drug : drugs) {
cout << drug.name << " (Quantity: " << drug.quantity << ")" << endl;
}
}

void searchDrug() {
string searchTerm;
cout << "Enter the name of the drug you want to search: ";
cin >> searchTerm;

for (const auto& drug : drugs) {
if (drug.name == searchTerm) {
cout << "Drug found:" << endl;
cout << "Name: " << drug.name << endl;
cout << "Manufacturer: " << drug.manufacturer << endl;
cout << "Price: " << drug.price << endl;
cout << "Expiration Date: " << drug.expirationDate << endl;
cout << "Quantity: " << drug.quantity << endl;
return;
}
}

cout << "Drug not found.\n";
}

int main() {
while (true) {
cout << "1 =)  Add new Drug\n";
cout << "2 =)  Edit Drug\n";
cout << "3 =)  Sell Drug\n";
cout << "4 =)  List Expiring Drugs\n";
cout << "5 =)  Search Drug\n";
cout << "6 =)  deleteDrug\n";
cout << "7 =)  Exit\n";

int choice;
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case 1:
addNewDrug();
break;
case 2:
editDrug();
break;
case 3:
sellDrug();
break;
case 4:
listExpiringDrugs();
break;
case 5:
searchDrug();
break;
case 6:
deleteDrug();
break;
case 7:
cout << "Exiting program.\n";
return 0;
default:
cout << "Please try again.\n";
}
}

return 0;
}
