#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Car {
    string owner;
    string plate;
    int hours;
};

vector<Car> cars;

void addCar() {
    Car c;
    cout << "Enter owner name: ";
    getline(cin, c.owner);
    cout << "Enter plate number: ";
    getline(cin, c.plate);
    cout << "Enter hours (1-8): ";
    cin >> c.hours;
    cin.ignore();

    if(c.owner.empty() || c.plate.empty() || c.hours < 1 || c.hours > 8) {
        cout << "Invalid input. Try again." << endl;
        return;
    }
    cars.push_back(c);
    cout << "Car added!" << endl;
}

void showCars() {
    if(cars.empty()) {
        cout << "No cars parked." << endl;
        return;
    }
    for(int i = 0; i < cars.size(); i++) {
        cout << i+1 << ". Owner: " << cars[i].owner 
             << ", Plate: " << cars[i].plate 
             << ", Hours: " << cars[i].hours << endl;
    }
}

int main() {
    int choice;
    while(true) {
        cout << "\n1. Add Car\n2. Show Cars\n3. Exit\nChoose: ";
        cin >> choice;
        cin.ignore();
        if(choice == 1) addCar();
        else if(choice == 2) showCars();
        else if(choice == 3) break;
        else cout << "Wrong choice." << endl;
    }
    return 0;
}