#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    int t = 0, a= 0;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        t += x; a += y;
    }
    if(t > a){
        cout << "Takahashi" << endl;
    }
    else if(t < a){
        cout << "Aoki" << endl;
    }else{
        cout << "Draw" << endl;
    }
    return 0;
}