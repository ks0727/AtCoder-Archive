#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,d;
    cin >> n >> d;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans = 0;
    int current = 0;
    rep(i,d){
        rep(j,n){
            if(s[j][i] == 'x'){
                current = 0;
                break;
            };
            if(j == n-1){
                current++;
            } 
        }
        ans = max(ans,current);
    }
    cout << ans << endl;
    return 0;
}