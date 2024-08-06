
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    b = a;
    sort(a.begin(),a.end());
    int key = a[n-2];
    rep(i,n){
        if(b[i] == key){
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}