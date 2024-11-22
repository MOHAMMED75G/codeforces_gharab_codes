#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if the current permutation can be a DFS order of the binary tree.
bool isDFSOrder(const vector<int>& p, int n) {
    vector<int> index(n + 1);
    for (int i = 0; i < n; i++) {
        index[p[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        int left = 2 * i;
        int right = 2 * i + 1;

        // Check if children are still in the DFS order compared to the parent
        if (left <= n && index[left] < index[i]) return false;
        if (right <= n && index[right] < index[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); // For faster I/O
    cin.tie(nullptr);

    int t;
    cin >> t;  // Read the number of test cases
    while (t--) {
        int n, q;
        cin >> n >> q;  // Read the number of vertices in the tree and the number of queries
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        for (int i = 0; i < q; ++i) {
            int x, y;
            cin >> x >> y;
            --x; --y; // Convert to zero-indexed for easier array manipulation
            swap(p[x], p[y]);

            // Validate the DFS order after each swap (here we could optimize further)
            if (isDFSOrder(p, n)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }

            // Since swaps are persistent, we keep the changes
        }
    }
    return 0;
}
