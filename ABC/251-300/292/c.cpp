#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int patterns(int ab){
    int pattern = 0;
    bool minus = false;
    for(int a = 1;a*a<=ab;a++){
        if(ab % a == 0) pattern++;
        if(ab / a == a && ab % a == 0) minus = true; 
    }
    pattern *= 2;
    if(minus) pattern--;
    return pattern;
}

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int ab = 1;2 * ab<=n;ab++){
        int cd = n - ab;
        ll pattern = 0;
        if(2*ab != n) pattern = (ll)patterns(ab)*patterns(cd)*2;
        else  pattern = (ll)patterns(ab)*patterns(cd);
        ans += pattern;
    }
    cout << ans << endl;
    return 0;
}