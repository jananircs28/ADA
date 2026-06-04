#include<stdio.h>
struct item {
   int profit,weight;
   float ratio;//profit/wt
};

void sort(struct item arr[],int n){
   for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(arr[i].ratio<arr[j].ratio){
            struct item temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
        }
    }
   }
}
int main(){
   int n,capacity;
   printf("enter no of items");
   scanf("%d",&n);
   struct item arr[n];

   for(int i=0;i<n;i++){
    printf("enter profit and wt!");
    scanf("%d %d",&arr[i].profit,&arr[i].weight);
    arr[i].ratio = (float)arr[i].profit/arr[i].weight;
   }
   printf("enter capacity:");
   scanf("%d",&capacity);
   sort(arr,n);
   float totalprofit = 0.0;

   for(int i=0;i<n;i++){
    if(capacity > arr[i].weight){
        totalprofit+=arr[i].profit;
        capacity-=arr[i].weight;
    }
    else{
        totalprofit+=arr[i].ratio*capacity;
        break;
    }
   }
   printf("optimal profit =%2f",totalprofit);
   return 0;
}








