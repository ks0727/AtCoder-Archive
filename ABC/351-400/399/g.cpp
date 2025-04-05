#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;

    vector<int> to(26, -1);
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        int s = S[i] - 'a';
        int t = T[i] - 'a';
        if (to[s] != -1 && to[s] != t) {
            possible = false;
            break;
        }
        to[s] = t;
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    unordered_set<int> used_chars;
    for (char c : S) used_chars.insert(c - 'a');
    for (char c : T) used_chars.insert(c - 'a');
    bool has_unused = used_chars.size() < 26;

    vector<int> visited(26, 0);
    int ans = 0;

    for (int i = 0; i < 26; ++i) {
        if (to[i] == -1 || to[i] == i || visited[i]) continue;

        vector<int> path;
        int u = i;
        while (true) {
            if (visited[u]) break;
            visited[u] = 1;
            path.push_back(u);
            u = to[u];
            if (u == -1) break;
        }

        bool in_cycle = false;
        for (int v : path) {
            if (to[v] == -1) continue;
            if (visited[to[v]] == 1) {
                in_cycle = true;
                break;
            }
        }

        if (in_cycle) {
            int start = -1;
            for (size_t j = 0; j < path.size(); ++j) {
                if (to[path[j]] == -1) continue;
                if (visited[to[path[j]]] == 1) {
                    start = j;
                    break;
                }
            }

            int cycle_len = 0;
            unordered_set<int> cycle;
            for (int j = start; j < (int)path.size(); ++j) {
                if (visited[path[j]] != 1) break;
                cycle.insert(path[j]);
                cycle_len++;
                visited[path[j]] = 2;
            }

            if (cycle_len >= 2) {
                if (!has_unused) {
                    cout << -1 << endl;
                    return 0;
                }
                ans += cycle_len + 1;
            }

            for (int j = 0; j < start; ++j) {
                if (cycle.count(path[j])) continue;
                ans++;
            }
        } else {
            ans += path.size();
            for (int v : path) visited[v] = 2;
        }
    }

    cout << ans << endl;

    return 0;
}