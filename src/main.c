#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static char board[9];
static char userSym, aiSym;
int userIdx, aiIdx;

void init();
void printBoard();
void initUserIdx();
void initAiIdx();

int isWin(char);
int isTie();

int main(void)
{
    srand(time(NULL));
    init();
    while (1)
    {
        printf("\n\n");
        printBoard();

        initUserIdx();
        if (isWin(userSym) || isTie()) break;

        initAiIdx();
        if (isWin(aiSym) || isTie()) break;
    }
    
    printf("\n\n");
    printBoard();

    if (isWin(userSym))
    {
        printf("You win!\n");
    }
    else if (isWin(aiSym))
    {
        printf("Computer win!\n");
    }
    else if (isTie())
    {
        printf("Tie!\n");
    }
    return 0;
}

void init()
{
    for (int i = 0; i < sizeof(board)/sizeof(char); i++)
    {
        board[i] = '-';
    }
    userSym = 'X'; aiSym = 'O';
}
void printBoard()
{
    for (int i = 0; i < sizeof(board)/sizeof(char); i++)
    {
        printf(" | %c", board[i]);

        if (i == 2 || i == 5 || i == 8)
        {
            printf(" |\n");
        }
    }
}

void initUserIdx()
{
    printf("Enter index 1 - 9 : ");

    scanf("%i", &userIdx);
    if (userIdx < 1 || userIdx > 9 || board[userIdx - 1] == userSym || board[userIdx - 1] == aiSym)
    {
        initUserIdx();
    }
    board[userIdx - 1] = userSym;
}

void initAiIdx()
{
    printf("Ai index 1 - 9 : ");
    do
    {
        aiIdx = rand()%9;
    } while (board[aiIdx] == userSym || board[aiIdx] == aiSym);
    printf("%i\n", aiIdx + 1);
    board[aiIdx] = aiSym;
}

int isWin(char sym)
{
    if (
        (board[0] == sym && board[1] == sym && board[2] == sym) ||
        (board[3] == sym && board[4] == sym && board[5] == sym) ||
        (board[6] == sym && board[7] == sym && board[8] == sym) ||

        (board[0] == sym && board[3] == sym && board[6] == sym) ||
        (board[1] == sym && board[4] == sym && board[7] == sym) ||
        (board[2] == sym && board[5] == sym && board[8] == sym) ||

        (board[0] == sym && board[4] == sym && board[8] == sym) ||
        (board[2] == sym && board[4] == sym && board[6] == sym)
        )
    {
        return 1;
    }
    return 0;
}

int isTie()
{
    int flag = 1;
    for (int i = 0; i < sizeof(board)/sizeof(char); i++)
    {
        if (board[i] == '-')
        {
            flag = 0;
        }
    }
    return flag;
}