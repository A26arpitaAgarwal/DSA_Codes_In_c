// Implementing Depth First Search using stack(functions use stack by default) in c

#include <stdio.h>
#include <stdlib.h>
// DFS implementation
int visited[7] = {0, 0, 0, 0, 0, 0, 0};

// Graph
int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i)
{
    int j;
    printf("%d ", i);
    visited[i] = 1;
    for (j = 0; j < 7; j++)
    {
        if (A[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    DFS(0);
    return 0;
}