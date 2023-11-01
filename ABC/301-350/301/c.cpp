#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin >> s >> t;
    int size = s.size();
    map<char,int> s_map,t_map;
    rep(i,size){
        s_map[s[i]]++;
        t_map[t[i]]++;
    }
    for(auto [key,value] : t_map){
        if(key == '@') continue;
        auto itr = s_map.find(key);
        //ある時の処理
        if(itr != s_map.end()){
            if(t_map[key] > s_map[key]){
                    int diff = t_map[key] - s_map[key];
                    s_map['@'] -= diff;
                    if(s_map['@'] < 0){
                        cout << "No" << endl;
                        return 0;
                    }
                    continue;
                }
                if(t_map[key] < s_map[key]){
                    int diff = s_map[key] - t_map[key];
                    t_map['@'] -= diff;
                    if(t_map['@'] < 0){
                        cout << "No" << endl;
                        return 0;
                    }
                    continue;
                } 
                if(t_map[key] == s_map[key]){
                    //t_map[key] =0;
                    //s_map[key] = 0;
                    continue;
                }
        }
        //ない時の処理
        else{
            if(key == 'a' || key == 't' || key == 'c' || key == 'o' || key == 'd' || key == 'e' || key == 'r'){
                s_map['@'] -= t_map[key];
                if(s_map['@'] < 0){
                    cout << "No" << endl;
                    return 0;
                }
            }
            else{
                cout << "No" << endl;
                return 0; 
            }
        }
    } 
    for(auto [key,value] : s_map){
        if(key == '@') continue;
        if(value == 0) continue;
        if(key == 'a' || key == 't' || key == 'c' || key == 'o' || key == 'd' || key == 'e' || key == 'r'){
            t_map['@'] -= s_map[key];
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    if(t_map['@'] >= 0 && s_map['@'] >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}