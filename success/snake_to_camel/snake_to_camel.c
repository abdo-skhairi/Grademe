#include <unistd.h>

void cammel(char *s)
{
    int i= 0;
    while(s[i])
    {
        if(s[i] == '_')
        {
            i++;
            s[i] = s[i] - 32;
            write(1, &s[i], 1);
        }
        else
            write(1, &s[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        cammel(av[1]);
    }
    else
        write(1, "\n", 1);
}