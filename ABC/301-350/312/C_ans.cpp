#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a.at(i);
    for(int i=0;i<m;i++) cin >> b.at(i);
    vector<pair<int,int> > events; //eventsという配列に,Aの値段とBの値段を全て入れる。さらにその値段が　AとBどちらから来たのかを判断できるように、0,1を入れる
    for(int i=0;i<n;i++) events.push_back(make_pair(a.at(i),0));
    for(int i=0;i<m;i++) events.push_back(make_pair(b.at(i)+1,1)); //ここでBからの値には1が足されている！！
    sort(events.begin(),events.end()); //eventsをソートする
    int na = 0, nb = m;
    for(auto[p,type] : events){
        if(type == 0) na++;
        else nb--;
        cout << p << endl;
        if(na >= nb){
            cout << p << endl;
            break;
        }
    }
}