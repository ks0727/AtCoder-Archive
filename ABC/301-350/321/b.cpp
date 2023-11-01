#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n-1);
    rep(i,n-1)  cin >> a[i];
    int right = 100;
    int left = 0;
    int mid;
    while(right - left > 1){
        vector<int> s;
        rep(i,n-1) s.push_back(a[i]);
        mid = (right + left)/2;
        s.push_back(mid);
        sort(s.begin(),s.end());
        int check = 0;
        for(int i=1;i<n-1;i++) check += s[i];
        if(check >= x){
            right = mid;
        }else{
            left = mid;
        }
    }
    cout << mid << endl;
    return 0;
}