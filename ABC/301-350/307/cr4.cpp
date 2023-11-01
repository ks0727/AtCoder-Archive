#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct Sheet{
    int h,w;
    vector<string> s;
    void input(){
        cin >> h >> w;
        s = vector<string>(h);
        rep(i,h) cin >> s[i];
    }
    bool shift(vector<string> &c, int di, int dj, int ch, int cw){
        rep(i,h){
            rep(j,w){
                int ni = i + di; int nj = j + dj;
                if(s[i][j] == '.') continue;
                if(ni < 0 || nj < 0 || ni >= ch || nj >= cw) return false;
                c[ni][nj] = s[i][j];
            }
        }
        return true;
    }
};

void clear(vector<string> &y,int h, int w){
    rep(i,h)rep(j,w){
        y[i][j] = '.';
    }
}

int main(){
    Sheet a,b,x;
    a.input();
    b.input();
    x.input();
    vector<string> y(x.h);
    rep(i,x.h){
        rep(j,x.w){
            y[i][j] = '.';
        }
    }
    for(int ai = -x.h; ai < x.h;ai++){
        for(int aj = -x.w;aj < x.w; aj++){
            for(int bi = -x.h; bi < x.h; bi++){
                for(int bj = -x.w;bj < x.w;bj++){
                    if(!a.shift(y,ai,aj,x.h,x.w)){
                        clear(y,x.h,x.w);
                        continue;
                    }
                    if(!b.shift(y,bi,bj,x.h,x.w)){
                        clear(y,x.h,x.w);
                        continue;
                    }                   
                    bool ok = true;
                    rep(i,x.h){
                        rep(j,x.w){
                            if(y[i][j] != x.s[i][j]){
                                ok = false;
                                break;
                            }
                            if(i == x.h-1 && j == x.w -1){
                                cout << "Yes" << endl;
                                return 0;
                            }
                        }
                        if(!ok) break;
                    }
                    clear(y,x.h,x.w);
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}