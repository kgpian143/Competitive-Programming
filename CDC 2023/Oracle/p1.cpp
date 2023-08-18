#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

vector<int> findMinCost(vector<int>& red, vector<int>& blue, int blueCost) {
    int n = red.size();
    vector<int> dp_red(n, 0);
    vector<int> dp_blue(n, 0);
    vector<int> result(n, 0);

    dp_red[0] = red[0];
    dp_blue[0] = blue[0];

    for (int i = 1; i < n; ++i) {
        dp_red[i] = min(dp_red[i - 1] + red[i-1], dp_blue[i - 1] + red[i-1]);
        dp_blue[i] = min(dp_blue[i - 1] + blue[i-1], dp_red[i - 1] + blue[i-1] + blueCost);
        result[i] = min(dp_red[i], dp_blue[i]);
    }

    return result;
}

int main() {
    vector<int> red = {2, 5, 7, 9}; // Replace these values with your actual data
    vector<int> blue = {4, 3, 6, 1}; // Replace these values with your actual data
    int blueCost = 3; // Replace this with the actual blue line extra time cost

    vector<int> minCost = findMinCost(red, blue, blueCost);
    for( auto it : minCost )cout << it << " " ;

    return 0;
}
