#include <bits/stdc++.h>

using namespace std;

//check parenthesis

#include <bits/stdc++.h>

using namespace std;

bool isEmpty(char* arr,int top){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(char *arr,int n,int top){
    if(top==n-1){
        return true;
    }
    return false;
}


char Pop(char *arr,int *top){
    if(!isEmpty(arr,*top)){
    char remove=arr[*top];
    arr[*top]=0;
    *top=*top-1;
    return remove ;}
    else{
        cout<<"Underflow! \n";
        return '\0';
    }
}

void Push(char *arr,int *top,int n,int data){
    if(isFull(arr,n,*top)){
        cout<<"Overflow!\n";
        return;
    }
    *top+=1;
    arr[*top]=data;
}

bool isempty(int* arr,int top){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

bool isfull(int *arr,int n,int top){
    if(top==n-1){
        return true;
    }
    return false;
}

int pop(int *arr,int *top){
    if(!isempty(arr,*top)){
    int remove=arr[*top];
    arr[*top]=0;
    *top=*top-1;
    return remove;}
    else{
        cout<<"Underflow! \n";
        return 0;
    }
}

void push(int *arr,int *top,int n,int data){
    if(isfull(arr,n,*top)){
        cout<<"Overflow!\n";
        return;
    }
    *top+=1;
    arr[*top]=data;
}

bool isoperand(char data){
    if(data>=48 &&data<=57){
        return true;
    }
    return false;
}

char Peek(char* arr, int top){
    if(!isEmpty(arr,top)){
        return arr[top];       
    }
    return '\0';
}

int getprcd(char charac){
    if(charac=='+'||charac=='-'){
        return 1;
    }
    else if(charac=='*'||charac=='/'){
        return 2;
    }
    else{
        return 0;
    }

}

bool prcd(char charac1,char charac2){
   //true if charac2>charac1
   //false if = or <
    int prcd1=getprcd(charac1);
    int prcd2=getprcd(charac2);
    if(charac1=='(' || charac2=='('){
        return true;
    }
    return prcd2>prcd1;

}

int eval(int op1,int op2,char oprtr){
    switch(oprtr){
        case '+':
        return op1+op2;
      
        case '-':
        return op1-op2;

        case '/':
        return op1/op2;
       
        case '*':
        return op1*op2;
        
    }
}

int main(){
    cout<<"Enter expression\n";
    string expression;
    cin>>expression;
    int n=expression.length();
    char* arr=new char[n];
    int i=0;
    int top=-1;
    int check=1;
    while(expression[i]!='\0'){
        if(expression[i]=='('){
            Push(arr,&top,n,expression[i]);
        }
        if(expression[i]==')'){
            if(isEmpty(arr,top)){
                cout<<"Faulty expression\n";
                check=0;
                break;
            }
            else{
                Pop(arr,&top);
            }
        }
        i++;
    }
    if(!isEmpty(arr,top)){
        cout<<"Faulty expression!\n";
        check=0;
    }
    printf("Checked!\n");
    if(check==1){
        char* postfix=new char[n];
        int pftop=-1;
        //infix to postfix
        int* operand=new int[n];
        int opndtop=-1;
        char* operatorr=new char[n];
        top=-1;
        int i=0;
        while(expression[i]!='\0'){
            if(isoperand(expression[i])){
                //Push(operand,&opndtop,n,expression[i]);
                Push(postfix,&pftop,n,expression[i]);
            }
            else{
                if(expression[i]!=' ' && expression[i]!=')'){
                    //must be operator or parenthesis (
                    if(prcd(Peek(operatorr,top),expression[i])){
                    Push(operatorr,&top,n,expression[i]);
                    }else{
                        //pop everythin till lower
                        while(!prcd(Peek(operatorr,top),expression[i])){
                            Push(postfix,&pftop,n,Pop(operatorr,&top));
                        }
                    }
                }
                else{
                    if(expression[i]!=' '){
                        //must be )
                        //pop everythin till u get (
                        while(Peek(operatorr,top)!='('){
                            Push(postfix,&pftop,n,Pop(operatorr,&top));
                        }
                        Pop(operatorr,&top);//remove da (
                    }
                }
            }
        i++;}
        while(!isEmpty(operatorr,top)){
            Push(postfix,&pftop,n,Pop(operatorr,&top));
        }
        
        cout<<"Postfix!\n";
        
        for(i=0;i<=pftop;i++){
            cout<<postfix[i];
        }
        cout<<endl;
        cout<<"Expression Evaluation!\n";
        for(i=0;i<=pftop;i++){
            char charac=postfix[i];
            if(isoperand(charac)){
                int data=charac-'0';
                push(operand,&opndtop,n,data);
            }
            else{
                int op1=pop(operand,&opndtop);
                char oprtr=charac;
                //op2 oprt op 1
                int op2=pop(operand,&opndtop);
                int result=eval(op2,op1,oprtr);
                push(operand,&opndtop,n,result);
            }
        }
        cout<<pop(operand,&opndtop);

    }
}