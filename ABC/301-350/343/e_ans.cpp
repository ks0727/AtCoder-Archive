#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct P{
    int x,y,z;
    P(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
};

const int INF = 1001001001;

int f(P a, P b, P c){ //共通部分の堆積を求める関数
    P l,r;
    l.x = min({a.x,b.x,c.x});
    l.y = min({a.y,b.y,c.y});
    l.z = min({a.z,b.z,c.z});
    r.x = max({a.x,b.x,c.x});
    r.y = max({a.y,b.y,c.y});
    r.z = max({a.z,b.z,c.z});
    int ans = 1;
    ans *= max(l.x+7-r.x,0);
    ans *= max(l.y+7-r.y,0);
    ans *= max(l.z+7-r.z,0);
    return ans;
};
int main(){
    int v1,v2,v3;
    cin >> v1 >> v2 >> v3;
    if(v1 != 7*7*7*3 - v2*2 - v3*3){
        cout << "No" << endl;
        return 0;
    }
    vector<P> cand;
    for(int x = -7;x<=7;x++){
        for(int y=-7;y<=7;y++){
            for(int z = -7;z<=7;z++){
                cand.emplace_back(x,y,z);
            }
        }
    }
    P p0;
    for(P p1:cand)for(P p2 : cand){
        if(f(p0,p1,p2) != v3) continue;
        int now = f(p0,p1,p2);
        now += f(p1,p2,p2);
        now += f(p2,p0,p0);
        now -= v3*3;
        if(now != v2) continue;
        cout << "Yes" << endl;
        printf("%d %d %d",p0.x,p0.y,p0.z);
        printf("%d %d %d",p1.x,p1.y,p1.z);
        printf("%d %d %d",p2.x,p2.y,p2.z);
        return 0;
    }
    cout << "No" << endl;
    return 0;
}