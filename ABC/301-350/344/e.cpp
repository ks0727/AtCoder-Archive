#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int,int> parent,child;
    const int INF = 1001001001;
    if(n <= 1){
        child[-1] = a[0];
        parent[INF] = a[0];
        child[a[0]] = INF;
        parent[a[0]] = -1;
    }else{
        child[-1] = a[0];
        parent[INF] = a[n-1];
        rep(i,n){
            if(i == 0){
                parent[a[i]] = -1;
                child[a[i]] = a[i+1];
            }else if(i == n-1){
                parent[a[i]] = a[i-1];
                child[a[i]] = INF;
            }
            else{
                parent[a[i]] = a[i-1];
                child[a[i]] = a[i+1];
            }
        }
    }
    int q;
    cin >> q;
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int x,y;
            cin >> x >> y;
            parent[child[x]] = y; //xの子供の親をyにする
            child[y] = child[x]; //yの子供をxの子供にする
            child[x] = y; //xの子をyにする
            parent[y] = x; //yの親をxにする
        }else{
            int x;
            cin >> x;
            parent[child[x]] = parent[x]; //子供の親をxの親にする
            child[parent[x]] = child[x]; //親の子供をxの子供にする
            child[x] = -INF; //接続を切る
            parent[x] = -INF; //接続を切る
        }
    }
    int now = -1;
    while(child[now] != INF){
        cout << child[now] << ' ';
        now = child[now];
    }
    cout << endl;
    return 0;
}