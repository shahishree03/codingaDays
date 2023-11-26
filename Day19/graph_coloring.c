#include<stdio.h>
#include<stdbool.h>
#define M_V 100

int graph[M_V][M_V];
int colors[M_V];
int numV, numC;

bool isSafe(int v , int c)
{
    for(int i=0;i<numV;i++)
    {
        if(graph[v][i]==numV && colors[i]==c)
        {
        return false;
        }
    }
    return true;
}

bool graphColoringUtil(int v)
{
    if(v==numV)
    {
        return true;
    }
    for(int c=1;c<=numC;c++)
    {
        if(isSafe(c,v))
        {
            colors[v]=c;

            if(graphColoringUtil(v+1)){
                return true;

            }
           
        }
         colors[v]=0;
    }
    return false;
}

void graphColoring()
{
    if(!graphColoringUtil(0))
    {
        printf("No solution exits\n");
    }
    else{
        for(int i=0;i<numV;i++)
        {
            printf("Vertex %d-> colors %d\n",i+1,colors[i]);
        }
    }
}
int main() {
printf("Enter the number of vertices: ");
scanf("%d", &numV);
printf("Enter the adjacency matrix:\n");
for (int i = 0; i < numV; i++) {
for (int j = 0; j < numV; j++) {
scanf("%d", &graph[i][j]);
}
}
printf("Enter the number of colors: ");
scanf("%d", &numC);
graphColoring();

}