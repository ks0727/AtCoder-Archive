#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i,n) cin >> a[i];
    if(n == 2){
        cout << "Yes" << endl;
        return 0;
    }
    rep(i,n-2){
        if(a[i+1]*a[i+1] != a[i]*a[i+2]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl; 
    return 0;
}