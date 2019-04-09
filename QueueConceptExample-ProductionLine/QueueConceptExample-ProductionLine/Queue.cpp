#include "Queue.h"

long long Queue[MAX];

int Front = 0;
int Rear = 0;
int Temp = 0;

bool Enqueue(unsigned long long InData)
{
	if ((Rear + 1) % MAX == Front)
		return false;
	Rear = (Rear + 1) % MAX;
	Queue[Rear] = InData;
	return true;
}

bool Dequeue()//long long *pOutData)
{
	if (Front == Rear)
		return false;
	Front = (Front + 1) % MAX;
	//*pOutData = Queue[Front];
	return true;
}

bool Peek(int iPos, unsigned long long *pOutData)
{
	Temp = iPos;
	if (Temp == Rear)
		return false;
	Temp = (Temp + 1) % MAX;
	*pOutData = Queue[Temp];
	return true;
}