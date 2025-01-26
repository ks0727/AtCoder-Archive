#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n=5;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    rep(i,n-1){
        vector<int> b = a;
        swap(b[i],b[i+1]);
        bool ok = true;
        rep(j,4){
            if(b[j] > b[j+1]) ok = false;
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}