#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int a,b,d;
    cin >> a >> b >> d;
    int x = a;
    while(1){
        cout << x << ' ';
        if(x == b) break;
        x += d;
    }
    cout << endl;
    return 0;
}