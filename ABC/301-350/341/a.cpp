#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    rep(i,2*n+1){
        if(i%2 == 0) cout << '1';
        else cout << '0';
    }
    cout << endl;
    return 0;
}