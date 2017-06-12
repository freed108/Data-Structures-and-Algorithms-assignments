#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
	ifstream inFile("DNAString.txt");
	//ifstream outFile("JasonFreedman.out");

	if(inFile.fail())
	{
		cerr << "Error Opening File" << endl;
		exit(1);
	}

	string line;
	
	double A_count = 0.0;
	double AA_count = 0.0;
	double AT_count = 0.0;
	double AC_count = 0.0;
	double AG_count = 0.0;
	
	double T_count = 0.0;
	double TA_count = 0.0;
	double TT_count = 0.0;
	double TC_count = 0.0;
	double TG_count = 0.0;
	
	double C_count = 0.0;
	double CA_count = 0.0;
        double CT_count = 0.0;
	double CC_count = 0.0;
        double CG_count = 0.0;
	
	double G_count = 0.0;
	double GA_count = 0.0;
        double GT_count = 0.0;
        double GC_count = 0.0;
	double GG_count = 0.0;

	double StringTotal = 0.0;
	double BigramTotal = 0.0;
	double total = 0.0;

	//L1 stands for Length 1, used to store how many strings are 1 character long
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double L5 = 0.0;
	double L6 = 0.0;
	double L7 = 0.0;
	double L8 = 0.0;
	double L9 = 0.0;
	double L10 = 0.0;

	while(!inFile.eof())
	{
		getline(inFile, line);

		StringTotal++;

		if(line.length() == 1)
		{
			L1++;
		}

		if(line.length() == 2)
                {
                        L2++;
                }

		if(line.length() == 3)
                {
                        L3++;
                }

		if(line.length() == 4)
                {
                        L4++;
                }

		if(line.length() == 5)
                {
                        L5++;
                }

		if(line.length() == 6)
                {
                        L6++;
                }

		if(line.length() == 7)
                {
                        L7++;
                }

		if(line.length() == 8)
                {
                        L8++;
                }

		if(line.length() == 9)
                {
                        L9++;
                }

		if(line.length() == 10)
                {
                        L10++;
                }
        
        	for(int i = 0; i < line.length(); i++)
        	{
			if(line[i] == *"A")
            		{
                		A_count++;
                		total++;

				if(line[i + 1] == *"A")
                                {
                                        AA_count++;
                                        BigramTotal++;
                                }

				if(line[i + 1] == *"T")
				{
					AT_count++;
                                	BigramTotal++;
				}

				if(line[i + 1] == *"C")
                                {
                                        AC_count++;
                                        BigramTotal++;
                                }

				if(line[i + 1] == *"G")
                                {
                                        AG_count++;
                                        BigramTotal++;
                                }
            		}
            
            		if(line[i] == *"T")
            		{
                		T_count++;
                		total++;

				if(line[i + 1] == *"A")
                                {
                                        TA_count++;
                                        BigramTotal++;
                                }

				if(line[i + 1] == *"T")
                                {
                                        TT_count++;
                                        BigramTotal++;
                                }

                                if(line[i + 1] == *"C")
                                {
                                        TC_count++;
                                        BigramTotal++;
                                }

                                if(line[i + 1] == *"G")
                                {
                                        TG_count++;
                                        BigramTotal++;
                                }
            		}
            
            		if(line[i] == *"C")
            		{
                		C_count++;
                		total++;

				if(line[i + 1] == *"A")
                                {
                                        CA_count++;
                                        BigramTotal++;
                                }

                                if(line[i + 1] == *"T")
                                {
                                        CT_count++;
                                        BigramTotal++;
                                }

				if(line[i + 1] == *"C")
                                {
                                        CC_count++;
                                        BigramTotal++;
                                }

                                if(line[i + 1] == *"G")
                                {
                                        CG_count++;
                                        BigramTotal++;
                                }
            		}
            
            		if(line[i] == *"G")
            		{
                		G_count++;
                		total++;

				if(line[i + 1] == *"A")
                                {
                                        GA_count++;
                                        BigramTotal++;
                                }

                                if(line[i + 1] == *"T")
                                {
                                        GT_count++;
                                        BigramTotal++;
                                }

                                if(line[i + 1] == *"C")
                                {
                                        GC_count++;
                                        BigramTotal++;
                                }

				if(line[i + 1] == *"G")
                                {
                                        GG_count++;
                                        BigramTotal++;
                                }
            		}
        	}
	}

	inFile.close();

	int mean = ((1 * L1) + (2 * L2) + (3 * L3) + (4 * L4) + (5 * L5) + (6 * L6) + (7 * L7) + (8 * L8) + (9 * L9) + (10 * L10)) / StringTotal;
	double variance = (((mean - 1) * (mean - 1) * L1) + ((mean - 2) * (mean - 2) * L2) + ((mean - 3) * (mean - 3) * L3) + ((mean - 4) * (mean - 4) * L4) + ((mean - 5) * (mean - 5) * L5) + ((mean - 6) * (mean - 6) * L6) + ((mean - 7) * (mean - 7) * L7) + ((mean - 8) * (mean - 8) * L8) + ((mean - 9) * (mean - 9) * L9) + ((mean - 10) * (mean - 10) * L10)) / StringTotal;
	double StandardDeviation = sqrt(variance);

	double A_percent = (A_count / total) * 100;
	double AA_percent = (AA_count / BigramTotal) * 100;
	double AT_percent = (AT_count / BigramTotal) * 100;
	double AC_percent = (AC_count / BigramTotal) * 100;
	double AG_percent = (AG_count / BigramTotal) * 100;

	double T_percent = (T_count / total) * 100;
	double TA_percent = (TA_count / BigramTotal) * 100;
	double TT_percent = (TT_count / BigramTotal) * 100;
        double TC_percent = (TC_count / BigramTotal) * 100;
        double TG_percent = (TG_count / BigramTotal) * 100;

	double C_percent = (C_count / total) * 100;
	double CA_percent = (CA_count / BigramTotal) * 100;
        double CT_percent = (CT_count / BigramTotal) * 100;
	double CC_percent = (CC_count / BigramTotal) * 100;
        double CG_percent = (CG_count / BigramTotal) * 100;

	double G_percent = (G_count / total) * 100;
	double GA_percent = (GA_count / BigramTotal) * 100;
        double GT_percent = (GT_count / BigramTotal) * 100;
        double GC_percent = (GC_count / BigramTotal) * 100;
	double GG_percent = (GG_count / BigramTotal) * 100;

	cout << "" << endl;
        cout << "" << endl;
	cout << "Jason Freedman	  I.D. # 001773840	Assignment1" << endl;
	cout << "" << endl;

	cout << A_count << " A's found" << endl;
	cout << A_percent << "% of the nucleotides are A" << endl;
	cout << AA_percent << "% of the bigrams are AA" << endl;
	cout << AT_percent << "% of the bigrams are AT" << endl;
	cout << AC_percent << "% of the bigrams are AC" << endl;
	cout << AG_percent << "% of the bigrams are AG" << endl;
	cout << "" << endl;

	cout << T_count << " T's found" << endl;
	cout << T_percent << "% of the nucleotides are T" << endl;
	cout << TA_percent << "% of the bigrams are TA" << endl;
	cout << TT_percent << "% of the bigrams are TT" << endl;
        cout << TC_percent << "% of the bigrams are TC" << endl;
        cout << TG_percent << "% of the bigrams are TG" << endl;
	cout << "" << endl;

	cout << C_count << " C's found" << endl;
	cout << C_percent << "% of the nucleotides are C" << endl;
	cout << CA_percent << "% of the bigrams are CA" << endl;
        cout << CT_percent << "% of the bigrams are CT" << endl;
	cout << CC_percent << "% of the bigrams are CC" << endl;
        cout << CG_percent << "% of the bigrams are CG" << endl;
	cout << "" << endl;

	cout << G_count << " G's found" << endl;
	cout << G_percent << "% of the nucleotides are G" << endl;
	cout << GA_percent << "% of the bigrams are GA" << endl;
        cout << GT_percent << "% of the bigrams are GT" << endl;
        cout << GC_percent << "% of the bigrams are GC" << endl;
	cout << GG_percent << "% of the bigrams are GG" << endl;
	cout << "" << endl;

	cout << "The mean is " << mean << endl;
	cout << "" << endl;

	cout << "The variance is " << variance << endl;
        cout << "" << endl;

	cout << "The standard deviation is " << StandardDeviation << endl;
        cout << "" << endl;
	cout << "" << endl;

	int DNAlines = 1000;
	int NextChar = 0;
	int TotalChar = 0;

	while(DNAlines > 0)
	{
		while(TotalChar < (mean - 1))
		{
			NextChar = 1 + (rand()%100);

			if(NextChar < A_percent)
			{
				cout << "A";
			}

			if(NextChar >= A_percent && NextChar < (A_percent + T_percent))
                        {
                                cout << "T";
                        }

			if(NextChar >= (A_percent + T_percent) && NextChar < (A_percent + T_percent + C_percent))
                        {
                                cout << "C";
                        }

			if(NextChar >= (A_percent + T_percent + C_percent))
                        {
                                cout << "G";
                        }

			TotalChar++;
		}

		if(NextChar < A_percent)
                {
                	cout << "A" << endl;
                }

                if(NextChar >= A_percent && NextChar < (A_percent + T_percent))
                {
                        cout << "T" << endl;
                }

                if(NextChar >= (A_percent + T_percent) && NextChar < (A_percent + T_percent + C_percent))
                {
                        cout << "C" << endl;
                }

                if(NextChar >= (A_percent + T_percent + C_percent))
                {
                        cout << "G" << endl;
                }

		TotalChar = 0;
		NextChar = 0;

		DNAlines = DNAlines - 1;
	}

	cout << "" << endl;
	cout << "" << endl;

	//outFile.close();

	return 0;
}
