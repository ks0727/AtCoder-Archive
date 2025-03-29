#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    int prev = -1;
    rep(i,n){
        int a;
        cin >> a;
        if(a <= prev){
            cout << "No" << endl;
            return 0;
        }
        prev = a;
    }
    cout << "Yes" << endl;
    return 0;
}