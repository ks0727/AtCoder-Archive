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
    void copy(Sheet c, int di, int dj){
        rep(i,h)rep(j,w){
            int ni = i+di; int nj = j+dj;
            if(ni < 0 || nj < 0 || ni >= h || nj >= w){
                
            }
        }
    }
};

int main(){
    Sheet a,b,x;
    a.input();
    b.input();
    x.input();

    return 0;
}