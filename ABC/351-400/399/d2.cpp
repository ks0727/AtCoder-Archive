#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int n2 = 2 * n;
    vector<int> a(n2);
    vector<pair<int,int>> ps(n, {-1, -1});
    for (int i = 0; i < n2; i++){
        cin >> a[i], a[i]--;   
    }
    for (int i = 0; i < n2; i++){
        int idx = a[i];
        if(ps[idx].first == -1) 
            ps[idx].first = i;
        else 
            ps[idx].second = i;
    }
    
    auto encode = [n2](int p, int q) -> long long {
        return (long long)p * n2 + q;
    };
    
    unordered_map<long long, int> mp;
    for (int i = 0; i < n; i++){
        int p = ps[i].first, q = ps[i].second;
        mp[encode(p, q)] = i;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++){
        int p = ps[i].first, q = ps[i].second;
        if(q + 1 < n2){
            int cp = p + 1;
            int cq = q + 1;
            if(mp.find(encode(cp, cq)) != mp.end()){
                ans++;
            }
        }
        if(p + 1 < q - 1){
            int cp = p + 1;
            int cq = q - 1;
            if(mp.find(encode(cp, cq)) != mp.end()){
                ans++;
            }
        }
    }
    
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
