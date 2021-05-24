//
//  main.c
//  C_demo6
//
//  Created by 胡家豪 on 2021/05/21.
//

#include <stdio.h>


//自定义函数---查找元素在数组中的位置
/*  a：需要查找的元素
    array[]：元素所在数组
    length：数组长度
 */
int search(int a,int array[],int length)
{
    int ret = -1;
    for (int i = 0; i < length; i ++) {
        if (array[i] == a)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

int isPrime(int x,int knownPrimes[],int numberOfKnownPrimes)
{
    int isPrime = 1;
    int i;
    for (i = 0 ; i < numberOfKnownPrimes; i ++) {
        if (x % knownPrimes[i] == 0) {
            isPrime = 0;
            break;
        }
    }
    
    return isPrime;
}

//二分搜索
int search_bisection(int key,int a[],int length)
{
    int ret = -1;
    int left = 0;
    int right = length - 1;

    while (left < right)
    {
        int mid = (left + right )/2;
        if (a[mid] == key)
        {
            ret = mid;
            break;
        }
        else if(a[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ret;
}

//求最大值ID
int max(int a[],int length)
{
    int max = 0;
    for (int i = 1; i < length ; i ++) {
        if (a[i] > a[max])
        {
            max = i;
        }
    }
    return max;
}


int main()
{
    //数组运算
    //① 线性搜索
//    int a[] = {2,4,6,7,1,3,5,9,11,13,23,4,32};
//    int x;
//    int loc;
//    printf("输入一个数字：");
//    scanf("%d",&x);
//    loc = search(x, a, sizeof(a) / sizeof(a[0]));
//    if (loc == -1)
//    {
//        printf("不存在\n");
//    } else
//    {
//        printf("数组中的第%d元素为%d\n",loc + 1,x);
//    }
    
    
    //一一对应查找
//    struct{
//        int amount;
//        char *name;
//    } coins[] = {
//        {1,"penny"},
//        {5,"nickel"},
//        {10,"dime"},
//        {25,"quarter"},
//        {50,"half-dollar"}
//    };
//
//    int k;
//    scanf("%d",&k);
//    for (int i = 0; i < sizeof(coins)/sizeof(coins[0]); i ++) {
//        if (k == coins[i].amount)
//        {
//            printf("%s\n",coins[i].name);
//            break;
//        }
//    }

    
    
    //二分法检索
//    int key;
//    scanf("%d",&key);
//    int a[] = {2,4,9,11,15,18,26,28,29,33,38,46,57,68,89};
//    if (search_bisection(key, a, sizeof(a)/sizeof(a[0])) == -1 )
//    {
//        printf("不存在");
//    }
//    else
//    {
//        printf("%d在数组中的%d位",key,search_bisection(key, a, sizeof(a)/sizeof(a[0])));
//    }
//
    
    //选择排序
    
    int a[] = {14,25,76,67,23,98,47,32,90,5,66,87,16};
    int len = sizeof(a)/sizeof(a[0]);
    int t = 0;
    for (int i = len - 1 ; i > 0; i --) {
        int maxid = max(a, i + 1);
        t = a[maxid];
        a[maxid] = a[i];
        a[i] = t;
    }
    for (int i = 0; i < len; i ++) {
        printf("%d\n",a[i]);
    }
    
    
    //输出素数（简便方法）
    //让一个数除以所有比他小的素数，如果不能整除，则这个数是素数
//    const int number = 100;
//    int Primes[number] = {2};
//    int cnt = 1;
//    int i = 3;
//    for (cnt = 1; cnt < number;i ++ ) {
//        if (isPrime(i,Primes,cnt))
//        {
//            Primes[cnt++] = i;
//        }
//    }
//    for (int i = 0; i < cnt; i ++) {
//        printf("%d\n",Primes[i]);
//    }
    
    

    
    
    
    return 0;
    
}
