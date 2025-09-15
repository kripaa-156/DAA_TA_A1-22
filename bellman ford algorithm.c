#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 11 
#define E 20 

struct Edge {
    int source, destination, weight;
};
void bellmanFord(struct Edge edges[], int edgeCount, int source) {
    int distance[V];
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }
    for (int j = 0; j < edgeCount; j++) {
        int u = edges[j].source;
        int v = edges[j].destination;
        int w = edges[j].weight;
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            printf("Graph contains a negative weight cycle!\n");
            return;
        }
    }
    printf("Vertex\tDistance from Source %d\n", source);
    for (int i = 0; i < V; i++) {
        if (distance[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, distance[i]);
    }
}
int main() {
    struct Edge edges[E];
    edges[0] = (struct Edge){0, 1, 6};
    edges[1] = (struct Edge){0, 2, 7};
    edges[2] = (struct Edge){1, 2, 8};
    edges[3] = (struct Edge){1, 3, 5};
    edges[4] = (struct Edge){1, 4, -4};
    edges[5] = (struct Edge){2, 3, -3};
    edges[6] = (struct Edge){2, 4, 9};
    edges[7] = (struct Edge){3, 1, -2};
    edges[8] = (struct Edge){4, 0, 2};
    edges[9] = (struct Edge){4, 3, 7};

    edges[10] = (struct Edge){5, 6, 3};
    edges[11] = (struct Edge){6, 7, 4};
    edges[12] = (struct Edge){7, 8, 1};
    edges[13] = (struct Edge){8, 9, -2};
    edges[14] = (struct Edge){9, 10, 5};
    edges[15] = (struct Edge){10, 5, -1};
    edges[16] = (struct Edge){6, 9, 2};
    edges[17] = (struct Edge){5, 8, 6};
    edges[18] = (struct Edge){7, 10, 3};
    edges[19] = (struct Edge){8, 6, -2};
    int source = 0;
    bellmanFord(edges, E, source);
    return 0;
}
