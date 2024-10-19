include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    int values[37][100] = {0};
    rep(i,n){
        cin >> c[i];
        rep(j,c[i]){
            int value;
            cin >> value;
            values[value][i]++;
        }
    }
    int x;
    cin >> x;
    vector<int> people;
    rep(i,100){
        if(values[x][i] != 0){
            people.push_back(i+1);
        }
    }
    
    vector<int> ans;
    if(people.size() > 0){
        rep(i,people.size()){
        ans.push_back(c[people[i]-1]);
        }
    }
    if(ans.size() > 0){
        int min = *min_element(ans.begin(),ans.end());
        vector<int> ans_index;
        rep(i,ans.size()){
            if(min == ans[i]) ans_index.push_back(i);
                cout << ans_index.size() << endl;
            }
            if(ans_index.size() > 0){
                rep(i,ans_index.size()) cout << people[ans_index[i]] << ' ';
            }  
        }
    }
    cout << '0' << endl;
    cout << endl;
    return 0;
}
