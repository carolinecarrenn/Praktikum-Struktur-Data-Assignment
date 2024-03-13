#include <iostream>
#include <string>

using namespace std;

// Struct to represent an address
struct Address {
    string street;
    string city;
    string state;
    string zipCode;
};

// Class to represent a person
class Person {
public:
    // Member data
    string name;
    int age;
    Address address;

    // Member function to display information
    void displayInfo() {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Address: " << address.street << ", " << address.city << ", "
             << address.state << " " << address.zipCode << "\n";
    }
};

int main() {
    // Create a Person object
    Person person;

    // Set the member data of the Person object
    person.name = "Na Jae-min";
    person.age = 24;
    person.address.street = "423,Apgujjeong-ro, Gangnam-gu";
    person.address.city = "Seoul";
    person.address.state = "NJ";
    person.address.zipCode = "130700";

    // Call the method to display information
    person.displayInfo();

    return 0;
}
