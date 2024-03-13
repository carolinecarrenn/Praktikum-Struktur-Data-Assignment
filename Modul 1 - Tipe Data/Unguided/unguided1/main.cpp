#include <iostream>

using namespace std;

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    const double PI = 3.14159265358979323846;
    return PI * radius * radius;
}

// Function to check if a number is even or odd
bool isEven(int number) {
    return number % 2 == 0;
}

int main() {
    // Variables
    char initial = 'C';
    int age = 18;
    double height = 1.75, circleRadius = 5.5;
    bool isStudent = true;

    // Display initial
    cout << "Initial: " << initial << endl;

    // Display age
    cout << "Age: " << age << endl;

    // Display height
    cout << "Height: " << height << endl;

    // Display circle area
    cout << "Circle area: " << calculateCircleArea(circleRadius) << endl;

    // Display if student or not
    if (isStudent) {
        cout << "Is a student" << endl;
    } else {
        cout << "Is not a student" << endl;
    }

    // Display if age is even or odd
    if (isEven(age)) {
        cout << "Age is even" << endl;
    } else {
        cout << "Age is odd" << endl;
    }

    return 0;
}
