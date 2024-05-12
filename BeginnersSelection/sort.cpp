#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    vector<int> a = {4,6,7,3,2,5,9,1,8};
    auto selection_sort = [&](vector<int> &a)->vector<int>{
        int n = a.size();
        rep(i,n){
            int mn = a[i];
            int mn_idx = i;
            for(int j=i+1;j<(n);j++){
                if(a[j] < mn){
                    mn_idx = j;
                    mn = a[j]; 
                }
            }
            swap(a[mn_idx],a[i]);
            rep(i,n) cout << a[i] << " "; cout << endl;
        }
        return a;
    };
    auto bubble_sort = [&](vector<int> &a)->vector<int>{
        int n = a.size();
        rep(i,n){
            rep(j,n-i-1){
                if(a[j] > a[j+1]){
                    swap(a[j],a[j+1]);
                }
            }
            rep(j,n) cout << a[j] << " "; cout << endl;
        }
        return a;
    };
    auto quick_sort = [&](auto quick_sort,vector<int> &a)->vector<int>{
        if(a.size() == 2){
            if(a[0] > a[1]) swap(a[0],a[1]);
            return a;
        }
        rep(i,a.size()) cout << a[i] << " "; cout << endl;
        vector<int> before,after;
        int v = a[0];
        rep(i,a.size()){
            if(a[i] <= v) before.push_back(a[i]);
            else after.push_back(a[i]);
        }
        vector<int> res;
        vector<int> resb,resa;
        resb = quick_sort(quick_sort,before);
        resa = quick_sort(quick_sort,after);
        rep(i,resb.size()) res.push_back(resb[i]);
        rep(i,resa.size()) res.push_back(resa[i]);
        return res;
    };
    vector<int> ans = quick_sort(quick_sort,a);
    for(int x : ans) cout <<  x << ' '; cout << endl;
    return 0;
}