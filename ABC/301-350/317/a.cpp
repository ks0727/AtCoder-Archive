#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,h,x;
    cin >> n >> h >> x;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    sort(p.begin(),p.end());
    int ans;
    rep(i,n){
        if(h + p[i] >= x){
            ans = i+1;
            break;
        }
    }
    cout << ans << endl;
}