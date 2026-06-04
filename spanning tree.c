#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Function to find vertex with minimum key value
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print MST and its total cost
void printMST(int parent[], int V, int graph[V][V]) {
    int totalCost = 0;

    for (int i = 1; i < V; i++) {
        totalCost += graph[i][parent[i]];
    }

    printf("\nTotal Cost of MST = %d\n", totalCost);
}

// Prim's Algorithm
void primMST(int V, int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, V, graph);
}

int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];

    srand(time(0));

    // Generate random graph
    for (int i = 0; i < V; i++) {
        for (int j = i; j < V; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                int weight = rand() % 20 + 1;
                graph[i][j] = graph[j][i] = weight;
            }
        }
    }

    // Measure time
    clock_t start, end;

    start = clock();   // start time

    primMST(V, graph);

    end = clock();     // end time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time: %f seconds\n", time_taken);

    return 0;
}
