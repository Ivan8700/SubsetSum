#include "RunAlgorithm.h"
RunAlgorithm::RunAlgorithm(int option) {
	int number_input = 0;
	this->input = new vector<int>;
	
	//<--------------------------- Get input ------------------------------>
	if (option == 0) // 0 - manual insertion, 1 - random generator
	{
		cout << "Enter your input - one number after the other, insert -1 to stop." << endl;
		cin >> number_input;
		while (number_input != -1)
		{
			this->input->push_back(number_input);
			cin >> number_input;
		}
	}
	else
	{
		if (option == 1)
		{
			srand(time(NULL));
			int q, range_max_number;
			do {
				cout << "Enter how many numbers you would like to generate (integer > 0)" << endl;
				cin >> q;
			} while (q < 0);
			do {
				cout << "Enter the range of numbers [1,number you insert], the number must be >0" << endl;
				cin >> range_max_number;
			} while (range_max_number < 0);
			cout << "The numbers that are being generated is : " << endl;
			for (int i = 0; i < q; i++) {
				this->input->push_back((std::rand() % range_max_number)+1);
				cout << "number at " << i + 1 << " index is " << this->input->back() << endl;
			}

		}
	}
	cout << std::endl << "Enter number to sum to" << endl;
	cin >> this->number_to_reach;
	//<---------------------- Start algo -------------------------->
	int index = 0, placeholder = 0;
	Node* n = new Node(this->input, this->number_to_reach, new vector<int>, 0, 0);
	vector<Node*>* computation = new vector<Node*>;
	computation->push_back(n);
	while (computation->size() != 0)
	{
		if (!computation->back()->check_for_answer(number_to_reach))
		{
			if (computation->back()->input->size() == 0) //not a solution and no elements to pick from the array
			{
				delete computation->back();
				computation->pop_back();
			}
			else
			{
				computation->back()->clear();
				placeholder = computation->back()->input->at(index);
				vector<int>::iterator it = computation->back()->input->begin() + index;
				computation->back()->input->erase(it);
				Node* k = new Node(computation->back()->input, computation->back()->number_to_reach - placeholder, computation->back()->history, computation->back()->history_sum, 1);
				Node* t = new Node(computation->back()->input, computation->back()->number_to_reach, computation->back()->history, computation->back()->history_sum, 1);

				k->add_to_history(placeholder);
				k->history_sum += placeholder;
				delete computation->back();
				computation->pop_back();
				computation->push_back(t);
				computation->push_back(k);
			}
		}
		else
		{
			computation->back()->print_solution();
			break;
		}
	}

	while (computation->size() != 0)
	{
		delete computation->back();
		computation->pop_back();
	}
	computation->clear();
	delete computation;
}
void RunAlgorithm::print() {
	for (int i = 0; i < this->input->size(); i++)
		cout << this->input->at(i);
}