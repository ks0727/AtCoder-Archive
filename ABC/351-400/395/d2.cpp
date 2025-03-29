#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> p(n), mp(n),inv(n);
    //mp : スワップしていく中で元々の巣がどこにいくか
    //inv : スワップされたのちに元々の巣はどれか
    rep(i,n){
        p[i] = i;
        inv[i] = i;
        mp[i] = i;
    }
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int a,b;
            cin >> a >> b;
            a--; b--;
            p[a] = inv[b];
        }
        else if(type == 2){
            int a,b;
            cin >> a >> b;
            a--; b--;
            mp[inv[a]] = b;
            mp[inv[b]] = a;
            swap(inv[a],inv[b]);
        }
        else if(type ==3){
            int a;
            cin >> a;
            a--;
            cout << mp[p[a]]+1 << endl;
        }
    }
    return 0;
}