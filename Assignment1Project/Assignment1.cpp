/*
 * Assignment1.cpp
 *
 *  Created on: Jul 21, 2015
 *      Author: hbollar
 */

// #include <stdio.h>
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;
class MagicSquare {
	public:
		int ** loc;
		int input, val, row, col, otherdiag, aSize;

		MagicSquare () {
			input = 0;
			row = 0;
			col = 0;
			val = 0;
			aSize = 0;
			otherdiag = 0;
			/*                                                                        */
			/* Print introduction of what this program is all about.                  */
			/*                                                                        */
			cout << "\nMagic Squares: This program produces an NxN matrix where" << endl;
			cout << "N is some positive odd integer.  The matrix contains the " << endl;
			cout << "values 1 to N*N.  The sum of each row, each column, and " << endl;
			cout << "the two main diagonals are all equal.  Not only does this " << endl;
			cout << "program produces the matrix, it also computes the totals for" << endl;
			cout << "each row, column, and two main diagonals." << endl;

			cout << "\nBecause of display constraints, this program can work with" << endl;
			cout << "values up to 13 only.\n" << endl;
		}

		void deleteLoc() {
			for (int i = 0; i < aSize; i++) {
				delete [] loc[i];
			}
			delete [] loc;
		}
		~MagicSquare () {
			// deleteLoc();
		}

		void getUserInput() {

			while (input != -1)
			{
				cout << "Enter a positive, odd integer (-1 to exit program):" << endl;
				cin >> input;
				if(cin.good())
				{
					if(input == -1)
					{
						/*                                                                        */
						/*    If input = -1, then exit program.                                   */
						/*                                                                        */
						cout <<"\nBye bye!" << endl;
					}
					else if (input <= 0)
					{
						/*                                                                        */
						/*    Validity check for input: Must be a positive odd integer < 13.      */
						/*                                                                        */

						cout <<"Sorry, but the integer has to be positive." << endl;
						cout <<"\nEnter a positive, odd integer (-1 to exit program):" << endl;
					}
					else if (input > 13)
					{
						cout <<"Sorry, but the integer has to be less than 15." << endl;
						cout <<"\nEnter a positive, odd integer (-1 to exit program):" << endl;
					}
					else if (input%2 == 0)
					{
						cout <<"Sorry, but the integer has to be odd." << endl;
						cout <<"\nEnter a positive, odd integer (-1 to exit program):" << endl;
					}
					else {
						break;
					}
				}
				else if(!isdigit(input))
				{
					cout << "Not a number" << endl;
					cin.clear();
					input = 0;
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				}
			}
		}

		void initializeMatrix() {
			aSize = input + 1;
			loc = new int*[aSize];
			for(int i = 0; i < aSize; i++) {
				loc[i] = new int[aSize];
			}

			cout << aSize << " is aSize" << endl;
			/*                                                                        */
			/*    Initialize matrix, row, col, and otherdiag                          */
			/*                                                                        */
			for (row = 0; row <= input; row++)
			{		/* Initialize matrix with     */
				for (col = 0; col <= input; col++)
				{	/*  all zeroes.               */
			         loc[row][col] = 0;
				}
			}
			            // cout << "in loop" << endl;
			            // cout << row << " is row " << col << " is col" << endl;
			            // cout << loc[row][col];     /* Values will reside within  */
				                                      /*  rows 1 to input*input and */
			                                           /*  columns 1 to input*input. */
			                                            /* Row totals will reside in  */
			                                            /*  loc[row][0], where row is */
			                                            /*  the row number, while the */
			                                            /*  column totals will reside */
			                                            /*  in loc[0][col], where col */
			                                            /*  is the column number.     */
			row = 1;                              		/* First value gets to sit on */
			col = input/2 + 1;                    		/*  1st row, middle of matrix.*/
	        otherdiag = 0;
	        cout << "gets here" << endl;
			/*                                                                        */
			/*    Loop for every value up to input*input, and position value in matrix*/
			/*                                                                        */
			for (int value = 1; value <= input*input; value++)
			{                                       	/* Loop for all values.       */
				if (loc[row][col] > 0)              	/* If some value already      */
				{                                   	/*  present, then             */
					row += 2;                       	/*  move down 1 row of prev.  */
					if (row > input)                	/*  If exceeds side, then     */
						row -= input;               	/*   go to other side.        */

					col--;                          	/*  move left 1 column.       */
					if (col < 1)                    	/*  If exceeds side, then     */
						col = input;                	/*   go to other side.        */
				 }

				 loc[row][col] = value;             	/* Assign value to location.  */
				 // cout << loc[row][col] << endl;
			/*                                                                        */
			/*       Add to totals                                                    */
			/*                                                                        */
				loc[0][col] += value;             		/* Add to its column total.   */
				loc[row][0] += value;              		/* Add to its row total.      */
				if (row == col)                    		/* Add to diagonal total if   */
					loc[0][0] += value;            		/*  it falls on the diagonal. */

				if (row+col == input + 1)            		/* Add to other diagonal if   */
					otherdiag += value;             	/*  it falls on the line.     */

			/*                                                                        */
			/*       Determine where new row and col are                              */
			/*                                                                        */
				 row--;
				 if (row < 1)                       	/* If row exceeds side then   */
					row = input;                    	/*  goto other side.          */
				 col++;
				 if (col > input)                   	/* If col exceeds side then   */
					col = 1;                        	/*  goto other side.          */
			}                                     		/* End of getting all values. */
			cout << "gets here 2" << endl;
		}

		void printMatrix() {
			/*                                                                        */
			/*    Print out the matrix with its totals                                */
			/*                                                                        */
			cout <<"\nThe number you selected was " << input;
			cout <<", and the matrix is:\n" << endl;
			for (row = 1; row <= input; row++)     		/* Loop: print a row at a time*/
			{
				cout <<"     ";                   /* Create column for diag.total*/
				for (col = 1; col <= input; col++)
					cout << " " << loc[row][col];  /* Print values found in a row*/
				cout << " = " <<
						loc[row][0] << endl;    	/* Print total of row.        */
			}

			/*                                                                        */
			/*    Print out the totals for each column, starting with diagonal total. */
			/*                                                                        */
			for (col = 0; col <= input; col++)     /* Print line separating the  */
				cout <<"-----";                   /*  value matrix and col totals*/
			cout << endl << otherdiag;            /* Print out the diagonal total*/
			for (col = 1; col <= input; col++)
			  cout << "   " << loc[0][col];         /* Print out the column totals*/
			cout << "   " << loc[0][0];         /* Print out the other diagonal*/
													/*  total                     */
			cout << endl;
			deleteLoc();
		}
};

/* MAGIC SQUARE - An NxN matrix containing values from 1 to N*N that are  */
/* ordered so that the sum of the rows, columns, and the major diagonals  */
/* are all equal.  There is a particular algorithm for odd integers, and  */
/* this program constructs that matrix, up to 13 rows and columns.  This   */
/* program also adds the sums of the row, columns, and major diagonals.   */



int main()
{
   MagicSquare * ms = new MagicSquare();
   while( ms->input != -1) {
	   ms->getUserInput();
	   cout << "input received and is " << ms->input << "" << endl;
	   if(ms->input != -1) {
		   cout << "input is " << ms->input << "" << endl;
		   ms->initializeMatrix();
		   cout << "initializedMatrix properly" << "" << endl;
		   ms->printMatrix();
	   }
   }
   delete ms;
}


