#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Enter the size of first matrix\n");
    int r1,c1,r2,c2;
    scanf("%d%d",&r1,&c1);
    printf("Enter the size of second matrix\n");
    scanf("%d%d",&r2,&c2);
    if (c1!=r2){
        printf("Cannot perform multiplication\n");
        return 1;
    }
    else{
        int **arr1,**arr2;
        arr1=(int**)malloc(r1*sizeof(int*));
        arr2=(int**)malloc(r2*sizeof(int*));
        if (arr1==NULL || arr2==NULL){
            printf("Memory allocation failed\n");
            return 1;
        }
        int i=0;
        for(i=0;i<r1;i++){
            arr1[i]=(int*)malloc(c1*sizeof(int));
            if (arr1[i]==NULL){
            printf("Memory allocation failed\n");
        }
        }
        for(i=0;i<r2;i++){
            arr2[i]=(int*)malloc(c2*sizeof(int));
            if (arr2[i]==NULL){
            printf("Memory allocation failed\n");
        }
        }
        for(i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                printf("For the first matrix; enter element at %d row and %d column \n",i+1,j+1);
                scanf("%d",&arr1[i][j]);
            }
        }
        for(i=0;i<r2;i++){
            for(int j=0;j<c2;j++){
                printf("For the second matrix; enter element at %d row and %d column \n",i+1,j+1);
                scanf("%d",*(arr2+i)+j);
            }
        }
        //Matrix multiplication
        int **result;
        result=(int**)malloc(r1*sizeof(int*));
        if (result==NULL){
            printf("Memory allocation failed\n");
        }
        else{
        for(i=0;i<r1;i++){
            result[i]=(int*)calloc(c2,sizeof(int));
            if (result[i]==NULL){
            printf("Memory allocation failed\n");
        }
        }
        for(i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                for(int k=0;k<c1;k++){
                    result[i][j]+=arr1[i][k]*arr2[k][j];
                }
                //ith row of 1st*jth column of 2nd
            }
        }}
        //print result
        printf("The resulting matrix \n");
        for(i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                printf("%d ",result[i][j]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < r1; i++) {
        free(arr1[i]);
    }
    free(arr1);

    for (int i = 0; i < r2; i++) {
        free(arr2[i]);
    }
    free(arr2);

    for (int i = 0; i < r1; i++) {
        free(result[i]);
    }
    free(result);
  return 0;
}