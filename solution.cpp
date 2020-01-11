#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
    dp[0][0] = 0;
    for(int i = 0; i < word1.size(); ++ i)
        dp[i+1][0] = i+1;
    for(int i = 0; i < word2.size(); ++ i)
        dp[0][i+1] = i+1;
    
    for(int i = 0; i < word1.size(); ++ i){
        for(int j = 0; j < word2.size(); ++ j){
            if(word1[i] == word2[j]){
                dp[i+1][j+1] = dp[i][j];
            }
            else{
                dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j])) + 1;
            }
        }
    }
    return dp.back().back();
}

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