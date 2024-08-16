#pragma once
#include <vector>;
#include <iostream>;
using std::vector; using std::cout;
class Node
{
public:
	vector<int> *input;
	int number_to_reach;
	int history_sum;
	vector<int> *history;
	
	Node(vector<int> *i, int sum_to, vector<int> *h, int history_s,int option=0);
	~Node();
	int check(int index);
	void add_to_history(int num);
	bool check_for_answer(int number_to_reach_global);
	void copy_history(vector<int> h, int sum,int option);
	void clear();
	void print_solution();
};

