#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
using ll = long long;

int main(){
    int n,k;
    cin >> n >> k;
    vector<P> med;
    rep(i,n){
        int days,pills;
        cin >> days >> pills;
        med.push_back({days,pills});
    }
    sort(med.rbegin(),med.rend());
    ll sum = 0;
    int ans = 1;
    rep(i,n){
        sum += med[i].second;
        if(sum > k){
            ans = med[i].first + 1;
            break;
        }
        if(sum == k){
            if(i == n-1) break;
            ans = med[i+1].first + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}