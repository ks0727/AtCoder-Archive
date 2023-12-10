#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;


int main(){
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    rep(i,n) cin >> a[i];
    for(int i=1;i<(n);i++){
        int v;
        cin >> v;
        v--;
        p[i] = v;
    }
    vector<vector<int> > g(n);
    for(int i=1;i<(n);i++){
        g[p[i]].push_back(i);
    }
    const int INF = 1e9;
    vector<int> dp(n,INF);
    ll sum = 0;
    auto f = [&](auto f, int v, int par)->void{
        
    };
    f(f,0,-1);
    sum -= a[0];
    if(sum > 0){
        cout << '+' << endl;
        return 0;
    }
    if(sum < 0){
        cout << '-' << endl;
        return 0;
    }
    if(sum == 0){
        if(a[0] > 0){
            cout << '+' << endl;
            return 0;
        }
        if(a[0] < 0){
            cout << '-' << endl;
            return 0;
        }
        if(a[0] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    return 0;
}