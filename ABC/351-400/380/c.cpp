#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<char,int>;

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<P> ps;
    rep(l,n){
        int r = l+1;
        while(r < n && s[l] == s[r]) r++;
        ps.emplace_back(s[l],r-l);
        l = r-1;
    }
    int cnt = 0;
    rep(i,ps.size()){
        if(ps[i].first == '1') {
            cnt++;
            if(cnt == k-1) swap(ps[i+1],ps[i+2]);
        }
    }
    string ans = "";
    rep(i,ps.size()){
        ans += string(ps[i].second,ps[i].first);
    }
    cout << ans << endl;
    return 0;
}