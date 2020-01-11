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
