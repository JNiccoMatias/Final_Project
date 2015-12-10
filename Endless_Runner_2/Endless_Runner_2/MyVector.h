#pragma once

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class My_Vector
{
	double x, y;

public:
	My_Vector();
	My_Vector(double, double);
	double Get_X()
	{
		return x;
	}
	double Get_Y()
	{
		return y;
	}
	void Set_X(double a)
	{
		x = a;
	}
	void Set_Y(double b)
	{
		y = b;
	}

	double squared_magnitude() const {
		return x * x + y * y;
	}

	double magnitude() const {
		return sqrt(squared_magnitude());
	}
	My_Vector operator+(const My_Vector &right_hand_side) const {
		return My_Vector(right_hand_side.x + x, right_hand_side.y + y);
	}

	My_Vector operator-(const My_Vector &right_hand_side) const {
		return My_Vector(x - right_hand_side.x, y - right_hand_side.y);
	}

	My_Vector operator*(const float scalar) const {
		return My_Vector(scalar * x, scalar * y);
	}

	double operator*(const My_Vector &right_hand_side) const {
		return x * right_hand_side.x + y * right_hand_side.y;
	}

	double operator%(const My_Vector &right_hand_side) const {
		return x * right_hand_side.y - y * right_hand_side.x;
	}

	My_Vector perpendicular_vector() const {
		return My_Vector(-y, x);
	}
};
My_Vector::My_Vector()
{
	x = 0;
	y = 0;
}
My_Vector::My_Vector(double a, double b)
{
	x = a;
	y = b;
}

#endif