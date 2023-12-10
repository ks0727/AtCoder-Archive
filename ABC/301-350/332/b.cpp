#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int k,g,m;
    cin >> k >> g >> m;
    int glass = 0;
    int cup = 0;
    rep(i,k){
        if(glass == g) glass = 0;
        else if(cup == 0) cup = m;
        else{
            if(g - glass >= cup){
                glass += cup;
                cup = 0;
            }else{
                cup -= (g-glass);
                glass = g;
            }
        }
    }
    cout << glass << ' ' << cup << endl;
    return 0;
}