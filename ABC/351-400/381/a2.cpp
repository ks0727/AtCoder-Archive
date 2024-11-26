#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n %2 == 0){
        cout << "No" << endl;
        return 0;
    }
    vector<pair<char,int> > rle;
    for(char c : s){
        if(rle.size() > 0 && rle.back().first == c){
            rle.back().second++;
        }else{
            rle.emplace_back(c,1);
        }
    }
    if(rle.size() == 3){
        if(rle[0].first == '1' && rle[1].first == '/' && rle[2].first == '2' && rle[0].second == rle[2].second && rle[1].second == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        if(s == "/") cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}