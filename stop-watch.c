#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#define sleep(x) Sleep(x * 1000)
#define CLEAR_SCREEN() system("cls")
#else
#include <unistd.h>
#define CLEAR_SCREEN() printf("\033[H\033[J")
#endif

#define CYCLE 5
int main()
{
    int hour, minite, second;
    printf("Enter hour minite and second:\n");
    scanf("%d%d%d", &hour, &minite, &second);

    int h=0, m=0, s=0;
    while(1)
    {
        printf("%.2d:%.2d:%.2d\n", h, m, s);
        if(h == hour && m == minite && s == second)
        {
            break;
        }
        else{
            CLEAR_SCREEN();
        }
        sleep(1);
        s++;
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
