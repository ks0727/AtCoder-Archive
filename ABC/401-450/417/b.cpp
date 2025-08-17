#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    vector<bool> erased(n,false);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[j] == b[i] && !erased[j]){
                erased[j] = true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!erased[i]) cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}