#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool solve(){
    int n,a,b;
    cin >> n >> a >> b;
    int num = n - a;
    if(num < 0) return false;
    while(n > 0){
        a--;
        b-=num;
        n-=2;
        if(a == n) break;
    }
    if(b <= 0) return true;
    else return false;
}

int main(){
    int t;
    cin >> t;
    rep(ti,t){
        if(solve()) cout << "Yes" << endl;
        else cout << "No" << endl;  
    }
    return 0;
}