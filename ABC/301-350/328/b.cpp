#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    int ans = 0;
    for(int i=1;i<=(n);i++){
        for(int j=1;j<=(d[i-1]);j++){
            if(i < 10){
                if(j<10){
                    if(i == j){
                        ans++;
                    }
                }else{
                    int ten = j/10;
                    int one = j%10;
                    if(i == ten && i == one) ans++;
                }
            }else{
                if(i == 10) continue;
                if(i%11 != 0) continue;
                if(j < 10){
                    int day = i/10;
                    if(j == day) ans++;
                }else{
                    if(i == j) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}