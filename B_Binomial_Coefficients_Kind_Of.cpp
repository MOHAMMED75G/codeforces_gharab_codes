#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

// Maximum value for `n` and `k` constraints
const int MAX_N = 100005;

vector<vector<int>> C(MAX_N, vector<int>(MAX_N, 0));

// Function to precompute binomial coefficients using the wrong formula
void precompute() {
    for (int n = 0; n < MAX_N; ++n) {
        C[n][0] = 1;  // C(n, 0) = 1
        if (n > 0) {
            C[n][n] = 1;  // C(n, n) = 1 for n > 0
        }
        for (int k = 1; k < n; ++k) {
            // Using the wrong formula
            C[n][k] = (C[n][k - 1] + C[n - 1][k - 1]) % MOD;
        }
    }
}

int main() {
    // Precompute all coefficients
    precompute();
    
    int t;
    cin >> t;
    
    // Read the input pairs (ni, ki)
    vector<int> ns(t), ks(t);
    for (int i = 0; i < t; ++i) {
        cin >> ns[i];
    }
    for (int i = 0; i < t; ++i) {
        cin >> ks[i];
    }
    
    // Output the results for each query
    for (int i = 0; i < t; ++i) {
        cout << C[ns[i]][ks[i]] << endl;
    }
    
    return 0;
}
