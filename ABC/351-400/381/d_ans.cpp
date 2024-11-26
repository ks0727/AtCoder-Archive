#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(si,2){
        vector<int> cnt(n+1);
        int r = si;
        for(int l=si;l+1<n;l+= 2){
            while(r+1 < n){
                if(a[r] != a[r+1]) break;
                if(cnt[a[r]]) break;
                cnt[a[r]]++;
                r += 2;
            }
            ans = max(ans,r-l);
            if(l == r) r += 2;
            else cnt[a[l]]--;
        }
    }
    cout << ans << endl;
    return 0;
}