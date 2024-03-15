#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    const int INF = 1001001001;
    int mnidx = INF;
    rep(i,n) cin >> a[i];
    priority_queue<P,vector<P>,greater<P> > q;
    rep(i,n){
        if(a[i] >= 0){
            if(mnidx == INF) mnidx = i;
            continue;
        }
        int x = -a[i];
        int y = (x+i)/(i+1);
        q.emplace(y,i);
    }
    rep(i,m){
        int idx = -1;
        ll cnt = 0;
        while(!q.empty()){
            if(q.top().first == i+1){
                idx = q.top().second;
                q.pop();
                if(idx < mnidx) mnidx = idx;
                if(a[idx]+(i+1)*(idx+1) != cnt) break;
                cnt++;
            }else break;
        }
        
    }
    return 0;
}