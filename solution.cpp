#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]) {
    string lineToAdd;
    string firstLine;
    vector<string> originalOrder;
    vector<string> desiredOrder;

    // Opens file
    string inputFileName = argv[1];
    ifstream f;
    f.open(inputFileName);

    getline(f, lineToAdd);

    // Add original to vector
    while (getline(f, lineToAdd)) {
        if (!lineToAdd.find("Desired: ")) {
            originalOrder.pop_back();
            break;
        }
        originalOrder.push_back(lineToAdd);
    }

    // Add desired to vector
    while (getline(f, lineToAdd)) {
        desiredOrder.push_back(lineToAdd);
    }

    cout << "Original vector\n";
    for (unsigned int i = 0; i < originalOrder.size(); ++i) {
        cout << i << ' ' << originalOrder[i] << '\n';
    }
    cout << '\n';
    cout << "Desired vector\n";
    for (unsigned int i = 0; i < desiredOrder.size(); ++i) {
        cout << i << ' ' << desiredOrder[i] << '\n';
    }
    cout << '\n';
    f.close();
}
