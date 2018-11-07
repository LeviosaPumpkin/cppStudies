#include"QueueWithPriority.h"

void main()
{
	typedef QueueWithPriority<std::string> myQueue_type;
	myQueue_type myQueue;
	myQueue.Put("A", myQueue_type::LOW);
	myQueue.Put("B", myQueue_type::LOW);
	myQueue.Put("C", myQueue_type::NORMAL);
	myQueue.Put("D", myQueue_type::NORMAL);
	myQueue.Put("E", myQueue_type::NORMAL);

	std::cout << "Queue in time order\n";
	myQueue.Print();

	std::cout << "Get elements from queue\n";
	size_t size = myQueue.Size();
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << *myQueue.Get();
	}

	myQueue.Put("1", myQueue_type::LOW);
	myQueue.Put("2", myQueue_type::HIGH);
	myQueue.Put("3", myQueue_type::LOW);
	myQueue.Put("4", myQueue_type::NORMAL);
	myQueue.Put("5", myQueue_type::HIGH);

	std::cout << "Queue\n";
	myQueue.Print();

	myQueue.Accelerate();
	std::cout << "After acceleration:\n";
	myQueue.Print();

	std::cout << "Get elements from queue\n";
	size = myQueue.Size();
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << *(myQueue.Get()) << std::endl;
	}

	myQueue.Get();
	myQueue.Accelerate();

}
