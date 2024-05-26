#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n,t;
    cin >> n >> t;
    vector<bool> used(n*n);
    vector<int> a(t);
    rep(i,t){
        cin >> a[i];
        a[i]--;
    } 
    rep(ti,t){
        int now = a[ti];
        used[now] = true;
        int i = now/n; int j = now%n;
        for(int r = j;r<n*n;r+=n){
            if(!used[r]){
                break;
            }
            if(r/n == n-1){
                cout << ti+1 << endl;
                return 0;
            }
        }
        for(int c=i*n;c<i*n+n;c++){
            if(!used[c]){
                break;
            }
            if(c ==i*n+n-1){
                cout << ti+1 << endl;
                return 0;
            }
        }
        if(i == j){
            for(int x = 0;x<n*n;x+=n+1){
                if(!used[x]) break;
                if(x == n*n-1){
                    cout << ti+1 << endl;
                    return 0;
                }
            }
        }
        if(i+j == n-1){
            for(int x = n-1;x<=n*n-n;x+=n-1){
                if(!used[x]) break;
                if(x == n*n-n){
                    cout << ti+1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}