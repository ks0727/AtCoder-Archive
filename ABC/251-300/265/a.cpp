#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int x,y,n;
    cin >> x >> y >> n;
    int ans = 1001001001;
    for(int i=0;i<=n;i++){
        for(int j=0;j*3<=n;j++){
            if(i+j*3 == n){
                ans = min(ans,i*x+y*j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}