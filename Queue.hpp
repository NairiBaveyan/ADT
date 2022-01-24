#include "Queue.h"


template <typename Type>
Queue<Type>::Queue():
	front{},count{},back{MAX_QUEUE -1}
{
	arr = new Type[MAX_QUEUE];
}


template <typename Type>
Queue<Type>::Queue(Type param)
{
	arr = new Type[MAX_QUEUE];
	enqueue(param);
}


template <typename Type>
Queue<Type>::Queue(const Queue& rhs)
	:front{rhs.front},back{rhs.back},count{rhs.count}
{
	arr = new Type[MAX_QUEUE];
	for(int i{};i < count;++i)
	{
		arr[i] = rhs.arr[i];

	}
}


template<typename Type>
Queue<Type>& Queue<Type>::operator=(const Queue& rhs)
{
	if(this == &rhs)
		return *this;
	front = rhs.front;
	back = rhs.back;
	count = rhs.count;
	for(int i{};i < count;++i)
	{
		arr[i] = rhs.arr[i];
	}
	return *this;
}

template<typename Type>
Queue<Type>& Queue<Type>::operator=(Queue&& rhs)noexcept
{
	if(this == &rhs)
		return *this;
	front = rhs.front;
        back = rhs.back;
        count = rhs.count;

	rhs.front = 0;
	rhs.back = 0;
	rhs.count = 0;

	arr = rhs.arr;
	arr.rhs = nullptr;

	return *this;
}

template <typename Type>
Queue<Type>::Queue(Queue&& rhs)noexcept
{
	arr = rhs.arr;
	front = rhs.front;
	back = rhs.back;
	count = rhs.count;

	rhs.arr = nullptr;                                          
        rhs.front = 0;                                      
        rhs.back = 0;                                        
        rhs.count = 0;	
}



template<typename Type>
Queue<Type>::~Queue()
{
	delete[] arr;
}


template<typename Type>
bool Queue<Type>::isEmpty()const
{
	return count ==0;
}


template <typename Type>
bool Queue<Type>::enqueue(const Type newItem)
{
	bool result = false;
	if(count < MAX_QUEUE){
		back = (back + 1) % MAX_QUEUE;
		arr[count] = newItem;
		++count;
		result = true;
	}
	return result;

}


template<typename Type>
bool Queue<Type>::dequeue()
{
	bool result = false;
	if(!isEmpty())
	{
		front = (front +1)% MAX_QUEUE;
		--count;
		result = true;
	}
	return result;	
}


template <typename Type>
Type Queue<Type>::getFront()const
{
	if(isEmpty())
	{
		throw("Empty Queue");
	}
	return arr[front];	
}

