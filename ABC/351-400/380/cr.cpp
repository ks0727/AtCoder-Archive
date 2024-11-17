#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<char,int> > ps;
    for(char c : s){
        if(ps.size() > 0 && ps.back().first == c){
            ps.back().second++;
        }else{
            ps.emplace_back(c,1);
        }
    }
    int ones = 0;
    int idx = 0;
    rep(i,ps.size()){
        if(ps[i].first == '1') ones++;
        if(ones == k){
            swap(ps[i],ps[i-1]);
        }
    }
    string ans = "";
    rep(i,ps.size()) ans += string(ps[i].second,ps[i].first);
    cout << ans << endl;
    return 0;
}
