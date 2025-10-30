#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char infix[20],postfix[20],stack1[20];
int stack2[20];
int top1=-1; int top2=-1;

int prec(char x){

    switch(x){
        case '^':
                return 3;
        case '*':
        case '/':
                return 2;
        case '+':
        case '-':
                return 1;
        default:
                return 0;
    }
}

void infix_postfix(){
int j=-1;
for(int i=0; infix[i]!='\0';i++){
    char x=infix[i];
    if(x=='('){
        stack1[++top1]=x;
    }
    else if(x==')'){
        while(stack1[top1]!='('){
            postfix[++j]=stack1[top1--];
        }
        top1--;
    }
    else if(prec(x)>0){
        while(prec(stack1[top1])>=prec(x)){
            postfix[++j]=stack1[top1--];
        }
        stack1[++top1]=x;

    }else{
        postfix[++j]=x;
    }
    }

    while(top1!=-1){
        postfix[++j]=stack1[top1--];
    }
    postfix[++j]='\0';


    printf("Postfix Expression: %s\n",postfix);
}


void postfix_eval(){

    int a,b,res;
    for(int i=0;postfix[i]!='\0';i++){
        char x=postfix[i];
        if(isdigit(x)){
            stack2[++top2]=x-'0';
        }
        else{
            a=stack2[top2--];
            b=stack2[top2--];

            switch(x){
                case'+':
                    res=b+a;
                    break;
                case '-':
                    res=b-a;
                    break;
                case'*':
                    res=b*a;
                    break;
                case '/':
                    if(a==0){printf("Cannot divide by zero!\n");exit(0);}
                    res=b/a;
                    break;
                case'^':
                    res=1;
                    for(int j=0;j<a;j++){
                        res*=b;
                    }
                    break;
            }
            stack2[++top2]=res;
        }

    }
    printf("Postfix evaluation:%d \n",stack2[0]);
}


int main(){
    scanf("%s",&infix);
    infix_postfix();
    postfix_eval();
    

    return 0;
}
