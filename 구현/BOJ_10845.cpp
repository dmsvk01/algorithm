#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
vector<int> res;
  
void solved(){
  int size, n=0;
  string input;
  cin >> size;
  
  for(int i=0; i<size; i++){
    cin >> input;
    
    if(input == "push"){
      cin >> n;
      q.push(n);
    }else if(input == "pop"){
      if(q.empty()){
        res.push_back(-1);
      }else{
        res.push_back(q.front());
        q.pop();
      }
    }else if(input == "size"){
        res.push_back(q.size());
    }else if(input == "empty"){
        res.push_back(q.empty());
    }else if(input == "front"){
      if(q.empty()){
        res.push_back(-1);
      }else{
        res.push_back(q.front());
      }
    }else if(input == "back"){
      if(q.empty()){
        res.push_back(-1);
      }else{
        res.push_back(q.back());
      }
    }else{
      
    }
  }

  for(int i=0; i<res.size(); i++){
    printf("%d\n", res[i]);
  }
}

int main(){
  solved();
  return 0;
}

