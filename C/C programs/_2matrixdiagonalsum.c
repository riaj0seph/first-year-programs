
#include <stdlib.h>
#include <stdio.h>

int main(){
   int n;
   printf("Enter n\n");
   scanf("%d",&n);
   int **arr=(int**)malloc(n*sizeof(int*));
   for(int i=0;i<n;i++){
    arr[i]=(int*)malloc(n*sizeof(int));
    for(int j=0;j<n;j++){
        printf("Enter the data for %dth row and %dth column",i+1,j+1);
        scanf("%d",&arr[i][j]);
    }
   }
   printf("Your array: \n");
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
   }
   int*arre=(int*)calloc((2*n-1),sizeof(int));
   for(int k=0;k<n;k++){
    int i=0,j=k;
    while(i<n && j>-1){
       (*arre)+=arr[i][j];
       i++;
       j--; 
    }
    arre++;
   }
   for(int k=1;k<n;k++){
    int i=k,j=n-1;
    while(i<n && j>-1){
        (*arre)+=arr[i][j];
        i++;
        j--;
    }
    arre++;
   }
   arre=arre-(2*n-1);
   printf("The diagonal sums:\n");
   for(int i=0;i<2*n-1;i++){
    printf("%d ",arre[i]);
   }
   return 0;
}
