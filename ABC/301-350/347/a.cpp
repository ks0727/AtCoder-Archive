#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n){
        if(a[i]%k == 0){
            cout << a[i]/k << ' ';
        }
    }
    cout << endl;
    return 0;
}
