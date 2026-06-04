#include <stdio.h>

#define MAX 10

int graph[MAX][MAX], indegree[MAX], queue[MAX];
int front = 0, rear = 0;

int main() {
    int n, i, j, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Calculate indegree
    for(i = 0; i < n; i++) {
        indegree[i] = 0;

        for(j = 0; j < n; j++) {
            indegree[i] += graph[j][i];
        }
    }

    // Insert vertices with indegree 0 into queue
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Ordering: ");

    while(front < rear) {
        int v = queue[front++];

        // +1 to display vertices as 1,2,3...
        printf("%d ", v + 1);

        count++;

        // Reduce indegree of adjacent vertices
        for(i = 0; i < n; i++) {
            if(graph[v][i] == 1) {
                indegree[i]--;

                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Cycle check
    if(count != n) {
        printf("\nGraph contains cycle");
    }

    return 0;
}
