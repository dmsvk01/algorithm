#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<string> solution(string s) {
    vector<string> answer;
    int size = s.length();
    char check[size+1];
    for(int i=0; i<size; i++) check[i]='X';
    check[size]='T';

    for(int i=0; i<size-1; i++){
        if(s[i]==s[i+1]){
            check[i]=s[i];
            check[i+1]=s[i];
        }
    }
    string p="";
    bool pass = true;
    for(int i=0; i<size+1; i++){
        if(check[i]=='X'){
            p+=s[i];
            pass=true;
        }else if(check[i]!='X' && pass==true){
            answer.push_back(p);
            pass=false;
            p="";
        }else if(check[i]!='X' && pass==false){

        }
    }
    if(check[size-1]!='X'){
      answer.push_back("");
    }
    return answer;
}


int main(){
  string a;
  cin >> a;
  vector<string> s = solution(a);
  for(int i=0; i<s.size(); i++){
    cout << s[i] << "\n";
  }
  return 0;
}

/*
"pizza"	["pi","a"]
"mississippi"	["mi","i","i","i"]
"aabcddddefggg"	["","bc","ef",""]
"abyyy"	["ab",""]
"kkkkkkk"	["",""]
*/
