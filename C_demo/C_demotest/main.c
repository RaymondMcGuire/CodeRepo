//
//  main.c
//  C_demotest
//
//  Created by 胡家豪 on 2021/05/25.
//

#include <stdio.h>
int divisor(int x,int y)
{
    int divisor = 0;
    if (x > y)
    {
        int temp = y;
        y = x;
        x = temp;
    }
    for (int i = 2; i <= x; i ++) {
        if (x % i == 0 && y % i == 0)
        {
            divisor = i;
            break;
        }
    }
    
    return divisor;
}

int main()
{
    /*
     输入格式:

     输入在一行中给出一个分数，分子和分母中间以斜杠“/”分隔，如： 12/34 表示34分之12。分子和分母都是正整数（不包含0）。

     提示：在scnaf的格式字符串中加入“／”。

     输出格式：

     在一行中输出这个分数对应的最简分式，格式与输入的相同，即采用“分子/分母”的形式表示分数。
     如 5/6 表示 6分之5

     */
    int a = 0;
    int b = 0;
    scanf("%d/%d",&a,&b);
    int d = divisor(a, b);
    while (divisor(a, b) != 0)
    {
        a /= d;
        b /= d;
        d = divisor(a, b);
    }
    printf("%d/%d\n",a,b);
//    printf("%d\n",divisor(a, b));
    
}
