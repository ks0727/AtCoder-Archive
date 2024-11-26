#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i],a[i]--;
    int ans = 0;
    vector<int> last(n,-1);
    rep(l,n-1){
        if(a[l] != a[l+1]) continue;
        last[a[l]] = l;
        int r = l+2;
        bool change = false;
        while(r<n-1 && a[r] == a[r+1]){
            if(l <= last[a[r]]){
                change = true;
                ans = max(ans,r-l);
                int la = last[a[r]];
                // l->last[a[r]]までをみていないことにする必要がある.
                for(int i=l;i<=last[a[r]];i+=2){
                    last[a[i]] = -1;
                }
                l = la+1;
                break;
            }
            last[a[r]] = r;
            r += 2;
        }
        if(change) continue;
        ans = max(ans,r-l);
        l = r-1;
    }
    cout << ans << endl;
    return 0;
}