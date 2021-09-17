#include <stdio.h>
#include <stdlib.h>
#define INF 999
#define MAX 10

void createSPT(int *spt, int nodes);
void createAM(int *matrix, int nodes);
int main(int argc, char *argv[])
{
    FILE *fptr;
    int *matrix;
    int *spt;
    int nodes;    // nodeRow is the current node we are on and
                                  // nodeCol is the node nodeRow connects to
                                  // value of nodeCol is how direct connections there are between the two nodes
    
    printf("Enter how many nodes: \n");
    scanf(" %d", &nodes);
    
    
    fptr = fopen("/Volumes/Work/projects/pathFinding/nodes.txt", "r+"); //open file containing matrix
    
    if(fptr ==NULL)
    {
        printf("Err opening file\n");
        exit(1);
    }
    
    printf("opened file successfully\n");
    
    fclose(fptr); // close file containing matrix
    createAM(matrix,nodes);
    createSPT(spt, nodes);
    free(matrix);// free allocated memory
    free(spt);
	return 0;
}
void createAM(int *matrix, int nodes) // allocate memory for matrix and set to default values
{
    int row = nodes;
    int col = nodes;
    matrix = (int *)malloc((row*col)*sizeof(int));
    for(int i=0; i<row*col;i++)
    {
        matrix[i] = i+1;
        printf("\n %d ",matrix[i]);
        
    }
    printf("\n");
    
}
void createSPT(int *spt, int nodes) // create shortest path tree array
{
    int row = nodes;
    int col = nodes;
    spt = (int *)malloc((row*col)*sizeof(int));
    printf("\n SPT \n");
    for(int i =0; i < row*col;i++){
        spt[i] = i+1;
        printf("\n %d",spt[i]);
    }
    printf("\n");
    
}

void dijkstra(int *matrix, int n)
{
    int cost[MAX][MAX], dist[MAX], visited[MAX],pred[MAX];
    int count, min,nextNode;
    
    //fill in cost array
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<n;j++)
        {
            if(matrix[i][j] ==0)
                cost[i][j] = INF;
            else(matrix[i][j] ==0)
            cost[i][j] = matrix[i][j];
        }
    }
    
    for(int i =0; i<n; i++) //fill in dist array and visited array
    {
        dist[i] = cost[0][i];
        pred[i] = 0;
        visited[i] =0;
    }
    
    dist[0] = 0;
    visited[i] = 1;
    count =1;
    
    while(count<n-1) //traversing the tree for shortest path
    {
        min = INF;
        for(int i =0; i <n; i++)
        {
            if(dist[i]<min && !visited[i])
            {
                min = dist[i];
                nextNode = i;
            }
        }
        visited[nextNode] =1;
        
        
        for(int i =0; i<n; i++)
        {
            if(!visited[i])
            {
                if((min + cost[nextNode][i]) <dist[i])
                {
                    dist[i] =min + cost[nextNode][i];
                    pred[i] = nextNode;
                }
            }
        }
        count++;
    }
}
