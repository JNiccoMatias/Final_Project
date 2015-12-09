#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace std;

class My_Vector
{
	double x, y;

public:
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

	float squared_magnitude() const {
		return x * x + y * y;
	}

	float magnitude() const {
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

class Gamestate
{

public:
	virtual void init() = 0;
	virtual void cleanUp() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void update() = 0;
	virtual void draw() = 0;

	virtual void onActivate() = 0;
	virtual void onDeactivate() = 0;
};

class GameStateManager
{
public:
	void ChangeState(Gamestate* state);
	void PushState(Gamestate* state);
	void PopState();
	void Clear();

private:
	std::vector<Gamestate*> m_states;
};

void GameStateManager::Clear()
{
	while (!m_states.empty())
	{
		m_states.back()->cleanUp();
		m_states.pop_back();
	}
}


void GameStateManager::ChangeState(Gamestate *state)
{
	// Cleanup the current state
	if (!m_states.empty())
	{
		m_states.back()->cleanUp();
		m_states.pop_back();
	}

	// Store and init the new state
	m_states.push_back(state);
	m_states.back()->init();
}



// Pause the current state and go to a new state
void GameStateManager::PushState(Gamestate *state)
{
	if (!m_states.empty())
		m_states.back()->pause();

	m_states.push_back(state);
	m_states.back()->init();
}


//Leave current state and go to previous state
void GameStateManager::PopState()
{
	if (!m_states.empty())
	{
		m_states.back()->cleanUp();
		m_states.pop_back();
	}

	if (!m_states.empty())
		m_states.back()->resume();
}


class MainMenu_Gamestate : public Gamestate
{
public:
	MainMenu_Gamestate() {}
};

class Pause_Gamestate : public Gamestate
{
public:
	Pause_Gamestate() {}
};

class GameOver_Gamestate : public Gamestate
{
public:
	GameOver_Gamestate() {}
};

class Leaderboard_Gamestate : public Gamestate
{
public:
	Leaderboard_Gamestate() {}
};

int main()
{
	int window_width = 1200;
	int window_height = 800;

	sf::Font font;
	if (!font.loadFromFile("AlegreyaSans-Regular.ttf"))
	{
		return 0;
	}

	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Endless Runner", sf::Style::Close);

	//Main game/window loop
	while (window.isOpen())
	{

		//closing event check
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Draw
		window.clear();
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);
		window.draw(shape);
		window.display();
	}

	return 0;
}