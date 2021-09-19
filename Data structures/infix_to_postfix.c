#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct stack_arr
{
    int size;
    int top;
    char *arr;
};

int check_top(struct stack_arr *s)
{
    return s->arr[s -> top];
}

int isoperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '%' || ch == '*' || ch == '/')
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

int precedence(char op)
{
    if(op == '/' || op == '*' || op == '%')
    {
        return 3;
    }
    else if(op == '+' || op == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int is_full(struct stack_arr *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int is_empty(struct stack_arr *s)
{
    if(s -> top == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void push(struct stack_arr *s,int val)
{
    if(is_full(s))
    {
        printf("\nOverflow condiotion\n");
    }

    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}

int pop(struct stack_arr *s)
{
    if(is_empty(s))
    {
        printf("\nUnderflow condition\n");
        return -1;
    }

    else
    {
        char val = s->arr[s->top];
        s->top--;
        return val;
    }
}

char* infix_to_postfix(char* infix)
{
    struct stack_arr *s = (struct stack_arr *)malloc(sizeof(struct stack_arr));
    s -> size = 10;
    s -> top = -1;
    s -> arr = (char *)malloc((s -> size) * sizeof(char));
    char* postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0;
    int j = 0;
    
    while (infix[i] != '\0')
    {
        if(!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }

        else
        {
            if(precedence(infix[i]) > precedence(check_top(s)))
            {
                push(s, infix[i]);
                i++;
            }

            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    
    while(!is_empty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char * infix = "x-y/z-k*d";
    printf("postfix is %s", infix_to_postfix(infix));
    return 0;
}
