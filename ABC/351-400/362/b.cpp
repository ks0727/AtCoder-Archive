#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

struct Vec{
    int x,y;
    Vec(int x=0,int y=0):x(x),y(y){}
    void input(){
        cin >> x >> y;
    }
    Vec relative(Vec other){
        Vec res;
        res.x = other.x - x;
        res.y = other.y - y;
        return res;
    }
    int len(){
        return x*x+y*y;
    }
};

int main(){
    Vec a,b,c;
    a.input();
    b.input();
    c.input();
    Vec ab = a.relative(b);
    Vec ac = a.relative(c);
    Vec ba = Vec(-ab.x,-ab.y);
    Vec bc = b.relative(c);
    Vec ca = Vec(-ac.x,-ac.y);
    Vec cb = Vec(-bc.x,-bc.y);
    Vec s,m,l;
    int abl = ab.len();
    int bcl = bc.len();
    int cal = ca.len();
    vector<int> length = {abl,bcl,cal};
    sort(length.begin(),length.end());
    if(length[0]+length[1] == length[2]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}