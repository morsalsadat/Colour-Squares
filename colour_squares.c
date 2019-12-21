#include<stdio.h>
#include<stdlib.h>

// DO NOT MODIFY the printColourSquare() function, it
// will cause your code to fail the auto-check!
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
   // Conditions:
   // We will test this with a *different* magic
   // square than the one in this starter code
   //
   // The solution must satisfy:
   // - Each colour R,G,B,Y appears only once
   //   along each column, row, and the 2 main
   //   diagonals of the square.
   //
   // This is about problem solving - you don't
   // need any fancy pointer management or anything
   // like that. Just plain old C with a 2D array
   // and a bit of thinking.
   //
   // As a reminder. 2D arrays in C are indexed as
   // array[i][j] - gives you the element at row i,
   // column j

   //////////////////////////////////////
   // TO DO: Complete this function
   //////////////////////////////////////
   // Iterate over the rows first...
int i, j, k;
int unknowns;
int red_count, yellow_count, green_count, blue_count; // Could have also stored these in an array of 4 integers, each colour being associated with either array[0], array[1], array[2], or array[3]

for (i = 0; i < 4; i++)
  {
   unknowns = 0;
   red_count = 0;
   yellow_count = 0;
   green_count = 0;
   blue_count = 0;

     for (j = 0; j < 4; j++)
     {
       if (square[i][j] == '*')
       {
         unknowns++;
         k = j; // Store the column with the star b/c the column (and hence this particular entry) is not stagnant
       }
       else if (square[i][j] == 'R')
       {
         red_count++;
       }
       else if (square[i][j] == 'Y')
       {
         yellow_count++;
       }
       else if (square[i][j] == 'G')
       {
         green_count++;
       }
       else if (square[i][j] == 'B')
       {
         blue_count++;
       }
     }

     if (unknowns == 1)
     {
       if (red_count == 0)
       {
         square[i][k] = 'R';
       }
       else if (yellow_count == 0)
       {
         square[i][k] = 'Y';
       }
       else if (green_count == 0)
       {
         square[i][k] = 'G';
       }
       else if (blue_count == 0)
       {
         square[i][k] = 'B';
       }
     }
   }


   // Now, iterate over the columns...
   for (i = 0; i < 4; i++)
   {
   unknowns = 0; // Must add datatype before var name b/c these variables are LOCAL to this for loop...
   red_count = 0;
   yellow_count = 0;
   green_count = 0;
   blue_count = 0;

     for (j = 0; j < 4; j++)
     {
       if (square[j][i] == '*') // column is constant, only rows are changing within this for loop (hence why we are only iterating through the columns...)
       {
         unknowns++;
         k = j;
       }
       else if (square[j][i] == 'R')
       {
         red_count++;
       }
       else if (square[j][i] == 'Y')
       {
         yellow_count++;
       }
       else if (square[j][i] == 'G')
       {
         green_count++;
       }
       else if (square[j][i] == 'B')
       {
         blue_count++;
       }
     }

     // Fill in the unknown slot with a value if possible...
     if (unknowns == 1)
     {
       if (red_count == 0)
       {
         square[k][i] = 'R';
       }
       else if (yellow_count == 0)
       {
         square[k][i] = 'Y';
       }
       else if (green_count == 0)
       {
         square[k][i] = 'G';
       }
       else if (blue_count == 0)
       {
         square[k][i] = 'B';
       }
     }
   }
}


// DO NOT MODIFY ANYTHING BELOW THIS LINE!
// (we mean it! the auto-checker won't be happy)
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
