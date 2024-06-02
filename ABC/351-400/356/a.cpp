#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,l,r;
    cin >> n >> l >> r;
    vector<int> ans;
    rep(i,n) ans.push_back(i+1);
    r--; l--;
    reverse(ans.begin()+l,ans.end()-n+r+1);
    rep(i,n) cout << ans[i] << " "; cout << endl;
    return 0;
}