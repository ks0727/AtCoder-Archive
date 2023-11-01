#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<bool> called(n);

    rep(i,n){
        int person;
        cin >> person;
        if(called[i]) continue;
        called[person-1] = true;
    }
    vector<int> ans;
    int num = 0;
    rep(i,n){
        if(!called[i]){
            ans.push_back(i+1);
            num++;
        } 
    }
    int size = ans.size();
    cout << num << endl;
    rep(i,size) cout << ans[i] << ' ';
    return 0;
}