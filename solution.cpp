#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]) {
    string lineToAdd;
    string firstLine;

    // Opens file
    string inputFileName = argv[1];
    ifstream f;
    f.open(inputFileName);

    // Getting size of original
    (getline(f, firstLine));
    firstLine.erase(0, 10);
    int originalSize = stoi(firstLine, nullptr);

    // Add original to array
    string originalOrder[originalSize];
    int counter = 0;
    while (getline(f, lineToAdd)) {
        if (!lineToAdd.find("Desired: ")) {
            break;
        }
        originalOrder[counter] = lineToAdd;
        ++counter;
    }

    // Getting size of desired
    lineToAdd.erase(0, 9);
    int desiredSize = stoi(lineToAdd, nullptr);

    // Add desired to array
    string desiredOrder[desiredSize];
    counter = 0;
    while (getline(f, lineToAdd)) {
        desiredOrder[counter] = lineToAdd;
        ++counter;
    }

    cout << "Original array\n";
    for (int i = 0; i < originalSize; ++i) {
        cout << originalOrder[i] << '\n';
    }
    cout << '\n';
    cout << "Desired array\n";
    for (int i = 0; i < desiredSize; ++i) {
        cout << desiredOrder[i] << '\n';
    }
    cout << '\n';
    f.close();
}