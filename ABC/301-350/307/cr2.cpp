#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct Sheet{
    int h,w;
    vector<string> s;
    void input(){
        cin >> h >> w;
        s = vector<string>(h);
        rep(i,h)rep(j,w) cin >> s[i][j];
    }
    void shift(Sheet &c, int di, int dj, bool &can){
        rep(i,h){
            rep(j,w){
                int ni = i + di; int nj = j + dj;
                if(s[i][j] != '.') continue;
                if(ni < 0 || nj < 0 || ni >= c.h || nj >= c.w){
                    can = false;
                    continue;
                }
                c.s[ni][nj] = '#';
            }
        }
    }
    void clear(){
        rep(i,h)rep(j,w) s[i][j] = '.';
    }
};

int main(){
    Sheet a,b,x;
    a.input();
    b.input();
    x.input();
    for(int ai = -a.h; ai < a.h;ai++){
        for(int aj = -a.w;aj<a.w;aj++){
            for(int bi = -b.h;bi < b.h;bi++){
                for(int bj = -b.w;bj<b.w;bj++){
                    Sheet y = x;
                    bool can = true;
                    y.clear();
                    a.shift(y,ai,aj,can);
                    b.shift(y,bi,bj,can);
                    if(x.s == y.s && can){
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