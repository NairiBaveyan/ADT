#ifndef QUEUE_H
#define QUEUE_H

const int MAX_QUEUE = 100;

template <typename Type>
class QueueInterface
{
public:
	virtual bool isEmpty()const = 0;
	virtual bool enqueue(const Type) = 0;
	virtual bool dequeue() = 0;
	virtual Type getFront()const = 0;
};


template <typename Type>
class Queue:public QueueInterface<Type>{
public:
        Queue();
        Queue(Type);
        Queue(const Queue& );
        Queue& operator = (const Queue&);
        Queue(Queue&& )noexcept;
        Queue& operator = (Queue&& )noexcept;
        ~Queue();


public:
	bool isEmpty()const;
	bool enqueue(const Type);//Adds newEntry at the back of this queue
	bool dequeue();//Removes the front of this queue
	Type getFront()const;//Returns the front of this queue

private:
	Type* arr;
	int front;
	int back;
	int count;
};

#endif  

