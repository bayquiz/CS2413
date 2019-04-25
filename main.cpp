#include "dijk.h"

int main()
{
	// Let us create the example 
	// graph discussed above 
	int graph[V][V] = { {0, 8, 22, 0},
					    {8, 0, 7, 15},
						{22, 7, 0, 18},
						{0, 15, 18, 0},

	};

	dijkstra(graph, 0);
	return 0;
}