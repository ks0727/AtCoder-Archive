#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int r= 0;
    int ans = 0;
    for(int l=0;l<n;l++){
        while(r < n && a[r]-a[l]<=d){
            r++;
        }
        if(a[r]-a[l]>d) r--;
        ans = max(ans,r-l+1);
    }
    cout << ans << endl;
    return 0;
}