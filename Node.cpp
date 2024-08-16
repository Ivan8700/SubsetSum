#include "Node.h"
Node::Node(vector<int> *input_arr,int sum_to ,vector<int>* h, int history_s,int option) {
	
	this->number_to_reach = sum_to;
	if (option == 0) {
		this->input = input_arr;
		this->history = h;
	}
	else
	{
		this->history = new vector<int>;
		this->input = new vector<int>;
		for (int i = 0; i < h->size(); i++)
		{
			this->history->push_back(h->at(i));
		}
		for (int i = 0; i < input_arr->size(); i++)
		{
			this->input->push_back(input_arr->at(i));
		}
	}
	this->history_sum = history_s;
}
Node::~Node()
{
	delete this->history;
	delete this->input;
}
int Node::check(int index){
	if (this->input->at(index) > this->number_to_reach)
		return 0;
	return 1;
}
void Node::add_to_history(int num) {
	this->history->push_back(num);
}

bool Node::check_for_answer(int number_to_reach_global) {
	if ((this->number_to_reach==0) && (this->history_sum == number_to_reach_global))
		return true;
	return false;
}
void Node::copy_history(vector<int> h,int sum,int option)
{
	/*vector<int>* t = new vector<int>;
	for (int i = 0; i < h->size(); i++)
		t->push_back(h->at(i));*/
	for (int i = 0; i < h.size(); i++)
		this->history->push_back(h.at(i));
	this->history_sum = sum;
}
void Node::clear()
{
	vector<int>::iterator it;
	for (int i = 0; i < this->input->size(); i++)
	{
		if (this->input->at(i) > this->number_to_reach) //filter numbers that can't be picked
		{
			it = this->input->begin() + i;
			this->input->erase(it);
			i--;
		}
	}
}
void Node::print_solution() {
	
	if (this->history->size() != 0) {
		cout << std::endl <<  "The solution is the set {";
		for (int i = 0; i < this->history->size() - 1; i++)
			cout << this->history->at(i) << " , ";
		cout << this->history->at(this->history->size() - 1) << "}" << std::endl;
		cout << "Sum of the solution is " << this->history_sum << std::endl;
	}
	else
		cout << "No solution found";
}