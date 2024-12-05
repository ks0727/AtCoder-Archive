#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,d;
    cin >> n >> d;
    string s;
    cin >> s;
    for(int i=n-1;i>=0;i--){
        if(d > 0 && s[i] == '@'){
            s[i] = '.';
            d--;
        }
    }
    cout << s << endl;
    return 0;
}