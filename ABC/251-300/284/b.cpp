#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int t;
    cin >> t;
    vector<int> ans(t);
    rep(i,t){
        int n;
        cin >> n;
        rep(j,n){
            int value;
            cin >> value;
            if(value%2 == 1) ans[i]++;
        }
    }
    rep(i,t) cout << ans[i] << endl;
    return 0;
}