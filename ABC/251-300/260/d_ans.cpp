#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n>> k;
    set<int> tops;
    vector<int> nxt(n,-1),num(n);
    vector<int> ans(n,-1);
    rep(ni,n){
        int p;
        cin >> p;
        p--;
        auto it = tops.lower_bound(p);
        if(it == tops.end()){
            num[p] = 1;
            tops.insert(p);
        }else{
            int i = *it;
            tops.erase(it);
            nxt[p] = i;
            num[p] = num[i]+1;
        }
        if(num[p] == k){
            tops.erase(p);
            int i = p;
            while(i != -1){
                ans[i] = ni+1;
                i = nxt[i];
            }
        }else{
            tops.insert(p);
        }
    }
    return 0;
}