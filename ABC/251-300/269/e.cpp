#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    int c = 1, x = n;
    while(x - c > 0){
        int d = (c+x)/2;
        cout << "? " << 1 <<' '<< n <<' '<< c << ' ' << d << endl;
        int t;
        cin >> t;
        if(t == d-c+1){
            c = d+1;
        }else{
            x = d;
        }
    }
    int a = 1, y = n;
    while(y - a > 0){
        int b = (a+y)/2;
        cout << "? " << a << ' ' << b << ' '<< 1 << ' ' << n << endl;
        int t;
        cin >> t;
        if(t == b-a+1){
            a = b+1;
        }else{
            y = b;
        }
    }
    cout << "! " << y << ' ' << x << endl;
    return 0;
}