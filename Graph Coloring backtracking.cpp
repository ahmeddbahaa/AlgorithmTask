// Graph_Coloring_1st.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Auther
Ahmed Bahaa
BACK TRACKING ALGORITHM FOR GRAPH COLORING PROBLEM
*/

#include <iostream>
#include <vector>
using namespace std;
//checks whether given vertics have Adjecent Vertix that has the same colour
bool isColor(int vertex, vector<int>colour, int size, vector< vector<int> >graph, int);
vector<int> vertexColoring(int vertex, int colorSize, vector<int> colours, int vertexSize, vector< vector<int> >graph);

bool validate(vector<int>);
//Print Graph
void print(vector<vector<int> >, int, int);

int main()
{
	// row represent row in matrix , coloum represent coloum in matrix
	//colorSize represent maximum color that can be used to color the given graph
	int row = 0, coloum = 0, colorSize;
	cout << "Enter Number Of Rows : ";
	cin >> row;
	cout << "Enter Number Of Coloums : ";
	cin >> coloum;

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

	vector<int>colors(row, 0);

	colors = vertexColoring(0, colorSize, colors, row, graph);
	if (validate(colors))
	{
		for (int i = 0; i < colors.size(); i++)
		{
			cout << "Vertex " << i + 1 << "  Colored By " << colors[i] << endl;

		}

	}
	else
	{
		cout << "Cannot Color this Graph with the Given Number of Colors" << endl;
	}


}
bool validate(vector<int> colors)
{
	bool flag = true;
	for (int i = 0; i < colors.size(); i++)
	{
		if (colors[i] == 0)
		{
			flag = false;
		}

	}
	if (flag)
		return true;

	return false;
}
vector<int> vertexColoring(int vertex, int colorSize, vector<int>, int vertexSize, vector< vector<int> >graph)
{
	static vector<int>colours(vertexSize);
	for (int colour = 1; colour <= colorSize; colour++)
	{
		if (isColor(vertex, colours, vertexSize, graph, colour))
		{

			colours[vertex] = colour;
			//	cout << "vertex " << vertex << " Colour" << colour << endl;
			if ((vertex + 1 < vertexSize))
			{
				//	cout << "Rec" << vertex + 1 << " ";
				vertexColoring(vertex + 1, colorSize, colours, vertexSize, graph);
			}

		}
	}


	return colours;

}

bool isColor(int vertex, vector<int>colour, int size, vector< vector<int> >graph, int color)
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


void print(vector < vector < int > > graph, int row, int coloum)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < coloum; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

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
