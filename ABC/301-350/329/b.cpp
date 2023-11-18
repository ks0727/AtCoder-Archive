#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int mx = a.back();
    while(a.back() == mx){
        a.pop_back();
    }
    cout << a.back() << endl;
    return 0;
}