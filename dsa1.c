#include<stdio.h>
#define Max 5

int stack[Max];
int Top = -1;

void push(){
    int value;
    if(Top == Max-1){
        printf("stack overflown ! cannot push more elements\n");
    }else{
        printf("Enter the value you want to push\n");
        scanf("%d", &value);
        Top++ ;
        stack[Top] = value;
        printf("The value %d is pushed\n", value);
    }
   
}

void pop(){
    if(Top == -1){
        printf("Stack is empty\n");
    }else{
        printf("%d is popped\n", stack[Top]);
        Top-- ;
    }
   
}

void peek(){
    if(Top == -1){
        printf("Stack is empty & does not contain any value\n");
    }else{
        printf("The value is %d\n", stack[Top]);
    }
   
}

int main(){
    int select;
   
    while(1){
       
        printf("1.Push\n");
        printf("2.POP\n");
        printf("3.Peek\n");
        printf("4.Exit\n");
        printf("select an option u want to be performed\n");
        scanf("%d", &select);
   
   
    switch(select){
        case 1 : push();
        break;
        case 2 : pop();
        break;
        case 3 : peek();
        break;
        case 4 : printf("Exited");
        return 0;
        default : printf("Invalid option");
    }
 }

 return 0;
}