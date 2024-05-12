#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int value[] = {1,5,10,50,100,500};
    vector<int> coins(6);
    rep(i,6) cin >> coins[i];
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    rep(i,n){
        for(int j=5;j>=0;j--){
            int need = x[i]/value[j];
            if(need <= coins[j]){
                coins[j] -= need;
                x[i] -= value[j]*need;
            }else{
                x[i] -= coins[j]*value[j];
                coins[j] = 0;
            }
        }
        if(x[i] != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}