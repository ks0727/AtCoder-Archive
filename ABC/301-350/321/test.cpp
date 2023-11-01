#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int k;
    cin >> k;
    vector<ll> likes;
    rep(i,9) likes.push_back(i+1);
    for(int i=1;i <10;i++){
        queue<string> que;
        que.push(to_string(i));
        while(!que.empty()){
            string s = que.front();
            que.pop();
            char c = *(s.end()-1);
            c--;
            if(c == '0'){
                likes.push_back(stol(s+c));
                break;
            } 
            que.push(s+c);
            likes.push_back(stol(s+c));
        }
    }
    sort(likes.begin(),likes.end());
    rep(i,likes.size()) cout << likes[i] << ' ';
    cout << endl;
    cout << likes[k] << endl;
    return 0;
}