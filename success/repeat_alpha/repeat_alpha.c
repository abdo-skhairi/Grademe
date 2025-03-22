#include <unistd.h>

int search(char c)
{
    char *s1 = "abcdefghijklmnopqrstuvwxyz";
    char *s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    while(s1[i] && s2[i])
    {
        if (s1[i] == c || s2[i] == c)
            return(i + 1);
        i++;
    }
    return(-1);
}

void    repeat(char *str)
{
    int i = 0;
    int k = 0;
    while(str[i])
    {
        k = search(str[i]);
        if (k == -1)
            write(1, &str[i], 1);
        else
        {
            while(k > 0)
            {
                write(1, &str[i], 1);
                k--;
            }
        }
        i++;
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
        repeat(av[1]);
    else
        write(1, "\n", 1);
}