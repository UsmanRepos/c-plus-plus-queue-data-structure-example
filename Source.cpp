#include<iostream>
#define SIZE 5

using namespace std;

class Queue
{
	int head, tail;
	int array[SIZE];
public:
	Queue() :head(-1), tail(-1)
	{
		for (int i = 0; i < SIZE; i++)
		{
			array[i] = 0;
		}
	}
	void myPush(int data);
	int  myPop();
	int  peakValue();
	int  myTop();
	bool isEmpty();
	void myGetter();
};

void Queue::myGetter()
{
	cout << " Queue Data: ";
	for (int i = head; i <= tail; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
}
void Queue::myPush(int data)
{
	if (tail > SIZE - 1)
	{
		cout << "\n Stack Overflow ... !!!\n";
	}
	else
	{
		if (head == -1)
			head = 0;
		array[++tail] = data;
	}
}
int Queue::myPop()
{
	if (head > tail)
	{
		cout << "\n Queue UnderFlow ... !!!\n";
		return -99;
	}
	else
	{
		return array[head++];
	}
}
int Queue::peakValue()
{
	if (head > tail )
	{
		cout << "\n Queue UnderFlow ... !!!\n";
	}
	else
	{
		return array[head];
	}
}
int Queue::myTop()
{
	return tail;
}
bool Queue::isEmpty()
{
	if (head > tail)
		return true;
	else
		return false;
}


int main()
{
	Queue queue;
	int data;
	char ch;

	while (true) {
		cout << "\n -----------(MAIN MENU)-----------\n";
		cout << " 1) PUSH \n";
		cout << " 2) POP \n";
		cout << " 3) PEAK \n";
		cout << " 4) IS EMPTY \n";
		cout << " 5) TOP \n";
		cout << " 6) GETTER \n";
		cout << " 7) EXIT \n\n";

		cout << " Enter Your Choice: ";
		cin >> ch;

		switch (ch)
		{
		case '1':
			cout << "\n Enter Data: ";
			cin >> data;
			queue.myPush(data);
			break;
		case '2':
			data = queue.myPop();
			if (data != -99)
				cout << "Pop Value: " << data << endl;
			break;
		case '3':
			cout << "Peak Value: " << queue.peakValue() << endl;
			break;
		case '4':
			if (queue.isEmpty())
				cout << " Stack is Empty ... \n";
			else
				cout << " Stack is Not Empty \n";
			break;
		case '5':
			cout << "Value Of Top: " << queue.myTop() << endl;
			break;
		case '6':
			queue.myGetter();
			break;
		case'7':
			exit(-1);
		default:
			cout << " Invalid Input ... !!!\n";
		}
	}
}