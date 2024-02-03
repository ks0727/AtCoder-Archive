#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct Pos{
    int i,j,d;
    Pos(int i,int j,int d):i(i),j(j),d(d){}
};
int main(){
    int h,w,n;
    cin >> h >> w >> n;
    vector<string> s(h);
    rep(i,h){
        rep(j,w) s[i] += '.';
    }
    auto f = [&](int i,int j, int d)->Pos{
        if(s[i][j] == '.'){
            s[i][j] = '#';
            if(d < 3) d++;
            else d = 0;
        }else{
            s[i][j] = '.';
            if(d > 0) d--;
            else d = 3;
        }
        if(d == 0) j++;
        else if(d == 1) i++;
        else if(d == 2) j--;
        else if(d == 3) i--;
        int ni = (i+h)%h; int nj = (j+w)%w;
        return Pos(ni,nj,d);
    };
    Pos now = Pos(0,0,3);
    rep(ni,n){
        now = f(now.i,now.j,now.d);
    }
    rep(i,h){
        rep(j,w) cout << s[i][j];
        cout << endl;
    }
    return 0;
}