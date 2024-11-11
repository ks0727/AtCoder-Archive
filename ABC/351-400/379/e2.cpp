#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll sum = 0;
    rep(i,n) sum += (ll)(s[i]-'0')*(i+1);
    string t = string(10*n,'0');
    int prev = 0;
    rep(i,n){
        string ns = to_string(sum);
        reverse(ns.begin(),ns.end());
        rep(j,ns.size()){
            int d = t[i+j]-'0';
            int nd = ns[j]-'0';
            int x = d+nd+prev;
            assert(x < 100);
            t[i+j] = (x%10)+'0';
            prev = x/10;
        }   
        t[ns.size()+i] = prev+'0';
        sum -= (ll)(s[n-i-1]-'0')*(n-i);
    }
    while(t.back() == '0') t.pop_back();
    if(t.size() == 0){
        cout << 0 << endl;
    }else{
        reverse(t.begin(),t.end());
        cout << t << endl;
    }
    return 0;
}