#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <iomanip>
#include <string>
#include <algorithm>

class Vehicle {
private:
    std::string make, model;
    int year;
    double price;

public:
    void setMake(const std::string& make) {
        this->make = make;
    }

    void setModel(const std::string& model) {
        this->model = model;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setPrice(double price) {
        this->price = price;
    }

    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    double getPrice() const {
        return price;
    }

    virtual float calculateTax() const {
        return 1.0; // Default tax calculation for base class
    }

    virtual ~Vehicle() = default; // Virtual destructor for polymorphic behavior

    void displayDetails() const {
        std::cout << "Make: " << make
                  << "\nModel: " << model
                  << "\nYear:  " << year
                  << "\nPrice: " << std::fixed << std::setprecision(2) << price << std::endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    void setNumDoors(int numDoors) {
        this->numDoors = numDoors;
    }

    int getNumDoors() const {
        return numDoors;
    }

    float calculateTax() const override {
        return 0.10 * getPrice(); // 10% tax for cars
    }
};

class Truck : public Vehicle {
private:
    int payload;
    int towingCapacity;

public:
    void setPayload(int payload) {
        this->payload = payload;
    }

    int getPayload() const {
        return payload;
    }

    void setTowingCapacity(int towingCapacity) {
        this->towingCapacity = towingCapacity;
    }

    float calculateTax() const override {
        return 0.12 * getPrice(); // 12% tax for trucks
    }
};

int main() {
    std::vector<std::unique_ptr<Vehicle>> vehicles(100);

    while (true) {
        std::cout << "\n----------------------------------------------\n";
        std::cout << "Welcome to the Vehicle management system!\n\n";
        std::cout << "Menu:\n";
        std::cout << "1. Add Vehicle \n"
                  << "2. Remove Vehicle\n"
                  << "3. Search for Vehicle\n"
                  << "4. Exit\n";

        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter vehicle type (car/truck): ";
                std::string vehicle_type;
                std::cin >> vehicle_type;

                std::cout << "Enter vehicle make: ";
                std::string make;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
                std::getline(std::cin, make);

                std::cout << "Enter vehicle model: ";
                std::string model;
                std::getline(std::cin, model);

                std::cout << "Enter vehicle year: ";
                int year;
                std::cin >> year;

                std::cout << "Enter vehicle price: ";
                double price;
                std::cin >> price;

                if (vehicle_type == "car") {
                    auto car = std::make_unique<Car>();
                    car->setNumDoors(4); // Assuming default number of doors for simplicity
                    car->setMake(make);
                    car->setModel(model);
                    car->setYear(year);
                    car->setPrice(price);
                    vehicles.push_back(std::move(car));
                    std::cout << "Car added to fleet\n";
                } else if (vehicle_type == "truck") {
                    auto truck = std::make_unique<Truck>();
                    truck->setPayload(1000); // Assuming default payload for simplicity
                    truck->setTowingCapacity(5000); // Assuming default towing capacity for simplicity
                    truck->setMake(make);
                    truck->setModel(model);
                    truck->setYear(year);
                    truck->setPrice(price);
                    vehicles.push_back(std::move(truck));
                    std::cout << "Truck added to fleet\n";
                } else {
                    std::cout << "Invalid vehicle type. Please enter 'car' or 'truck'.\n";
                }
                break;
            }

            case 2: {
                std::cout << "Enter vehicle make: ";
                std::string make;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
                std::getline(std::cin, make);

                std::cout << "Enter vehicle model: ";
                std::string model;
                std::getline(std::cin, model);

                auto it = std::remove_if(vehicles.begin(), vehicles.end(), [&make, &model](const auto& vehicle) {
                    return vehicle->getMake() == make && vehicle->getModel() == model;
                });

                if (it != vehicles.end()) {
                    vehicles.erase(it, vehicles.end());
                    std::cout << "Vehicle removed from fleet\n";
                } else {
                    std::cout << "Vehicle not found!\n";
                }
                break;
            }

            case 3: {
                std::cout << "Enter vehicle make: ";
                std::string make;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
                std::getline(std::cin, make);

                std::cout << "Enter vehicle model: ";
                std::string model;
                std::getline(std::cin, model);

                auto it = std::find_if(vehicles.begin(), vehicles.end(), [&make, &model](const auto& vehicle) {
                    return vehicle->getMake() == make && vehicle->getModel() == model;
                });

                if (it != vehicles.end()) {
                    std::cout << "Vehicle Information:\n";
                    (*it)->displayDetails();
                } else {
                    std::cout << "Vehicle not found!\n";
                }
                break;
            }

            case 4:
                std::cout << "Thank you for using the Vehicle management system\n";
                return 0;

            default:
                std::cout << "Error! Please enter a valid choice\n";
                break;
        }
    }

    return 0;
}
