#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int r;
    cin >> r;
    int ans = -1;
    if(r <= 99) ans = 100 - r;
    else if(r <= 199) ans = 200 - r;
    else if(r <= 299) ans = 300 - r;
    cout << ans << endl;
    return 0;
}