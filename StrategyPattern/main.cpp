#include <iostream>
#include <vector>
#include <algorithm>

class SortStrategy
{
public:
	virtual ~SortStrategy() {}
	virtual void sort(std::vector<int>& input) = 0;
};

class BubbleSortStrategy: public SortStrategy
{
public:
	void sort(std::vector<int>& input) override
	{
		for (int i = 0; i < input.size() - 1; i++)
		{
			for (int j = 0; j < input.size() - i - 1; j++)
			{
				if(input[j] > input[j+1])
					std::swap(input[j], input[j+1]);
			}
		}
	}
};

class InsertionSortStrategy : public SortStrategy
{
public:
	void sort(std::vector<int>& input) override
	{
		std::cout << "[WARNING: Insertion Sort not implemented]" << std::endl;
	}
};


class CustomVector
{
public:
	std::vector<int> custom_vector;
	SortStrategy* sort_strategy;

	CustomVector() : sort_strategy(new BubbleSortStrategy) {}
	CustomVector(SortStrategy* p_sort_strategy) : sort_strategy(p_sort_strategy), custom_vector({}) {}
	~CustomVector() { delete sort_strategy; }

	void set_strategy(SortStrategy* p_sort_strategy)
	{
		if (sort_strategy) delete sort_strategy;
		else return;

		this->sort_strategy = p_sort_strategy;
	}

	void sort()
	{
		sort_strategy->sort(custom_vector);
	}

	void print()
	{
		for (int element : custom_vector)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
};


int main()
{
	CustomVector* v2 = new CustomVector();
	v2->custom_vector = { 4,2,1,5,8,9,3 };
	v2->sort();
	v2->print();

	v2->set_strategy(new InsertionSortStrategy);
	v2->custom_vector = { 4,2,1,5,8,9,3 };
	v2->sort();
	v2->print();

	delete v2;
}