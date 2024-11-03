#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> ans;
    map<int,int> mp;
    rep(i,n){
        int a;cin >> a;
        if(mp.count(a)){
            ans.push_back(mp[a]+1);
        }else{
            ans.push_back(-1);
        }
        mp[a] = i;
    }
    rep(i,n) cout << ans[i] << ' '; cout << endl;
    return 0;
}