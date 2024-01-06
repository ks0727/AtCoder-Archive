#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,q;
    cin >> n >> q;
    deque<P> dq;
    rep(i,n){
        dq.push_back(P(i+1,0));
    }
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            char c;
            cin >> c;
            P np = dq.front();
            if(c == 'U'){
                np.second++;
            }
            if(c == 'D'){
                np.second--;
            }
            if(c == 'R'){
                np.first++;
            }
            if(c == 'L'){
                np.first--;
            }
            dq.pop_back();
            dq.push_front(np);
        }else{
            int p;
            cin >> p;
            p--;
            cout << dq[p].first << ' ' << dq[p].second << endl;
        }
    }
    return 0;
}