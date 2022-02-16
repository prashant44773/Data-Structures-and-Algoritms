#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};

int a[7][7] = {

    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

void DFS(int i)
{
    int j;
    printf("%d ", i);

    visited[i] = 1;


    for (j = 0; j < 7; j++)
    {
        if(a[i][j] == 1  &&  !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    // DFS Implementation
    DFS(6);
    return 0;
}