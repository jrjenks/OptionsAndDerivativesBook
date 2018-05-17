#pragma once
//
//  StringProduction.h

#include <vector>

class Dictionary;

class StringProduction {
public:
	StringProduction(Dictionary &d);
	StringProduction(const StringProduction &p);
	~StringProduction();
	StringProduction &operator=(const StringProduction &p);

	bool produces(const std::string &src, const std::string &dest, std::vector<std::string> &path);
	void shortest_path(int v, int dest, int n, std::vector<std::string> &path);
	std::vector<int> recoverPath(int src, int dest, const std::vector<int> &P, std::vector<int> &path);
private:
	Dictionary & m_dic;
};

