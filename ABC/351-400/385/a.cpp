#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    bool ok = false;
    if(a == b && b == c) ok = true;
    if(a + b == c) ok = true;
    if(b+c == a) ok = true;
    if(a+c == b) ok = true;
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}