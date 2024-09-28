#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int m;
    cin >> m;
    vector<int> ans;
    int cnt = 0;
    while(m){
        rep(i,m%3) ans.push_back(cnt);
        m /= 3;
        cnt++;
    }
    cout << ans.size() << endl;
    rep(i,ans.size()) cout << ans[i] << ' '; cout << endl;
    return 0;
}