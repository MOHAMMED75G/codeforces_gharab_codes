#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;
using Matrix = vector<vector<long long>>;


Matrix matrix_mult(const Matrix& A, const Matrix& B, long long mod) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    return C;
}

// Function to perform matrix exponentiation
Matrix matrix_exponentiation(Matrix A, long long power, long long mod) {
    int n = A.size();
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;  
    }
    while (power > 0) {
        if (power % 2 == 1) {
            result = matrix_mult(result, A, mod);
        }
        A = matrix_mult(A, A, mod);
        power /= 2;
    }
    return result;
}

long long sum_paths(long long n) {
    Matrix A = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };

    Matrix current_power = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    long long total_paths = 0;
    for (long long length = 0; length <= n; ++length) {
        if (length > 0) {
            current_power = matrix_mult(current_power, A, MOD);
        }
        total_paths = (total_paths + current_power[0][0]) % MOD;
    }

    return total_paths;
}

int main() {
    long long n;
    cin >> n;
    cout << sum_paths(n)-1 << endl;
    return 0;
}
