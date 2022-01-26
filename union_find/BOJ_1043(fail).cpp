#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<int> true_person;
vector<int> party[50];
int n,m,count=0;
int tn,t,pn,p;

int main(){
 scanf("%d %d", &n, &m);
 scanf("%d", &tn);
 for(int i=0; i<tn; i++){
  scanf("%d", &t);
  true_person.insert(t);
 }
 for(int i=0; i<m; i++){
  scanf("%d", &pn);
  for(int j=0; j<pn; j++){
   scanf("%d", &p);
   party[i].push_back(p);
  }
 }

 for(int i=0; i<m; i++){
   for(int j=0; j<party[i].size(); j++){
     if(true_person.find(party[i][j]) != true_person.end()){ // 진실사람을 찾았다면
    //  printf("find! %d번째파티 %번째 사람 %d가 진실사람입니다.\n", i,j,party[i][j]);
       for(int k=0; k<party[i].size(); k++){ // 해당파티원 모두 진실사람
         true_person.insert(party[i][k]);
        //  printf("%d ", party[i][k]);
       }
      //  printf("\n");
       break;
     }
   }
 }
 for(int i=0; i<m; i++){
   int pass = 1;
   for(int j=0; j<party[i].size(); j++){
     if(true_person.find(party[i][j]) != true_person.end()){ // 진실사람을 찾았다면
       pass=0; // 카운팅 안되게하기
     }
   }
   if(pass) count++;
 }
 printf("%d\n", count);
}
/*
3 4
1 3
1 1
1 2
2 1 2
3 1 2 3

10 9
4 1 2 3 4
2 1 5
2 2 6
1 7
1 8
2 7 8
1 9
1 10
2 3 10
1 4

4 5
1 1
1 1
1 2
1 3
1 4
2 4 1

4 3
0
2 1 2
1 3
3 2 3 4

4 1
1 1
4 1 2 3 4
*/
