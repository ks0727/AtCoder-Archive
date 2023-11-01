#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,bool>;

int main(){
    int n,q;
    cin >> n >> q;
    vector<P> people(n);
    vector<int> ans;
    rep(i,n) people[i].first = i+1;
    rep(i,q){
        int event;
        cin >> event;
        if(event == 1){
            rep(j,n){
                if(people[j].second == false){
                    people[j].second = true;
                    break;
                }
            }
        }
        if(event == 2){
            int person;
            cin >> person;
            rep(j,n){
                if(people[j].first == person){
                    people.erase(people.begin()+j);
                } 
            }
        }
        if(event == 3){
            rep(j,n){
                if(people[j].second == true){
                    ans.push_back(people[j].first);
                    break;
                }
            }
        }
    }
    int size = ans.size();
    rep(i,size){
        cout << ans[i] << '\n';
    }
}