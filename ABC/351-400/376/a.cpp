#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,c;
    cin >> n >> c;
    int last = -1001001001;
    int ans = 0;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        if(t-last<c) continue;
        last = t;
        ans++;
    }
    cout << ans << endl;
    return 0;
}