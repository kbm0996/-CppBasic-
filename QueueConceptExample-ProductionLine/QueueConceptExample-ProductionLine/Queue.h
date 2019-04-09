#ifndef __QUEUE_H__
#define __QUEUE_H__

#define MAX 5

bool Enqueue(unsigned long long InData);
bool Dequeue();// (long long *pOutData);
bool Peek(int iPos, unsigned long long *pOutData);

#endif