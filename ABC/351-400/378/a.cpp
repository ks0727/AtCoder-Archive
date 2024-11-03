#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    vector<int> cnt(4);
    rep(i,4){
        int a;
        cin >> a;
        a--;
        cnt[a]++;
    }
    int ans = 0;
    rep(i,4){
        if(cnt[i] >= 2){
            ans += cnt[i]/2;
        }
    }
    cout << ans << endl;
    return 0;
}