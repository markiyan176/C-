#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    // Структура для опису власника автомобіля
    struct CarOwner {
        string fullName;  
        string carBrand;  
        string carNumber; 
        int carPower;      

        CarOwner(string name, string brand, string number, int power)
            : fullName(name), carBrand(brand), carNumber(number), carPower(power) {}
    };

    // Створення списку власників автомобілів
    list<CarOwner> owners = {
        CarOwner("Тарас", "Bentley", "ВР0001ВР", 150),
        CarOwner("Петро", "BMW", "ВС1010СВ", 200),
        CarOwner("Олег", "Mercedes", "AA2222AA", 180)
    };

    // Сортування списку за потужністю автомобілів за допомогою бульбашкового сортування
    bool swapped;
    do {
        swapped = false;
        for (auto it1 = owners.begin(); it1 != owners.end(); ++it1) {
            auto it2 = it1;
            ++it2;
            if (it2 != owners.end() && it1->carPower > it2->carPower) {
                swap(*it1, *it2); // Обмін місцями
                swapped = true;    // Вказує, що був здійснений обмін
            }
        }
    } while (swapped); // Продовжує до тих пір, поки є обміни

    // Виведення відсортованого списку власників автомобілів
    for (const auto& owner : owners) {
        cout << "ПІБ: " << owner.fullName
             << ", Марка: " << owner.carBrand
             << ", Номер: " << owner.carNumber
             << ", Потужність: " << owner.carPower << " к.с." << endl;
    }

    return 0;
}
