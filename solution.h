#ifndef SOLUTION_H
#define SOLUTION_H

#include <cstdio>
#include <list>
#include <vector>
#include "customer.h"
#include "route.h"
#include "problem.h"

class solution{
public:
	void print(FILE *fp) const;
	void clear();
	void random(int maxRoutes, const problem& input);
	void random(const problem& input);
	void solomon(const problem& input, bool farthest, double mu = 1, double lambda = 2, double alpha1 = 0);
	void fitness(const problem& input);
	static int cmp(const solution &solA, const solution &solB, const problem &input);
	static bool fdominate(const solution &solA, const solution &solB);
	static bool idominate(const solution &solA, const solution &solB);
	bool operator == (const solution &another) const;
	bool operator < (const solution &another) const;

	std::list<route> routes;
	double totalDistance, totalTimewarp, totalWaiting;
	int unbalancedCapacity, exceededCapacity;
	bool feasible;
};

#endif