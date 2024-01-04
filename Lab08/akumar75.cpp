#include <iostream>
#include <climits>
#include <vector>

using namespace std;

//Recursive function for printing parentheses for matrix chain multiplication
void bestParens(vector<vector<int>>& parens, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        //Uses 2D vector with variables inside the [] as parameters
        bestParens(parens, i, parens[i][j]);
        bestParens(parens, parens[i][j] + 1, j);
        cout << ")";
    }
}

//Calculates minimum number of scalar multiplications for matrix chain multiplication
//Vector represents dimensions of matrices as input
void matrixChainMult(vector<int>& dimens) {
    //Number of matrices
    int n = dimens.size() - 1;
    //Vector for storing minimum number of scalar multiplications needed for subproblems
    vector<vector<int>> scalarMult(n, vector<int>(n, 0));
    //Stores the optimal break points for subproblems
    vector<vector<int>> parens(n, vector<int>(n, 0));
    //Goes through all chain lengths, starts from 2 since minimum chain length can be multiplied is 2
    for (int len = 2; len <= n; ++len) {
        //Goes through all possible starting matrix indices for given chain length
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            scalarMult[i][j] = INT_MAX;
            //Iterates over all posible break points in subchain and calculates minimum cost
            for (int k = i; k < j; ++k) {
                //Minimum cost of multiplying matrices in those combinations
                int cost = scalarMult[i][k] + scalarMult[k + 1][j] + dimens[i] * dimens[k + 1] * dimens[j + 1];
                //Calculates total cost of multiplying matrices
                //Updates minimum cost and the current break point where minimum cost is achieved
                if (cost < scalarMult[i][j]) {
                    scalarMult[i][j] = cost;
                    parens[i][j] = k;
                }
            }
        }
    }
    //Multiplies all matrices from index 0 to n-1
    cout << scalarMult[0][n - 1] << endl;
    //Called to print optimal placement of parentheses based on bracket table
    bestParens(parens, 0, n - 1);
    //For clean output
    cout << endl;
}

int main() {
    int n;
    //Input for number of matrices
    cin >> n;
    vector<int> dimens(n + 1);
    //Input for dimensions for size of vector
    for (int i = 0; i <= n; ++i) {
        cin >> dimens[i];
    }
    //Calculates and prints minimum number of scalar multiplications
    //& optimal placement of parentheses for matrix chain multiplication
    matrixChainMult(dimens);

    return 0;
}
