#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> vtop(n),ptov(n);
    rep(i,n){
        vtop[i] = i;
        ptov[i] = i;
    }
    while(q--){
        int x; cin >> x;
        x--;
        if(vtop[x] == n-1){
            int p = vtop[x];
            int nx = ptov[p-1];
            vtop[x] = p-1;
            vtop[nx] = p;
            ptov[p] = nx;
            ptov[p-1] = x;
        }else{
            int p = vtop[x];
            int nx = ptov[p+1];
            vtop[nx] = p;
            vtop[x] = p+1;
            ptov[p] = nx;
            ptov[p+1] = x;
        }
    }
    rep(i,n) cout << ptov[i]+1 << ' '; cout << endl;
    return 0;
}