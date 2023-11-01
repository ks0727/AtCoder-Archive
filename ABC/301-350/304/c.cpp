#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int square(int x){
    return x*x;
} 

float distance(P a,P b){
    float d;
    d = sqrt(square(a.first-b.first)+square(a.second-b.second));
    return d;
}

int main(){
    int n,d;
    cin >> n >> d;
    vector<P> ps;
    rep(i,n){
        int x,y;
        cin >> x >>y;
        ps.push_back({x,y});
    }
    queue<P> q;
    set<P> infected;
    q.push(ps[0]);
    infected.insert(ps[0]);
    while(!q.empty()){ 
        auto pos = q.front();
        q.pop();
        for(auto p : ps){
            if(pos == p) continue;
            if(distance(pos,p) <= d){
                if(infected.count(p)) continue;
                infected.insert(p);
                q.push(p);
            }
        }
    }
    rep(i,n){
        if(infected.count(ps[i])) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}