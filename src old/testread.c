#include "so_long.h"

int checkname(char *str)
{
    char *ext;

    if (!str)
        return (0);
    ext = strstr(str, ".ber");
    if (ext && strlen(ext) == 4)
    {
        return (1);
    }
    return (0);
}

int main(void)
{
    char    *file;

    file = "truc.ber";
    
    if (checkname(file))
        printf("%s", file);
    return (0);
}

