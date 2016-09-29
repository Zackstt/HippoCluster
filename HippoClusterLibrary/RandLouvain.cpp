#include "stdafx.h"
#include "RandLouvain.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <ppl.h>

using namespace std;

namespace HippoClusterLibrary
{

	RandLouvain::RandLouvain(AdjacencyList* AdjList)
	{
		adjList = AdjList;
		clusterOfNodes cluster;
		cluster.nodes = AdjList;
	}

	// cluster is a vector of nodes
	float RandLouvain::getModularity(int nodeI, clusterOfNodes cluster)
	{
		// vector<tuple<int, double, double>> neighbors = adjList->allNeighbors(v);
		double weightOfNetwork = adjList->sumWeights();

		float weightIntoCluster = 0, weightIntoNode = 0, weightiToCluster = 0;

		// go through all nodes in the cluster
		for (int i = 0; i != cluster.subCluster.size(); i++)
		{
			// get all neighbors of node i
			vector<tuple<int, double, double>> neighbors = adjList.allNeighbors(i);
			// go through all neighbors of node i and check if they are in cluster. If not add wieght to weightIntoCluster
			for (int j = 0; j != neighbors.size(); j++)
			{
				if (find(cluster.begin(), cluster.end(), neighbors[j]) == v.end())
				{
					weightIntoCluster += get<1>(neighbors);
				}
			}
		}

		for (int i = 0; i != cluster.size(); i++)
		{
			// get all neighbors of node i
			vector<tuple<int, double, double>> neighbors = adjList.allNeighbors(i);
			// go through all neighbors of node i and check if they are in cluster. If they are add wieght to weightIntoCluster
			for (int j = 0; j != neighbors.size(); j++)
			{
				if (find(cluster.begin(), cluster.end(), neighbors[j]) != v.end())
				{
					weightiToCluster += get<1>(neighbors);
				}
			}
		}

		vector<tuple<int, double, double>> neighbors = adjList.allNeighbors(i);
		for (int i=0; i != ) 



	}

}
std::vector<int>::iterator it;
// it = std::search(haystack.begin(), haystack.end(), needle1, needle1 + 4);