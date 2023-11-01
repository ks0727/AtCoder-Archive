#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    vector<string> all;
    rep(i,n){
        string s;
        cin >> s;
        all.push_back(s);
    }
    vector<string> ans(k);
    rep(i,k){
        ans[i] = all[i];
    }
    sort(ans.begin(),ans.end());
    rep(i,k){
        cout << ans[i] << endl;
    }
    return 0;
}