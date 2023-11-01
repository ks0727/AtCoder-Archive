#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >>m;
    vector<int> p(n);
    vector<vector<int> > f(n);

    rep(i,n){
        int c;
        cin >> p[i] >> c;
        f[i] = vector<int>(c);
        rep(j,c) cin >> f[i][j];
    }
    rep(i,n)rep(j,n){
        if(i == j) continue;
        if(p[i] < p[j]) continue;
        bool ok = true;
        for(int e: f[i]){
            if(find(f[j].begin(),f[j].end(),e) == f[j].end()) ok = false;
        }
        if(!ok) continue;
        if(p[i] == p[j] && f[i] == f[j]) continue;
        cout << "Yes" << endl;
        return 0;
        }
    cout << "No" << endl;
    return 0;
}