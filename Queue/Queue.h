#pragma once
#include "Character.h"
template<class T>
struct Node
{
	T data;
	Node<T>* next;
};
template<class T>
class ListQueue
{
	Node<T>* m_front;
	Node<T>* m_tail;
	int m_size;
public:
	ListQueue() : m_size(0)
	{
		m_front = nullptr;
		m_tail = nullptr;
	}
	~ListQueue();

	void Enqueue(T data);
	T Dequeue();
	int GetSize() {return m_size;}
	bool IsEmpty() { return m_size == 0; }
	T getFront() { return m_front != nullptr ? m_front->data : T(); }
};
template<class T>
ListQueue<T>::~ListQueue()
{
	int a = GetSize();
	for (int i = 0; i < a; i++)
	{
		Dequeue();
	}
}
template<class T>
void ListQueue<T>::Enqueue(T data)
{
	if (m_size == 0)
	{
		m_tail = new Node<T>;
		m_front = m_tail;
		m_tail->data = data;
		m_size++;
		return;
	}
	m_tail->next = new Node<T>;
	m_tail->next->data = data;
	m_tail = m_tail->next;
	m_size++;
}
template<class T>
T ListQueue<T>::Dequeue()
{
	if (m_size == 0) return T();

	T returnValue = m_front->data;
	Node<T>* deleteNode = m_front;
	m_front = m_front->next;

	m_size--;
	delete deleteNode;
	return returnValue;
}