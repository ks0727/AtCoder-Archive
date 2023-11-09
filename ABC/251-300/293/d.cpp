#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct Rope{
    int red,blue;
    Rope(int red = -1,int blue = -1): red(red),blue(blue){}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<Rope> ropes(n);
    rep(i,m){
        int a,c;
        char b,d;
        cin >> a >> b >> c >> d;
        a--; c--;
        if(b == 'R' && d == 'B'){
            ropes[a].red = c;
            ropes[c].blue = a;
        }else{
            ropes[a].blue = c;
            ropes[c].red = a;
        }
    }
    int loops = 0,rs = n;
    vector<bool> seen(n);
    auto f = [&](auto f, Rope r, int prev)->void{ // prevは0なら青,1なら赤
        seen[r] = true;
        if(prev == -1){
            if(r.blue == -1 && r.red == -1) return;
            if(r.blue == -1 && r.red != -1) return f(f,r.red,1);
            if(r.blue != -1 && r.red == -1) return f(f,r.blue,0);
            if(r.blue != -1 && r.red != -1) return f(f,r.red,1);
        }else{
            if(prev == 0){
                if(r.red == -1) return;
                else f(f,r.red,1);
            }else{
                if(r.blue == -1) return;
                else f(f,r.blue,1);
            }
        }
    };
}