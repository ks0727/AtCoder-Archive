#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    map<long long,int> mp;
    long long ans = 0;
    for(int i=0;i<n;i++){
        long long now = i - a[i];
        ans += mp[now];
        long long add = i+a[i];
        mp[add]++;
    }
    cout << ans << endl;
    return 0;
}