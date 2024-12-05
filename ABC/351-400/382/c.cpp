#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    rep(i,n) cin >> a[i];
    vector<P> ps;
    int prev = 1001001001;
    rep(i,n){
        if(a[i] < prev){
            ps.emplace_back(a[i],i);
            prev = a[i];
        }
    }
    sort(ps.begin(),ps.end());
    rep(i,m){
        int b;
        cin >> b;
        if(b < ps[0].first){
            cout << -1 << endl;
        }else{
            auto it = upper_bound(ps.begin(),ps.end(),make_pair(b,1001001001));
            it--;
            cout << it->second + 1 << endl;
        }
    }
    return 0;
}