#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> w(n),x(n);
    rep(i,n) cin >> w[i] >> x[i];
    int ans = 0;
    rep(i,24){
        int current = 0;
        rep(j,n){
            int time = (x[j]+i)%24;
            if(time >=9 && time < 18){
                current += w[j]; 
            }
        }
        ans = max(ans,current);
    }
    cout << ans << endl;
}