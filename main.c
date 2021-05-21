//
//  main.c
//  C_demo5
//
//  Created by 胡家豪 on 2021/05/21.
//

#include <stdio.h>

//判断是否是素数的自定义函数
int isPrime(int a)
{
    int ret = 1;
    for (int i = 2; i < a; i ++)
    {
        if (a % i == 0)
        {
            ret = 0;
        }
    }
    return ret;
}

//求和的自定义函数
int sum(int a,int b)
{
    int sum = 0;
    for (int i = a; i <= b; i ++) {
        sum += i;
    }
    return sum;
}

int main()
{
//    数组与函数
//    ①求平均数，并输出比平均数大的数
//    int x;
//    int cnt = 0;
//    int number[100];
//    double sum = 0.0;
//    scanf("%d",&x);
//    while (x != -1)
//    {
//        number[cnt] = x;
//        sum += x;
//        cnt ++;
//        scanf("%d",&x);
//    }
//    double avg;
//    avg = sum / cnt;
//    printf("%f\n",avg);
//
//    for (int i = 0; i < cnt; i++)
//    {
//        if (number[i] > avg)
//        {
//            printf("%d\n",number[i]);
//        }
//    }
    
    
//    ②输入一位数的非负整数，统计每个数字出现的次数
    //不符合规则的数字视为输出结束
//    int x ;
//    const int LENGTH = 10;
//    int cnt[LENGTH];
//    scanf("%d",&x);
//    for (int i = 0; i < LENGTH; i ++) {
//        cnt[i] = 0;
//    }
//    while (x >= 0 && x <= 9) {
//        cnt[x] ++;
//        scanf("%d", &x);
//    }
//    for (int i = 0; i < LENGTH; i ++) {
//        printf("输入%d为%d次\n",i,cnt[i]);
//    }
    
//    ③自定义函数
//    求[a,b]之间素数的和(a<b)
    
//    int a , b;
//    int sum = 0;
//    int cnt = 0;
//    scanf("%d %d",&a, &b);
//    for (int i = a; i <= b; i ++) {
//        if (isPrime(i))
//        {
//            sum += i;
//            cnt ++;
//        }
//    }
//    printf("%d和%d之间共有%d个素数，他们的和为%d\n",a,b,cnt,sum);
    
//
//    ④自定义函数
//    求和
    
    int x , y;
    scanf("%d %d",&x,&y);
    printf("%d到%d的所有数字的和为%d\n",x,y,sum(x, y));
    
    
    return 0;
}
