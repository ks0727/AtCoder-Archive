#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

/* 10 進表記がすべて '1' ならその文字列を返す */
string onesNumber(int x) {
    string s = to_string(x);
    return (all_of(s.begin(), s.end(), [](char c){ return c == '1'; })) ? s : "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;               // 1 ≤ N ≤ 2000
    if (!(cin >> N)) return 0;

    vector<string> term(N + 1), expr(N + 1);
    vector<int>    tlen(N + 1, INF), elen(N + 1, INF);

    auto bestFactor = [&](int v, auto&& self) -> string {
        /* <factor>: <number> か '(' <expr> ')' の短い方 */
        string best = onesNumber(v);
        if (!expr[v].empty()) {
            string par = "(" + expr[v] + ")";
            if (best.empty() || par.size() < best.size()) best = par;
        }
        return best;
    };

    for (int v = 1; v <= N; ++v) {

        /* --- 1. <number> として --- */
        string num = onesNumber(v);
        if (!num.empty()) { term[v] = num;  tlen[v] = num.size(); }

        /* --- 2. 乗算遷移で term[v] を更新 --- */
        for (int d = 2; d * d <= v; ++d) if (v % d == 0) {
            int a = v / d, b = d;

            if (!term[a].empty()) {
                string f = bestFactor(b, bestFactor);
                if (!f.empty() && tlen[a] + 1 + f.size() < tlen[v]) {
                    term[v] = term[a] + "*" + f;
                    tlen[v] = term[v].size();
                }
            }
            if (!term[b].empty()) {
                string f = bestFactor(a, bestFactor);
                if (!f.empty() && tlen[b] + 1 + f.size() < tlen[v]) {
                    term[v] = term[b] + "*" + f;
                    tlen[v] = term[v].size();
                }
            }
        }

        /* --- 3. expr[v] を初期化（単項 or 乗算形） --- */
        if (!term[v].empty()) { expr[v] = term[v]; elen[v] = tlen[v]; }

        /* --- 4. 加算遷移で expr[v] を更新 --- */
        for (int a = 1; a < v; ++a) {
            int b = v - a;
            if (!expr[a].empty() && !term[b].empty()) {
                string cand = expr[a] + "+" + term[b];
                if (cand.size() < elen[v]) {
                    expr[v] = cand;  elen[v] = cand.size();
                }
            }
        }

        /* --- 5. 括弧で term[v] を補完（必要なら） --- */
        if (!expr[v].empty()) {
            string par = "(" + expr[v] + ")";
            if (par.size() < tlen[v]) {
                term[v] = par;   tlen[v] = par.size();
                /* term が短くなった分 expr も更新できる */
                if (tlen[v] < elen[v]) { expr[v] = term[v]; elen[v] = tlen[v]; }
            }
        }
    }

    cout << expr[N] << '\n';
    return 0;
}

