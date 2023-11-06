#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0;i<(n);i++)

int pow(int a,int b){
    int ans = 1;
    rep(i,b){
        ans *= a;
    }
    return ans;
}

int main(){
    int ans = 0;
    for(int i=1;i<=6;i++){
        ans += pow(2,i)-1;
    }
    for(int j=7;j<=(10);j++){
        ans += pow(2,j)-1;
    }
    cout << ans << endl;
    return 0;
}