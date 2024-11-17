#include <iostream>
#include <vector>
using namespace std;

vector<pair<char,int> > RLE(string s){
  vector<pair<char,int> > res;
  for(char c : s){
    if(res.size() > 0 && res.back().first == c){
      res.back().second++;
    }else{
      res.emplace_back(c,1);
    }
  }
  return res;
}
