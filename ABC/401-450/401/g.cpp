#include <bits/stdc++.h>
using namespace std;

bool is_valid(const string& s, int k) {
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == 'o') {
            if (i > 0 && s[i - 1] == 'o') return false;
            cnt++;
        }
    }
    return cnt == k;
}

bool can_make(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') s[i] = '.';
    }

    // greedy に o を配置
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o') {
            if (i > 0 && s[i - 1] == 'o') return false;
            cnt++;
        } else if (s[i] == '.' && cnt < k) {
            if ((i == 0 || s[i - 1] != 'o') && (i == n - 1 || s[i + 1] != 'o')) {
                s[i] = 'o';
                cnt++;
            }
        }
    }
    return is_valid(s, k);
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<char> ans(n, '?');

    for (int i = 0; i < n; ++i) {
        if (s[i] != '?') {
            ans[i] = s[i];
            continue;
        }

        string try_o = s;
        try_o[i] = 'o';
        bool o_ok = can_make(try_o, k);

        string try_dot = s;
        try_dot[i] = '.';
        bool dot_ok = can_make(try_dot, k);

        if (o_ok && dot_ok) ans[i] = '?';
        else if (o_ok) ans[i] = 'o';
        else if (dot_ok) ans[i] = '.';
    }

    for (char c : ans) cout << c;
    cout << endl;
    return 0;
}

