#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to calculate Euclidean distance between two points
ll calculateDistance(ll x1, ll y1, ll x2, ll y2) {
    ll dx = x2 - x1; 
    ll dy = y2 - y1; 
    return dx * dx + dy * dy; ;
}

int main() {
    int t;  // number of test cases
    cin >> t;
    while (t--) {
        int n;  // number of circles
        cin >> n;
        
        vector<pair<int, int>> circles(n);
        for (int i = 0; i < n; ++i) {
            cin >> circles[i].first >> circles[i].second;
        }
        
        int xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;

        ll directDistance = calculateDistance(xs, ys, xt, yt);

        bool possible = true;
        for (const auto& circle : circles) {
            
            ll distTargetToCircle = calculateDistance(xt, yt, circle.first, circle.second);

            // Check if the circle obstructs the path
            if ( directDistance >=distTargetToCircle ) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
