#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Node{
    int next; int val;
    Node(int next=-1,int val=-1):next(next),val(val){}
};

struct List{
    Node head; Node last;
    List():head(head){
        head.val = -1;
        head.next = head.val;
    }
    void push(Node x){
        x.next = last.val;
        last.val = x.val;
    }
    void print(){
        while(last.next == head.val){
            cout << last.val << ' ';
            last.val = last.next;
        }
        cout << endl;
    }
};

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    rep(i,n) p[i]--;
    if(k == 1){
        rep(i,n){
            cout << p[i]+1 << endl;
        }
        return 0;
    }
    dsu uf(n);
    vector<int> ans(n,-1);
    set<int> piles;
    const int INF = 1001001001;
    piles.insert(INF);
    rep(i,n){
        int key = *lower_bound(piles.begin(),piles.end(),p[i]);
        if(key != INF){ //重ねる山がある時
            uf.merge(p[i],key);
            if(uf.size(p[i]) == k){ //すでに山が満タンになった時
                piles.erase(key);
                ans[uf.leader(p[i])] = i+1;
            }else{ //まだ行ける時
                piles.erase(key);
                piles.insert(p[i]);
            }
        }else{ //それが山の1枚目になる時
            piles.insert(p[i]);
        }
    }
    rep(i,n){
        cout << ans[uf.leader(i)] << endl;
    }
    return 0;
}