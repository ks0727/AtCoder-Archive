#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll x; int k;
    cin >> x >> k;
    vector<int> num;
    ll nx = x;
    int d = 0;
    while(nx >= 10){
        nx /= 10;
        d++;
    }
    d++;
    if(d < k){
        cout << 0 << endl;
        return 0;
    }
    for(int i = d;i>=1;i--){
        int v = x%10;
        num.push_back(v);
        x /= 10;
        d--;
    }
    num.push_back(0);
    rep(i,k){
        if(num[i] <= 4){
            num[i] = 0;
        }else{
            int j = i;
            num[j] = 9;
            while(num[j] == 9 && j < k+1){
                num[j] = 0;
                num[j+1] += 1;
            }
        }
    }
    ll ans = 0;
    reverse(num.begin(),num.end());
    rep(i,num.size()){
        ans *= 10;
        ans += num[i];
    }
    cout << ans << endl;
    return 0;
}
