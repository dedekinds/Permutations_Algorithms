#include<stdio.h>
#include<string.h>
#define N 3

int find_legal_move_loacation(int direction[], int nums[]){
    int maxlocation=-10086;
    int maxnum=-10086;
    int x;
    for(x=0;x<N;x++){
        if(x+direction[x]>-1 && x+direction[x]<N){
            if(nums[x]>nums[x+direction[x]] && nums[x]>=maxnum){
                maxlocation=x;
                maxnum=nums[x];
            }
        }
    }
    return maxlocation;
}


int main(){
    int direction[N];
    int nums[N];
    int k;
    int location;
    int temp;
    int a;
    int temp_location;
    int i;
    for(i=0;i<N;i++)
        nums[i]=i;
    for(i=0;i<N;i++)
        direction[i]=-1;
        //={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}

    //k=find_legal_move_loacation(direction,nums);
   //printf("%d ",k);
    while(1){
        int j;
        for(j=0;j<N;j++){
            printf("%d",nums[j]+1);
        }
        printf("\n");
        location=find_legal_move_loacation(direction,nums);
        //printf("%d",location);
        if (location==-10086)
            break;
        //swap数值
            temp=nums[location];
            nums[location]=nums[location+direction[location]];
            nums[location+direction[location]]=temp;
         //swap 方向
            temp_location=location+direction[location];
            a=direction[temp_location];
            direction[temp_location]=direction[location];
            direction[location]=a;
         ///更新方向
            int x;
            for(x=0;x<N;x++){
                if (nums[x]>temp){
                    direction[x]*=-1;
                }
            }
            //t+=1
    }
    return 0;
}

