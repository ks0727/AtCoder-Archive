#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int max_value;
    rep(i,n) max_value = max(max_value,p[i]);
    int ans = 0;
    bool isSame = false;
    if(p[0] == max_value){
        rep(i,n+1){
            if(p[i+1] == max_value){
                isSame = true;
                break;
            }
        }
        if(isSame) ans = 1;
        else ans = 0;
    }
    else ans = max_value + 1 - p[0];
    cout << ans << endl;
}