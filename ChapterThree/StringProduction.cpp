//
//  StringProduction.cpp

#include "stdafx.h"
#include "StringProduction.h"
#include "Dictionary.h"

#include <map>
#include <set>

using std::vector;
using std::string;
using std::map;
using std::set;

StringProduction::StringProduction(Dictionary &d)
	: m_dic(d)
{
}

StringProduction::StringProduction(const StringProduction &p)
	: m_dic(p.m_dic)
{
}

StringProduction::~StringProduction()
{
}

StringProduction &StringProduction::operator=(const StringProduction &p)
{
	if (&p != this) {
		m_dic = p.m_dic;
	}
	return *this;
}

//
// recovers the path from a list of previous nodes (P)
vector<int> StringProduction::recoverPath(int src, int dest, const vector<int> &P, vector<int> &path) {
	int v = dest;
	while (v != src) {
		path.push_back(v);
		v = P[v];
	}
	path.push_back(src);
	std::reverse(path.begin(), path.end());
	return path;
}

//
// computes the shortest path.
// node v is the source, dest is destination. If the path can be found, it is stored on parameter path
void StringProduction::shortest_path(int v, int dest, int n, vector<string> &path)
{
	const std::vector<std::vector<bool> > &A = m_dic.adjList(); // get the adjacency matrix
	path.clear();

	vector<int> dist(n, 0);
	vector<int> prev(n, 0);
	set<int> Q;              // set of nodes
	const int INF = INT_MAX; // a large number

							 // initialize the set of distances and the set of nodes
	for (int i = 0; i <n; i++) {
		Q.insert(i);
		if (i != v) {
			dist[i] = INF;
		}
	}

	// this is Dijkstra’s algorithm
	while (!Q.empty()) {

		int min = INF;
		int u = -1;
		for (set<int>::iterator it = Q.begin(); it != Q.end(); ++it) {
			// find the minimum value in queue
			if (dist[*it] < min) {
				min = dist[*it];
				u = *it;
			}
		}

		Q.erase(u);   // remove min vertex u from set

					  // relaxation step
		for (int i = 0; i<n; ++i) {

			if (A[u][i]) {              // this is a neighbor
				int d = dist[u] + 1;
				if (d < dist[i]) {
					dist[i] = d;
					prev[i] = u;
				}
			}
		}
	}

	// recover the path from vector prev
	vector<int> npath;
	recoverPath(v, dest, prev, npath);
	for (unsigned i = 0; i<npath.size(); ++i) {
		path.push_back(m_dic.elemAtPos(npath[i]));
	}

}

//
// returns true if the word src produces dest using the dictionary dic
// If true, then path will contain the path between src and dest
//
bool StringProduction::produces(const string &src, const string &dest, vector<string> &path) {

	if (!m_dic.contains(src) || !m_dic.contains(dest)) return false;

	shortest_path(m_dic.elemPosition(src), m_dic.elemPosition(dest), m_dic.size(), path);

	return path.size() > 0;
}