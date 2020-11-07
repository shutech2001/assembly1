#include <stdio.h>
int main(int argc, char *argv [])
{
    char last_op='+', *p = argv [1];
    int acc=0, num, mem;
    while(*p != 0){
        num = *p++ - '0';
        while((*p >= 48 && *p <= 57)||*p==83){
            if(*p == 83)
            {
                num = - num;
                *p++;
            }
            else if(num>=0){
                num = num*10 + (*p++ - '0');
            }
            else if(num<0){
                num = num*10 - (*p++ - '0');
            }
        }
        switch (last_op){
        case '+':
            acc += num;
            break;
        case '-':
            acc -= num;
            break;
        case '*':
            acc *= num;
            break;
        case '/':
            acc /= num;
            break;
        }
        while(*p == 42 || *p == 43 || *p == 45 || *p == 47){
            last_op = *p++;
        }
        if(*p < 48 || *p > 57){
            *p++;
        }
    }
    printf("%d\n", acc);
}