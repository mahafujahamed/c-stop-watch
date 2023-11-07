#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

void clearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = {0, 0}; // Home position of the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return;
    }
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with spaces.
    if (!FillConsoleOutputCharacter(hConsole, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten)) {
        return;
    }

    // Move the cursor home.
    if (!SetConsoleCursorPosition(hConsole, coordScreen)) {
        return;
    }
}

#define sleep(x) Sleep(x * 1000)

#else
#include <unistd.h>
#define clearScreen() printf("\033[H\033[J")
#define sleep(x) sleep(x)
#endif

int main() {
    int h = 0, m = 0, s = 0;

    while (1) {
        printf("%.2d:%.2d:%.2d", h, m, s);
        fflush(stdout);

        sleep(1); // Wait for one second
        s++;

        if (s == 60) {
            m++;
            s = 0;
        }
        if (m == 60) {
            h++;
            m = 0;
        }

        clearScreen(); // Clear the screen using the appropriate method
    }

    return 0;
}
