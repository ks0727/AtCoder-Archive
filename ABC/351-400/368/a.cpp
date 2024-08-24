#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b;
    int cnt = 0;
    while(k--){
        b.push_back(a[a.size()-1-cnt]);
        cnt++;
    }
    reverse(b.begin(),b.end());
    rep(i,n-cnt){
        b.push_back(a[i]);
    }
    for(int x : b) cout <<x << ' '; cout <<endl;
    return 0;
}