#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool CheckParenthesis(char* s ){

    char stack[100];
    int top = -1;

    for(int i = 0;i <s[i]!='\0';i++){
        char current = s[i];
        if(current == '(' || current == '{' || current == '['){
            stack[++top] = current;
        }
        else{
            if (top == -1) return false;
            char topChar = stack[top--];
            if((current == ')' && topChar!= '(')  || (current == '}' && topChar != '{') || (current == ']' && topChar != '[')){
                return false;
            }

        }
    }
    return top==-1;
}

int main()
{
    char* s = "()([]){}";

    if(CheckParenthesis(s)){

        printf("Valid Parenthesis");
    }
    else 
    {
        printf("Invalid Parenthesis");
    }
        return -1;
}