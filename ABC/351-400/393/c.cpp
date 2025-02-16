#include <bits/stdc++.h>
using namespace std;
#include<atcoder/dsu>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    cin >> n >> m;
    set<pair<int,int> > st;
    int ans = 0;
    rep(i,m){
        int a,b;
        cin >> a  >> b;
        a--; b--;
        if(a > b) swap(a,b);
        if(st.count(make_pair(a,b)) || a == b) ans++;
        else st.emplace(a,b);
    }
    cout << ans << endl;
    return 0;
}