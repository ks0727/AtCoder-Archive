#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,t,a;
    cin >> n >> t >> a;
    int now = t+a;
    int rest = n - now;
    int lose = min(t,a);
    int win = max(t,a);
    if(lose + rest < win) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}