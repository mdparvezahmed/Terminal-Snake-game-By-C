#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define True 1
#define False 0

int fruit_x, fruit_y, shap, game_over, score;
int window_hight = 25;
int window_weight = 25;
int position_x = 1;
int position_y = 7;
int score = 0;

int random_fruit()
{
    srand(time(NULL));

    int fruit = rand() % window_hight;
    if (fruit != 0 || fruit != window_hight - 1)
    {
        return fruit;
    }
    else
        return random_fruit();
}
void fruit_init()
{
    fruit_x = random_fruit();
    fruit_y = random_fruit();
}

void game_score()
{
    if (fruit_x == position_x && fruit_y == position_y)
    {
        score++;
        fruit_init();
    }
}

void move()
{
    int moveing = getch();

    switch (moveing)
    {
    case 'w':
        position_y = position_y - 1;
        break;
    case 's':
        position_y = position_y + 1;
        break;
    case 'a':
        position_x = position_x - 1;
        break;
    case 'd':
        position_x = position_x + 1;
        break;

    default:
        break;
    }
}

void window_view()
{
    shap = 0;

    for (int i = 0; i < window_hight; i++)
    {
        for (int j = 0; j < window_weight; j++)
        {
            game_score();
            if (i == 0 || i == window_hight - 1 || j == 0 || j == window_weight - 1)
            {
                printf("#");
            }
            else if (position_x == 0 || position_y == 0 || position_x == window_hight - 1 || position_y == window_weight - 1)
            {
                game_over = True;
            }

            else if (i == position_y && j == position_x)
            {
                printf("%d", shap);
            }
            else if (i == fruit_y && j == fruit_x)
            {
                printf("*");
            }

            else
                printf(" ");
        }
        printf("\n");
    }
}
void score_board()
{
    printf("######## Score Board ############\n");
    printf("#################################\n");
    printf("####### Your Score is %d ########\n", score);
    printf("###                            ##\n");
    printf("#################################\n");
}

int main()
{
    game_over = False;
    fruit_init();

    while (!game_over)
    {
        
        window_view();
        move();
        
    }
    score_board();

    return 0;
}
