#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    rep(i,n){
        rep(j,n){
            int d = min({i,j,n-1-i, n-1-j});
            if(d % 2 == 0)
                cout << "#";
            else
                cout << ".";
        }
        cout << "\n";
    }
    return 0;
}
