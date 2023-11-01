#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<deque<char> > colors(m);
    string s;
    vector<int> color_order;
    cin >> s;
    rep(i,n){
        int color;
        cin >> color;
        color--;
        colors[color].push_back(s[i]);
        color_order.push_back(color);
    }
    rep(i,m){
        char c_front = colors[i].back();
        colors[i].pop_back();
        colors[i].push_front(c_front);
    }
    string ans = "";
    rep(i,n){
        int color = color_order[i];
        ans += colors[color].front();
        colors[color].pop_front();
    }
    cout << ans << endl;
    return 0;
}