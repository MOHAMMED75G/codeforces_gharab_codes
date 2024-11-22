#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to calculate total score starting from position `start`, with `k` moves
long long calculateScore(int start, int k, const vector<int>& p, const vector<long long>& a) {
    vector<bool> visited(p.size(), false);
    vector<long long> score_path;
    int pos = start;

    // Simulate the path and detect cycles
    while (!visited[pos]) {
        visited[pos] = true;
        score_path.push_back(a[pos]);
        pos = p[pos];
    }

    // Cycle detected: identify cycle start and length
    int cycle_start = pos;
    long long cycle_score = 0;
    int cycle_length = 0;
    bool in_cycle = false;

    for (int i = 0; i < score_path.size(); i++) {
        if (pos == cycle_start && !in_cycle) {
            in_cycle = true; // start of cycle found
        }
        if (in_cycle) {
            cycle_score += score_path[i];
            cycle_length++;
        }
    }

    // Calculate total score efficiently
    long long total_score = 0;
    int moves = 0;

    // Add score until entering the cycle or using up all `k` moves
    for (int i = 0; i < score_path.size(); i++) {
        total_score += score_path[i];
        moves++;
        if (moves == k) return total_score;
    }

    // If we have remaining moves, we can use the cycle
    k -= moves;
    if (k > 0 && cycle_length > 0) {
        total_score += (k / cycle_length) * cycle_score;
        k %= cycle_length;
        for (int i = 0; i < k; i++) {
            total_score += score_path[cycle_start + i];
        }
    }
    return total_score;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, PB, PS;
        cin >> n >> k >> PB >> PS;
        PB--; PS--; // Convert to 0-based indexing

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--; // Convert to 0-based indexing
        }

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long scoreBodya = calculateScore(PB, k, p, a);
        long long scoreSasha = calculateScore(PS, k, p, a);

        if (scoreBodya > scoreSasha) {
            cout << "Bodya" << endl;
        } else if (scoreBodya < scoreSasha) {
            cout << "Sasha" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }
    return 0;
}
