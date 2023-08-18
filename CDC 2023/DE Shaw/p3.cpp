#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int maxScore(vector<int>& arr) {
    map<int, int> frequency;
    for (int num : arr) {
        frequency[num]++;
    }
    vector<int> unique_nums;
    for (auto& kv : frequency) {
        unique_nums.push_back(kv.first);
    }
    vector<long long> dp(unique_nums.size() + 1, 0);
    for (int i = 1; i <= unique_nums.size(); i++) {
        long long prev_score = (i > 0) ? dp[i-1] : 0;
        if (i > 1 && unique_nums[i-2] == unique_nums[i-1] - 1) {
            dp[i] = max(prev_score, dp[i-2] + (1LL * unique_nums[i-1] * frequency[unique_nums[i-1]]) );
        }
        else dp[i] = (1LL * unique_nums[i-1] * frequency[unique_nums[i-1]]) + prev_score;
        dp[i] %= MOD;
    }
    int max_score = 0;
    for (int score : dp) {
        max_score = max(max_score, score);
    }
    return max_score;
}

int main() {
    // Example usage
    vector<int> arr = {3, 3, 3, 4, 5, 5, 5, 6};
    int result = maxScore(arr);
    cout << "Maximum score: " << result << endl;

    return 0;
}