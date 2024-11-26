#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n%2 ==0){
        cout << "No" << endl;
        return 0;
    }
    rep(i,n){
        if(i<(n+1)/2-1 && s[i] != '1'){
            cout << "No" << endl;
            
            return 0;
        }
        if(i == (n+1)/2-1 && s[i] != '/'){
            cout << "No" << endl;
            return 0;
        }
        if(i > (n+1)/2-1 && s[i] != '2'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}