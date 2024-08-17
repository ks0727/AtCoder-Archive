#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    bool prime = true;
    for(int i=2;i*i<=n;++i){
        if(n % i == 0){
            prime = false;
            break;
        }  
    }
    if(prime) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}