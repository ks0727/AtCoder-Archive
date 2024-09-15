#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    cin >> n >> m;
    set<int> boys;
    rep(i,m){
        int a; char b;
        cin >> a >> b;
        if(b == 'F'){
            cout << "No" << endl;
            continue;
        }else{
            if(boys.count(a)){
                cout << "No" << endl;
            }else{
                cout << "Yes" << endl;
                boys.insert(a);
            }
        }
    }
    return 0;
}