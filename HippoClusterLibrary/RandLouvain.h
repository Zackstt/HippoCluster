#pragma once

#ifdef HIPPOCLUSTERLIBRARY_EXPORTS
#define HIPPOCLUSTERLIBRARY_API __declspec(dllexport) 
#else
#define HIPPOCLUSTERLIBRARY_API __declspec(dllimport) 
#endif

#include <vector>
#include "AdjacencyList.h"

namespace HippoClusterLibrary
{
	class RandLouvain
	{
	private:

		// the struct should either all the nodes in the cluster or all the nodes in the cluster and the subClusters
		struct clusterOfNodes {
			AdjacencyList* nodes;
			vector<clusterOfNodes> subCluster;
		};
		// std::vector<int> clusterAssignments;
		AdjacencyList* adjList;
		clusterOfNodes cluster;

		
		// subgraph is a subgraph of adjList which is excluding nodeI. NodeI is a singular node of adjList
		AdjacencyList* cluster, nodeI;
		int numVertices;

	public:

		HIPPOCLUSTERLIBRARY_API RandLouvain(AdjacencyList* adjList);

		/*
		may need to change some of these functions also
		*/

		// constructs a new cluster *** I need to make sure the new cluster contains both a vector of subClusters and all the nodes in the cluster
		HIPPOCLUSTERLIBRARY_API void cluster();

		// getModularity returns a number between -1 and 1 indicating the quality of a clustered graph
		HIPPOCLUSTERLIBRARY_API float getModularity(int nodeI, clusterOfNodes cluster);

		HIPPOCLUSTERLIBRARY_API ~RandLouvain();
	};
}
