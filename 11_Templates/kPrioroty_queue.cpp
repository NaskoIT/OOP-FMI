#include <iostream>
#include <vector>
#include <queue>
#include <exception>

using namespace std;

const int INITIAL_PRIORITY = -1;

template<typename T>
class KPriorityQueue {
private:
	vector<queue<T>> container;
	int highestPriority;
	int getNewHighestPriority() {
		for (int i = highestPriority - 1; i >= 0; i--)
		{
			if (!container[i].empty()) {
				return i;
			}
		}

		return INITIAL_PRIORITY;
	}

public:
	KPriorityQueue(int priority) {
		container = vector<queue<T>>(priority);
		this->highestPriority = INITIAL_PRIORITY;
	}

	void push(const T value, const int priority) {
		if (priority >= container.size()) {
			throw invalid_argument("Priority should be less than: " + container.size());
		}

		container[priority].push(value);

		if (highestPriority < priority) {
			highestPriority = priority;
		}
	}

	void pop() {
		if (highestPriority == INITIAL_PRIORITY) {
			throw logic_error("There are no elements in the queue!");
		}

		container[highestPriority].pop();

		if (container[highestPriority].empty()) {
			highestPriority = getNewHighestPriority();
		}

	}

	T peek() {
		int priority = highestPriority();
		return container[priority].peek();
	}
};

int main()
{
}
