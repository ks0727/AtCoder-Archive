#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    vector<int> x(3);
    rep(i,3) cin >> x[i];
    int ans = x[1];
    sort(x.begin(),x.end());
    if(ans == x[1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}