#include <iostream>
#include <vector>
#include "Character.h"
#include "Queue.h"
using namespace std;

int main()
{
	Character character(0 , 0);
	ListQueue<Vector2> queue;
	bool still = true;
	char input;
	int inputX, inputY;

	while (still)
	{
		cout << "1.큐에 좌표넣기" << endl;
		cout << "2.이동하기" << endl;
		cout << "3.종료" << endl;
		cout << "번호 : ";

		cin >> input;
		switch (input)
		{
		case '1':
			cin >> inputX >> inputY;
			queue.Enqueue(Vector2(inputX, inputY));
			break;
		case '2':
			while (!queue.IsEmpty())
			{
				character.move(queue.Dequeue());
			}
			break;
		case '3':
			still = false;
			break;
		default:
			break;
		}
	}
}