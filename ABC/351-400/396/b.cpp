#include <iostream>
#include<vector>
using namespace std;

int main(){
   int q;
   cin >> q;
   vector<int> p;
   for(int i=0;i<100;i++) p.push_back(0);
   for(;q--;){
     int type;
     cin >> type;
     if(type == 1){
       int x;
       cin >> x;
       p.push_back(x);
     }else{
       cout << p.back() << endl;
       p.pop_back();
     }
   }
}

