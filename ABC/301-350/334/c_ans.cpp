#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> cnt(n,2);
    rep(i,k){
        int a;
        cin >> a;
        a--;
        cnt[a]--;
    }
    vector<int> x;
    rep(i,n)rep(j,cnt[i]){
        x.push_back(i);
    }
    n = x.size();
    if(n%2 == 0){
        int ans = 0;
        rep(i,n/2){
            ans += x[i*2+1]-x[i*2];
        }
        cout << ans << endl;
    }else{
        int now = 0;
        rep(i,n/2){
            now += x[i*2+2] - x[i*2-1];
        }
        int ans = now;
        for(int i = 2;i<n;i+=2){
            now += x[i-1]-x[i-2];
            now -= x[i]-x[i-1];
            ans = min(ans,now);
        }
    }
    return 0;
}