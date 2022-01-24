#ifndef STACK_H
#define STACK_H

const int MAX_STACK = 100;

template <class Type>
class StackInterface{
public:
	virtual bool isEmpthy()const = 0;
	virtual bool push(Type) = 0;;
	virtual bool pop() = 0;
	virtual Type peek()const = 0;
};



template <class Type>
class Stack:public StackInterface <Type>{
public:
	Stack();
	Stack(Type);
	Stack(const Stack& rhs);
	Stack& operator = (const Stack& rhs);
	Stack(Stack&& rhs)noexcept;
	Stack& operator = (Stack&& rhs)noexcept;
	~Stack();
public:
	virtual bool isEmpthy()const ;
	virtual bool push(Type) ;
	virtual bool pop() ;
	virtual Type peek()const; 
private:
	int top;
	Type* arr ;

};






#endif //STACK_H
