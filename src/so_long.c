#include "so_long.h"

int main(int argc, char **argv)
{
    char    **map;
    int     fd;
    int     file_chars = 0;
    int     width;
    int     height;
    char    line;
    // char    *ret;
    int     ret_read = 45674564;
    int     i;
    (void)argc;

    fd = open(argv[1], O_RDONLY); // ouvrir le fichier .ber
    width = 0;
    height = 0;
    line = '$';
    
    while (get_next_line(fd) != NULL)
        height++;
    close(fd);

    fd = open(argv[1], O_RDONLY);
    while(ret_read != 0)
    {
        ret_read = read(fd, &line, 1);
        if (ret_read == 0)
            break ; // return (0); si dans une fonction sinon arrete tout le programme
        else if (ret_read == -1)
            return (-1);
        else if (ret_read == 1)
            file_chars++;
    }
    close(fd); // fermer le fichier 
    width = (file_chars) / height;
    map = malloc(sizeof(char *) * height);
    i = 0;
    while (i < height)
    {
        map[i] = malloc(sizeof(char) * width);
        i++;
    }

    fd = open(argv[1], O_RDONLY);
    i = 0;
    while (i < height)
    {
        map[i] = get_next_line(fd);
        i++;
    }

    int j;
    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            printf("%c", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}