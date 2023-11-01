#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    queue<int> people;
    set<int> called;
    set<int> went;
    vector<int> ans;
    rep(i,n) people.push(i+1);
    rep(i,q){
        int event;
        cin >> event;
        if(event == 1){
            int person = people.front(); people.pop();
            called.insert(person);
        }
        if(event == 2){
            int x;
            cin >> x;
            went.insert(x);
            called.erase(x);
        }
        if(event == 3){
            for(auto person : called){
                if(went.count(person)) continue;
                cout << person << endl;
                break;
            }
        }
    }
    rep(i,ans.size()) cout << ans[i] << endl;
    return 0;
}