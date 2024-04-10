#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int y;
    cin >> y;
    rep(i,1000){
        if((i+y)%4 == 2){
            cout << i+y << endl;
            return 0;
        }
    }
    return 0;
}