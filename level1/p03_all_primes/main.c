#include <stdio.h>
#include <time.h>
using namespace std;
int a[1001],c[1001]= {0};
int main()
{ clock_t start,end;
  double timecost;
  start=clock();
  for(int i=2;i<=1000;i++){
    if(a[i]==0){
      for(int j=2*i;j<=1000;j+=i){
        a[j]=1;
      }
    }
  }
  for (int i=2;i<=1000;i++){
    if(a[i]==0){
      printf("%d\n",i);
    }
  }
  end=clock();
  timecost=(double)(end-start)/CLOCKS_PER_SEC;
  printf("总计算时间：%.4fs",timecost);
  return 0;
}
