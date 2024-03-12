#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> p(n-1);
    rep(i,n-1) cin >> p[i];
    int cur = n;
    int ans = 0;
    while(1){
        cur = p[cur-2];
        ans++;
        if(cur == 1) break;
    }
    cout << ans << endl;
    return 0;
}