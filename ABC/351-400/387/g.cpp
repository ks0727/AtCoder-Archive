#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
// メモ化用配列
long long memo[20][2][10][2];

// 桁DPのメイン関数
long long digit_dp(int pos, bool tight, int max_digit, bool is_snake, const vector<int>& digits) {
    if (pos == digits.size()) {
        return is_snake ? 1 : 0;  // 最後まで到達し、ヘビ数ならカウント
    }
    if (memo[pos][tight][max_digit][is_snake] != -1) {
        return memo[pos][tight][max_digit][is_snake];
    }

    int limit = tight ? digits[pos] : 9;
    long long total = 0;

    for (int d = 0; d <= limit; ++d) {
        bool new_tight = tight && (d == limit);
        int new_max_digit = max(max_digit, d);
        bool new_is_snake = is_snake && (pos == 0 || d < max_digit);
        total += digit_dp(pos + 1, new_tight, new_max_digit, new_is_snake, digits);
    }

    memo[pos][tight][max_digit][is_snake] = total;
    return total;
}

// 数値x以下のヘビ数の個数を求める
long long solve(long long x) {
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());

    memset(memo, -1, sizeof(memo));
    return digit_dp(0, true, 0, true, digits);
}

// 範囲[L, R]のヘビ数の個数を求める
long long count_snake_numbers(long long L, long long R) {
    return solve(R) - solve(L - 1);
}

int main() {
    long long L, R;
    cin >> L >> R;
    cout << count_snake_numbers(L, R) << endl;
    return 0;
}
