#include "so_long.h"


void    linescheck(int fd, t_game *game)
{
    char    *gnl;
    //int     fd;
   // **argv = NULL;
    // fd = open(argv, O_RDONLY);
    gnl = ft_strtrim(get_next_line(fd), "\n");
    game->map.lines = ft_strdup("");
    game->map.width = 0;
    game->map.height = 0;
    while (gnl != NULL) 
    {
        if (game->map.width != (int)ft_strlen(gnl) && game->map.width)
            critical_errors(ERR_LINES);
        game->map.lines = ft_strjoin(game->map.lines, gnl);
        game->map.width = (int)ft_strlen(gnl);
        gnl = ft_strtrim(get_next_line(fd), "\n");
        game->map.height++;
    }
   // close(fd);
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

   // printf("~~~ %s ~~~", game->map.lines);
    i = 0;
    board = malloc(game->map.height * sizeof(char *));
    if (!board)
        return ;
    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        board[y] = ft_calloc((game->map.width) + 1, sizeof(char));
        if (!board[y])
            return ;
        while (x < game->map.width)
        {
            board[y][x] = game->map.lines[i];
            x++;
            i++;
        }
        // i++;
        y++;
    }

    //int r = 0;
    //int e = 0;
    //while (board[r][e])
    //{
        
    //    e++;
    //}

    game->map.map2d = board;
}

//ajoutee pour tester mais ne resoud pas le probleme --->
// char	**map_height(t_game *game, int fd)
// {
// 	int		nbline;

// 	nbline = linescheck(fd, game);
// 	if (nbline <= 0)
// 		return (0);
// 	game->map.height = nbline;
// 	game->map.map2d = (char **)malloc(sizeof(int *) * (nbline + 1));
// 	if (game->map.map2d == NULL)
// 		return (0);
// 	return (game->map.map2d);
// }

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
   // init_tiles(&game);
    check_args(argc);
    checkname(argv[1]);
    str_to_board(&game);
    check_map(&game);
   // check_walls(&game); // a enlever d ici et le remettre dans ma fonction check map mais tester avant
    check_tiles(&game);
    printf("height[%d] width[%d]\n", game.map.height, game.map.width);
    printf("lines\n%s\n", game.map.lines);
    game.window = mlx_new_window(game.mlx, game.map.width * IMG_X, game.map.height * IMG_Y, "so_long");
    draw_tile(&game);
    draw_map(&game);
    // define_map(&game, game.map.width, game.map.height);
    // mlx_key_hook(game.window, keep_in_touch, &game);
    // mlx_hook(game.window, 17, 0, bouge_ton_bool, &game);
    mlx_loop_hook(game.mlx, in_key_s_hook, &game);
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