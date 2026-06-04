#include <stdio.h>
#include <limits.h>
#define V 5  // Number of vertices

// Function to find the vertex with minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Output array (shortest distances)
    int visited[V];   // Visited vertices

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    // Main loop
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);

        // Safety check
        if (u == -1) break;

        visited[u] = 1;

        // Update adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print results
    printf("\nVertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    int source;

    // Take user input
    printf("Enter source vertex (0 to %d): ", V - 1);
    scanf("%d", &source);

    // Validate input
    if (source < 0 || source >= V) {
        printf("Invalid source vertex!\n");
        return 1;
    }

    // Run Dijkstra
    dijkstra(graph, source);

    return 0;
}

