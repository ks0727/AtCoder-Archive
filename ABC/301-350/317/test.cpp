#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > G(m);
    map<pair<int,int>,int> distance;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
        distance[make_pair(a-1,b-1)] = c;
        distance[make_pair(b-1,a-1)] = c;
    }
    int current = 0;
    int mx = 0;
    vector<bool> seen(n);

    rep(i,n){
        seen[i] = true;
        for(auto next : G[

}