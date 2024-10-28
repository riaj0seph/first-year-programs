#include <stdio.h>

void towerofhanoi(int n,char x,char y,char z){
    if (n==3){
        printf("disc 1 moves to %c \n",z);
        printf("disc 2 moves to %c \n",y);
        printf("disc 1 moves to %c \n",y);
        printf("disc 3 moves to %c \n",z);
        printf("disc 1 moves to %c \n",x);
        printf("disc 2 moves to %c \n",z);
        printf("disc 1 moves to %c \n",z);
    }
    else{
        towerofhanoi(n-1,x,z,y);
        printf("disc %d moves to %c\n",n,z);
        towerofhanoi(n-1,y,x,z);
    }
}


int main(){
    int n;
    printf("WELCOME TO THE TOWER OF HANOI PROGRAM\n");
    printf("PLEASE ENTER THE NUMBER OF DISCS (n>2): \n");
    scanf("%d",&n);
    printf("The discs here are A,B,C from left to right\n The discs are numbered 1,2,3.. and are in increasing in size in that order\n");
    int min=4*(n-2)*(n-2)-4*(n-2)+7;
    printf("The minimum moves for this situation: %d\n",min);
    printf("The steps for achieving this are as follows: \n");
    towerofhanoi(n,'A','B','C');
    return 0;
}