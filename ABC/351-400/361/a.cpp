#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,k,x;
    cin >> n >> k >> x;
    vector<int> a(n+1);
    rep(i,n+1){
        if(i == k) a[i] = x;
        else cin >> a[i];
    }
    rep(i,n+1) cout << a[i] << ' '; cout << endl; 
    return 0;
}