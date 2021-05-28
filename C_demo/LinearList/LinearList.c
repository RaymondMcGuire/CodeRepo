//
//  main.c
//  LinearList
//
//  Created by 胡家豪 on 2021/05/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List{
    int value;
    struct List *next;
} list;

list * InitList(void)//初始化链表(创建一个空的链表)
{
    list * p = (list *)(malloc(sizeof(list)));//创建头节点

    return p;
}

int FindPostion(int postion,list *p)
{
    list * temp = p;
    int k = 1;
    
    for (int i = 1; i < postion; i ++)
    {
        if (temp->next == NULL)
        {
            k = -1;
            printf("该链表的最后一个元素位置为%d,%d处不存在链表\n",i - 1,postion);
        }
        temp = temp->next;
    }
    return k;
}

list * InsertList(int value,int postion,list *p)//在postion后面插入一个链表
{
    list * temp = p;
    if (FindPostion(postion, p) != -1)
    {
        for (int i = 1; i < postion; i++)
        {
            temp = temp->next;
        }
    
    list * node = (list *)(malloc(sizeof(list)));
    node->value = value;
    node->next = temp->next;
    temp->next = node;
    }
    return p;
}

int FindValue(int value,list *p)
{
    list * temp = p;
    int i = 0;
    while (temp)
    {
        if (temp->value == value)
        {
            return i;
            break;
        }
        i++;
        temp = temp->next;
    }
    return -1;
}
list * ChangeValue(int Postion,int Value,list *p)
{
    list * temp = p;
    if (FindPostion(Postion, p) != -1)
    {
        for (int i = 1; i <= Postion; i++)
        {
            temp = temp->next;
        }
        temp->value = Value;
    }
    return p;
}

list * Delete(int Postion,list * p)
{
    list * temp = p;
    if (FindPostion(Postion, p) != -1)
    {
        for (int i = 1; i < Postion; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
    return p;
}
void display(list *p)
{
    list * temp = p;
    int i = 1;
    if (temp->next == NULL)
    {
        printf("空链表");
        return;
    }
    else
    {
    while (temp->next)
    {
        temp = temp->next;
        printf("%d,%d\n",i,temp->value);
        i++;
    }
    }
}
int main()
{
    list *p = InitList();
//    printf("初始化链表\n");
    bool loop = true;
    while (loop) {
        printf("    请输入指令    \n");
        printf("1:创建新的链表\n");
        printf("2:显示所有链表的数据\n");
        printf("3:插入链表\n");
        printf("4:删除链表\n");
        printf("5:更改链表\n");
        printf("6:查找链表\n");
        printf("0:退出\n");
        int key;
        scanf("%d",&key);
        switch (key) {
            case 1:
                p->next = NULL;
                printf("初始化完成\n");
                break;
            case 2:
                display(p);
                printf("\n");
                break;
            case 3:
                printf("输入要插入的位置\n");
                int pos;
                scanf("%d",&pos);
                int value;
                printf("输入要插入的值\n");
                scanf("%d",&value);
                display(InsertList(value, pos, p));
                break;
            case 4:
                printf("输入要删除的链表的位置");
                int Pos;
                scanf("%d",& Pos);
                display(Delete(Pos, p));
                break;
            case 5:
                printf("输入需要更改的链表的位置\n");
                int Postion = 0;
                scanf("%d",&Postion);
                printf("输入需要更改的链表的值\n");
                int Value = 0;
                scanf("%d",&Value);
                display(ChangeValue(Postion, Value, p));
                break;
            case 6:
                printf("输入要查找的值\n");
                int search = 0;
                scanf("%d",&search);
                int k = 0;
                k = FindValue(search, p);
                if (k == 0)
                {
                    printf("不存在\n");
                }
                else
                {
                    printf("值为%d的链表位置为%d\n",search,k);
                }
                break;
            case 0:
                printf("安全退出\n");
                free(p);
                loop = false;
                break;
            default:
                free(p);
                loop = false;
                break;
        }
    }
    
    return 0;
}
