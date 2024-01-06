#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    rep(i,22){
        rep(j,22){
            rep(k,22){
                if(i+j+k > n) continue;
                cout << i << ' ' << j << ' ' << k << endl;
            }
        }
    }
    return 0;
}