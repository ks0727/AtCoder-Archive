#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    map<int,set<int> > mp;
    rep(i,n){
        int a,c;
        cin >> a >> c;
        mp[c].insert(a);
    }
    const int INF = 1001001001;
    int ans = -INF;
    for(auto [c,st]:mp){
        ans = max(ans,*st.begin());
    }
    cout << ans << endl;
    return 0;
}