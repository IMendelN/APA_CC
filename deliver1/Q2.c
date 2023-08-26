#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements in an array
void Swap(int v[], int i, int j) {
  int tmp;
  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

// Function to check if a configuration of queens on a board is valid
int ValidSolution(int rows[]) {
  int i;
  int x, y;
  int xx, yy;

  for (i = 0; i < 8; i++) {
    x = i;
    y = rows[i];

    xx = x;
    yy = y;
    while (1) {
      xx += 1;
      yy -= 1;
      if (xx > 7 || yy < 0)
        break;

      if (yy == rows[xx])
        return 0; // If a queen is on the same diagonal, the solution is invalid
    }

    xx = x;
    yy = y;
    while (1) {
      xx -= 1;
      yy -= 1;
      if (xx < 0 || yy < 0)
        break;

      if (yy == rows[xx])
        return 0; // If a queen is on the same diagonal, the solution is invalid
    }
  }
  return 1; // The solution is valid
}

// Function to print a valid queen configuration on a board
void PrintSolution(int rows[]) {
  char board[8][8];
  int i, j;
  int x, y;
  static int nsols = 0; // Counter for valid solutions found

  nsols++;

  printf("******** SOLUTION: %d ********\n", nsols);

  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      board[i][j] = '.';

  for (i = 0; i < 8; i++) {
    x = i;
    y = rows[i];
    board[y][x] = 'Q'; // Mark the queen's position on the board
  }

  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      printf(" %c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to find all possible solutions to the 8 queens problem
void Find8QueensSolutions() {
  int rows[8];
  int i;
  for (i = 0; i < 8; i++)
    rows[i] = i; // Initialize the rows where queens can be placed
  TestPermutations(rows, 0);
}

// Recursive function to test all possible permutations of queens
void TestPermutations(int rows[], int k) {
  int i;
  static int foundSolution = 0; // Variable to control if a solution has been found

  if (k == 8) {
    if (ValidSolution(rows)) {
      PrintSolution(rows); // If a valid solution is found, print it
      foundSolution = 1;
    }
  } else {
    for (i = k; i < 8 && !foundSolution; i++) {
      Swap(rows, k, i); // Swap queen positions to generate different configurations
      TestPermutations(rows, k + 1); // Call the function recursively for the next queen
      Swap(rows, i, k); // Undo the swap to revert to the previous configuration
    }
  }
}

// Main function
int main() {
  Find8QueensSolutions(); // Find and print all possible solutions to the 8 queens problem
  return 0; // Indicate successful program execution
}
