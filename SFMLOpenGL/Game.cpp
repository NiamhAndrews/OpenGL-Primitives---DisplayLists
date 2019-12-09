#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0); 
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	//cout << "Draw up" << endl; 
	
	if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) )
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		{
			glColor3f(0.0f, 0.9f, 0.8f);
			glVertex3f(0.0, 1.0, -5.0);
			glColor3f(0.1f, 0.2f, 0.3f);
			glVertex3f(-1.0, -1.0, -5.0);
			glColor3f(0.1f, 0.2f, 0.3f);
			glVertex3f(1.0, -1.0, -5.0);


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

			//Link green

			//Mint
			//glColor3f(0.0f, 0.9f, 0.8f);
			//Deep Navy
			//glColor3f(0.1f, 0.2f, 0.3f);

			std::cout << "GL Triangles\n\n";
		}
		glEnd();
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_POINTS);
		{
			glColor3f(0.4f, 1.0f, 0.0f);
			glVertex3f(0.0, 1.0, -5.0);
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(1.0, -1.0, -5.0);
			glVertex3f(2.0, 1.0, -5.0);

			std::cout << "GL Points\n\n";
		}
		glEnd();
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_LINES);
		{
			glColor3f(0.6f, 0.0f, 0.0f);
			glVertex3f(0.0, 1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(-1.0, -1.0, -5.0);
			glColor3f(0.4f, 1.0f, 0.0f);
			glVertex3f(1.0, -1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(2.0, 1.0, -5.0);
			std::cout << "GL Lines\n\n";
		}
		glEnd();
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_LINE_STRIP);
		{
			glColor3f(0.6f, 0.0f, 0.0f);
			glVertex3f(0.0, 1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(-1.0, -1.0, -5.0);
			glColor3f(0.4f, 1.0f, 0.0f);
			glVertex3f(1.0, -1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(2.0, 1.0, -5.0);
			std::cout << "GL Line strip\n\n";
		}
		glEnd();
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_LINE_LOOP);
		{
			glColor3f(0.6f, 0.0f, 0.0f);
			glVertex3f(0.0, 1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(-1.0, -1.0, -5.0);
			glColor3f(0.4f, 1.0f, 0.0f);
			glVertex3f(1.0, -1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(2.0, 1.0, -5.0);
			std::cout << "GL Line loop\n\n";
		}
		glEnd();
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_TRIANGLE_STRIP);
		{
			glColor3f(0.6f, 0.0f, 0.0f);
			glVertex3f(-2.0, -1.0, -5.0);//causing shape point overlap
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(-1.0, 1.0, -5.0);
			glColor3f(0.4f, 1.0f, 0.0f);
			glVertex3f(0.0, -1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(1.0, 1.0, -5.0);
			glColor3f(0.4f, 1.0f, 0.0f);
			glVertex3f(2.0, -1.0, -5.0);
			std::cout << "GL Triangle Strip\n\n";
		}
		glEnd();
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_TRIANGLE_FAN);
		{
			glColor3f(0.6f, 0.0f, 0.0f);
			glVertex3f(0.0, 1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(-1.0, -1.0, -5.0);
			glColor3f(0.4f, 1.0f, 0.0f);
			glVertex3f(1.0, -1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(2.0, 1.0, -5.0);
			std::cout << "GL Triangle Fan\n\n";
		}
		glEnd();
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_QUADS);
		{
			glColor3f(0.6f, 0.0f, 0.0f);
			glVertex3f(0.0, 1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(-1.0, -1.0, -5.0);
			glColor3f(0.4f, 1.0f, 0.0f);
			glVertex3f(1.0, -1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(2.0, 1.0, -5.0);
			std::cout << "GL Quads\n\n";
		}
		glEnd();
	}


	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_QUAD_STRIP);
		{
			glColor3f(0.6f, 0.0f, 0.0f);
			glVertex3f(-2.0f, -1.0f, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(-1.0f, 1.0f, -5.0);
			glColor3f(0.4f, 1.0f, 0.0f);
			glVertex3f(0.0f, -1.0f, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(1.0f, 1.0f, -5.0);
			//glColor3f(0.4f, 1.0f, 0.0f);
			glColor3f(0.0f, 0.1f, 0.9f);
			glVertex3f(2.0f, 1.0f, -5.0);
			glColor3f(0.0f, 0.5f, 0.5f);
			glVertex3f(2.0f, -2.0f, -5.0);
			std::cout << "GL Quad Strip\n\n";
		}
		glEnd();
	}


	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_POLYGON);
		{
			glColor3f(0.6f, 0.0f, 0.0f);
			glVertex3f(-2.0, -1.0, -5.0);//causing shape point overlap
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(-0.5, 1.0, -5.0);
			glColor3f(0.4f, 1.0f, 0.0f);
			//glVertex3f(0.0, -1.0, -5.0);
			glColor3f(1.0f, 0.3f, 0.0f);
			glVertex3f(0.5, 1.0, -5.0);
			glColor3f(0.4f, 1.0f, 0.0f);
			glVertex3f(2.0, -1.0, -5.0);
			std::cout << "GL Polygon\n\n";
		}
		glEnd();
	}




	window.display();
}

void Game::draw()
{
	//cout << "Draw up" << endl;
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}


//Finally modify your code to include drawing of the Primitives 
//1 GL_TRIANGLES 
//2 GL_POINTS 
//3 GL_LINES 
//4 GL_LINE_STRIP 
//5 GL_LINE_LOOP 
//6 GL_TRIANGLE_STRIP 
//7 GL_TRIANGLE_FAN 
//8 GL_QUADS 
//9 GL_QUAD_STRIP 
//0 GL_POLYGON
