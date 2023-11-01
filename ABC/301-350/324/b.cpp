#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll pow(int a, int b){
    ll ans = 1;
    rep(i,b){
        ans *= (ll)a;
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    rep(i,60){
        rep(j,50){
            if( n == pow(2,i)*pow(3,j)){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}