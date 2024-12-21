#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    vector<int> x(5);
    vector<pair<int,string> > ps;
    rep(i,5) cin >> x[i];
    rep(i,1<<5){
        string t = "";
        int now = 0;
        rep(j,5){
            if(i>>j&1){
                now += x[j];
                t += char('A'+j);
            }
        }
        ps.emplace_back(-now,t);
    }
    sort(ps.begin(),ps.end());
    rep(i,31){
        cout << ps[i].second << endl;
    }
    return 0;
}