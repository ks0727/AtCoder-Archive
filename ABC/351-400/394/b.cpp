#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    vector<pair<int,string> > ps;
    int n;
    cin >> n;
    rep(i,n){
        string s;
        cin >> s;
        int len = s.size();
        ps.emplace_back(len,s);
    }
    sort(ps.begin(),ps.end());
    rep(i,n) cout << ps[i].second;
    cout << endl;
    return 0;
}