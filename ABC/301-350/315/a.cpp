#include<bits/stdc++.h>
using namespace std;

int main(){
    char c[5] = {'a','i','u','e','o'};
    string s;
    cin >> s;
    vector<char> ans(0);
    for(int i=0;i<s.size();i++){
        if(s.at(i) != 'a' && s.at(i) != 'i' && s.at(i) != 'u' && s.at(i) != 'e'&& s.at(i) != 'o'){
            ans.push_back(s.at(i));
        }
    }
    for(int i=0;i<ans.size();i++) cout << ans.at(i);
    cout << endl;
}