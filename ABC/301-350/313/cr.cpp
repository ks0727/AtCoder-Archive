#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    vector<int> a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    
    sort(a.begin(),a.end());
    vector<int> final;
    int rest = sum % n;
    int ave = sum / n;
    rep(i,n-rest) final.push_back(ave);
    rep(i,rest) final.push_back(ave+1);
    int gap = 0;
    rep(i,n){
        if(a[i] < final[i]){
            gap += a[i] - final[i];
        }
    }
    cout << -gap << endl;
    return 0;
}