#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,d;
    cin >> n >> d;
    vector<int> t(n),l(n);
    rep(i,n) cin >> t[i] >> l[i];
    for(int k=1;k<=d;k++){
        int now = 0;
        rep(i,n){
            now = max(now,t[i]*(l[i]+k));
        }
        cout << now << endl;
    }
    return 0;
}