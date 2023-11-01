#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    rep(i,n){
        if(c[i] == a+b){
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}