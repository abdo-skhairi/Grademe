#include <unistd.h>

int chkerlast(char *str)
{
    int i = 0;
    while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
        i++;
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    if(!str[i])
        return(1);
    return(0);
}

void taker(char *str)
{
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while(str[i])
    {
        while(str[i] && !(str[i] == ' ' || str[i] == '\t'))
        {
            write(1, &str[i], 1);
            i++;
        }
        if(chkerlast(str + i) == 1)
            break;
        int k = 1;
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        {
            if(k == 1)
            {
                write(1, " ", 1);
                k--;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0])
    {
        taker(av[1]);
    }
    else
        write(1, "\n", 1);
}