#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int q;
    cin >> q;
    rep(i,q){
        int type;
        cin >> type;
        if(type == 1){
            int k,x;
            cin >> k >> x;
            k--;
            a[k] = x;
        }
        if(type == 2){
            int k;
            cin >> k;
            k--;
            cout << a[k] << '\n';
        }
    }
    return 0;
}