/*#include <stdio.h>

#define A 0
#define B 1
#define C 2
#define MAX_NODES 1000
#define O 1000000000

int capacity[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int pred[MAX_NODES];

int min(int x, int y) {
    return x < y ? x : y;
}

int front, rear;
int q[MAX_NODES + 2];

void push(int x) {
    q[rear] = x;
    rear++;
    visited[x] = B;
}

int pop() {
    int x = q[front];
    front++;
    visited[x] = C;
    return x;
}

int bfs(int start, int target, int n) {
    int u, f;
    for (u = 0; u < n; u++) {
        visited[u] = A;
    }
    front = rear = 0;
    push(start);
    pred[start] = -1;
    while (front != rear) {
        u = pop();
        for (f = 0; f < n; f++) {
            if (visited[f] == A && capacity[u][f] - flow[u][f] > 0) {
                push(f);
                pred[f] = u; // Corrected this line to assign pred[f] to u
            }
        }
    }
    return visited[target] == C;
}

int fordfulkersonAlgo(int s, int t, int n) {
    int i, j, u;
    int max_flow = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            flow[i][j] = 0;
        }
    }

    while (bfs(s, t, n)) {
        int increment = O;
        for (u = t; pred[u] >= 0; u = pred[u]) {
            increment = min(increment, capacity[pred[u]][u] - flow[pred[u]][u]);
        }
        for (u = t; pred[u] >= 0; u = pred[u]) {
            flow[pred[u]][u] += increment;
            flow[u][pred[u]] -= increment;
        }

        max_flow += increment;
    }
    return max_flow;
}
void displayResidualGraph(int n) {
    printf("Residual Graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", capacity[i][j] - flow[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    int vertices, s, t;
    printf("Enter the number of vertices...\n");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            capacity[i][j] = 0;
        }
    }

    int u, v, count = 1;
    int max_allotted = vertices * (vertices - 1);
    char ch = 'Y';

    while (ch != 'N' && (count != max_allotted)) {
        printf("Enter capacity from source to destination (u to v) in the range (0-%d): ", vertices - 1);
        scanf("%d %d", &u, &v);
        scanf("%d", &capacity[u][v]);
        count++;
        printf("Do you want to enter more? Type 'Y' for yes and 'N' for exit\n");
        scanf(" %c", &ch);
    }

    printf("Provide source and sink node values: ");
    scanf("%d %d", &s, &t);
    int maxFlow = fordfulkersonAlgo(s, t, vertices); // Calculate the maximum flow
    displayResidualGraph(vertices); // Display the residual graph after the first iteration
    printf("Max Flow: %d\n", maxFlow); // Print the maximum flow

    return 0;
}
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100
#define INF 1000000

int capacity[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int parent[MAX_NODES];
int n;

// Utility function to perform a Depth-First Search to find an augmenting path
bool dfs(int s, int t) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    visited[s] = true;
    parent[s] = -1;

    int stack[MAX_NODES];
    int top = 0;
    stack[top++] = s;

    while (top > 0) {
        int u = stack[--top];

        for (int v = 0; v < n; v++) {
            if (!visited[v] && capacity[u][v] - flow[u][v] > 0) {
                visited[v] = true;
                parent[v] = u;
                stack[top++] = v;
            }
        }
    }

    return visited[t];
}

// Ford-Fulkerson algorithm
int fordFulkerson(int source, int sink) {
    int maxFlow = 0;

    while (dfs(source, sink)) {
        int pathFlow = INF;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = (pathFlow < capacity[u][v] - flow[u][v]) ? pathFlow : (capacity[u][v] - flow[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += pathFlow;
            flow[v][u] -= pathFlow;
        }

        maxFlow += pathFlow;

        // Display the residual graph
        printf("Residual Graph (Capacity - Flow):\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%2d ", capacity[i][j] - flow[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return maxFlow;
}

// Display the final flow
void displayFlow() {
    printf("Final Flow:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (flow[i][j] > 0) {
                printf("Edge (%d -> %d): Flow = %d\n", i, j, flow[i][j]);
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            capacity[i][j] = 0;
            flow[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    int numEdges;
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int u, v, c;
        printf("Enter edge (u v c): ");
        scanf("%d %d %d", &u, &v, &c);
        capacity[u][v] = c;
    }

    int source, sink;
    printf("Enter source and sink (s t): ");
    scanf("%d %d", &source, &sink);

    int maxFlow = fordFulkerson(source, sink);

    printf("Maximum Flow: %d\n", maxFlow);
    displayFlow();

    return 0;
}
