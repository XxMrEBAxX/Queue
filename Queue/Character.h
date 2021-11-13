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
		cout << "��� ��ǥ : " << vector->GetX() << ", " << vector->GetY() << endl;
		//���� ��ǥ�� ������
		if (targetX == vector->GetX() && targetY == vector->GetY()) { cout << "���� ��ǥ : " << targetX << ", " << targetY << endl; return; }

		//�и� 0�� �ƴϸ�
		if(targetX != vector->GetX())
			slope = (targetY - vector->GetY()) / (targetX - vector->GetX());
		float b = vector->GetY() - slope * vector->GetX();

		// x ��ǥ �������� �̵�

		// ������ x ��ǥ�� �����ؾ� �ȴٸ�
		if (targetX - vector->GetX() > 0)
		{
			for (int i = vector->GetX() + 1; i <= targetX; i++)
			{
				int y = slope * i + b;
				vector->SetXY(i, y);
				if (targetX != vector->GetX() || targetY != vector->GetY())
					cout << "�߰� ��ǥ : " << i << ", " << y << endl;
			}
		}
		// ������ x ��ǥ�� �����ؾ� �ȴٸ�
		else if (targetX - vector->GetX() < 0)
		{
			for (int i = vector->GetX() - 1; i >= targetX; i--)
			{
				int y = slope * i + b;
				vector->SetXY(i, y);
				if (targetX != vector->GetX() || targetY != vector->GetY())
					cout << "�߰� ��ǥ : " << i << ", " << y << endl;
			}
		}
		// ������ x ��ǥ�� ���ٸ�
		else
		{
			// ������ y ��ǥ�� �����ؾ� �ȴٸ�
			if (targetY - vector->GetY() > 0)
			{
				for (int i = vector->GetY() + 1; i <= targetY; i++)
				{
					vector->SetXY(vector->GetX(), i);
					//if (targetX != vector->GetX() || targetY != vector->GetY())
						cout << "�߰� ��ǥ : " << vector->GetX() << ", " << i << endl;
				}
			}
			// ������ y ��ǥ�� �����ؾ� �ȴٸ�
			else
			{
				for (int i = vector->GetY() - 1; i >= targetY; i--)
				{
					vector->SetXY(vector->GetX(), i);
					//if (targetX != vector->GetX() || targetY != vector->GetY())
						cout << "�߰� ��ǥ : " << vector->GetX() << ", " << i << endl;
				}
			}
		}
		cout << "���� ��ǥ : " << vector->GetX() << ", " << vector->GetY() << endl << endl;
	}
};

