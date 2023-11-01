#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    if(n == 1){
        cout<< ans << endl;
        return 0;
    }
    while(true){
        int max,min;
        bool increased = false,decreased = false;
        max = *max_element(a.begin(),a.end());
        min = *min_element(a.begin(),a.end());
        if(max - min <= 1) break;
        rep(i,n){
            if(increased && decreased) break;
            else{
                if(!decreased){
                    if(a[i] == max){
                    decreased = true;
                    a[i]--;
                    }
                }
                if(!increased){
                    if(a[i] == min){
                    increased = true;
                    a[i]++;
                    }
                }
                
            }
            
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}