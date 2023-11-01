#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int ans;
    rep(i,n+1){
        if(a[i] == a[0]+i) continue;
        else{
            ans = a[0] + i;
            break;
        }
    }
    cout << ans << endl;
}