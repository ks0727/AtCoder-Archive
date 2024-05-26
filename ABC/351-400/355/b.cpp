#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

int main(){
    int n,m;
    cin >> n>> m;
    vector<int> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<P> c;
    rep(i,n){
        c.emplace_back(a[i],0);
    }
    rep(i,m) c.emplace_back(b[i],1);
    sort(c.begin(),c.end());
    rep(i,n+m-1){
        if(c[i].second == 0 && c[i+1].second == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}