#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<vector<int> > a(n);
    rep(i,n){
        int l;
        cin >> l;
        rep(j,l){
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    rep(qi,q){
        int s,t;
        cin >> s >> t;
        s--; t--;
        cout << a[s][t] << endl;
    }
}