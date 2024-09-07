#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n,k,l;
    cin >> n >> k >> l;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int lb = 0, rb = n+5;

    while(rb-lb > 1){
        int mid = (lb+rb)/2;
        int j = 0;
        ll sum = 0;
        int cnt = 0;
        rep(i,n){
            while(j < n && cnt < k){
                if(a[j] < mid) cnt++;
                j++;
            }
            if(cnt >= k) sum += n-j+1;
            if(i == j) j++;
            else if(a[i] < mid) cnt--;
        }
        if(sum >= l) rb = mid;
        else lb = mid;
    }
    cout << lb << endl;
    return 0;
}
