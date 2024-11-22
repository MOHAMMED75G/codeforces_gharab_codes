#include <iostream>
#include <algorithm>
using namespace std;

int max_possible_width(int a, int b, int c) {
    // The total number of tiles available
    int total_cells = 4 * a + 4 * b + 3 * c;  // Squares and S-tiles both use 4 cells, corners use 3 cells

    // We are trying to fill a 2×n grid, where the total number of cells is 2 * n
    // Find the largest n such that 2 * n <= total_cells
    return total_cells / 2;
}

int main() {
    // Input
    int a, b, c;
    cin >> a >> b >> c;

    // Output the maximum possible width n that can perfectly fill the grid
    cout << max_possible_width(a, b, c) << endl;
    
    return 0;
}
