#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int a,b;
    cin >> a >> b;
    if(a+1 == b){
        if(a%3 != 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(a == b+1){
        if(b%3 != 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}