#include <stdio.h>
#include <stdlib.h>

//incomplete

/*
2. Pointers and Dynamic 2D Arrays
Task: Create a dynamic 2D array using pointers to pointers.

Steps:

Declare a pointer to a pointer for the 2D array.
Use malloc to allocate memory for rows and columns.
Fill the 2D array with user input using double pointer dereferencing.
Print the 2D array.
Free all allocated memory. */

int main(){
int **ptr2;
printf("Enter number of rows and columns respectively: \n");
int col,row;
scanf("%d %d",&row,&col);
ptr2=(int **)malloc(row*sizeof(int *));
if (ptr2==NULL){
printf("Memory allocation failed \n");
return 1;
}
for (int i=0;i<row;i++){
ptr2[i]=(int *)malloc(col*sizeof(int));
if (ptr2[i]==NULL){
printf("Allocation failed \n");
return 1;
}
}
//assign values
for (int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        printf("Enter the element that goes in the %d row and %d column\n",i+1,j+1);
        scanf("%d",*(ptr2+i)+j);
    }
}

//printing
for (int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        printf("%d ",*(ptr2[i]+j));
    }
    printf("\n");
    free(ptr2[i]);
}


free(ptr2);
return 0;
                                     
}
