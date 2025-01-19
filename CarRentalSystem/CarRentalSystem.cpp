#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Car {
    string Company;
    string Model;
    string Color;
    string MaxSpeed;
    string FuelType;
    string Manufacturer;
    string Price;
};

vector<Car> cars = {
    {"Honda", "City", "Red", "180", "Petrol", "Japan", "300"},
    {"Honda", "Civic", "Blue", "190", "Petrol", "Japan", "400"},
    {"Toyota", "Camry", "Black", "200", "Petrol", "Japan", "500"},
    {"Toyota", "Innova", "White", "210", "Diesel", "Japan", "600"},
    {"Hyundai", "Sonata", "Silver", "220", "Petrol", "Korea", "700"},
    {"Hyundai", "Elantra", "Gold", "230", "Petrol", "Korea", "800"},
    {"Volkswagen", "Passat", "Red", "240", "Diesel", "Germany", "900"},
    {"Volkswagen", "Golf", "Blue", "250", "Petrol", "Germany", "1000"},
    {"BMW", "5 Series", "Black", "260", "Petrol", "Germany", "1200"},
    {"BMW", "iX", "White", "270", "Electric", "Germany", "1500"},
    {"Mercedes Benz", "A 200", "Silver", "280", "Petrol", "Germany", "1100"},
    {"Mercedes Benz", "S 580", "Gold", "290", "Petrol", "Germany", "1800"}
};

void menu() {
    cout << "\t\t Choose your option:" << endl;
    cout << endl;
    cout << "\t\t 1. Honda" << endl;
    cout << "\t\t 2. Toyota" << endl;
    cout << "\t\t 3. Hyundai" << endl;
    cout << "\t\t 4. Volkswagen" << endl;
    cout << "\t\t 5. BMW" << endl;
    cout << "\t\t 6. Mercedes Benz" << endl;
    cout << endl;
}

void displayModels(const string& company) {
    cout << "\t\t Available Models for " << company << ":" << endl;
    for (const Car& car : cars) {
        if (car.Company == company) {
            cout << "\t\t- " << car.Model << endl;
        }
    }
}

bool login() {
    string username, password;

    cout << "\t\t Vishan's Car Rental System login" << endl;
    cout << "\t\t Username: ";
    getline(cin, username);
    cout << "\t\t Password: ";
    getline(cin, password);
    cout << endl;

    
    if (username == "admin" && password == "password") {
        cout << "\t\t Login successful." << endl;
        cout << endl;
        return true;
    }
    else {
        cout << "\t\t Invalid credentials. Please try again." << endl;
        cout << endl;
        return false;
    }
}

int main() {

    if (!login()) {
        return 1; // Exit if login fails
    }

    string decide = "yes";
    string decision;

    cout << "\t\t -------------------------------------" << endl;
    cout << "\t\t Welcome to Vishan's Car Rental System" << endl;
    cout << "\t\t -------------------------------------" << endl;
    cout << endl;
    while (decide != "exit") {

        menu();

        cout << "\t\t Your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Clear newline character
        cout << endl;

        string selectedCompany;
        switch (choice) {
        case 1:
            selectedCompany = "Honda";
            break;
        case 2:
            selectedCompany = "Toyota";
            break;
        case 3:
            selectedCompany = "Hyundai";
            break;
        case 4:
            selectedCompany = "Volkswagen";
            break;
        case 5:
            selectedCompany = "BMW";
            break;
        case 6:
            selectedCompany = "Mercedes Benz";
            break;
        default:
            cout << "\t\t Invalid choice. Please try again." << endl;
            continue; // Skip the rest of the loop iteration
        }

        displayModels(selectedCompany);
        cout << endl;

        cout << "\t\t Enter the model you want to rent: ";
        string selectedModel;
        getline(cin, selectedModel);
        cout << endl;

        cout << "\t\t Are you sure you want rent: " << selectedCompany << " " << selectedModel << " ?  (yes/no)" << endl;
        cout << "\t\t ";
        getline(cin, decision);
        cout << endl;

        if (decision == "yes" || decision == "Yes" || decision == "YES") {
            bool carFound = false;
            for (const Car& car : cars) {
                if (car.Company == selectedCompany && car.Model == selectedModel) {
                    cout << "\t\t ------------------------" << endl;
                    cout << "\t\t Car rented successfully!" << endl;
                    cout << "\t\t ------------------------" << endl;
                    cout << endl;
                    cout << "\t\t Company: ----------- " << car.Company << endl;
                    cout << "\t\t Model: ------------- " << car.Model << endl;
                    cout << "\t\t Color: ------------- " << car.Color << endl;
                    cout << "\t\t Max Speed: --------- " << car.MaxSpeed << endl;
                    cout << "\t\t Fuel Type: --------- " << car.FuelType << endl;
                    cout << "\t\t Manufacturer: ------ " << car.Manufacturer << endl;
                    cout << "\t\t Price: ------------- RM " << car.Price << endl;
                    cout << endl;
                    cout << "\t\t ---------------------------------" << endl;
                    cout << "\t\t Thank you for renting with Vishan" << endl;
                    cout << "\t\t ---------------------------------" << endl;
                    carFound = true;
                    break;
                }
            }

            if (!carFound) {
                cout << "\t\t Car not found." << endl;
            }

            cout << "\t\t Do you want to rent another car? (yes/no/exit)" << endl;
            cout << "\t\t ";
            getline(cin, decide);
            cout << endl;

            if (decide == "no" || decide == "No" || decide == "NO") {
                cout << "\t\t ---------------------------------" << endl;
                cout << "\t\t     Thank you for visiting us" << endl;
                cout << "\t\t ---------------------------------" << endl;
                break;
            }
        }
        else if (decision == "no" || decision == "No" || decision == "NO") {
            cout << "\t\t ---------------------------------" << endl;
            cout << "\t\t     Thank you for visiting us" << endl;
            cout << "\t\t ---------------------------------" << endl;
            break;
        }
    }

    return 0;
}

