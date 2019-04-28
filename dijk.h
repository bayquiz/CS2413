#pragma once 
#include <stdio.h> 
#include <limits.h> 

// Number of vertices 
#define V 4 

// A utility function to find the 
// vertex with minimum distance 
// value, from the set of vertices 
// not yet included in shortest 4
// path tree 
int minDistance(int dist[],
	bool sptSet[])
{

	// Initialize min value 
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)			//For all the vertices A->D
		if (sptSet[v] == false &&		//if distance < min
			dist[v] <= min)
			min = dist[v], min_index = v;		//set min to that distance, and index to that vertice

	return min_index;
}

// Function to print shortest 
// path from source to j 
// using parent array 
void printPath(int parent[], int j)
{

	// Base Case : If j is source 
	if (parent[j] == -1)
		return;

	printPath(parent, parent[j]);

	printf("%c ", j+97);		//only added 97 to convert to correct ascii (A, B, C, D)
}

// A utility function to print 
// the constructed distance 
// array 
void printSolution(int dist[], int n, int parent[])
{
	int src = 'a';											//where we will start
	printf("Vertex\t\t Distance\tPath");					//print header
	printf("\n%c \t\t %d\t\t%c", src, dist[0], src);		//print for source

	for (int i = 'b', j = 1; i < 'd', j < 4; i++, j++)		//starting at b, and dist[1]
	{
		printf("\n%c -> %c \t\t %d\t\t%c ", src, i, dist[j], src);		//print A->B  dist    Apath
		printPath(parent, j);		//changed to j... now print path using parent and j (1-4)			
	}
}


// using adjacency matrix representation and src which is A
void dijkstra(int graph[V][V], int src)
{
 
	// will hold the shortest 
	// distance from src (A) to i 
	int dist[V];

	// sptSet[i] will be true if vertex 
	// i is included OR in shortest 
	// path tree OR shortest distance 
	// from src(A) to i is finalized 
	bool sptSet[V];

	// Parent array to store 
	// shortest path tree 
	int parent[V];

	// Initialize all distances as 
	// INFINITE and stpSet[] as false 
	for (int i = 0; i < V; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// Distance of source vertex 
	// from itself is always 0 
	dist[src] = 0;

	// Find shortest path 
	// for all vertices 
	for (int count = 0; count < V - 1; count++)		//from 0-3
	{
		// Pick the minimum distance 
		// vertex from the set of 
		// vertices not yet processed. 
		// u is always equal to src 
		// in first iteration. 
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex 
		// as processed 
		sptSet[u] = true;

		// Update dist value of the 
		// adjacent vertices of the 
		// picked vertex. 
		for (int v = 0; v < V; v++)

			// Update dist[v] only if its 
			// not in sptSet, there is 
			// an edge from u to v, and 
			// total weight of path from 
			// src to v through u is smaller 
			// than current value of 
			// dist[v] 
			if (!sptSet[v] && graph[u][v] &&					//if the weight of path is < distance
				dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;									//change edge set
				dist[v] = dist[u] + graph[u][v];
			}
	}

	// print the constructed 
	// distance array 
	printSolution(dist, V, parent);
}
