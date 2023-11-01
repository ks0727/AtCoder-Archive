#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    if(n == 1){
        cout<< ans << endl;
        return 0;
    }
    rep(i,n) cin >> a[i];
    int max = *max_element(a.begin(),a.end());
    int min = *min_element(a.begin(),a.end());
    int average = int((max + min) /2);
    
    vector<int> dif(n);
    rep(i,n){
        dif[i] = a[i] - average;
    }
    int negative,positive;
    rep(i,n){
        if(dif[i] < 0) negative += dif[i];
        else positive += dif[i];
    }
    int abs = positive - negative;
    ans = abs / 2;
    cout << ans << endl;
}