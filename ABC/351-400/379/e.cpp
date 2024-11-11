#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "";
    long long sum = 0;
    rep(i,n) sum += (s[i] - '0')*(i+1);
    bool prev = false;
    rep(i,n){
        string ns = to_string(sum);
        reverse(ns.begin(),ns.end());
        if(ns.size() > t.size()-i){
            t += string(ns.size()+1,'0');
        }
        rep(j,ns.size()){
            int ti = t[i+j]-'0';
            int nsi = ns[j]-'0';
            int digit = ti+nsi;
            digit += (prev?1:0);
            prev = digit/10 >= 1;
            t[i+j] = (digit%10)+'0'; 
        }
        if(prev) t[i+ns.size()] = '1';
        sum -= (s[n-i-1]-'0')*(n-i);
    }
    while(t.back() == '0') t.pop_back();
    if(t.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    for(int i=t.size()-1;i>=0;i--) cout << t[i];
    cout << endl;
    return 0;
}