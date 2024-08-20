#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    bool ok = true;
    while(b != c){
        if(b == a){
            ok = false;
            break;
        }else{
            b++;
            if(b == 24) b = 0;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}