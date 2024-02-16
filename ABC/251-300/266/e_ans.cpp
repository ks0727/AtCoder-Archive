#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    double ans = 0;
    rep(i,n){
        double now = 0;
        for(int j=1;j<=6;j++){
            now += max(double(j),ans);
        }
        ans = now/6;
    }
    printf("%.10f\n",ans);
    return 0;
}