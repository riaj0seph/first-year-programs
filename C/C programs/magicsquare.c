#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter n \n");
    scanf("%d",&n);
    if(n%2==0){
        printf("Not possible\n");
    }
    else{

    int **square=(int**)malloc(sizeof(int*));
    if(square==NULL){
        printf("Memory allocation failed\n");
        return 1;
    }


    for(int i=0;i<n;i++){
        square[i]=(int*)calloc(n,sizeof(int));
        if(square[i]==NULL){
            printf("Memory allocation failed\n");
            for(int j = 0; j < i; j++) {
                free(square[j]);
            }
            free(square);
            return 1;
        }
    }

    int num=1;
    int i=0,j=(n-1)/2;
    square[i][j]=num;
    while(num!=n*n){
        //go up left
        int itemp,jtemp;
        itemp=(n+(i-1))%n;
        jtemp=(n+(j-1))%n;
        //printf("\nHi %d %d",itemp,jtemp);
        if(square[itemp][jtemp]!=0){
            //occupied, move down
            i=(i+1)%n;
        }
        else{
            i=itemp;
            j=jtemp;
        }
        num++;
        //printf("\nHi %d",num);
        //printf("\nHey %d %d",i,j);
        square[i][j]=num;
    }
    
    //display it now
    printf("The magic square: \n");
    for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
        printf("%d ",square[i][j]);
     }
     printf("\n");
    }
    for(i = 0; i < n; i++) {
        free(square[i]);
    }
    free(square);
}
    return 0;
}
