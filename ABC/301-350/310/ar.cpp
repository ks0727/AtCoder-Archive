#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,p,q;
    cin >> n >> p >> q;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    const int INF = 1e8;
    int minimum = INF;
    rep(i,n){
        minimum = min(d[i],minimum);
    }
    cout << min(p,minimum+q) << endl;
}