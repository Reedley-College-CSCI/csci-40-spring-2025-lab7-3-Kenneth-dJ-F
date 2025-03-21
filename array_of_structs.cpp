
//Kenneth Flores

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
struct TemperatureRecord {
    int day;
    int temperature;
 
};


// Constants
const int MAX_DAYS = 31;


// Function Prototypes
void readTemperatures(TemperatureRecord tempDay [], int& size); // TODO: Fix the parameters
void printTemperatures(const TemperatureRecord tempDay[], int size);
//TemperatureRecord findMin(const ???);
//TemperatureRecord findMax(const ???);
double findAverage(const TemperatureRecord tempDay[], int size);

int main() {
    double average;
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)

   TemperatureRecord temp_per_day[MAX_DAYS];
    
    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(temp_per_day, size);
    
    // TODO: Step 4 - Print the temperatures
    printTemperatures(temp_per_day, size);

    // TODO: Step 5 - Compute and display min, max, and average temperature
    average = findAverage(temp_per_day, size);

    cout << "\nAverage Temperature is "
        << fixed << setprecision(2) << average << endl;

    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(TemperatureRecord tempDay[], int& size) {
    fstream tempFS;
    tempFS.open("temps.txt");

    if (!tempFS) {
        cout << "Error openning file\n";
        return;
    }

    while (size < 31 && tempFS >> tempDay[size].day >> tempDay[size].temperature) {
        size++;

    }

    tempFS.close();
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(const TemperatureRecord tempDay[], int size) {
    
    cout << "Day   Temp\n";

    for (int i = 0; i < size; ++i) {
        cout << tempDay[i].day << setw(7) << tempDay[i].temperature << endl;
    }

}

// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature

// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
double findAverage(const TemperatureRecord tempDay[], int size) {
    double avg;
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += tempDay[i].temperature;
    }
    
    avg = sum / static_cast<double>(size);

    return avg;

}
