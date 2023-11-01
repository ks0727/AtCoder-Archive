#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> a(n);
    rep(i,n) cin >> s[i] >> a[i];
    int min_a = 1e9;
    rep(i,n) min_a = min(min_a,a[i]);
    int si = 0;
    rep(i,n) if(a[i] == min_a) si = i;
    rep(i,n){
        int ni = (si+i)%n;
        cout << s[ni] << endl;
    }
    return 0;
}