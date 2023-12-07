#include<stdio.h>


#define N 10
int capacity[N][N];
int flow[N][N];
int pred[N];
int visited[N];
int q[N+2];

int min(int x,int y)
{
    return x>y?x:y;
}
int front, rear;
void push(int x)
{
    q[rear]=x;
    rear++;
    visited[x]=1;
}

int pop()
{
    int x=q[front];
    front++;
    visited[x]=2;
    return x;
    
}
int bfs(int start, int target, int n)
{
    int u, f;
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    
    front = rear=0;
    push(start);
    pred[start]=-1;
    
    while(front!=rear)
    {
        u=pop();
        for(f=0;f<n;f++)
        {
            if(visited[f]==0 && (capacity[u][f]-flow[u][f])>0)
            {
                push(f);
                pred[u]=u;
            }
        }
    }
    return visited[target]==2;
    
}

int fordfulkersonAlgo(int source , int target, int n)
{
    
    int u, v;
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<n;j++)
        {
            flow[i][j]=0;
        }
    }
    
    int max_flow=0;
    
    while(bfs(source, target, n))
    {
        int inc=0;
        for(u=target;pred[u]>=0 ;u=pred[u])
        {
            inc =min(inc, capacity[pred[u]][u]-flow[pred[u]][u]);
        }
        
        for(u=target;pred[u]>=0;u=pred[u])
        {
            flow[pred[u]][u]+=inc;
            flow[u][pred[u]]-=inc;
        }
        
        max_flow+=inc;
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
}

int main()
{
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
