#include "RPN.hpp"


bool isOperator(int c)
{
    if((c == '*') || (c == '/') || (c == '-') || (c == '+'))
    {
        return(true);
    }
    return(false);
}

int makeoper(int a,int b, char c)
{
    switch(c)
    {
        case '+':
            return(a+b);
            break;
        case '/':
            return(a/b);
            break;
        case '-':
            return(a-b);
            break;
        case '*':
            return(a*b);
            break;
        default:
            return(0);
            break;
    }
    return(0);
}

