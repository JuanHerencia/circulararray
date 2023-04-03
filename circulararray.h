#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray(int _capacity = 10);
    virtual ~CircularArray();
    void showdata();
    int  size();
    bool is_full();
    bool is_empty();
    void push_back(T data);
    void push_front(T data);
    T pop_front();
    T pop_back();
    /*
    void insert(T data, int pos);
    void clear();
    T& operator[](int);    
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" "); 

private:
    int next(int);
    int prev(int); */
};

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1;//empty
}

template <class T>
CircularArray<T>::~CircularArray()
{
    //delete this->array;
    delete [] this->array;
}
template <class T>
void CircularArray<T>::showdata()
{
	for(int i = 0; i < capacity; i++)
	{
		cout<<"\t"<<*(array + i);
	}
	cout<<"\n";
}

template <class T>
int CircularArray<T>::size()
{
    if(back < front) {
    	return capacity % front + back + 1;
	}
	else if(back > front) {
		return back - front + 1;
	}
	else if(back == 0 && front == 0) {
		return 1;
	}
	else if(back == -1 && front == -1){
		return 0;
	}
	else {
		return capacity;
	}
}

template <class T>
bool CircularArray<T>::is_full()
{
    if(size() == capacity) {
    	return true;
	}
	else {
		return false;
	}
}

template <class T>
bool CircularArray<T>::is_empty()
{
    if(size() == 0) {
    	return true;
	}
	else {
		return false;
	}
}

template <class T>
void CircularArray<T>::push_back(T data)
{
	cout<<"Front:"<<front<<endl;
	cout<<"Back :"<<back<<endl;
	cout<<"Valor:"<<data<<endl;
	if(is_empty()) {
		front = 0;
		back  = 0;
		*(array + back) = data;
	}
	else if(!is_full()) {
		back++;
		if(back == capacity) {
			back = 0;
		}
		*(array + back) = data;
	}
	else {
		cout<<"Arreglo circular lleno!"<<endl;
	}
}

template <class T>
T CircularArray<T>::pop_back()
{
	if(!is_empty()) {
		cout<<"Front:"<<front<<endl;
		cout<<"Back:" <<back<<endl;
		int t = back;
		back--;
		if(back == -1) {
			back = capacity-1;
		}
		return *(array + t);
	} else if(front == back) {
		int t = back;
		front = back = -1;
		return *(array + t);
	}
	else {
	    cout<<"Arreglo circular vacío!"<<endl;
	}
}

template <class T>
void CircularArray<T>::push_front(T data)
{
	if(is_empty()) {
		front = 0;
		back  = 0;
		*(array + back) = data;		
	}
	else if(!is_full()) {
		if(front == 0)
		{
			front = capacity - 1;
			*(array + front) = data;	
		} else if(front > back + 1) {
			front--;
			*(array + front) = data;
		} else if(front < back) {
			front--;
			*(array + front) = data;
		}
		else {
		    cout<<"Arreglo circular lleno!"<<endl;
	    }
	}
	else {
		cout<<"Arreglo circular lleno!"<<endl;
	}
}

template <class T>
T CircularArray<T>::pop_front()
{
	if(!is_empty()) {
		cout<<"Front:"<<front<<endl;
		cout<<"Back:" <<back<<endl;
		if(front > back) {
			int t = front;
			front++;
			if(front == capacity){
				front = 0;
			}
			return *(array + t);
		} else if(front < back) {
			front++;
			return *(array + front - 1);
		} else if(front == back) {
			int t = front;
			front = back = -1;
			return *(array + t);
		}
	} else {
	    cout<<"Arreglo circular vacío!"<<endl;
	}
}
