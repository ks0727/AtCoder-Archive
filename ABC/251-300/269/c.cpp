#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    string s = "";
    while(n > 0){
        s += char(n%2+'0');
        n /= 2;
    }
    int flag = 0;
    rep(i,s.size()){
        if(s[i] == '1'){
            s[i] = '?';
            flag++;
        } 
    }
    set<ll> st;
    auto f = [&](string s,string now)->void{
        string res = "";
        int idx = 0;
        rep(i,s.size()){
            if(s[i] == '?'){
                assert(idx < now.size());
                res += now[idx];
                idx++;
            }else{
                res += '0';
            }
        }
        reverse(res.begin(),res.end());
        ll response = 0;
        rep(i,res.size()){
            if(res[i] == '1'){
                response = response*2+1;
            }else{
                response *= 2;
            }
        }
        st.insert(response);
    };
    rep(bit,1<<flag){
        string now = "";
        rep(i,flag){
            if(bit & (1 << i)) now += '1';
            else now += '0';
        }
        reverse(now.begin(),now.end());
        f(s,now);
    }
    for(ll x : st) cout << x << endl;
    return 0;
}