#include <iostream>
#define VMAX 1000000 + 1

using namespace std;

int parent[VMAX]={0};
int n;

int getparent(int x){
  if(parent[x]==x) return x;
  return parent[x] = getparent(parent[x]);
}

void merge(int sa, int sb){
  int a = getparent(sa);
  int b = getparent(sb);

  if(a==b) return ;
  if(a < b)
    parent[b]=a;
  else
    parent[a]=b;
}

bool sameparent(int sa, int sb){
  int a = getparent(sa);
  int b = getparent(sb);
  if(a==b) return true;
  else return false;
}

int do_find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = do_find(parent[x]);
}


int main(){
  int m; cin >> n >> m;
  for(int i=0; i<=n; i++) parent[i]=i;

  for(int k,a,b,i=0; i<m; i++){
    scanf("%d %d %d", &k, &a, &b);
    if(k==0){
      merge(a,b);
      //for(int i=0; i<=n; i++) printf("%d ", parent[i]);
      //printf("\n");
    }else{
      bool p = sameparent(a,b);
      printf(p==true?"YES\n":"NO\n");
    }
  }
}

/*

7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

*/
