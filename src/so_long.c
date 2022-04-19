#include "so_long.h"


void    linescheck(int fd, t_game *game)
{
    char    *gnl;

    gnl = ft_strtrim(get_next_line(fd), "\n");
    game->map.lines = ft_strdup("");
    game->map.width = 0;
    game->map.height = 0;
    while (gnl != NULL) 
    {
        if (game->map.width != (int)ft_strlen(gnl) && game->map.width)
        {
            printf("Erreur, le rectangle n'est pas un rectangle !\n");
            exit(EXIT_FAILURE);
        }
        game->map.lines = ft_strjoin(game->map.lines, gnl);
        game->map.width = (int)ft_strlen(gnl);
        gnl = ft_strtrim(get_next_line(fd), "\n");
        game->map.height++;
    }
    // printf("width[%d] height[%d]\n", width, height);
    // printf("map:\n%s\n", map);       
}

//  faire une fonction pour transformer les lignes en tableau
void    str_to_board(t_game *game)
{
    // int table[x][y]; //tableau de int de x lignes et y colonnes

    int x;
    int y;
    int i;
    char **board;

    i = 0;
    board = malloc(game->map.height * sizeof(int *));
    if (!board)
        return ;
    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        board[y] = malloc((game->map.width - 1) * sizeof(int));
        if (!board[y])
            return ;
        while (x < game->map.width - 1)
        {
            board[y][x++] = game->map.lines[i];
            i++;
        }
        i++;
        y++;
    }
    game->map.map2d = board;
}

int main(int argc, char **argv) // fonctions a reorganiser
{
    t_game  game;
    int     fd;
    int     x;
    int     y;
    (void)argc;
    
    x = 0;
    y = 0;
    game.mlx = mlx_init();
    fd = open(argv[1], O_RDONLY);
    linescheck(fd, &game);
    close(fd);
    printf("height[%d] width[%d]\n", game.map.height, game.map.width);
    printf("lines\n%s\n", game.map.lines);
    str_to_board(&game);
    game.window = mlx_new_window(game.mlx, game.map.width, game.map.height, "so_long");
    draw_tile(&game);
    define_map(&game, x, y);
    draw_map(&game);
    mlx_loop(game.mlx);
}

    // // int readline()
    // // {
    //     int     file_chars = 0;
    //     int     ret_read = -1;

    //     fd = open(argv[1], O_RDONLY);
    //     while(ret_read != 0)
    //     {
    //         ret_read = read(fd, &line, 1);
    //         if (ret_read == 0)
    //             break ; // return (0); si dans une fonction sinon arrete tout le programme
    //         else if (ret_read == -1)
    //             return (-1);
    //         else if (ret_read == 1)
    //             file_chars++;
    //     }
    // close(fd); // fermer le fichier 
    // }
    // width = game.map.width;
    // height = game.map.height;
    // width = (file_chars) / height;
    // printf("height:%d width:%d\n", height, width);
    // map = malloc(sizeof(char *) * height);
    // i = 0;
    // while (i < height)
    // {
    //     map[i] = malloc(sizeof(char) * width);
    //     i++;
    // }

    // fd = open(argv[1], O_RDONLY);
    // i = 0;
    // while (i < height)
    // {
    //     map[i] = get_next_line(fd);
    //     i++;
    // }