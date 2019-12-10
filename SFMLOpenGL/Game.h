#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	 // Uncomment for Part 2
	 // ********************
	 const int primatives;

	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
	 // ********************
};

	//Bright Orange
	//glColor3f(1.0f, 0.3f, 0.0f);

	//Super vivid green
	//glColor3f(0.4f, 1.0f, 0.0f);

	//Sky blue
	//glColor3f(0.0f, 1.0f, 1.0f);

	//Bright purple
	//glColor3f(0.5f, 0.0f, 0.9f);

	//Moave
	//glColor3f(0.7f, 0.0f, 0.4f);

	//Mint
	//glColor3f(0.0f, 0.9f, 0.8f);

	//Deep Navy
	//glColor3f(0.1f, 0.2f, 0.3f);