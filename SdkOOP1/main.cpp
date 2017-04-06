// SdkOOP1.CPP A C++ PROGRAM
// PROGRAMMED BY :- MAHMUDUL HASAN KHAN CE09003
// THIS PROGRAM CAN BE USED TO SOLVE 9X9 SUDOKU GAME IN THE PROTHOM ALO

#include<stdio.h>
#include<conio.h>

class IOSdkOOP1
{
public:
	static char** input_Sudoku();
	static void show_Sudoku(char **sudoku);
	static void show_Sudoku(char **sudoku, char *message)
	{
		printf(message);
		show_Sudoku(sudoku);
	}
	static void view_Programmer_Info()
	{
		printf("\n\n\n\tPROGRAMMED BY :- ");
		printf("\n\n\tMAHMUDUL HASAN KHAN CE09003");
		printf("\n\n\tTHANK YOU !!!");
		getch();
	}
};

class SdkOOP1
{
	char **sudoku, **fixed;
		// FIXED digits OF GIVEN SUDOKU WILL BE STORED IN FIXED[9][9]
		// SOLUTION MATRIX WILL BE STORED IN SUDOKU[9][9]

public:

	// RETURN FIXED SUDOKU
	char** get_Fixed()
	{
		return fixed;
	}

	SdkOOP1(); // CONSTRUCTOR
	SdkOOP1(char **sudoku); // CONSTRUCTOR
	char** solve_Sudoku();
	~SdkOOP1(); // DESTRUCTOR
};

int main()
{
	SdkOOP1 *obj1 = new SdkOOP1(IOSdkOOP1::input_Sudoku());
	IOSdkOOP1::show_Sudoku(obj1->get_Fixed(),
		"\n\n\n\tTHE GIVEN SUDOKU IS : ");
	IOSdkOOP1::show_Sudoku(obj1->solve_Sudoku(),
		"\n\n\n\tTHE SOLUTION IS : ");
	delete obj1;
	return 0;
}

// FUNCTION TO INPUT SUDOKU
char** IOSdkOOP1::input_Sudoku()
{
	char **fixed = new char*[9];
	printf("\n\n\n\tWELCOME TO 9X9 SUDOKU SOLVER !!!");
	printf("\n\n\n\tENTER NUMBERS : ENTER * FOR BLANK SPACE :- ");
	for(int row=0;row<9;row++)
	{
		fixed[row] = new char[9];
		printf("\n\n\tENTER ROW %d : ",row+1);
		for(int col=0;col<9;col++)
			scanf("%c",&fixed[row][col]);
		char c_h;
		scanf("%c",&c_h);
	}
	return fixed;
}

// FUNCTION TO DISPLAY SUDOKU
void IOSdkOOP1::show_Sudoku(char **sudoku)
{
	for(int row=0;row<9;row++)
	{
		if(!(row%3))
			printf("\n\n");
		printf("\n\n\t");
		for(int col=0;col<9;col++)
		{
			if(!(col%3))
				printf("  ");
			printf(" %c",sudoku[row][col]);
		}
	}
}

// SdkOOP1'S CONSTRUCTOR
SdkOOP1::SdkOOP1(char **input)
{
	fixed = input;
	sudoku = new char*[9];
	for(int row = 0; row < 9; row++)
		sudoku[row] = new char[9];
}

// FUNCTION TO SOLVE SUDOKU
char** SdkOOP1::solve_Sudoku()
{
	int pos = 0;
		/* INDEX OF POSITION IN 9X9 MATRIX
		AND 9*9 = 81 BLOCKS . SO, 0<=pos<=81 */
	char stack[81][9];
		/* IT IS 9X9 MATRIX . SO, TOTAL 9*9 = 81 BLOCKS
		SO, HERE IS 81 stacks FOR EACH BLOCK .
		ALL POSSIBLE AND VALID digits OF EACH BLOCK
		WILL BE STORED IN EACH stack */
	char top[81];
		// TOTAL 81 tops FOR 81 stacks
	int i,j;
	for(i=0;i<81;i++)
		top[i]=0;
		// INITIALIZE ALL tops TO 0
	for(int row=0;row<9;row++)
	{
		for(int col=0;col<9;col++)
		{
			// IF THE digit IN THIS ROW AND COLUMN IS FIXED
			if(fixed[row][col]>='1'&&fixed[row][col]<='9')
				// THEN PUT THE FIXED digit IN THIS ROW AND COLUMN
				sudoku[row][col] = fixed[row][col];
			// ELSE IF THE digit IN THIS ROW AND COLUMN IS VARIABLE
			else
			// FIND THE POSSIBLE AND VALID digit FOR THIS ROW AND COLUMN
			{
				for(char digit ='1';digit<='9';digit++)
				{
					int valid=1;
					// CHECK VALIDITY ACCORDING TO FIXED digits

					if(valid) // CHECK VALIDITY IN THE ROW
						for(j=0;j<9;j++)
							if(fixed[row][j]==digit)
							{
								valid = 0;
								break;
							}
					if(valid) // CHECK VALIDITY IN THE COLUMN
						for(i=0;i<9;i++)
							if(fixed[i][col]==digit)
							{
								valid = 0;
								break;
							}

					int r2=row-row%3;
					int c2=col-col%3;

					if(valid) // CHECK VALIDITY IN THE 3X3 SQUARE
					{
						for(i=r2;(i<r2+3)&&valid;i++)
							for(j=c2;j<c2+3;j++)
								if(fixed[i][j]==digit)
								{
									valid = 0;
									break;
								}
					}

					/* CHECK VALIDITY ACCORDING TO
					PREVIOUS VARIABLE digits*/

					if(valid) // CHECK VALIDITY IN THE ROW
						for(j=0;j<col;j++)
							if(sudoku[row][j]==digit)
							{
								valid = 0;
								break;
							}
					if(valid) // CHECK VALIDITY IN THE COLUMN
						for(i=0;i<row;i++)
							if(sudoku[i][col]==digit)
							{
								valid = 0;
								break;
							}
					if(valid) // CHECK VALIDITY IN THE 3X3 SQUARE
						for(i=r2;(i<row)&&valid;i++)
							for(j=c2;j<c2+3;j++)
								if(sudoku[i][j]==digit)
								{
									valid = 0;
									break;
								}
					if(valid)
						for(j=c2;j<col;j++)
							if(sudoku[row][j]==digit)
							{
								valid = 0;
								break;
							}

					// IF THE POSSIBLE AND VALID digits ARE FOUND
					if(valid)
					/* THEN PUSH THE POSSIBLE AND VALID digits
					IN THE stack[pos] FOR THIS POSITION pos */
						stack[pos][top[pos]++] = digit;
				}
				/* IF VALID digit IS NOT FOUND, THEN stack[pos]
				WILL BE EMPTY AND top[pos] == 0; */
				while(!top[pos])
				{
					/* SEARCH PREVIOUS BLOCKS UNTIL A stack
					WITH POSSIBLE digits IS FOUND */
					// DECREASE POSITION pos
					pos--;
					// GO TO PREVIOUS ROW AND COLUMN
					// IF IT IS NOT THE FIRST COLUMN
					if(col)
						col--;
					/* ELSE GO TO THE LAST COLUMN
					OF PREVIOUS ROW */
					else
					{
						row--;
						col = 8;
					}
				} /* WHILE LOOP WILL END WHEN stack WITH
				  POSSIBLE digits IS FOUND */
				/* POP THE POSSIBLE digit FROM THE stack AND
				PUT THE POSSIBLE AND VALID DIGIT IN THE SUDOKU */
				sudoku[row][col] = stack[pos][--top[pos]];
			}
			// GO TO NEXT POSITION pos
			pos++;
		}
	}

	// RETURN OUTPUT :-
	return sudoku;
}

SdkOOP1::~SdkOOP1()
{
	for(int row = 0; row < 9; row++)
	{
		delete [] fixed[row];
		delete [] sudoku[row];
	}
	delete [] fixed;
	delete [] sudoku;
	IOSdkOOP1::view_Programmer_Info();
}
