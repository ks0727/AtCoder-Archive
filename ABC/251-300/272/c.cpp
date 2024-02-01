#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> odd,even;
    rep(i,n){
        if(a[i] % 2 == 0){
            even.push_back(a[i]);
        }else{
            odd.push_back(a[i]);
        }
    }
    if(even.size() <= 1 && odd.size() <= 1){
        cout << -1 << endl;
        return 0;
    }else{
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        int ans = -1;
        if(even.size() >= 2){
            ans = even[even.size()-1] + even[even.size()-2];
        }
        if(odd.size() >= 2){
            ans = max(ans,odd[odd.size()-1]+odd[odd.size()-2]);
        }
        cout << ans << endl;
        return 0;
    }
    return 0;
}