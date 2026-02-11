#include <iostream>
using namespace std;

int main() {
    double celsius, fahrenheit;

    // Ask user for input
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    // Convert to Fahrenheit
    fahrenheit = (celsius * 1.8) + 32;

    // Output result
    cout << "Temperature in Fahrenheit: " << fahrenheit << endl;

    // Bonus conditions
    if (celsius < 0) {
        cout << "Freezing!" << endl;
    }
    else if (celsius > 30) {
        cout << "Hot!" << endl;
    }

    return 0;
}

