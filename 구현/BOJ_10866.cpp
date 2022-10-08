#include <iostream>
#include <deque>
#include <vector>


using namespace std;

// push_front X: 정수 X를 덱의 앞에 넣는다.
// push_back X: 정수 X를 덱의 뒤에 넣는다.
// pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 덱에 들어있는 정수의 개수를 출력한다.
// empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
// front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
  
deque<int> dp;
vector<int> res;

void PrintRes(){
  for(int i=0; i<res.size(); i++){
    printf("%d\n", res[i]);
  }
  return ;
}


void solved(){
  int size, n=0;
  string input;
  cin >> size;
  
  for(int i=0; i<size; i++){
    cin >> input;
    
    if(input == "push_front"){
      cin >> n;
      dp.push_front(n);
    }else if(input == "push_back"){
      cin >> n;
      dp.push_back(n);
    }else if(input == "pop_front"){
      if(dp.empty()){
        res.push_back(-1);
      }else{
        res.push_back(dp.front());
        dp.pop_front();
      }
    }else if(input == "pop_back"){
      if(dp.empty()){
        res.push_back(-1);
      }else{
        res.push_back(dp.back());
        dp.pop_back();
      }
    }else if(input == "size"){
        res.push_back(dp.size());
    }else if(input == "empty"){
        res.push_back(dp.empty());
    }else if(input == "front"){
      if(dp.empty()){
        res.push_back(-1);
      }else{
        res.push_back(dp.front());
      }
    }else if(input == "back"){
      if(dp.empty()){
        res.push_back(-1);
      }else{
        res.push_back(dp.back());
      }
    }else{
      return ;
    }
  }
  PrintRes();
  return ;
}

int main(){
  solved();
  return 0;
}

