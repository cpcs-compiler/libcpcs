#ifdef _WIN32
# include <Windows.h>
#else
# include <stdio.h>
#endif /* !_WIN32 */

void    cpcs_cls(void)
{
#ifdef _WIN32
    HANDLE console;
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD tmp;

    console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ',
        screen.dwSize.X * screen.dwSize.Y, (COORD){0, 0}, &tmp);
    FillConsoleOutputAttribute(console,
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, (COORD){0, 0}, &tmp);
    SetConsoleCursorPosition(console, (COORD){0, 0});
#else
    puts("\x1B[2J\x1B[H");
#endif  /* !_WIN32 */
}