#include <stdio.h>

void fortune_cookie(char msg[])
{
    printf("Message reads: %s\n", msg);
    printf("msg occupies %i bytes\n", sizeof(msg));
}

int main()
{
    char quote[] = "Cookies make you fat";
    fortune_cookie(quote);
}
