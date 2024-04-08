#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

const int INF = 1e9;

struct Data{
    int small,big;
    Data(int small=-INF, int big=INF):small(small),big(big){}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<Data> d(n+1);
    rep(i,m){
        int x,y;
        cin >> x >> y;
        d[x].big = y;
        d[y].small = x;
    }
    int scnt=0,bcnt=0;
    int start = -1,end = -1;
    for(int i=1;i<n+1;i++){
        if(d[i].small == -INF){
            scnt++;
            start = i;
        } 
        if(d[i].big == INF){
            bcnt++;
            end = i;
        } 
    }
    if(scnt != 1 || bcnt != 1){
        cout << "No" << endl;
        return 0;
    } 
    int now = start;
    vector<int> ans(n,-1);
    int cnt = 1;
    while(now != end){
        if(ans[now-1] == -1) ans[now-1] = cnt;
        else{
            cout << "No" << endl;
            return 0;
        }
        now = d[now].big;
        cnt++;  
    }
    if(ans[end-1] == -1) ans[end-1] = cnt;
    else{
        cout << "No" << endl;
        return 0;
    } 
    cout << "Yes" << endl;
    for(int x : ans) cout << x << ' '; cout << endl;
    return 0;
}