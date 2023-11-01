#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    int tot = 0;
    rep(i,n) tot += d[i];
    int k = (tot + 1) / 2;
    rep(i,n){
        if( k<= d[i]){
            cout << i + 1 << ' ' << k << endl;
            return 0;
        }
        k -= d[i];
    }
}