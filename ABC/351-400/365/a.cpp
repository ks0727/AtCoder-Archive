#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int y;
    cin >> y;
    int ans = -1;
    if(y % 4 != 0) ans = 365;
    else if(y %100!= 0) ans = 366;
    else if(y % 400 != 0 ) ans = 365;
    else ans = 366;
    cout << ans << endl;
    return 0;
}