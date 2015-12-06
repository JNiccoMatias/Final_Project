#include <SFML/Graphics.hpp>

class My_Vector
{
	double x, y;

public:
	float squared_magnitude() const {
		return x * x + y * y;
	}

	float magnitude() const {
		return std::sqrt(squared_magnitude());
	}
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

	My_Vector operator+(const My_Vector &right_hand_side) const {
		return My_Vector(right_hand_side.x + x, right_hand_side.y + y);
	}

	My_Vector operator-(const My_Vector &right_hand_side) const {
		return My_Vector(x - right_hand_side.x, y - right_hand_side.y);
	}

	My_Vector operator*(const float scalar) const {
		return My_Vector(scalar * x, scalar * y);
	}

	float operator*(const My_Vector &right_hand_side) const {
		return x * right_hand_side.x + y * right_hand_side.y;
	}

	float operator%(const My_Vector &right_hand_side) const {
		return x * right_hand_side.y - y * right_hand_side.x;
	}

	My_Vector perpendicular_vector() const {
		return My_Vector(-y, x);
	}
};
My_Vector::My_Vector(double a, double b)
{
	x = a;
	y = b;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}