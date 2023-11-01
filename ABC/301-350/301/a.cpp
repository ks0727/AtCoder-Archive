#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t = 0,a = 0;
    rep(i,n){
        if(s[i] == 'T') t++;
        if(s[i] == 'A') a++;
        if(t >= (n+1)/2){
            cout << 'T' << endl;
            return 0;
        }
        if(a >= (n+1)/2){
            cout << 'A' << endl;
            return 0;
        }
    }
    if(a > t) cout << 'A' << endl;
    else cout << 'T' << endl;
    return 0;
}