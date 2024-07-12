#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());

    int l = 0,r = n-1;
    int mx = a[r];
    int mn = a[l];
    while(k > 0){
        int nmx = a[r-1];
        int nmn = a[l+1];
        if(mx - nmn > nmx - mn){
            r--;
            mx = nmx;
            k--;
        }else if(mx - nmn > nmx - mn){
            l++;
            mn = nmn;
            k--;
        }else{
            if(k == 1){
                mx = nmx;
                r--;
                k--;
            }
            while(k > 1 && mx - nmn == nmx - mn){
                k -= 2;
                mx = nmx;
                mn = nmn;
                nmx = a[r--];
                nmn = a[l++];
            }
        }
        
    }
    cout << mx - mn << endl;
    return 0;
}