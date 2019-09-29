// memory_alloc.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Thera are 3 kind of memory:
1. Static (RAM data)
2. Auto (stack)
3. Dynamic (heap)

Memory model in C++
|--------------------------------------------------------|
|						STACK							 |	local vars and function params
|														 |
|--------------------------------------------------------|
|						HEAP							 |	dynamic (malloc, new...)
|														 |
|--------------------------------------------------------|
|						.BSS							 |	non-init global and static vars
|														 |
|--------------------------------------------------------|
|						.DATA							 |	init global and static vars
|														 |
|--------------------------------------------------------|
|						.RODATA							 |	const (read only)
|														 |
|--------------------------------------------------------|
|						.TEXT							 |	code section
|														 |
|--------------------------------------------------------|
|						VECTOR							 |	ISR vector
|--------------------------------------------------------|
*/
/*
malloc vs new
*/
/*
--- MALLOC ---
1. Function;
2. Need sizeof(); - source of error
3. Need type-cast; Return value is (void*)
4. !!! Doesn't call constructor !!!;
5. Impossible to override;
6. In case of failure returns NULL;
7. free() function doesn’t call the destructor;
!!! Sizeof EMPTY class and STRUCT In C++ = 1; in C sizeof empty struct = 0;

--- NEW ---
1. Operator (build-in C++);
2. No need to calculate size manually;
3. Return exact data type;
4. Call Constructor (1. Allocate mamory->check result->call constructor in case of SUCCESS, else THOW exception)
5. Can be overriden;
6. In case of failure THOW exception;
7. Delete call destructor;
*/

#include <iostream>
using namespace std;

class Test {
	int a;
	int buff[100];
public:
	void init(void) {						//you can forget to call this function
		cout << "Init the object" << endl;
		this->a = 0;
		memset(this->buff, 0, sizeof(this->buff));
	}

	void destroy(void) {					//you can forget to call this function
		cout << "Destroy the object" << endl;
	}

	Test() {
		cout << "Constructor" << endl;
	}

	virtual ~Test() {
		cout << "Destructor" << endl;
	}
};

static int counter = 0;
void out_of_mem(void);
//
int main()
{
	Test* test = (Test*)malloc(10 * sizeof(Test));
	if (NULL == test) {
		cout << "Can't allocate memory" << endl;
		return -1;
	}
	cout << "Memory allocated SUCCESSFULLY" << endl;
	
	test->init();

//do something with allocated memory

	test->destroy();

	free(test);

	cout << "-------------------------" << endl;

	int sz = 10;
	int* mem_ptr = (int*)malloc(sz * sizeof(int));
	if (NULL == mem_ptr) {
		cout << "Can't allocate memory" << endl;
		return -1;
	}
	cout << "Memory allocated SUCCESSFULLY" << endl;
	for (int i = 0; i < sz; i++) {
		mem_ptr[i] = i;
		cout << "arr[" << i << "]:\t" << mem_ptr[i] << endl;
	}

	cout << "Memory RE-ALLOCATED" << endl;

	sz = 20;
	mem_ptr = (int*)realloc(mem_ptr, sz * sizeof(int));
	if (NULL == mem_ptr) {
		cout << "Can't re-allocate memory" << endl;
		return -1;
	}

	for (int i = 0; i < sz; i++) {
		mem_ptr[i] = i;
		cout << "arr[" << i << "]: " << mem_ptr[i] << endl;
	}

	cout << "-------------------------" << endl;

//The right way to use NEW and DELETE for classes
	Test* t1 = new Test[10];
	
	delete[]t1;

	set_new_handler(out_of_mem);

	while (true)
	{
		counter++;
		new int[1000];
	}

	return 0;
}

void out_of_mem(void) {
	cerr << "memory exhausted after " << counter << " allocations!" << endl;
	exit(1);
}