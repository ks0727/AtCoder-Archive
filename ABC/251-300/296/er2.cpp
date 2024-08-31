#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n),dim(n);
    set<int> vs;
    rep(i,n){
        cin >> a[i];a[i]--;
        vs.insert(i);
        dim[a[i]]++;
    } 
    queue<int> q;
    rep(i,n) if(dim[i] == 0) q.push(i);
    while(!q.empty()){
        int v = q.front(); q.pop();
        vs.erase(v);
        dim[a[v]]--;
        if(dim[a[v]] == 0) q.push(a[v]);
    }
    cout << vs.size() << endl;
    return 0;
}