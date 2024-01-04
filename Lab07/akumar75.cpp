#include <iostream>
#include <vector>

using namespace std;

//Defines Rod-Cutting, returns integer of maximum revenue and vector of integers with optimal cuts
pair<int, vector<int>> rodCutting(int n, vector<int>& price) {
    //Creates vector to store maximum revenue
    vector<int> mr(n + 1, 0);
    //Stores length of first piece in optimal solution for length of i
    vector<int> cuts(n + 1, -1);
    //Does possible rod lengths
    for (int i = 1; i <= n; ++i) {
        //Initializes variable to store maximum revenue obtainable for current rod length i
        int maxRev = -1;
        for (int j = 1; j <= i; ++j) {
            //Checks if revenue obtained by cutting rod into pieces if length 'j' and 'i-j' is greater than current maxRevenue
            if (maxRev < price[j] + mr[i - j]) {
                //Updates to new maximum revenue
                maxRev = price[j] + mr[i - j];
                //Updates cuts[i] with length of first place in optimal solution for rod length i
                cuts[i] = j;
            }
        }
        //Stores calculated maximum revenue for rod of length i in dp array
        mr[i] = maxRev;
    }

    // Reconstruct the solution
    vector<int> piece;
    //Backtracks through cuts array for lengths of pieces of optimal solution
    //While loop traces back cuts and stores pieces in pieces vector
    while (n > 0) {
        piece.push_back(cuts[n]);
        n -= cuts[n];
    }
    //Returns pair containing maximum revenue and vector of piece lengths
    return make_pair(mr[mr.size() - 1], piece);
}

int main() {
    int n;
    //First input
    cin >> n;
    //Declares vector 'prices' of size 'n+1' to store prices of different rod lengths
    vector<int> price(n + 1);
    //Reads prices of rod lengths from 1 to 'n' from standard input and stores in prices vector
    for (int i = 1; i <= n; ++i) {
        cin >> price[i];
    }
    //Calls rodCutting function with input values n and prices and stores result
    pair<int, vector<int>> result = rodCutting(n, price);

    // Output maximum revenue
    cout << result.first << endl;

    // Output the pieces
    for (int i = 0; i < result.second.size(); ++i) {
        cout << result.second[i];
        if (i < result.second.size() - 1) {
            cout << " ";
        }
    }
    cout << " -1" << endl;

    return 0;
}
