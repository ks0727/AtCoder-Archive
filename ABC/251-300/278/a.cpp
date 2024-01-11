#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    deque<int> q;
    int n,k;
    cin >> n >> k;
    rep(i,n){
        int a;
        cin >> a;
        q.push_back(a);
    }
    rep(i,k){
        q.pop_front();
        q.push_back(0);
    }
    for(int a : q){
        cout << a << ' ';
    }
    return 0;
}