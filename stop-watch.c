#include<stdio.h>
#define CYCLE 5

#ifdef _WIN64 && _WIN32
#include<conio.h>
#define sleep(x) Sleep(x*1000)
#else
#define clrscr()
#include<unistd.h>
#endif
int main()
{
    int hour, minite, second;
    printf("Enter hour minite and second:\n");
    scanf("%d%d%d", &hour, &minite, &second);
    clrscr();
    int h=0, m=0, s=0;
    while(1)
    {
        printf("%.2d:%.2d:%.2d\n", h, m, s);
        if(h == hour && m == minite && s == second)
        {
            break;
        }
        else
        {
            clrscr();
        }
        s++;
        sleep(1);
        if(s == CYCLE)
        {
            m++;
            s = 0;
        }
        if(m == CYCLE)
        {
            h++;
            m = 0;
        }

    }
    return 0;
}
