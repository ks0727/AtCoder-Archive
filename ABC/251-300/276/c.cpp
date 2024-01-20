#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    reverse(p.begin(),p.end());
    int change = -1;
    int j = -1;
    for(int i=1;i<n;i++){
        if(p[i] > p[i-1]){
            change = p[i];
            j = i;
            break;
        }
    }
    int nd = -1;
    int nd_idx = -1;
    rep(i,j+1){
        if(p[i] < change){
            if(nd < p[i]){
                nd_idx = i;
                nd = p[i];
            }
        }
    }
    swap(p[nd_idx],p[j]);
    reverse(p.begin(),p.end());
    sort(p.begin()+n-j,p.end());
    reverse(p.begin()+n-j,p.end());
    rep(i,n){
        cout << p[i] << ' ';
    }
    cout << endl;
    return 0;
}