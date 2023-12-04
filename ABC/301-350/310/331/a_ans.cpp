#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main(){
    int M,D,y,m,d;
    cin >> M >> D >> y >> m >> d;
    d++;
    if(d > D){
        d = 1;
        m++;
    }
    if(m > M){
        m = 1;
        y++;
    }
    cout << y << ' ' << m << ' ' << d << endl;
    return 0;
}