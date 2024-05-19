#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >>n ;
    vector<string> s(n);
    vector<int> c(n);
    rep(i,n) cin >> s[i] >>c[i];
    ll t = 0;
    rep(i,n) t += c[i];
    int win = t%n;
    sort(s.begin(),s.end());
    cout << s[win] << endl;
    return 0;
}