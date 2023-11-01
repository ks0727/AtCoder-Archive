#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<pair<int,string> > people;
    int youngest = -1;
    int minage = 2e9;
    rep(i,n){
        string name;
        int age;
        cin >> name >> age;
        people.push_back(make_pair(age,name));
        if(minage > age){
            minage = age;
            youngest = i;
        }
    }
    for(int i = youngest;i<n;i++){
        cout << people[i].second << endl;
    }
    for(int i =0;i<youngest;i++){
        cout << people[i].second << endl;
    }
    return 0;
}