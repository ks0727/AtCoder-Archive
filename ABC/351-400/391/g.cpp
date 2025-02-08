#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    string A_str;
    cin >> N >> A_str;
    int len = A_str.size();
    vector<int> A(len);
    for (int i = 0; i < len; ++i) {
        A[i] = A_str[i] - '0';
    }

    // Precompute original values for each depth
    vector<vector<int>> original(N + 1);
    original[0] = A;
    for (int d = 1; d <= N; ++d) {
        int prev_len = original[d-1].size();
        int curr_len = prev_len / 3;
        original[d].resize(curr_len);
        for (int i = 0; i < curr_len; ++i) {
            int a = original[d-1][3*i];
            int b = original[d-1][3*i + 1];
            int c = original[d-1][3*i + 2];
            int cnt = a + b + c;
            original[d][i] = (cnt >= 2) ? 1 : 0;
        }
    }

    int original_value = original[N][0];
    int target = 1 - original_value;

    // Initialize memo
    vector<vector<array<int, 2>>> memo(N + 1);
    for (int d = 0; d <= N; ++d) {
        int size = original[d].size();
        memo[d].resize(size, {-1, -1});
    }

    // Recursive function with memoization
    auto dfs = [&](int d, int pos, int target)->vector<vector<array<int,2> > >{
        if (d == 0) {
            return (original[d][pos] != target) ? 1 : 0;
        }
        if (memo[d][pos][target] != -1) {
            return memo[d][pos][target];
        }
        // If the current node's original value is already target, cost is 0
        if (original[d][pos] == target) {
            return memo[d][pos][target] = 0;
        }
        int child0 = pos * 3;
        int child1 = pos * 3 + 1;
        int child2 = pos * 3 + 2;
        int cost0 = dfs(d-1, child0, target);
        int cost1 = dfs(d-1, child1, target);
        int cost2 = dfs(d-1, child2, target);
        vector<int> costs = {cost0, cost1, cost2};
        sort(costs.begin(), costs.end());
        int total = costs[0] + costs[1];
        memo[d][pos][target] = total;
        return total;
    };

    int result = dfs(N, 0, target);
    cout << result << endl;

    return 0;
}