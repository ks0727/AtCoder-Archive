#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int INF = 1001001001;

struct Node{
    int pre,next;
    Node(int pre=-1,int next = -1):pre(pre),next(next){}
};

struct List{
    unordered_map<int,Node> nodes;
    int head,tail;

    List():head(-INF),tail(INF){
        nodes[head] = Node(-1,tail);
        nodes[tail] = Node(head,-1);
    } //headとtailを-1で初期化

    void erase(int x){
        Node a = nodes[x];
        nodes[a.pre].next = a.next;
        nodes[a.next].pre = a.pre;
        nodes.erase(x);
    }

    void add(int x,int y){
        int z = nodes[x].next;
        nodes[x].next = y;
        nodes[z].pre = y;
        nodes[y] = Node(x,z);
    }

    void print(){
        int i = nodes[head].next;
        while(i != tail){
            cout << i << ' ';
            i = nodes[i].next;
        }
        cout << endl;
    }

};

int main(){
    int n,q;
    cin >> n >> q;
    List d;
    {
        int now = d.head;
        rep(i,n){
            int a;
            cin >> a;
            d.add(now,a);
            now = a;
        }
    }
    cin >> q;
    rep(qi,q){
        int type,x;
        cin >> type >> x;
        if(type == 1){
            int y;
            cin >> y;
            d.add(x,y);
        }else{
            d.erase(x);
        }
    }
    d.print();
    return 0;
}