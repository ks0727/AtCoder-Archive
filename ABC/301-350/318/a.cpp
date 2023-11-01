#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m,p;
    cin >> n >> m >> p;
    int day = 0;
    int ans = 0;
    rep(i,n){
        if(i == 0){
            day += m;
        }
        if(i != 0)  day += p;
        if(day > n) break;
        
        ans++;
    }
    cout << ans << endl;
}