#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> hato(n);
    vector<set<int>> su(n);
    vector<int> mp(n);
    vector<int> inv(n);
    rep(i, n){
        hato[i] = i;
        su[i].insert(i);
        mp[i] = i;
        inv[i] = i;
    }
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int a, b;
            cin >> a >> b;
            a--; b--;
            su[hato[a]].erase(a);
            su[inv[b]].insert(a);
            hato[a] = inv[b];
        }
        else if(type == 2){
            int a, b;
            cin >> a >> b;
            a--; b--;
            int base_a = inv[a];
            int base_b = inv[b];
            swap(su[base_a], su[base_b]);
            swap(mp[base_a], mp[base_b]);
            inv[mp[base_a]] = base_a;
            inv[mp[base_b]] = base_b;
        }
        else if(type == 3){
            int a;
            cin >> a;
            a--;
            cout << mp[hato[a]] + 1 << '\n';
        }
    }
    return 0;
}
