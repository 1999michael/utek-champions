#include <vector> 
using namespace std;

int main(string word1, string word2) {
    vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
    vector<vector<int>> results; 
    vector<int> operation; 
    vector<int> reference;
    // vector results; 
    int mini; 
    reference = {0,0,0};
    dp[0][0] = 0;
    //initializing the first row and col 
    for(int i = 0; i < word1.size(); ++ i) //original
        dp[i+1][0] = i+1;
    for(int i = 0; i < word2.size(); ++ i)
        dp[0][i+1] = i+1;
    
    for(int i = 0; i < word1.size(); ++ i){
        for(int j = 0; j < word2.size(); ++ j){
            if(word1[i] == word2[j]){ //same letter 
                dp[i+1][j+1] = dp[i][j]; //copy the diagonal, NO OPERATION 
            }
            else{
                dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j])) + 1;
            }
        }
    }
    //back tracking 
    int i = word1.size(); 
    int j = word2.size();
    while ((i != 0) && (j != 0)){
        if (dp[i][j] == dp[i-1][j-1]){
            // operation = make_tuple(3,i-1,j-1) ; 
            operation = {3,i-1,j-1} ; 
        } //No operation == 3
        else {
            mini = min(dp[i-1][j-1], (dp[i][j-1], dp[i-1][j]));
            if (dp[i-1][j-1] == mini){ //from diag, REPLACE == 0
                operation = {0,i-1,j-1};}
            if (dp[i][j-1] == mini){ //from up, DELETE == 1
                if (((operation != reference) && (operation[0] != results[results.size()-1][0])) || (operation == reference)){ // if more than one min 
                    operation = {1,i,j-1};
                }
            }
            if (dp[i-1][j] == mini){ //from left, INSERT == 2
                if (((operation != reference) && (operation[0] != results[results.size()-1][0])) || (operation == reference)) { // if more than one min 
                    operation = {2,i-1,j};;
                }
            }
            //30303
        }
        cout << operation[0] << operation[1] << operation[2] << '\n'; 
        results.push_back(operation);
        i = operation[1];
        j = operation[2];
        operation = reference;
    }
    // return results
    return dp.back().back();
}

