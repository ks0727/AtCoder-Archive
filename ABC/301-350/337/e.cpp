#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    int m = 0;
    if(n <= 3) m = n-1;
    else m = n-2;  
    cout << m << endl;
    if(n <= 3){
        rep(i,m){
            cout << 1 << ' ' << i+1 << endl;
        }
    }else{
        rep(i,m){
            cout << 2 << ' ' << i+1 << ' ' << i+2 << endl;
        }
    }
    string s;
    cin >> s;
    rep(i,m){
        if(s[i] == '1'){
            if(i == m-1){
                cout << n-1 << endl;
                return 0;
            }else{
                if(s[i+1] == '1'){
                    cout << i+2 << endl;
                    return 0;
                }else{
                    cout << i+1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << n << endl;
    return 0;
}