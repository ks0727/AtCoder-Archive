#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n-1);
    rep(i,n-1) cin >> a[i];
    int num = 0;
    while(num < 101){
        vector<int> s;
        rep(i,n-1) s.push_back(a[i]);
        s.push_back(num);
        sort(s.begin(),s.end());
        int sum = 0;
        for(int i=1;i<n-1;i++) sum += s[i];
        if(sum < x) num++;
        else break;
    }
    if(num > 100) cout << -1 << endl;
    else cout << num << endl;
}