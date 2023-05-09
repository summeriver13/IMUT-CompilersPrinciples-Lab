#include <stdio.h>
#include <string.h>

void solve()
{
    char wfh[50]; /*定义数组大小为50 用于存放要判断的无符号数*/

    int i, zf; /*定义变量*/

    char ch1, ch2;

    printf("Please Input Number:"); /*输入要判断的无符号数*/

    scanf("%s", wfh);

    strcat(wfh, "$"); /*自动在输入的串末尾加入$结束符*/

    i = 0;
    zf = 0; /*初始时令zf=0，使得如果输入全不符合时退出*/

    while (wfh[i] != '$')
    { /*条件：输入不为结束符时执行判断*/

        ch1 = wfh[i]; /*将第一个字符送入变量ch1*/

        ch2 = wfh[i + 1]; /*将次输入的字符送入变量ch2*/

        if (ch1 >= '0' && ch1 <= '9')
        { /*当前字是否0-9的数字*/

            if ((ch2 >= '0' && ch2 <= '9') || ch2 == '.' || ch2 == 'e' || ch2 == '$')
                /*如果是数字，则判断下一个字符是否是"0-9"，"."，"E"."$"*/

                zf = 1; /*输入为正确标志*/

            else
                zf = 0; /*输入为错误标志*/
        }

        if (ch1 == '.')
        {
            /*如果上面条件不符合，判断是否是小数点*/
            if (ch2 >= '0' && ch2 <= '9' || ch2 == '$')
                /*判断小数点后是否是"0-9"，或为"$"*，否则出错?*/
                zf = 1;
            else
                zf = 0;
        }
        if (ch1 == 'e')
        { /*判断是否是指数标志*/

            if (ch2 >= '0' && ch2 <= '9' || ch2 == '+' || ch2 == '-' || ch2 == '$')
                /*判断指数标志后是否是"0-9"，或是"+，-"，"$",否则出错*/
                zf = 1;
            else
                zf = 0;
        }
        if (ch1 == '+' || ch1 == '-')
        { /*如果以上不符，判断是否是"+，-，"*/

            if (i == 0)
                break; /*如果是第一个输入的字符为"+，-"则输入错误*/

            if (ch2 >= '0' && ch2 <= '9' || ch2 == '$') /*"+,-"后只能为"0-9"，"$",否则出错*/
                zf = 1;
            else
                zf = 0;
        }
        if (zf == 0)
            break; /*如果标志zf=0输入错，退出*/

        i++; /* i加1，判断下一个字符*/
    }
    if (zf == 0) /*输入字符串不是无符号数*/
        printf("Input number are error!\n");
    else
        printf("Input number are right!\n"); /*输入字符串为无符号数*/
}

int main(){
    int t = 4;
    while(t--) solve();
    return 0;
}
