#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int Q;
    cin >> Q;
    queue<long long> q;
    vector<long long> ps;
    ps.push_back(0);
    long long gone = 0;
    long long gc = 0;
    while(Q--){
        int type;
        cin >> type;
        if(type == 1){
            long long l;
            cin >> l;
            ps.push_back(ps.back()+l);
        }
        else if(type == 2){
            gc++;
            gone += ps[gc] - ps[gc-1];
        }
        else if(type == 3){
            int k;
            cin >> k;
            k--;
            cout << ps[k+gc] - gone << endl;
        }
    }
    return 0;
}