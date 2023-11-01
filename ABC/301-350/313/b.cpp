#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > info(m);
    //情報の数が足りなかったら-1を出力
    rep(i,m){
        int a,b;
        cin >> a >> b;
        info[i] = make_pair(a,b);
    }
    if(m < n-1){
        cout << -1 << endl;
        return 0;
    }
    vector<bool> isStrong(n);
    rep(i,n) isStrong[i] = true;
    rep(i,m){
        isStrong[info[i].second - 1] = false;
    }
    int cnt = 0;
    int index;
    rep(i,n){
        if(isStrong[i]){
            cnt++;
            index = i;
        }
    }
    if(cnt > 1) cout << -1 << endl;
    else cout << index + 1 << endl;
}