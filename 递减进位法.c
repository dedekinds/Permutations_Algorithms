#include<stdio.h>
#include<string.h>
#define N 3
long factorial_iteration(int n){
    int result = 1;

    while(n>1){
        result *= n;
        n--;
    }
    return result;
}

int main(){
    int Factorialnum[N];
    int k;
    int i;
    int t;
    int j;
    int temp;
    int tempnums[N];
    int nums[N];
    for(k=0;k<N;k++)
        Factorialnum[k]=0;
    int n=0;
    for(i=0;i<N;i++)
        nums[i]=i;
    int times=1;
    int total=factorial_iteration(N);


    while(times<=total){

     for(j=0;j<N;j++){
            printf("%d",nums[j]+1);
        }
        printf("\n");

      for(i=0;i<N;i++)
        nums[i]=i;
//生成下一个阶乘数（逆序数）__________________
        n=0;

       while(n<N){
        if (Factorialnum[n]+1<N-n){
            Factorialnum[n]+=1;
            break;
        }
        else{
            Factorialnum[n]=0;
            n+=1;
        }
       }

          //printf("%d",n);___________________________________



      //逆序数→排列数______________________
      i=0;
    while(i<N-1){
        if(Factorialnum[i]==0)
            i+=1;
        else{
          for(j=i+Factorialnum[i];j>i;j--){
                temp=nums[j];
                nums[j]=nums[j-1];
                nums[j-1]=temp;
            }
            //nums=nums[:i]+[t]+nums[i:i+Factorialnum[i]]+nums[1+i+Factorialnum[i]:]
            i+=1;
        }
    }
          //逆序数→排列数______________________



        times+=1;
    }
    //逆序数→排列数


    return 0;
}

