#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n-1);
    rep(i,n-1) cin >> a[i];
    int left = -1;
    int right = 101;

    while(right - left > 1){
        vector<int> s(n);
        rep(i,n-1) s[i] = a[i];
        int mid = (left+right)/2;
        s[n-1] = mid;
        sort(s.begin(),s.end());
        int sum = 0;
        for(int i=1;i<(n-1);i++){
            sum += s[i];
        }
        if(sum >= x) right = mid;
        else left = mid;
    }
    if(right > 100) cout << -1 <<endl;
    else cout << right << endl;
    return 0; 
}