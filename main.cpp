#include <iostream>
using namespace std;

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double c) {
    return (c * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double f) {
    return (f - 32) * 5/9;
}

int main() {
    int choice;
    double temperature;

    cout << "===== Temperature Converter =====" << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "Choose option: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter temperature in Celsius: ";
        cin >> temperature;

        double result = celsiusToFahrenheit(temperature);
        cout << "Temperature in Fahrenheit: " << result << endl;
    }
    else if (choice == 2) {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> temperature;

        double result = fahrenheitToCelsius(temperature);
        cout << "Temperature in Celsius: " << result << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

