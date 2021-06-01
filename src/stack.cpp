//
//  main.c
//  Stack
//
//  Created by 胡家豪 on 2021/05/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
    int value;
    struct Stack * next;
} stack;

int IsEmpty(stack * s)
{
    int a;
    a = (s->next == NULL);
    return a;
}

stack * creatStack (void)
{
    stack * s = (stack *)(malloc(sizeof(stack)));
    s->next = NULL;
    return s;
}

stack * push (int value,stack * s)
{
    stack * node = (stack *)(malloc(sizeof(stack)));
    node->value = value;
    node->next = s;
    return node;
}

stack * pop (stack * s)
{
    stack * temp = s;
    if (IsEmpty(temp))
    {
        printf("failed:stack is null\n");
    }
    else
    {
        int top = 0;
        top = temp->value;
        printf("pop %d\n",top);
        s = temp->next;
        free(temp);
    }
    
    return s;
}

void peek(stack * s)
{
    if (IsEmpty(s))
    {
        printf("failed:stack is null\n");
    }
    else
    {
    int top = 0;
    top = s->value;
    printf("%d\n",top);
    }
}

void print(stack * s)
{
    stack * temp = s;
    if (temp->next == NULL)
    {
        printf("failed:stack is null\n");
        printf("\n");
    }
    while (temp->next != NULL)
    {
        printf("%d\n",temp->value);
        temp = temp->next;
    }
}
int main()
{
    stack * s = creatStack();
    bool loop = true;
    while (loop)
    {
        printf("2:push\n");
        printf("3:pop\n");
        printf("4:peek\n");
        printf("5:print stack\n");
        printf("0:exit\n");
        int key;
        scanf("%d",&key);
        switch (key) {
            case 2:
            {
                printf("push\n");
                int value;
                scanf("%d",&value);
                s = push(value, s);
                break;
            }
            case 3:
            {
                printf("pop\n");
                s = pop(s);
                break;
            }
            case 4:
            {
                printf("peek\n");
                peek(s);
                break;
            }
            case 5:
            {
                printf("print stack\n");
                print(s);
                break;
            }
            case 0:
            {
                printf("exit\n");
                loop = false;
                free(s);
            }
        }
    }
    return 0;
}
