#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    const int INF = 1001001001;
    rep(i,n) cin >> a[i];
    rep(i,n){
        if(i == 0){
            mp[0] = -1;
        }
        else{
            mp[a[i]] = a[i-1];
        }
    }
    int q;
    cin >> q;
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int x,y;
            cin >> x >> y;
            mp[y] = x;
        }else{
            int x;
            cin >> x;
        }
    }
    int now = -1;
    return 0;
}