#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct V{
    int x,y;
    V(int x=0,int y=0):x(x),y(y){}
    V operator-(const V& a)const{
        return V(x-a.x,y-a.y);
    }
    int cross(const V& a)const{
        return x*a.y - y*a.x;
    }
    int ccw(const V& a) const{
        int area = cross(a);
        if(area > 0) return 1; //ccw(反時計回り) 
        else return -1; //cw(時計回り)
    }
};

int main(){
    vector<V> p(4);
    rep(i,4) cin >> p[i].x >> p[i].y;
    rep(i,4){
        V A = p[i];
        V B = p[(i+1)%4];
        V C = p[(i+2)%4];
        V AB = B-A, AC = C-A;
        if(AB.ccw(AC) != 1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}