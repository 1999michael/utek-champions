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
    f.open(inputFileName.c_str());

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
    f.close();

    // cout << "Original vector\n";
    // for (unsigned int i = 0; i < originalOrder.size(); ++i) {
    //     cout << i << ' ' << originalOrder[i] << '\n';
    // }
    // cout << '\n';
    // cout << "Desired vector\n";
    // for (unsigned int i = 0; i < desiredOrder.size(); ++i) {
    //     cout << i << ' ' << desiredOrder[i] << '\n';
    // }
    // cout << '\n';

    vector<vector<int>> dp(originalOrder.size()+1, vector<int>(desiredOrder.size()+1));
    dp[0][0] = 0;
    for(int i = 0; i < originalWord.size(); ++ i)
        dp[i+1][0] = i+1;
    for(int i = 0; i < desiredWord.size(); ++ i)
        dp[0][i+1] = i+1;
        
    for(int i = 0; i < originalWord.size(); ++ i){
        for(int j = 0; j < desiredWord.size(); ++ j){
            if(originalWord[i] == desiredWord[j]){
                dp[i+1][j+1] = dp[i][j];
            }
            else{
                dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j])) + 1;
            }
        }
    }

    for (int i = 0; i < desiredWord.size()+1; ++i) {
        for (int j = 0; j < originalWord.size()+1; ++j) {
            if (dp[j][i] < 10) {
                cout << ' ';
            }
            if (dp[j][i] < 100) {
                cout << ' ';
            }
            if (dp[j][i] < 1000) {
                cout << ' ';
            }
            cout << dp[j][i] << ' ';
        }
        cout << '\n';
    }
}
