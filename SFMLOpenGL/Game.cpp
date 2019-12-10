#include <Game.h>


bool flip = false;
int current = 1;



Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(10)
{

	 index = glGenLists(primatives);
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;
	sf::Clock gameClock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float FPS = 60.0f;
	sf::Time timePerFrame = sf::seconds(1.0f / FPS);

	while (isRunning) {

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}

		timeSinceLastUpdate += gameClock.restart();

		if (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update();
		}
		
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
	glTranslatef(0.0f, 0.0f, -5.0f);

	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 0.9f, 0.8f);
		glVertex3f(0.0, 1.0, 0.0);
		glColor3f(0.1f, 0.2f, 0.3f);
		glVertex3f(-1.0, -1.0, 0.0);
		glColor3f(0.1f, 0.2f, 0.3f);
		glVertex3f(1.0, -1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_POINTS);
	{
		glColor3f(0.4f, 1.0f, 0.0f);
		glVertex3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0, -1.0, 0.0);
		glVertex3f(1.0, -1.0, 0.0);
		glVertex3f(2.0, 1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 2, GL_COMPILE);
	glBegin(GL_LINES);
	{
		glColor3f(0.6f, 0.0f, 0.0f);
		glVertex3f(0.0, 1.0, 0.0);
		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3f(-1.0, -1.0, 0.0);
		glColor3f(0.4f, 1.0f, 0.0f);
		glVertex3f(1.0, -1.0, 0.0);
		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3f(2.0, 1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 3, GL_COMPILE);
	glBegin(GL_LINE_STRIP);
	{
		glColor3f(0.6f, 0.0f, 0.0f);
		glVertex3f(0.0, 1.0, 0.0);
		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3f(-1.0, -1.0, 0.0);
		glColor3f(0.4f, 1.0f, 0.0f);
		glVertex3f(1.0, -1.0, 0.0);
		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3f(2.0, 1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 4, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(0.6f, 0.0f, 0.0f);
		glVertex3f(0.0, 1.0, 0.0);
		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3f(-1.0, -1.0, 0.0);
		glColor3f(0.4f, 1.0f, 0.0f);
		glVertex3f(1.0, -1.0, 0.0);
		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3f(2.0, 1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 5, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3f(0.8f, 0.0f, 0.0f);
		glVertex3f(-2.0, -1.0, 0.0);

		glColor3f(1.0f, 0.7f, 0.0f);
		glVertex3f(-1.0, 1.0, 0.0);

		glColor3f(0.4f, 1.0f, 0.0f);
		glVertex3f(0.0, -1.0, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0, 1.0, 0.0);

		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(2.0, -1.0, 0.0);

	}
	glEnd();
	glEndList();

	glNewList(index + 6, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(0.6f, 0.0f, 0.0f);
		glVertex3f(-2.0, -1.0, 0.0);

		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3f(-2.0, 2.0, 0.0);

		glColor3f(0.4f, 1.0f, 0.0f);
		glVertex3f(-1.0, 2.0, 0.0);

		glColor3f(0.0f, 0.3f, 0.5f);
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(0.6f, 0.0f, 0.0f);
		glVertex3f(0.5, -0.5, 0.0);

		glColor3f(0.9f, 0.9f, 0.0f);
		glVertex3f(0.5, -1.5, 0.0);

	}
	glEnd();
	glEndList();

	glNewList(index + 7, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		glColor3f(0.6f, 0.0f, 0.0f);
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3f(-1.0, -1.0, 0.0);

		glColor3f(0.4f, 1.0f, 0.0f);
		glVertex3f(1.0, -1.0, 0.0);

		glColor3f(0.0f, 0.3f, 0.7f);
		glVertex3f(2.0, 1.0, 0.0);

	}
	glEnd();
	glEndList();

	glNewList(index + 8, GL_COMPILE);
	glBegin(GL_QUAD_STRIP);
	{
		glColor3f(0.7f, 0.0f, 0.0f);
		glVertex3f(-2.0f, -1.0f, 0.0);

		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 0.0);

		glColor3f(0.4f, 1.0f, 0.0f);
		glVertex3f(0.0f, -1.0f, 0.0);

		glColor3f(0.0f, 0.1f, 0.9f);
		glVertex3f(1.0f, 1.0f, 0.0);

		glColor3f(0.0f, 0.5f, 0.5f);//last point
		glVertex3f(1.0f, -2.0f, 0.0);

		glColor3f(0.9f, 0.9f, 0.0f);//2nd last point
		glVertex3f(2.0f, 0.0f, 0.0);

	}
	glEnd();
	glEndList();

	glNewList(index + 9, GL_COMPILE);
	glBegin(GL_POLYGON);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-2.0, -1.0, 0.0);

		glColor3f(0.5f, 0.0f, 0.9f);
		glVertex3f(-0.5, 1.0, 0.0);

		glColor3f(0.7f, 0.0f, 0.4f);
		glVertex3f(0.5, 1.0, 0.0);

		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3f(2.0, -1.0, 0.0);

	}
	glEnd();
	glEndList();


	/*glNewList(index + 10, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.2, 0.0, -2.0);
		glVertex3f(-2.0, -2.0, -2.0);
		glVertex3f(2.0, -2.0, -2.0);
	}
	glEnd();
	glEndList();
*/


}

void Game::update()
{ 

	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		current++;
		if (current > primatives)
		{
			current = 1;
		}
	}




	//Load identity
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::I)))
	{
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -5.0f);
	}

	//Rotate Right
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		glRotatef(1.0f, 0.0f, 0.0f, 1.0f);
	}
	//Rotate Left
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		glRotatef(1.0f, 0.0f, 0.0f, -1.0f);
	}

	//Translate
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::T)))
	{
		glTranslatef(0.05f, 0.0f, 0.0f);
	}

	//Increase Scale
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
	{
		glScalef(1.01f, 1.01f, 1.01f);
	}
	//Decrease Scale
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
	{
		glScalef(0.995f, 0.995f, 0.995f);
	}



	//--------------------------------------------------------------------------------------Shape creation

	/*if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		std::cout << "GL Lines\n\n";
	}*/




	window.display();
}



void Game::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glCallList(current);
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

