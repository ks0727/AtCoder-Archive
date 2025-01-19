#include <bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int Q;
    cin >> Q;
    fenwick_tree<long long> a(Q+1);
    int offset = 0;
    int last = 0;
    while(Q--){
        int type;
        cin >> type;
        if(type == 1){
            long long l;
            cin >> l;
            a.add(last,l);
            last++;
        }
        else if(type == 2){
            long long val = a.sum(offset,offset+1);
            a.add(offset,-val);
            offset++;
        }
        else if(type == 3){
            int k;
            cin >> k;
            long long now = a.sum(0,k+offset-1);
            cout << now << endl;
        }
        //rep(i,5) cout << a.sum(i,i+1) << ' '; cout << endl;
    }
    return 0;
}