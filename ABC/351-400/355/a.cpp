#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int a,b;
    cin >> a >> b;
    if(a == b){
        cout << -1 << endl;
        return 0;
    }
    if(a > b) swap(a,b);
    if(a != 1){
        cout << 1 << endl;
    }else if(b != 2){
        cout << 2 << endl;
    }else{
        cout << 3 << endl;
    }
    return 0;
}