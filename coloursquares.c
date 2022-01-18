#include<stdio.h>
#include<stdlib.h>

// DO NOT MODIFY the printColourSquare() function
void printColourSquare(int square[4][4])
{
   // Prints out the contents of a magic square 6x6

   int i,j;

   printf("---------------------------\n");
   for (i=0; i<4; i++)
   {
       for (j=0; j<4; j++)
       {
           printf("%c, ",square[i][j]);
       }
       printf("\n");
   }
   printf("---------------------------\n");

}

void solveColourSquare(int square[4][4])
{
 // This function receives an array of size 4x4
 // that corresponds to a coloured square.
 // It then finds any entries with value '*'
 // (which means they are not known),
 // and figures out what their value should
 // be to solve the coloured square.
 //
 // The solution must satisfy:
 // - Each colour R,G,B,Y appears only once
 //   along each column, row, and the 2 main
 //   diagonals of the square.
 //
 // 2D arrays in C are indexed as
 // array[i][j] - gives you the element at row i,
 // column j

 int i, j, unknown_i, unknowns;
 int cs[4]; 

 for (i = 0; i < 4; i++)
 {
   unknowns = 0;
   cs[0] = 0;
   cs[1] = 0;
   cs[2] = 0;
   cs[3] = 0;

   for (j = 0; j < 4; j++)
   {
     if (square[i][j] == '*')
     {
       unknowns++;
       unknown_i = j;
     }
     else if (square[i][j] == 'R')
     {
       cs[0]++;
     }
     else if (square[i][j] == 'G')
     {
       cs[1]++;
     }
     else if (square[i][j] == 'B')
     {
       cs[2]++;
     }
     else if (square[i][j] == 'Y')
     {
       cs[3]++;
     }
   }
   if (unknowns == 1)
   {
     if (cs[0] == 0)
     {
       square[i][unknown_i] = 'R';
     }
     else if (cs[1] == 0)
     {
       square[i][unknown_i] = 'G';
     }
     else if (cs[2] == 0)
     {
       square[i][unknown_i] = 'B';
     }
     else if (cs[3] == 0)
     {
       square[i][unknown_i] = 'Y';
     }
   }
 }

 for (i = 0; i < 4; i++)
 {
   unknowns = 0;
   cs[0] = 0;
   cs[1] = 0;
   cs[2] = 0;
   cs[3] = 0;
   for (j = 0; j < 4; j++)
   {
     if (square[j][i] == '*')
     {
       unknowns++;
       unknown_i = j;
     }
     else if (square[j][i] == 'R')
     {
       cs[0]++;
     }
     else if (square[j][i] == 'G')
     {
       cs[1]++;
     }
     else if (square[j][i] == 'B')
     {
       cs[2]++;
     }
     else if (square[j][i] == 'Y')
     {
       cs[3]++;
     }
   }
   if (unknowns == 1)
   {
     if (cs[0] == 0)
     {
       square[unknown_i][i] = 'R';
     }
     else if (cs[1] == 0)
     {
       square[unknown_i][i] = 'G';
     }
     else if (cs[2] == 0)
     {
       square[unknown_i][i] = 'B';
     }
     else if (cs[3] == 0)
     {
       square[unknown_i][i] = 'Y';
     }
   }
 }
}

// DO NOT MODIFY ANYTHING BELOW THIS LINE!
#ifndef __testing   // This is a compiler directive - used by the auto-checker to enable/disable this part of the code
int main()
{
    int colsqr[4][4]={{'R','Y','B','G'},{'*','G','R','Y'},{'G','*','Y','R'},{'*','R','*','B'}};

    printColourSquare(colsqr);
    printf("Solving Coloured Square!\n");
    solveColourSquare(colsqr);
    printColourSquare(colsqr);

    return 0;
}
#endif
