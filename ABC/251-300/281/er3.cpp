#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct DS{
    ll sum,k;
    multiset<int> left,right;
    DS(int k):k(k),sum(0){}
    void add(int x){
        if(left.size() < k) ladd(x); //もしleftが空いていたらleftに入れる
        else{ //もしleftがいっぱいだったら
            if(x < *left.rbegin()){ //もしxをleftに入れるなら
                int y = *left.rbegin();
                lerase(y);
                ladd(x);
                radd(y);
            }else{
                radd(x);
            }
        }
    }
    void printl(){
        for(int x : left) cout << x << ' '; cout << endl;
    }
    void printr(){
        for(int x : right) cout << x << ' '; cout << endl;
    }
    void ladd(int x){
        left.insert(x);
        sum += x;
    }
    void radd(int x){
        right.insert(x);
    }
    void lerase(int x){
        auto it = left.find(x);
        if(it != left.end()){
            left.erase(it);
            sum -= x;
        } 
    }
    void rerase(int x){
        auto it = right.find(x);
        if(it != right.end()) right.erase(it);
    }
};

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    DS d(k);
    rep(i,m) d.add(a[i]);
    rep(i,n-m+1){
        cout << d.sum << ' ';
        if(a[i] <= *d.left.rbegin()){ //a[i]が左側に入っていた時
            d.lerase(a[i]);
            if(a[i+m] < *d.right.begin()){ //もしもa[i+m]が右の最小よりも小さければ
                d.ladd(a[i+m]);
            }else{
                d.radd(a[i+m]);
                int x = *d.right.begin();
                d.rerase(x);
                d.ladd(x);
            }
        }else{ //a[i]が右側に入っていた時
            d.rerase(a[i]);
            if(a[i+m] < *d.right.begin()){ //もしもa[i+m]が右の最小よりも小さければ
                d.ladd(a[i+m]);
                int x = *d.left.rbegin();
                d.lerase(x);
                d.radd(x);
            }else{
                d.radd(a[i+m]);
            }
        }
    }
    return 0;
}