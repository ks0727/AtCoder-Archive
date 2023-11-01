#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
//方針
//異なる味のときと同じ味のときでそれぞれ最大値を出し、最後にその二つを比べることで答えを決定する。
int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n); //味ごとにおいしさを格納していく
    rep(i,n){
        int f,s;
        cin >> f >> s;
        a[f-1].push_back(s);
    }
    int ans = 0;
    //以下同じ味のときの処理
    rep(i,n){
        if(a[i].size() < 2) continue;
        sort(a[i].rbegin(),a[i].rend());
        int now = a[i][0] + a[i][1]/2;
        ans = max(ans,now);
    }
    //以下味が異なるときの処理
    vector<int> b;
    rep(i,n){
        if(a[i].size() == 0) continue;
        b.push_back(a[i][0]);
    }
    sort(b.rbegin(),b.rend());
    if(b.size() >= 2) ans = max(ans,b[0]+b[1]);

    cout << ans << endl;
    return 0;
}