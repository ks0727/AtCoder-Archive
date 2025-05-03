#include<vector>
#include<string>
using namespace std;
struct Trie{
  struct Node{
    bool is_word;
    vector<int> next;
    int cnt;
    Node():is_word(false),cnt(0),next(26,-1){}
  };
  //1次元配列でもつ、ポインタみたいな感じで、次のところがどこの添字にあるのかという情報を持つ
  vector<Node> nodes;   
  Trie(){nodes.emplace_back();}
  void insert(const string& s){
    int cur = 0;
    nodes[cur].cnt++;
    for(char c : s){
      int idx = c - 'a';
      if(nodes[cur].next[idx] == -1){ //子がない
        nodes[cur].next[idx] = nodes.size();
        nodes.emplace_back();
      }
      cur = nodes[cur].next[idx];
      nodes[cur].cnt++;
    }
    nodes[cur].is_word = true;
  }
  //文字列をたどって存在すればノード添字、存在しないなら-1
  int traverse(const string& s){
    int cur = 0;
    for(char c : s){
      int idx = c-'a';
      cur = nodes[cur].next[idx];
      if(cur == -1) return -1;
    }
    return cur;
  }
  //完全一致検索
  bool search(const string& s){
    int cur = traverse(s);
    return cur != -1 && nodes[cur].is_word;
  }
  //sが存在するか判定
  bool starts_with(const string& s){
    return traverse(s) != -1;
  }
  int count_prefix(string &prefix){
    int cur = traverse(prefix);
    return (cur == -1)?0:nodes[cur].cnt;
  }
};

