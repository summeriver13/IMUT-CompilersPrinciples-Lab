#include <stdio.h>
#include <string.h>

#define Max 100

char exp[Max], stack[Max]; /*定义表达式区、逆波兰区和运算符栈*/
int t = 0, top = 0;

char in[Max][2] = {
    "a+(b*(c-d^e)+f)/m",
    "a+2@3*5"
};

int main()
{
    printf("**** Expression to NBL form ****\n");
    printf("Please input the expression:");
    char str[Max];
    scanf("%s", str); /*将表达式送入表达式区*/
    char ch = str[0];
    for (int i = 1 ;ch != '\0'; i++) /*判断是否是表达式结束符*/
    {
        if (ch >= 'a' && ch <= 'z') /*如果是操作数,把它送入逆波兰区*/
        {
            exp[t] = ch;
            t++;
        }
        else if (ch == '(') /*如果是左括号，把它送入运算符栈*/
        {
            top++;
            stack[top] = ch;
        }
        else if (ch == ')')
        {
            while (stack[top] != '(') /*如果是右括号，把运算符栈的内容送入逆波兰区*/
            {
                exp[t] = stack[top];
                top--;
                t++;
            }
            top--;
        }
        else if (ch == '+' || ch == '-') /*如果是运算符，栈内运算符和栈外运算符进行比较*/
        {
            while (top != 0 && stack[top] != '(')
            {
                exp[t] = stack[top];
                top--;
                t++;
            }
            top++;
            stack[top] = ch;
        }
        else if (ch == '*' || ch == '/')
        {
            while (stack[top] == '*' || stack[top] == '/')
            {
                exp[t] = stack[top];
                top--;
                t++;
            }
            top++;
            printf("top = %d\n", top);
            stack[top] = ch;
        } else if(ch == '^'){
            while (stack[top] == '^')
            {
                exp[t] = stack[top];
                top--;
                t++;
            }
            top++;
            printf("top = %d\n", top);
            stack[top] = ch;
        }
        else{
            printf("Error: Invalid charactor: %c\n", str[i]);
            printf("Accured at postion: %d\n", i+1);
            return 0;
        }
        printf("i = %d\n", i);
        ch = str[i];
    }
    while (top != 0) /*将运算符栈的内容送入逆波兰区*/
    {
        exp[t] = stack[top];
        t++;
        top--;
    }
    printf("NBL from:");
    for (int i = 0; i < t; i++) /*打印逆波兰式*/
        printf("%c", exp[i]);
    printf("\n");
}
