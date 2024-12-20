#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    struct CarOwner {
        string fullName;  
        string carBrand;  
        string carNumber; 
        int carPower;      

        CarOwner(string name, string brand, string number, int power)
            : fullName(name), carBrand(brand), carNumber(number), carPower(power) {}
    };

   
    list<CarOwner> owners = {
        CarOwner("Тарас", "Bentley", "ВР0001ВР", 150),
        CarOwner("Петро", "BMW", "ВС1010СВ", 200),
        CarOwner("Олег", "Mercedes", "AA2222AA", 180)
    };

    
    bool swapped;
    do {
        swapped = false;
        for (auto it1 = owners.begin(); it1 != owners.end(); ++it1) {
            auto it2 = it1;
            ++it2;
            if (it2 != owners.end() && it1->carPower > it2->carPower) {
                swap(*it1, *it2); 
                swapped = true;    
            }
        }
    } while (swapped);


    for (const auto& owner : owners) {
        cout << "ПІБ: " << owner.fullName
             << ", Марка: " << owner.carBrand
             << ", Номер: " << owner.carNumber
             << ", Потужність: " << owner.carPower << " к.с." << endl;
    }

    return 0;
}
