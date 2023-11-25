#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    map<int,int> mp;
    rep(i,n){
        int x;
        cin >> x;
        mp[x]++;
        a[i] = x;
    } 
    int mex = 0;
    vector<int> b = a;
    sort(b.begin(),b.end());
    unique(b.begin(),b.end());
    rep(i,n){
        if(b[i] != i){
            mex = i;
            break;
        }
    }
    rep(qi,q){
        int i,x;
        cin >> i >> x;
        i--;
        int value = a[i];
        mp[value]--;
        mp[x]++;
        a[i] = x;
        if(mex > value && mp[value] == 0){
            mex = value;
            cout << mex << '\n';
            continue;
        }
        if(x == mex && value < mex && mp[value] != 0){
            vector<int> c = a;
            sort(c.begin(),c.end());
            int itr = lower_bound(c.begin(),c.end(),mex) - c.begin();
            if(itr > 0) itr--;
            int mx = n-1;
            if(mx - itr == c[mx] - c[itr]) mex = c[mx]+1;
            else{
                int k = c[itr]+1;
                for(int j = itr+1;j < n;j++){
                    if(c[j] != k){
                        mex = k;
                        break;
                    }else{
                        k++;
                    }
                }
            }
            cout << mex << '\n';
        }else{
            cout << mex << '\n';
        }
    }
    return 0;
}