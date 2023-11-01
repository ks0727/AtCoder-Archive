#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<bool> seen(n);
    vector<int> ans;
    ans.push_back(1);
    seen[0] = true;
    int prev = 0;
    while(true){
        int value = a[prev];
        if(seen[value-1]){
            rep(i,ans.size()){
                if(ans[i] == value){
                    ans.erase(ans.begin(),ans.begin()+i);
                    //ans.pop_back();
                    cout << ans.size() << endl;
                    rep(j,ans.size()) cout << ans[j] << ' ';
                    return 0;
                }
            }
        }
        ans.push_back(value);
        seen[value-1] = true;
        prev = value - 1;
    }
    return 0; 
}