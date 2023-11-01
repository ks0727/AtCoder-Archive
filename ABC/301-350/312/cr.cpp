#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    int left = 0;
    int right = 1001001001;
    while(right - left > 1){
        int buy = 0;
        int sell = 0;
        int mid = (right+left)/2;
        rep(i,n) if(a[i] <= mid) sell++;
        rep(i,m) if(b[i] >= mid) buy++;
        if(sell >= buy){
            right = mid;
        }else{
            left = mid;
        }
    }
    cout << right << endl;
    return 0;
}