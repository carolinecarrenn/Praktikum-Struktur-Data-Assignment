#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Create a map object with string as key and int as value
    map<string, int> employeeAges;

    // Add entries to the map
    employeeAges["Alice"] = 25;
    employeeAges["Bob"] = 30;
    employeeAges["Charlie"] = 28;

    // Display the ages of employees
    cout << "Alice's age: " << employeeAges["Alice"] << " years" << endl;
    cout << "Bob's age: " << employeeAges["Bob"] << " years" << endl;
    cout << "Charlie's age: " << employeeAges["Charlie"] << " years" << endl;

    // Use an iterator to print the entire map
    cout << "\nPrinting the entire map:\n";
    for (auto it = employeeAges.begin(); it != employeeAges.end(); ++it) {
        cout << "Name: " << it->first << ", Age: " << it->second << " years" << endl;
    }

    return 0;
}
