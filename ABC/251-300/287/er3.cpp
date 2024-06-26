#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<pair<string,int> > s(n);
    rep(i,n) cin >> s[i].first;
    rep(i,n) s[i].second = i;
    stable_sort(s.begin(),s.end());
    vector<int> ans(n,-1);
    rep(i,n-1){
        int now = 0;
        auto [a,ai] = s[i];
        auto [b,bi] = s[i+1];
        while(now < a.size() && now < b.size()){
            if(a[now] != b[now]) break; 
            now++;
        }
        ans[ai] = max(ans[ai],now);
        ans[bi] = max(ans[bi],now);
    }
    rep(i,n){
        cout << ans[i] << '\n';
    }
    return 0;
}