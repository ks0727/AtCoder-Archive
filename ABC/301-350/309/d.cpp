#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n1,n2,m;
    cin >> n1 >> n2 >> m;
    vector<vector<int> > g(n1+n2);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<P> st1;
    vector<int> cost1(n1,-1);
    cost1[0] = 0;
    st1.push(P(0,cost1[0]));
    vector<int> visit;
    visit.push_back(0);
    while(!st1.empty()){
        auto [v,c] = st1.front(); st1.pop();
        for(auto u : g[v]){
            if(cost1[u] != -1) continue;
            visit.push_back(u);
            cost1[u] = c+1;
            st1.push(P(u,cost1[u]));
        }
    }
    queue<P> st2;
    vector<int> cost2(n2,-1);
    cost2[n2-1] = 0;
    st2.push(P(n2-1,cost2[n2-1]));
    while(!st2.empty()){
        auto [v,c] = st2.front(); st2.pop();
        for(auto u : g[v+n1]){
            if(cost2[u-n1] != -1) continue;
            cost2[u-n1] = c+1;
            st2.push(P(u-n1,cost2[u-n1]));
        }
    }
    int mx1 = *max_element(cost1.begin(),cost1.end());
    int mx2 = *max_element(cost2.begin(),cost2.end());
    int ans = mx1 + mx2;
    cout << ans + 1<< endl;
    return 0;
}