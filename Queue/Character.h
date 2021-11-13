#pragma once
#include <iostream>
using namespace std;

class Vector2
{
	float x, y;
public:
	Vector2() : x(0), y(0) {}
	Vector2(float x, float y) : x(x), y(y) {}
	void SetXY(float x, float y) { this->x = x; this->y = y; }
	float GetX() { return x; }
	float GetY() { return y; }
};

class Character
{
	Vector2* vector;
public:
	Character(float x, float y) { vector = new Vector2(x, y); }
	~Character() { delete vector; }

	void move(Vector2 vec)
	{
		float targetX = vec.GetX();
		float targetY = vec.GetY();
		float slope = 1;
		cout << "출발 좌표 : " << vector->GetX() << ", " << vector->GetY() << endl;
		//만약 좌표가 같으면
		if (targetX == vector->GetX() && targetY == vector->GetY()) { cout << "도착 좌표 : " << targetX << ", " << targetY << endl; return; }

		//분모가 0이 아니면
		if(targetX != vector->GetX())
			slope = (targetY - vector->GetY()) / (targetX - vector->GetX());
		float b = vector->GetY() - slope * vector->GetX();

		// x 좌표 기준으로 이동

		// 가야할 x 좌표가 증가해야 된다면
		if (targetX - vector->GetX() > 0)
		{
			for (int i = vector->GetX() + 1; i <= targetX; i++)
			{
				int y = slope * i + b;
				vector->SetXY(i, y);
				if (targetX != vector->GetX() || targetY != vector->GetY())
					cout << "중간 좌표 : " << i << ", " << y << endl;
			}
		}
		// 가야할 x 좌표가 감소해야 된다면
		else if (targetX - vector->GetX() < 0)
		{
			for (int i = vector->GetX() - 1; i >= targetX; i--)
			{
				int y = slope * i + b;
				vector->SetXY(i, y);
				if (targetX != vector->GetX() || targetY != vector->GetY())
					cout << "중간 좌표 : " << i << ", " << y << endl;
			}
		}
		// 가야할 x 좌표가 같다면
		else
		{
			// 가야할 y 좌표가 증가해야 된다면
			if (targetY - vector->GetY() > 0)
			{
				for (int i = vector->GetY() + 1; i <= targetY; i++)
				{
					vector->SetXY(vector->GetX(), i);
					//if (targetX != vector->GetX() || targetY != vector->GetY())
						cout << "중간 좌표 : " << vector->GetX() << ", " << i << endl;
				}
			}
			// 가야할 y 좌표가 감소해야 된다면
			else
			{
				for (int i = vector->GetY() - 1; i >= targetY; i--)
				{
					vector->SetXY(vector->GetX(), i);
					//if (targetX != vector->GetX() || targetY != vector->GetY())
						cout << "중간 좌표 : " << vector->GetX() << ", " << i << endl;
				}
			}
		}
		cout << "도착 좌표 : " << vector->GetX() << ", " << vector->GetY() << endl << endl;
	}
};

