#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> s(n+1);
    for(int i =1;i<=(n);i++) cin >> s[i];
    vector<int> a(n);
    rep(i,n){
        a[i] = s[i+1] - s[i];
    }
    rep(i,n) cout << a[i] << ' ';
    cout << endl;
    return 0;
}