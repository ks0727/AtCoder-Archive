#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    set<int> s;
    int ans = 0;
    stack<tuple<int, int, set<int>>> st;
    st.push({0, 0, s});
    while (!st.empty()) {
        int i, j;
        tie(i, j, s) = st.top();
        st.pop();
        if (i == h - 1 && j == w - 1) {
            ans++;
            continue;
        }
        if (j + 1 < w) {
            int next_i = i;
            int next_j = j + 1;
            set<int> next_s = s;
            
            if (!next_s.count(a[next_i][next_j])) {
                next_s.insert(a[next_i][next_j]);
                st.push({next_i, next_j, next_s});
            }
        }
        if (i + 1 < h) {
            int next_i = i + 1;
            int next_j = j;
            set<int> next_s = s;
            if (!next_s.count(a[next_i][next_j])) {
                next_s.insert(a[next_i][next_j]);
                st.push({next_i, next_j, next_s});
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
