#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<int> cs(n);
    int tosen = -1;
    int mx = 0;
    rep(i,m){
        cs[a[i]-1]++;
        if(cs[a[i]-1] > mx){
            tosen = a[i];
            mx = cs[a[i]-1];
            cout << tosen << '\n';
            continue;
        }
        else if(cs[a[i]-1] == mx && a[i] < tosen){
            tosen = a[i];
            cout << tosen << '\n';
            continue;
        }else{
            cout << tosen << '\n';
        }
    }
    return 0;
}