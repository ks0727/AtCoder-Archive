#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    const int M = 1000000;
    vector<int> spf(M+1, 0);
    for (int i = 2; i <= M; i++){
        if(spf[i] == 0){
            spf[i] = i;
            if((long long)i * i <= M){
                for (int j = i * i; j <= M; j += i){
                    if(spf[j] == 0)
                        spf[j] = i;
                }
            }
        }
    }
 
    vector<int> dpf(M+1, 0);
    for (int i = 2; i <= M; i++){
        int x = i;
        int last = 0;
        int count = 0;
        while(x > 1){
            int y = spf[x];
            if(y != last){
                count++;
                last = y;
            }
            x /= y;
        }
        dpf[i] = count;
    }
    vector<long long> Numbers;
    for (int i = 2; i <= M; i++){
        if(dpf[i] == 2){
            long long num = (long long)i * i;
            Numbers.push_back(num);
        }
    }
    sort(Numbers.begin(), Numbers.end());
 
    int q;
    cin >> q;
    while(q--){
        long long a;
        cin >> a ;
        auto it = upper_bound(Numbers.begin(), Numbers.end(), a);
        if(it == Numbers.begin()){
            cout << *it << "\n";
        } else {
            --it;
            cout << *it << "\n";
        }
    }
    return 0;
}

