#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int M,D;
    cin >> M >> D;
    int y,m,d;
    cin >> y >> m >> d;
    if(d != D){
        cout << y << ' ' << m << ' ' << d + 1 << endl;
        return 0;
    }else{
        if(m == M){
            cout << y+1 << ' ' << 1 << ' ' << 1 << endl;
        }else{
            cout << y << ' ' << m + 1 << ' ' << 1 << endl;
        }
    }
    return 0;
}