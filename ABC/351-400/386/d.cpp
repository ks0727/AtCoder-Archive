#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > bs,ws;
    rep(i,m){
        int x,y; char c;
        cin >> x >> y >> c;
        if(c == 'B') bs.emplace_back(x,y);
        else ws.emplace_back(x,y);
    }
    sort(bs.rbegin(),bs.rend());
    map<int,int> mp;
    int mx = 0;
    rep(i,bs.size()){
        if(mx < bs[i].second){
            mp[bs[i].first] = bs[i].second;
            mx = bs[i].second;
        }
    }
    rep(i,ws.size()){
        auto [x,y] = ws[i];
        auto it = mp.lower_bound(x);
        if(it->second >= y){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}