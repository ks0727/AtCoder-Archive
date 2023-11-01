#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll dp[3000005][2];
bool mem[3000005][2];

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    auto f = [&](auto f,int i,int c) -> ll{
        if(i == s.size()) return 0;
        if(mem[i][c]) return dp[i][c];
        ll res = 1e18;
        int a = s[i] == 'A' ? 1 : 0;
        int cost1 = (a == c) ? x : y;
        int cost2 = ((a == c) ? x : y) + z;
        res = cost1 + f(f,i+1,c);
        res = min(res,cost2 + f(f,i+1,!c));
        mem[i][c] = true;
        return dp[i][c] = res;
    };
    cout << f(f,0,0) << endl;
    return 0;
}