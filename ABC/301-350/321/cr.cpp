#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll pow(int a,int b){
    ll ans = 1;
    rep(i,b) ans *= ll(a);
    return ans;
}

int main(){
    int k;
    cin >> k;
    vector<ll> numbers;
    for(ll bit = 0;bit < (1<<10);bit++){
        string s = "";
        rep(i,10){
            if(bit & 1<<(i)){
                s += to_string(i);
            }
        }
        reverse(s.begin(),s.end());
        ll number = -1;
        if(s != "")  number = stoll(s);
        if(number != -1) numbers.push_back(number);
    }
    sort(numbers.begin(),numbers.end());
    cout << numbers[k] << endl;
    return 0;
}