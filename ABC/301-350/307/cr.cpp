#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct Sheet{
    int h,w;
    vector<string> s;
    void input(){
        cin >> h >> w;
        s = vector<string>(h);
        rep(i,h){
            cin >> s[i];
        }
    }
    void clear(){
        rep(i,h)rep(j,w){
            s[i][j] = '.';
        }
    }
    void shift(int si,int sj){
        
    }
    void copy(Sheet c){
        rep(i,h){
            rep(j,w){
                if(c.s[i][j] == '#') s[i][j] = '#';
            }
        }
    }
};

int main(){
    Sheet a,b,x;
    a.input();
    b.input();
    x.input();
    Sheet y = x;
    y.clear();
    for(int ai = -a.h;ai<x.h;ai++){
        for(int aj = -a.w;aj<x.w;aj++){
            for(int bi = -b.h;bi<x.h;bi++){
                for(int bj = -b.w;bj<x.w;bj++){
                    a.shift(ai,aj);
                    b.shift(bi,bj);
                    y.copy(a);
                    y.copy(b);
                    if(y.s == x.s){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}