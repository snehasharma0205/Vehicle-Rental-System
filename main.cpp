#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

// Base class: stores information common to every vehicle.
class Vehicle {
protected:
    int vehicleID;
    string model;
    double rentalRate; // rental rate per day

public:
    Vehicle(int id, const string& name, double rate)
        : vehicleID(id), model(name), rentalRate(rate) {}

    virtual double calculateRent(int days) const {
        return rentalRate * days;
    }

    virtual string getVehicleType() const {
        return "Vehicle";
    }

    virtual void displayDetails() const {
        cout << "Vehicle type : " << getVehicleType() << '\n';
        cout << "Vehicle ID   : " << vehicleID << '\n';
        cout << "Model        : " << model << '\n';
        cout << "Rate per day : Rs. " << fixed << setprecision(2) << rentalRate << '\n';
    }

    virtual ~Vehicle() = default;
};

// Derived class: Car has an additional fixed insurance charge.
class Car : public Vehicle {
private:
    double insuranceCharge;

public:
    Car(int id, const string& name, double rate)
        : Vehicle(id, name, rate), insuranceCharge(200.0) {}

    double calculateRent(int days) const override {
        return (rentalRate * days) + insuranceCharge;
    }

    string getVehicleType() const override {
        return "Car";
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Insurance    : Rs. " << insuranceCharge << '\n';
    }
};

// Derived class: Bike is charged only by the number of rental days.
class Bike : public Vehicle {
public:
    Bike(int id, const string& name, double rate)
        : Vehicle(id, name, rate) {}

    double calculateRent(int days) const override {
        return rentalRate * days;
    }

    string getVehicleType() const override {
        return "Bike";
    }
};

int readPositiveInteger(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            return value;
        }

        cout << "Invalid input. Please enter a positive whole number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    cout << "=====================================\n";
    cout << "       VEHICLE RENTAL SYSTEM\n";
    cout << "=====================================\n";

    bool running = true;

    while (running) {
        cout << "\nChoose a vehicle:\n";
        cout << "1. Car\n";
        cout << "2. Bike\n";
        cout << "3. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter 1, 2, or 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 3) {
            running = false;
            cout << "\nThank you for using the Vehicle Rental System!\n";
            continue;
        }

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please select 1, 2, or 3.\n";
            continue;
        }

        int id = readPositiveInteger("Enter vehicle ID (positive number): ");

        string model;
        cout << "Enter vehicle model (one word, e.g. Swift or Activa): ";
        cin >> model;

        double rate;
        if (choice == 1) {
            rate = 1500.0;
        } else {
            rate = 500.0;
        }

        int days = readPositiveInteger("Enter rental duration in days: ");

        // Base-class pointer demonstrates runtime polymorphism.
        Vehicle* rentedVehicle = nullptr;
        if (choice == 1) {
            rentedVehicle = new Car(id, model, rate);
        } else {
            rentedVehicle = new Bike(id, model, rate);
        }

        cout << "\n----------- RENTAL RECEIPT -----------\n";
        rentedVehicle->displayDetails();
        cout << "Duration     : " << days << " day(s)\n";
        cout << "Total charges: Rs. "
             << fixed << setprecision(2)
             << rentedVehicle->calculateRent(days) << '\n';
        cout << "--------------------------------------\n";

        delete rentedVehicle;
        rentedVehicle = nullptr;
    }

    return 0;
}
