#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> cnt(n+1);
    pair<int,int> ans(0,-1);
    rep(i,m){
        int a;
        cin >> a;
        cnt[a]++;
        ans = min(ans,make_pair(-cnt[a],a));
        cout << ans.second << '\n';
    }
    return 0;
}