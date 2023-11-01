#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    set<int> yet,called;
    rep(i,n) yet.insert(i+1);
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int x = *yet.begin();
            yet.erase(x);
            called.insert(x);
        }
        if(type == 2){
            int x;
            cin >> x;
            called.erase(x);
        }
        if(type == 3){
            int x = *called.begin();
            cout << x << '\n';
        }
    }
    return 0;
}