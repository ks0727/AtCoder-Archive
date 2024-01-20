#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    rep(i,n){
        int a;
        cin >> a;
        a--;
        mp[a] = i;
    }
    vector<int> ans;
    int now = mp[-2];
    rep(i,n){
        ans.push_back(now);
        now = mp[now];
    }
    rep(i,n) cout << ans[i]+1 << ' ';
    cout << endl;
    return 0;
}