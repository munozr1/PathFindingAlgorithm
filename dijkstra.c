#include <stdio.h>
#include <stdlib.h>



void createAM(int *matrix, int row, int col);
int main(int argc, char *argv[])
{
    FILE *fptr;
    int *matrix;
    bool *spt;
    int nodeRow =0, nodeCol=0;    // nodeRow is the current node we are on and
                                  // nodeCol is the node nodeRow connects to
                                  // value of nodeCol is how direct connections there are between the two nodes
    
    printf("Enter how many rows: \n");
    scanf(" %d", &nodeRow);
    printf("Enter how many cols: \n");
    scanf(" %d", &nodeCol);
    
    fptr = fopen("/Volumes/Work/projects/pathFinding/nodes.txt", "r+"); //open file containing matrix
    
    if(fptr ==NULL)
    {
        printf("Err opening file\n");
        exit(1);
    }
    
    printf("opened file successfully\n");
    
    fclose(fptr); // close file containing matrix
    createAM(matrix,nodeRow, nodeCol);
    free(matrix);// free allocated memory
    free(spt);
	return 0;
}
void createAM(int *matrix, int row, int col) // allocate memory for matrix and set to default values
{
    matrix = (int *)malloc((row*col)*sizeof(int));
    for(int i=0; i<row*col;i++)
    {
        matrix[i] = i+1;
        printf("\n %d ",matrix[i]);
        
    }
    printf("\n");
    
}
void createSPT(int *spt, int row, int col)
{
    spt = (int *)malloc((row*col)*sizeof(int));
    
}
