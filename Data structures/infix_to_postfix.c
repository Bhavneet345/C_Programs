#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack_arr
{
    char *arr;
    int size;
    int top;
};

char check_top(struct stack_arr *s)
{
    char val = s->arr[s -> top];
    return val;
}

int isoperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '%' || ch == '*' || ch == '/' || ch == '^')
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int precedence(char op)
{   if(op == '^')
    {
        return 4;
    }
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

void push(struct stack_arr *s,char val)
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

char* infix_to_postfix(char *infix)
{
    struct stack_arr *s = (struct stack_arr *)malloc(sizeof(sizeof (struct stack_arr)));
    s -> size = 10;
    s -> top = -1;
    s -> arr = (char *)malloc((s -> size) * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) *  sizeof(char));

    //pushing ')' at the top of the stack
    
    push(s,'(');

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if(!isoperator(infix[i]) && infix[i] != '(' && infix[i] != ')')
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }

        else
        {
            if(infix[i] == '(')
            {
                push(s,infix[i]);
                i++;
            }

            else if(precedence(infix[i]) > precedence(check_top(s)))
            {
                push(s,infix[i]);
                i++;
            }

            else if(infix[i] == ')')
            {
                char val = pop(s);

                if(val != '(')
                {
                    postfix[j] = val;
                    j++;
                }  

                else
                {
                    i++;
                }
            }

            else
            {
                char val = pop(s);
                postfix[j] = val;
                j++;
            }
        }
    }
    postfix[j] = '\0';
    return postfix;
} 

int main()
{       
    char * infix = "A+(B*C-(D/E^F)*G)*H)";
    printf("postfix is %s", infix_to_postfix(infix));
    return 0;
}