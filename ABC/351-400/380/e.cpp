#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> color(n,1);
    vector<int> group(n);
    rep(i,n) group[i] = i;
    set<int> st;
    rep(i,n) st.insert(i);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x,c;
            cin >> x >> c;
            x--; c--;
        }
        else if(type == 2){
            int c;
            cin >> c;
            c--;
            cout << color[c] << "\n";
        }
    }
}