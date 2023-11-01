#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll pow(int a,int b){
    ll num = 1;
    rep(i,b){
        num *= a;
    }
    return num;
}


int main(){
    string s;
    cin >> s;
    ll n;
    cin >> n;
    int digit = 0;
    int size = s.size();
    rep(i,25){
        ll test = pow(2,i);
        if(test >= n){
            digit = i;
            break;
        }
    }

    rep(i,max(size-digit,1)){
        if(s[i] == '1'){
            cout << -1  << endl;
            return 0;
        } 
    }
    string ns = s.substr(size-digit,2); 

}