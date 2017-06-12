#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
	int x = 5;
	int y = 7;

	string line;

        int xCount = 0;
        int yCount = 0;
        double Cell = 0.0;
	double density = 0.0;
        int Gen = 0;

	string TextFile = "ExampleGrid.txt";

	int mode = 0;

	cout << "Enter '0' if you want to generate a grid" << endl;
	cout << "Enter '1' if you want to use a grid from a text file" << endl;
	cin >> mode;

	if(mode == 1)
        {
                cout << "Enter the name of the file" << endl;
                cin >> TextFile;
	}
	ifstream inFile(TextFile);
	if(inFile.fail())
	{
		cerr << "Error Opening File" << endl;
		exit(1);
	}

	if(mode == 0)
        {
	}

	if(mode == 1)
	{
		while(!inFile.eof())
		{
			getline(inFile, line);
			for(int i = 0; i < line.length(); i++)
        		{
				if(line[i] == *"X")
            			{
				}

				else if(line[i] == *"-")
                                {
                                } 

				else
				{
					if(xCount == 0)
					{
						y = atoi(&line[i]);
						xCount = 1;
					}

					else if(xCount == 1 && yCount == 0)
					{
						x = atoi(&line[i]);
						yCount = 1;
					}
				}
			}
		}
		xCount = 0;
        	yCount = -2;

		//cout << "x is " << x << endl;
		//cout << "y is " << y << endl;
	}
	inFile.close();
	ifstream inFile2(TextFile);

	if(mode == 0)
	{
		cout << "Please enter the number of rows" << endl;
		cin >> y;
		cout << "Please enter the number of collumns" << endl;
		cin >> x;
		cout << "You are playing with a " << x << " X " << y << " grid" << endl;
		cout << "Please enter the population density as a decimal between 0 and 1" << endl;
                cin >> density;
	}

	//This is the array for the current generation
        char LifeGame[y][x];

        //This array keeps track of the births and deaths for the next generation
        char NextGen[y][x];

	if(mode == 1)
        {
		while(!inFile2.eof())
                {
                        getline(inFile2, line);
                        for(int i = 0; i < line.length(); i++)
                        {
                                if(line[i] == *"X")
                                {
					LifeGame[yCount][xCount] = 'X';
					xCount++;
                                }

				else if(line[i] == *"-")
                                {
                                        LifeGame[yCount][xCount] = '-';
                                        xCount++;
                                }

                                else
                                {
					if(yCount >= 0)
					{
						LifeGame[yCount][xCount] = '-';
						xCount++;
					}
                                }
                        }
			xCount = 0;
			yCount++;
                }
		yCount = 0;
		/*cout << "Array[0][0] is" << LifeGame[0][0] << endl;
		cout << "Array[0][1] is" << LifeGame[0][1] << endl;
		cout << "Array[0][2] is" << LifeGame[0][2] << endl;
		cout << "Array[1][0] is" << LifeGame[1][0] << endl;
		cout << "Array[1][1] is" << LifeGame[1][1] << endl;
		cout << "Array[1][2] is" << LifeGame[1][2] << endl;*/
	}
	inFile2.close();

        if(mode == 0)
        {
                for(int yCount = 0; yCount < y; yCount++)
                {
                        for(int xCount = 0; xCount < x; xCount++)
                        {
                                Cell = ((double) rand()/(RAND_MAX));

                                if(Cell > density)
                                {
                                        LifeGame[yCount][xCount] = '-';
                                }

                                else if(Cell <= density)
                                {
                                        LifeGame[yCount][xCount] = 'X';
                                }
                        }
                        xCount = 0;
                }
                yCount = 0;
        }

	cout << " " << endl;
	cout << " " << endl;
	cout << "This is what your initial grid will look like:" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "Generation " << Gen << endl;
        cout << " " << endl;

	for(int yCount = 0; yCount < y; yCount++)
	{
		for(int xCount = 0; xCount < x; xCount++)
		{
			cout << LifeGame[yCount][xCount] << " ";
		}
		xCount = 0;
		cout << endl;
	}
	yCount = 0;

	int choice = 0;
	int Cont = 1;
	//Cont is supposed to be short for continue
	//The program wouldn't let me name the variable "continue"

	int Neighbors = 0;
	int Check = 1;
	int Final = 0;

	while(choice != 1 && choice != 2 && choice != 3)
	{
		cout << "Please enter which game mode you would like to play" << endl;
		cout << "Enter '1' to play Classic Mode" << endl;
		cout << "Enter '2' to play Doughnut Mode" << endl;
		cout << "Enter '3' to play Mirror Mode" << endl;
        	cin >> choice;

		if(choice == 1)
		{
			cout << "You chose Classic Mode" << endl;

			while(Cont != 0)
			{
				for(int yCount = 0; yCount < y; yCount++)
        			{
                			for(int xCount = 0; xCount < x; xCount++)
                			{
						//UpperLeft
						if((xCount - 1) >= 0 && (yCount - 1) >= 0)
						{
                               				if(LifeGame[yCount - 1][xCount - 1] == 'X')
							{
								Neighbors++;
							}
						}
						else
                                                {
                                                }

						//Above
                                                if((yCount - 1) >= 0)
                                                {
                                                        if(LifeGame[yCount - 1][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
                                                }

						//UpperRight
                                                if((xCount + 1) <= x && (yCount - 1) >= 0)
                                                {
                                                        if(LifeGame[yCount - 1][xCount + 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
                                                }

                                                //Left
                                                if((xCount - 1) >= 0)
                                                {
                                                        if(LifeGame[yCount][xCount - 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
                                                }

						//Right
                                                if((xCount + 1) <= x)
                                                {
                                                        if(LifeGame[yCount][xCount + 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
                                                }

                                                //LowerLeft
                                                if((xCount - 1) >= 0 && (yCount + 1) <= y)
                                                {
                                                        if(LifeGame[yCount + 1][xCount - 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
                                                }

						//Bellow
                                                if((yCount + 1) <= y)
                                                {
                                                        if(LifeGame[yCount + 1][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
                                                }

                                                //LowerRight
                                                if((xCount + 1) <= x && (yCount + 1) <= y)
                                                {
                                                        if(LifeGame[yCount + 1][xCount + 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
						{
						}

						if(Neighbors <= 1 || Neighbors >= 4)
						{
                             				NextGen[yCount][xCount] = '-';
						}

						else if(Neighbors == 2)
                                               	{
                                                       	NextGen[yCount][xCount] = LifeGame[yCount][xCount];
                                                }

						else if(Neighbors == 3)
                                                {
                                                        NextGen[yCount][xCount] = 'X';
                                                }

						Neighbors = 0;
               				}
                			xCount = 0;
        			}
        			yCount = 0;
				Gen++;

				for(int yCount = 0; yCount < y; yCount++)
                                {
                                        for(int xCount = 0; xCount < x; xCount++)
                                        {
                                                LifeGame[yCount][xCount] = NextGen[yCount][xCount];
                                        }
                                        xCount = 0;
                                }
                                yCount = 0;

				Cont = 0;
				//This checks if the grid is empty
				Final = 1;
				for(int yCount = 0; yCount < y; yCount++)
                                {
                                        for(int xCount = 0; xCount < x; xCount++)
                                        {
                                                if(LifeGame[yCount][xCount] == 'X')
						{
							Cont = 1;
							Final = 0;
						}
                                        }
                                        xCount = 0;
                                }
                                yCount = 0;

				//This checks if the grid is full
				if(Cont != 0)
				{
					Cont = 0;
					Final = 2;
                                	for(int yCount = 0; yCount < y; yCount++)
                                	{
                                        	for(int xCount = 0; xCount < x; xCount++)
                                        	{
                                                	if(LifeGame[yCount][xCount] == '-')
                                                	{
                                                        	Cont = 1;
								Final = 0;
                                                	}
                                        	}
                                        	xCount = 0;
                                	}
                                	yCount = 0;
				}

				if(Cont != 0)
				{
					if(Check != 0)
					{
						cout << "Do you want the process to automate itself from here?" << endl;
                                		cout << "Enter '0' if you want the process to automate itself" << endl;
						cout << "Enter '1' if you want to see this generation" << endl;
                                		cin >> Check;

						if(Check != 0)
                                        	{
							cout << "This is what your current grid will looks like:" << endl;
        						cout << " " << endl;
        						cout << " " << endl;
        						cout << "Generation " << Gen << endl;
        						cout << " " << endl;

        						for(int yCount = 0; yCount < y; yCount++)
        						{
                						for(int xCount = 0; xCount < x; xCount++)
                						{
                        						cout << LifeGame[yCount][xCount] << " ";
                						}
                						xCount = 0;
                						cout << endl;
        						}
        						yCount = 0;

							cout << "Enter '1' to display the next generation" << endl;
							cout << "Enter '0' before pressing the 'enter' button to stop" << endl;
                					cin >> Cont;
						}
					}
				}

				if(Final == 1)
				{
					cout << "It took " << Gen << " Generations for the cell population to die out" << endl;
				}

				if(Final == 2)
                                {
                                        cout << "It took " << Gen << " Generations for the cell population to fill the board" << endl;
                                }

				if(Gen == 1000)
				{
					cout << "The cell population lasted for over 1,000 generations" << endl;
					Cont = 0;
				}
			}
		}

		else if(choice == 2)
                {
			cout << "You chose Doughnut Mode" << endl;

			while(Cont != 0)
			{
				for(int yCount = 0; yCount < y; yCount++)
        			{
                			for(int xCount = 0; xCount < x; xCount++)
                			{
						//UpperLeft
						if((xCount - 1) >= 0 && (yCount - 1) >= 0)
						{
                               				if(LifeGame[yCount - 1][xCount - 1] == 'X')
							{
								Neighbors++;
							}
						}
						else
                                                {
							if(LifeGame[y][x] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

						//Above
                                                if((yCount - 1) >= 0)
                                                {
                                                        if(LifeGame[yCount - 1][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
							if(LifeGame[y][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

						//UpperRight
                                                if((xCount + 1) <= x && (yCount - 1) >= 0)
                                                {
                                                        if(LifeGame[yCount - 1][xCount + 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
							if(LifeGame[y][0] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

                                                //Left
                                                if((xCount - 1) >= 0)
                                                {
                                                        if(LifeGame[yCount][xCount - 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
							if(LifeGame[yCount][x] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

						//Right
                                                if((xCount + 1) <= x)
                                                {
                                                        if(LifeGame[yCount][xCount + 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
							if(LifeGame[yCount][0] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

                                                //LowerLeft
                                                if((xCount - 1) >= 0 && (yCount + 1) <= y)
                                                {
                                                        if(LifeGame[yCount + 1][xCount - 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
							if(LifeGame[0][x] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

						//Bellow
                                                if((yCount + 1) <= y)
                                                {
                                                        if(LifeGame[yCount + 1][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
							if(LifeGame[0][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

                                                //LowerRight
                                                if((xCount + 1) <= x && (yCount + 1) <= y)
                                                {
                                                        if(LifeGame[yCount + 1][xCount + 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
						{
							if(LifeGame[0][0] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
						}

						if(Neighbors <= 1 || Neighbors >= 4)
						{
                             				NextGen[yCount][xCount] = '-';
						}

						else if(Neighbors == 2)
                                               	{
                                                       	NextGen[yCount][xCount] = LifeGame[yCount][xCount];
                                                }

						else if(Neighbors == 3)
                                                {
                                                        NextGen[yCount][xCount] = 'X';
                                                }

						Neighbors = 0;
               				}
                			xCount = 0;
        			}
        			yCount = 0;
				Gen++;

				for(int yCount = 0; yCount < y; yCount++)
                                {
                                        for(int xCount = 0; xCount < x; xCount++)
                                        {
                                                LifeGame[yCount][xCount] = NextGen[yCount][xCount];
                                        }
                                        xCount = 0;
                                }
                                yCount = 0;

				Cont = 0;
				//This checks if the grid is empty
				Final = 1;
				for(int yCount = 0; yCount < y; yCount++)
                                {
                                        for(int xCount = 0; xCount < x; xCount++)
                                        {
                                                if(LifeGame[yCount][xCount] == 'X')
						{
							Cont = 1;
							Final = 0;
						}
                                        }
                                        xCount = 0;
                                }
                                yCount = 0;

				//This checks if the grid is full
				if(Cont != 0)
				{
					Cont = 0;
					Final = 2;
                                	for(int yCount = 0; yCount < y; yCount++)
                                	{
                                        	for(int xCount = 0; xCount < x; xCount++)
                                        	{
                                                	if(LifeGame[yCount][xCount] == '-')
                                                	{
                                                        	Cont = 1;
								Final = 0;
                                                	}
                                        	}
                                        	xCount = 0;
                                	}
                                	yCount = 0;
				}

				if(Cont != 0)
				{
					if(Check != 0)
					{
						cout << "Do you want the process to automate itself from here?" << endl;
                                		cout << "Enter '0' if you want the process to automate itself" << endl;
						cout << "Enter '1' if you want to see this generation" << endl;
                                		cin >> Check;

						if(Check != 0)
                                        	{
							cout << "This is what your current grid will looks like:" << endl;
        						cout << " " << endl;
        						cout << " " << endl;
        						cout << "Generation " << Gen << endl;
        						cout << " " << endl;

        						for(int yCount = 0; yCount < y; yCount++)
        						{
                						for(int xCount = 0; xCount < x; xCount++)
                						{
                        						cout << LifeGame[yCount][xCount] << " ";
                						}
                						xCount = 0;
                						cout << endl;
        						}
        						yCount = 0;

							cout << "Enter '1' to display the next generation" << endl;
							cout << "Enter '0' before pressing the 'enter' button to stop" << endl;
                					cin >> Cont;
						}
					}
				}

				if(Final == 1)
				{
					cout << "It took " << Gen << " Generations for the cell population to die out" << endl;
				}

				if(Final == 2)
                                {
                                        cout << "It took " << Gen << " Generations for the cell population to fill the board" << endl;
                                }

				if(Gen == 1000)
                                {
                                        cout << "The cell population lasted for over 1,000 generations" << endl;
                                        Cont = 0;
                                }
			}
                }

		else if(choice == 3)
                {
			cout << "You chose Mirror Mode" << endl;

			while(Cont != 0)
			{
				for(int yCount = 0; yCount < y; yCount++)
        			{
                			for(int xCount = 0; xCount < x; xCount++)
                			{
						//UpperLeft
						if((xCount - 1) >= 0 && (yCount - 1) >= 0)
						{
                               				if(LifeGame[yCount - 1][xCount - 1] == 'X')
							{
								Neighbors++;
							}
						}
						else if((xCount - 1) >= 0)
                                                {
							if(LifeGame[yCount][xCount - 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
                                                        if(LifeGame[yCount][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

						//Above
                                                if((yCount - 1) >= 0)
                                                {
                                                        if(LifeGame[yCount - 1][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
							if(LifeGame[yCount][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

						//UpperRight
                                                if((xCount + 1) <= x && (yCount - 1) >= 0)
                                                {
                                                        if(LifeGame[yCount - 1][xCount + 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else if((xCount + 1) <= x)
                                                {
							if(LifeGame[yCount][xCount + 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else                      
                                                {
                                                        if(LifeGame[yCount][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

                                                //Left
                                                if((xCount - 1) >= 0)
                                                {
                                                        if(LifeGame[yCount][xCount - 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
							if(LifeGame[yCount][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

						//Right
                                                if((xCount + 1) <= x)
                                                {
                                                        if(LifeGame[yCount][xCount + 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
							if(LifeGame[yCount][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

                                                //LowerLeft
                                                if((xCount - 1) >= 0 && (yCount + 1) <= y)
                                                {
                                                        if(LifeGame[yCount + 1][xCount - 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else if((xCount - 1) >= 0)
                                                {
							if(LifeGame[yCount][xCount - 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else                      
                                                {
                                                        if(LifeGame[yCount][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

						//Bellow
                                                if((yCount + 1) <= y)
                                                {
                                                        if(LifeGame[yCount + 1][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else
                                                {
							if(LifeGame[yCount][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

                                                //LowerRight
                                                if((xCount + 1) <= x && (yCount + 1) <= y)
                                                {
                                                        if(LifeGame[yCount + 1][xCount + 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }
						else if((xCount + 1) <= x)
						{
							if(LifeGame[yCount][xCount + 1] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
						}
						else                      
                                                {
                                                        if(LifeGame[yCount][xCount] == 'X')
                                                        {
                                                                Neighbors++;
                                                        }
                                                }

						if(Neighbors <= 1 || Neighbors >= 4)
						{
                             				NextGen[yCount][xCount] = '-';
						}

						else if(Neighbors == 2)
                                               	{
                                                       	NextGen[yCount][xCount] = LifeGame[yCount][xCount];
                                                }

						else if(Neighbors == 3)
                                                {
                                                        NextGen[yCount][xCount] = 'X';
                                                }

						Neighbors = 0;
               				}
                			xCount = 0;
        			}
        			yCount = 0;
				Gen++;

				for(int yCount = 0; yCount < y; yCount++)
                                {
                                        for(int xCount = 0; xCount < x; xCount++)
                                        {
                                                LifeGame[yCount][xCount] = NextGen[yCount][xCount];
                                        }
                                        xCount = 0;
                                }
                                yCount = 0;

				Cont = 0;
				//This checks if the grid is empty
				Final = 1;
				for(int yCount = 0; yCount < y; yCount++)
                                {
                                        for(int xCount = 0; xCount < x; xCount++)
                                        {
                                                if(LifeGame[yCount][xCount] == 'X')
						{
							Cont = 1;
							Final = 0;
						}
                                        }
                                        xCount = 0;
                                }
                                yCount = 0;

				//This checks if the grid is full
				if(Cont != 0)
				{
					Cont = 0;
					Final = 2;
                                	for(int yCount = 0; yCount < y; yCount++)
                                	{
                                        	for(int xCount = 0; xCount < x; xCount++)
                                        	{
                                                	if(LifeGame[yCount][xCount] == '-')
                                                	{
                                                        	Cont = 1;
								Final = 0;
                                                	}
                                        	}
                                        	xCount = 0;
                                	}
                                	yCount = 0;
				}

				if(Cont != 0)
				{
					if(Check != 0)
					{
						cout << "Do you want the process to automate itself from here?" << endl;
                                		cout << "Enter '0' if you want the process to automate itself" << endl;
						cout << "Enter '1' if you want to see this generation" << endl;
                                		cin >> Check;

						if(Check != 0)
                                        	{
							cout << "This is what your current grid will looks like:" << endl;
        						cout << " " << endl;
        						cout << " " << endl;
        						cout << "Generation " << Gen << endl;
        						cout << " " << endl;

        						for(int yCount = 0; yCount < y; yCount++)
        						{
                						for(int xCount = 0; xCount < x; xCount++)
                						{
                        						cout << LifeGame[yCount][xCount] << " ";
                						}
                						xCount = 0;
                						cout << endl;
        						}
        						yCount = 0;

							cout << "Enter '1' to display the next generation" << endl;
							cout << "Enter '0' before pressing the 'enter' button to stop" << endl;
                					cin >> Cont;
						}
					}
				}

				if(Final == 1)
				{
					cout << "It took " << Gen << " Generations for the cell population to die out" << endl;
				}

				if(Final == 2)
                                {
                                        cout << "It took " << Gen << " Generations for the cell population to fill the board" << endl;
                                }

				if(Gen == 1000)
                                {
                                        cout << "The cell population lasted for over 1,000 generations" << endl;
                                        Cont = 0;
                                }
			}
                }

		else
                {
			cout << "Please enter 1, 2, or 3" << endl;
                }
	}
}
