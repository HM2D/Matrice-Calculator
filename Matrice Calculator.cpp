//Compiled by Visual Studio 2013
//Hooman Malekzadeh 9231615

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <conio.h>
#include <exception>


using namespace std;
void setmatrix();
class matrix
{

	int matrice[10][10];
	double resault[10][10];
	int a;
	int b;

public:
	matrix(int i, int j)
	{
		matrice[i][j];
		a = i;
		b = j;
		for (int x = 0; x<i; x++)
		for (int y = 0; y<j; y++)
			resault[x][y] = 0;
	}
	void setrc(int a,int b)
	{
		this->a = a;
		this->b = b;
	}
	matrix()
	{

	}
	friend void addmatrix();
	void transpose()
	{
		int temp;
		if (a == b)
		{
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < i; j++)
				{
					temp = matrice[i][j];
					matrice[i][j] = matrice[j][i];
					matrice[j][i] = temp;
				}
			}
		}
		else throw exception("Not a square Matrix");
	}

	
	int* operator[] (int index)
	{
		int a[100];
		for (int i = 0; i<b; i++)
			a[i] = matrice[index][i];
		return a;
    }
  
	void putnum(int n, int i, int j)
	{
		matrice[i][j] = n;
	}
	friend ostream& operator << (ostream& str, matrix& l)
	{
		for (int i = 0; i < l.a; i++)
		{
			for (int j = 0; j < l.b; j++)
			{
				str << l.matrice[i][j]<< "\t";
			}
			str << endl;
			str << endl;
		}
		return str;
	
	}
	friend istream& operator >>(istream& str, matrix& l)
	{
		



		for (int i = 0; i < l.a; i++)
		{
			for (int j = 0; j < l.b; j++)
			{
				cout << "insert your number in row " << i << " and in column " << j << ":";
				str >> l.matrice[i][j];
			}
		}
		return str;
	}
	void operator ++()
	{
		for (int i = 0; i<a; i++)
		{
			for (int j = 0; j<b; j++)
			{
				matrice[i][j] = matrice[i][j] + 1;
			}
		}
	}
	void operator --()
	{
		for (int i = 0; i<a; i++)
		{
			for (int j = 0; j<b; j++)
			{
				matrice[i][j] = matrice[i][j] - 1;
			}
		}
	}
	void operator +(matrix& l)
	{
		add(l);
	}
	void operator -(matrix& l
		)
	{
		sub(l);
	}
	void operator ^ (matrix& l)
	{
		multi(l);
	}
	void operator * (matrix& l)
	{
		multionetoone(l);
	}
	void multionetoone(matrix& l)
	{
		if ((a == l.a) && (b == l.b))
		{
			for (int i = 0; i<a; i++)
			{
				for (int j = 0; j<b; j++)
				{
					resault[i][j] = matrice[i][j] * l.matrice[i][j];
				}
			}
		}
		else throw exception("not in the same scale");

	}
	void multi(matrix& l)
	{
		if ((a == l.a) && (b == l.b))
		{
			for (int i = 0; i<a; i++)
			for (int j = 0; j<b; j++)
			{
				resault[i][j] = 0;
				for (int k = 0; k<b; k++)
					resault[i][j] += matrice[i][k] * l.matrice[k][j];
			}
		}
		else throw exception("Not In The Same Scale");

	}
	void add(matrix& l)
	{
		if ((a == l.a) && (b == l.b))
		{
			for (int i = 0; i<a; i++)
			{
				for (int j = 0; j<b; j++)
				{
					resault[i][j] = matrice[i][j] + l.matrice[i][j];
				}
			}
		}
		else throw exception("Not in the same scale");

	}
	void sub(matrix& l)
	{
		if ((a == l.a) && (b == l.b))
		{
			for (int i = 0; i<a; i++)
			{
				for (int j = 0; j<b; j++)
				{
					resault[i][j] = matrice[i][j] - l.matrice[i][j];
				}
			}
		}
		else throw exception("Not in the same scale");
	}
	/*operator double()
	{
		cout << determinant() << endl;
	}*/

	void operator !()
	{
		double h = 1 / determinant();
		cout << h << endl;
		transpose();
		for (int x = 0; x<a; x++)
		for (int y = 0; y<b; y++)
			resault[x][y] = h*matrice[x][y];
	}
	double determinant()
	{
		double det;
		if (a == b)
		{
			if (a == 2)
			{
				det = (matrice[0][0] * matrice[1][1]) - (matrice[1][0] * matrice[0][1]);
			}
			if (a == 3)
			{
				det = matrice[0][0] * ((matrice[1][1] * matrice[2][2]) - (matrice[2][1] * matrice[1][2])) - matrice[0][1] * (matrice[1][0] * matrice[2][2] - matrice[2][0] * matrice[1][2]) + matrice[0][2] * (matrice[1][0] * matrice[2][1] - matrice[2][0] * matrice[1][1]);
			}
			return det;

		}
		else throw exception("Not a Square Matrix");
	}

	void printres()
	{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
				cout << resault[i][j]<< "\t";
			cout << endl;
			cout << endl;
		}
	}
};

matrix h[100];
int index = 0;

void setmatrix()
{
	cout << "Matrix number " << index << endl;
	int row, column;
	cout << "Enter number of rows: ";
	cin >> row;
	cout << "Enter Number of columns: ";
	cin >> column;
	h[index].setrc(row, column);
	cin >> h[index];
	index++;
}



int main()

{
	int x,y; 
	while (1)
	{
		cout << "Enter you choice" << endl << endl;
		cout << "1.Add a matrix" << endl << endl;
		cout << "2.Add two matrixes" << endl << endl;
		cout << "3.Sub two matrixes" << endl << endl;
		cout << "4.Multiply two matrixes" << endl << endl;
		cout << "5.Determinant of matrix" << endl << endl;
		cout << "6.transpose" << endl << endl;
		cout << "7.Print your Desired matrix" << endl << endl;
		cout << "8.Print all Saved Matrixes" << endl << endl;
		cout << "9.Exit" << endl << endl;
		cout << endl << endl << endl << "copy right by Hooman Malekzadeh" << endl;
		x=_getch();
		if (x == '1')
		{
			setmatrix();
			cout << endl << endl;
		}
		if (x == '2')
		{
			if (index == 0)
			{
				cout << "You don't Have any saved Matrix";
			}
			if (index == 1)
			{
				cout << "You only have one save matrix" << endl;
			}
			else{
				int m1, m2;
				cout << "Which matrixes do you want to add together? ";
				cin >> m1 >> m2;
				try{
					h[m1] + h[m2];

					cout << h[m1] << endl << "+" << endl << h[m2] << endl;
					cout << "__________________" << endl;
					h[m1].printres();
					cout << endl << endl;
				}
				catch (exception e)
				{
					cout << e.what() << endl;
				}
			}
		}
		if (x == '3')
		{
			if (index == 0)
			{
				cout << "You don't Have any saved Matrix";
			}
			if (index ==1)
			{
				cout << "You only have one save matrix"<<endl;
			}
			else{
				int m1, m2;
				cout << "Which matrixes do you want to sub? ";
				cin >> m1 >> m2;
				try{
					h[m1] - h[m2];
					cout << h[m1] << endl << "-" << endl << h[m2] << endl;
					cout << "__________________" << endl;
					h[m1].printres();
					cout << endl << endl;
				}
				catch (exception e)
				{
					cout << e.what() << endl;
				}
			}
		}
		if (x == '4')
		{
			if (index == 0)
			{
				cout << "You don't Have any saved Matrix";
			}
			if (index < 2)
			{
				cout << "You only have one save matrix"<<endl;
			}
			else {
				int m1, m2;
				cout << "Which matrixes do you want to multiply together? ";
				cin >> m1 >> m2;
				try{
					h[m1] ^ h[m2];
					cout << h[m1] << endl << "*" << endl << h[m2] << endl;
					cout << "________________" << endl;
					h[m1].printres();
					cout << endl << endl;
				}
				catch (exception e)
				{
					cout << e.what() << endl;
				}
			}
		}
		if (x == '5')
		{
			if (index == 0)
			{
				cout << "You don't have any saved matrix"<<endl;
			}
			else {
				int m;
				cout << "Which matrixe do you Calculate The Determinant? ";
				cin >> m;
				try
				{
					cout << h[m].determinant() << endl;
				}
				catch (exception e)
				{
					cout << e.what() << endl;
				}
			}
		}
		if (x == '6')
		{
			if (index == 0)
			{
				cout << "You don't have any saved matrix"<< endl;
			}
			else {
				int m;
				cout << "Which Matrix do you want to Transpose? ";
				cin >> m;
				try
				{
					h[m].transpose();
					h[m].printres();
				}
				catch (exception e)
				{
					cout << e.what() << endl;
				}
			}
		}
		if (x == '7')
		{
			if (index == 0)
			{
				cout << "You don't have any saved matrix to print"<<endl;
			}
			else{
				int f;
				cout << "Which matrix do you want to print? ";
				cin >> f;
				cout << "Matrix number " << f << endl;
				cout << h[f] << endl << endl;
			}
		}
		if (x == '8')
		{
			if (index == 0)
			{
				cout << "There is no Matrix to print" << endl;
			}
			else{
				for (int i = 0; i < index; i++)
				{
					cout << "Matrix Number " << i << endl;
					cout << h[i] << endl;
				}
			}
		}
		if (x == '9')
		{
			break;
		}

		cout << "Insert 1 to quit" << endl << "Insert any other key to continue" << endl;
		y =_getch();
		if (y == '1')
		{
			break;
		}
		system("cls");
	}

}

