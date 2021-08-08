#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

vector<int> solution(string text) {
    vector<int> answer;
    vector<string> li;
    li.push_back("A");
    li.push_back("B");
    int cur=0;
    int size = text.length();
    string w;
    while(cur!=size){

      printf("1------------------------\n");
      printf("cur : %d\n", cur);
      for(int i=li.size()-1; i>=0; i--){
        string sli = li[i];
        int sli_size = li[i].size();
        printf("i:%d\n",i);
        cout << "sli : " <<sli << endl;
        printf("sil_size : %d\n", sli_size);
        if(cur+sli_size < text.size())
          w = text.substr(cur, sli_size);
      cout << "w : "<< w << "\n";
        if(sli.compare(w)==0){
          string nstr = text.substr(cur, sli_size+1);
          li.push_back(nstr);
          cur+=sli_size;
      printf("발견! i:%d--> str: ",i);
      cout << nstr << endl;
          answer.push_back(i);
          break;
        }
      }
    }
    
    
    return answer;
}


int main(){
  string a;
  cin >> a;
  vector<int> s = solution(a);
  printf("the end\n");
  for(int i=0; i<s.size(); i++){
    cout << s[i] << "\n";
  }
  return 0;
}

/*
"ABABAABAB"	[0,1,2,0,4,1]
"BBAAA"	[1, 1, 0, 4]
*/
