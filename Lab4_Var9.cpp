#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

struct CarOwner {
    string fullName;  
    string carBrand;  
    string carNumber; 
    int carPower;      


    CarOwner(string name, string brand, string number, int power)
        : fullName(name), carBrand(brand), carNumber(number), carPower(power) {}
};


void printOwnersList(const list<CarOwner>& owners) {
    for (const auto& owner : owners) {
        cout << "ПІБ: " << owner.fullName
             << ", Марка: " << owner.carBrand
             << ", Номер: " << owner.carNumber
             << ", Потужність: " << owner.carPower << " к.с." << endl;
    }
}

bool compareByPower(const CarOwner& a, const CarOwner& b) {
    return a.carPower < b.carPower;
}

int main() {

    list<CarOwner> owners = {
        CarOwner("Тарас", "Bentley", "ВР0001ВР", 150),
        CarOwner("Петро", "BMW", "ВС1010СВ", 200),
        CarOwner("Олег", "Mercedes", "AA2222AA", 180)
    };

    owners.sort(compareByPower);

    printOwnersList(owners);

    return 0;
}
