#include <bits/stdc++.h>
using namespace std;

int main(){
    int M;
    cin >> M;
    vector<int> D(M);
    for(int i=0;i<M;i++) cin >> D.at(i);
    int a=0,b=0;
    int day = 0;
    int key_day;
        for(int i=0;i<M;i++) day += D.at(i);
        day +=1 ;
        day /= 2;
        key_day = day;
        for(int i=0;i<M;i++){
            day -= D.at(i);
            if(day <= 0){
                a = i + 1;
                break;
            }
        }
        for(int i=0;i<a-1;i++) key_day -= D.at(i);
        b = key_day;
    
    cout << a << " " << b << endl;
}