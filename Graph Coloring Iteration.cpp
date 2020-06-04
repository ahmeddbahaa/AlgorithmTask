// Graph_Algorithm_2nd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Author
Ahmed Bahaa
*/

#include <iostream>
#include <vector>

using namespace std;
vector<int> breadthFirstAlgorithm(vector<vector<int>> graph, int sizeVertecies);
bool isColor(int vertex, vector<int>colour, int size, vector< vector<int>>graph, int color);
int main()
{
	int row = 0, coloum = 0, colorSize;
	cout << "Enter Number Of Rows : ";
	cin >> row;

	cout << "Enter Number Of Coloums : ";
	cin >> coloum;
	
	cout << "Enter The Adjacency matrix" << endl;

	//represent the graph like 2D array but with more functionalties

	vector < vector < int > > graph(row, vector <int>(coloum, 0));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < coloum; j++)
		{
			cin >> graph[i][j];
		}
	}
	cout << "Enter Number of Colors : ";
	cin >> colorSize;
	vector<int>colors(row);

	colors = breadthFirstAlgorithm(graph, row);

	for (int i = 0; i < colors.size(); i++)
		if (colors[i] > colorSize)
		{
			cout << "The Number you enterted to Color the Graph is invald" << endl
				<< "the minimum Number of colors to color this graph is " << colors.size()<<endl
				<< "It's Shown as below how to color the given graph with minimum number of colors" << endl<<endl;
			break;
		}

for (int i = 0; i < colors.size(); i++)
	{
	
	cout << "vertex "<<i << " is Colored By color  "<<colors[i]<<endl;
	}


}//end main


vector<int> breadthFirstAlgorithm(vector<vector<int>> graph , int sizeVertecies)
{
	vector<int>colors(sizeVertecies, 0);

		//loop of vertex
		for (int i = 0; i < sizeVertecies; i++)
		{
			
			for (int c = 1; c <= sizeVertecies; c++)
			{
			//	cout << "Bool" << isColor(i, colors, colors.size(), graph, c) << "in vertex " << i << "color: " << c << endl;

				if ( isColor(i, colors, colors.size(), graph, c))
				{
					colors[i] = c;
					//cout << "vertex "<<i << " colored " << c<<endl;
					break;
				}
			}
	
		}
					
	return colors;
}


bool isColor(int vertex, vector<int>colour, int size, vector< vector<int>>graph, int color)
{
	for (int i = 0; i < size; i++)
	{
		if ((graph[vertex][i] == 1 && color == colour[i]))
		{

			return false;
		}
	}
	return true;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
