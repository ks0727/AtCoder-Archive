#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int a,b;
    cin >> a >> b;
    set<int> t;
    auto f = [&](int x){
        if(x == 1){
            t.insert(1);
        }else if(x == 2){
            t.insert(2);
        }else if(x == 4){
            t.insert(4);
        }else if(x == 5){
            t.insert(1);
            t.insert(4);
        }else if(x == 3){
            t.insert(1);
            t.insert(2);
        }else if(x == 7){
            t.insert(1);
            t.insert(2);
            t.insert(4);
        }else if(x == 6){
            t.insert(2);
            t.insert(4);
        }
    };
    f(a);
    f(b);
    int ans = 0;
    for(int x : t){
        ans += x;
    }
    cout << ans << endl;
    return 0;
}