#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    int m = 0;
    while((1<<m) < n) m++;
    cout << m << endl;
    rep(i,m){
        vector<int> a;
        rep(j,n) if((j>>i)&1) a.push_back(j);
        cout << a.size();
        for(int j : a) cout << ' ' << j;
        cout << endl;
    }
    string s;
    cin >> s;
    int ans = 0;
    rep(i,m) if(s[i] == 1) ans |= 1<<i;
    cout << ans+1 << endl;
    return 0;
}