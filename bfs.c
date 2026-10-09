#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;

void eq(int node)
{
    if (front == -1)
        front = 0;
    queue[++rear] = node;
}
int deq()
{
    return queue[front++];
}
void BFS(int start)
{
    int current, i;

    eq(start);

    visited[start] = 1;

    while (front <= rear)
    {
        current = deq();
        printf("%d ", current);
        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                eq(i);
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start);

    return 0;
}