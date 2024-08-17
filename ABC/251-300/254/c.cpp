#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int> > gs(k);
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,k){
        for(int j=i;j<n;j+=k){
            gs[i].push_back(a[j]);
        }
    }
    rep(i,k) sort(gs[i].begin(),gs[i].end());
    vector<int> ans;
    rep(j,n){
        rep(i,k){
            if(gs[i].size() <= j) break;
            ans.push_back(gs[i][j]);
        }
    }
    assert(ans.size() == n);
    rep(i,n-1){
        if(ans[i] > ans[i+1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}