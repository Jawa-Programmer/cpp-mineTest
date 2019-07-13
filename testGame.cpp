
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <limits>

#include <GL/glut.h>

#include "Blocks/Block.h"
#include "Blocks/AirBlock.h"
#include "Blocks/StoneBlock.h"
#include "Blocks/DirtBlock.h"
#include "Controls/Keyboard.h"

using namespace std;

Block *bl[20][10][10];

int SCR_WIDTH = 500, SCR_HEIGHT = 500;

const float PI = 3.1415926536,MouseSpeed=0.0035, speed = 0.1;

float rX = 0.707107, rY = 0, rZ = 0.707107, cX=0,cY=1,cZ=0,vX=0,vY = 0,vZ=0;


	void make3D()
	{
		glPopAttrib();
		glPushAttrib(GL_ENABLE_BIT);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		//glEnable(GL_TEXTURE_2D);
		
		glViewport(0,0, SCR_WIDTH, SCR_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		
		
		gluPerspective(60.0f, (float) SCR_WIDTH / SCR_HEIGHT, 0.01f, 200.0f);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		}
	
	void make2D()
	{
		glPopAttrib();
		glPushAttrib(GL_ENABLE_BIT);

		glViewport(0,0, SCR_WIDTH, SCR_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, SCR_WIDTH, SCR_HEIGHT, 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		}
	
/*
void pressKey(int key, int x,int y)
{
	float N = hypot(rX,rZ);
	switch(key)
	{
		case GLUT_KEY_UP:
			vZ = speed * rZ / N;
			vX = speed * rX / N;
		break;
		case GLUT_KEY_DOWN:
			vZ =- speed * rZ / N;
            vX =- speed * rX / N;
		break;
		case GLUT_KEY_LEFT:
			vZ =- speed * rX / N;
            vX = speed * rZ / N;
		break;
		case GLUT_KEY_RIGHT:
            vZ = speed * rX / N;
            vX =- speed * rZ / N;
		break;
		}
	}
void releaseKey(int key, int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
		case GLUT_KEY_DOWN:
		case GLUT_KEY_LEFT:
		case GLUT_KEY_RIGHT:
		vX=0;
		vZ=0;
		break;
		}
	}
*/
void MouseMove(int x, int y)
{
	
	int centerX = glutGet(GLUT_WINDOW_WIDTH)/2;
	int centerY = glutGet(GLUT_WINDOW_HEIGHT)/2;
	float dX = x - centerX, dY = y - centerY;
	
	if(abs(dX)>1||abs(dY)>1){
		
		float xr = dX*MouseSpeed, yr = dY * MouseSpeed;

		float trX = rX * cos(xr) - rZ * sin(xr),
						trZ = rX * sin(xr) + rZ * cos(xr);

		rX = trX;
		rZ = trZ;

		float F = hypot(rX, rZ);

		float trY = rY * cos(yr) - F * sin(yr);

		rY = trY;


	glutWarpPointer(centerX, centerY);
	
	}

	//cout << x << "\t" << y << endl;
}

void Move()
{
		vZ=0;
		vX=0;
		vY=0;
	float N = hypot(rX,rZ);
	if(Keyboard::IsButtonDown('w') && Keyboard::IsButtonDown('a'))
	{
		float tvZ = rZ / N	- rX / N;
		float tvX = rX / N + rZ / N;
		float tN = hypot(tvX,tvZ);

		vZ = speed * tvZ / tN;
		vX = speed * tvX / tN;
		
		}
	else if(Keyboard::IsButtonDown('w') && Keyboard::IsButtonDown('d'))
	{
		float tvZ = rZ / N	+ rX / N;
		float tvX = rX / N - rZ / N;
		float tN = hypot(tvX,tvZ);

		vZ = speed * tvZ / tN;
		vX = speed * tvX / tN;
		
		}
	else if(Keyboard::IsButtonDown('s') && Keyboard::IsButtonDown('d'))
	{
		float tvZ = rZ / N	- rX / N;
		float tvX = rX / N + rZ / N;
		float tN = hypot(tvX,tvZ);

		vZ = -speed * tvZ / tN;
		vX = -speed * tvX / tN;
		
		}
	else if(Keyboard::IsButtonDown('s') && Keyboard::IsButtonDown('a'))
	{
		float tvZ = rZ / N	+ rX / N;
		float tvX = rX / N - rZ / N;
		float tN = hypot(tvX,tvZ);

		vZ = -speed * tvZ / tN;
		vX = -speed * tvX / tN;
		
		}
	else if(Keyboard::IsButtonDown('w'))
	{
		vZ = speed * rZ / N;
		vX = speed * rX / N;
		}
	else if(Keyboard::IsButtonDown('s'))
	{
		vZ =- speed * rZ / N;
        vX =- speed * rX / N;
		}	
	else if(Keyboard::IsButtonDown('a'))
	{
		vZ =- speed * rX / N;
        vX = speed * rZ / N;
		}	
	else if(Keyboard::IsButtonDown('d'))
	{
        vZ = speed * rX / N;
        vX =- speed * rZ / N;
		}	
	
	if(Keyboard::IsButtonDown('c'))
	{
        vY = -speed;
		}
	else if(Keyboard::IsButtonDown(' '))
	{
        vY = speed;
		}
	
	cX+=vX;
	cZ+=vZ;
	cY+=vY;
	}
	
void keyboardChange(unsigned char key, bool isPressed)
{
	//cout << "State of " << key << " was changed" <<  endl; 
	if(key == 27) exit(0);
	}
	
		void init()
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0f, 1, 0.01f, 200.0f);
		glMatrixMode(GL_MODELVIEW);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);
		}

const bool isDrawLines = true;

	void draw()
{
	
	 //make3D();
	 init();
	  
	 /* glBegin(GL_LINES);
	  glColor3f(0,0,0);
	  
	  glVertex3f(0,-5,0);
	  glVertex3f(10,-5,0);
	  
	  glVertex3f(0,-5,0);
	  glVertex3f(0,-5,10);
	  
	  glVertex3f(0,-5,0);
	  glVertex3f(0,15,0);
	  
	  glVertex3f(10,15,10);
	  glVertex3f(10,15,0);
	  
	  glVertex3f(10,15,10);
	  glVertex3f(0,15,10);
	  
	  
	  glVertex3f(10,15,10);
	  glVertex3f(10,-5,10);
	  
	  glVertex3f(0,15,10);
	  glVertex3f(0,-5,10);
	  
	  glVertex3f(10,15,0);
	  glVertex3f(10,-5,0);
	  
	  glEnd();
	  */
	  
	  for(int Y = 0; Y < 20; Y++)
	  for(int X = 0; X < 10; X++)
	  for(int Z = 0; Z < 10; Z++){
	  bl[Y][X][Z]->Draw();
	  if(!bl[Y][X][Z]->isAir() && isDrawLines)
		bl[Y][X][Z]->drawLines();
	  
	// if(bl[Y][X][Z]->IsSeeAtMe(cX,cY,cZ,rX,rY,rZ, &b, &a))
	// cout << "You Look At Me!\t" << X <<"\t" << Y << "\t" << Z << endl;
	  }

	}
	void draw2D()
	{
		
	  make2D();
	  
	  glBegin(GL_LINES);
	  glColor3f(1, 1, 1);
	  
	  glVertex2i(SCR_WIDTH/2-10,SCR_HEIGHT/2);
	  glVertex2i(SCR_WIDTH/2+10,SCR_HEIGHT/2);
	  
	  glVertex2i(SCR_WIDTH/2,SCR_HEIGHT/2-10);
	  glVertex2i(SCR_WIDTH/2,SCR_HEIGHT/2+10);
	  
	  glEnd();
		}

void display()
{
	glClearColor(0.0, 0.7, 0.9, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Move();
	glLoadIdentity();
	gluLookAt(cX, cY, cZ, cX+rX, cY+rY, cZ+rZ, 0, 1, 0);
	draw();
	draw2D();
	glutSwapBuffers();
	}


void ClickFunc(int but, int state, int x, int y)
{
	if(but == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		// cout << "Mouse clicked" << endl;
		
		float min_len = numeric_limits<float>::max();
		int side;
		int xx,yy,zz;
		
		for(int YY=0; YY < 20; YY++)
			for(int XX = 0; XX < 10; XX++)
				for(int ZZ = 0; ZZ < 10; ZZ++)
				{
					int sd = 0;
					float ln = 0;
					if(bl[YY][XX][ZZ]->IsSeeAtMe(cX,cY,cZ,rX,rY,rZ,&ln,&sd) && (ln < min_len && ln > 0))
						{
						xx=XX;
						yy=YY;
						zz=ZZ;
						min_len = ln;
						side = sd;
						}
						
					}
		
		if(min_len < numeric_limits<float>::max())
		{
			
			bl[yy][xx][zz] = new AirBlock(bl[yy][xx][zz]->getX(),bl[yy][xx][zz]->getY(),bl[yy][xx][zz]->getZ());;
			}
		
		} else if(but == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		// cout << "Mouse clicked" << endl;
		
		float min_len = numeric_limits<float>::max();
		int side;
		int xx,yy,zz;
		
		for(int YY=0; YY < 20; YY++)
			for(int XX = 0; XX < 10; XX++)
				for(int ZZ = 0; ZZ < 10; ZZ++)
				{
					int sd = 0;
					float ln = 0;
					if(bl[YY][XX][ZZ]->IsSeeAtMe(cX,cY,cZ,rX,rY,rZ,&ln,&sd) && (ln < min_len && ln > 0))
						{
						xx=XX;
						yy=YY;
						zz=ZZ;
						min_len = ln;
						side = sd;
						}
						
					}
		
		if(min_len < numeric_limits<float>::max())
		{
			//cout << (bool) bl[yy-1][xx][zz]->isAir() << endl;
			switch(side)
			{
				case Block::SIDE_TOP:
					if(yy>0 && bl[yy-1][xx][zz]->isAir())
					{
						bl[yy-1][xx][zz] = new DirtBlock(bl[yy-1][xx][zz]->getX(),bl[yy-1][xx][zz]->getY(),bl[yy-1][xx][zz]->getZ());
						}
				break;
				case Block::SIDE_BOTTOM:
					if(yy<4 && bl[yy+1][xx][zz]->isAir())
					{
						bl[yy+1][xx][zz] = new DirtBlock(bl[yy+1][xx][zz]->getX(),bl[yy+1][xx][zz]->getY(),bl[yy+1][xx][zz]->getZ());
						}
				break;
				case Block::SIDE_RIGHT:
					if(xx<9 && bl[yy][xx+1][zz]->isAir())
					{
						bl[yy][xx+1][zz] = new DirtBlock(bl[yy][xx+1][zz]->getX(),bl[yy][xx+1][zz]->getY(),bl[yy][xx+1][zz]->getZ());
						}
				break;
				case Block::SIDE_LEFT:
					if(xx>0 && bl[yy][xx-1][zz]->isAir())
					{
						bl[yy][xx-1][zz] = new DirtBlock(bl[yy][xx-1][zz]->getX(),bl[yy][xx-1][zz]->getY(),bl[yy][xx-1][zz]->getZ());
						}
				break;
				case Block::SIDE_BACKWARD:
					if(zz<9 && bl[yy][xx][zz+1]->isAir())
					{
						bl[yy][xx][zz+1] = new DirtBlock(bl[yy][xx][zz+1]->getX(),bl[yy][xx][zz+1]->getY(),bl[yy][xx][zz+1]->getZ());
						}
				break;
				case Block::SIDE_FORWARD:
					if(zz>0 && bl[yy][xx][zz-1]->isAir())
					{
						bl[yy][xx][zz-1] = new DirtBlock(bl[yy][xx][zz-1]->getX(),bl[yy][xx][zz-1]->getY(),bl[yy][xx][zz-1]->getZ());
						}
				break;
				}
			
			}
		
		}
		
	}
	
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(20,20);
	

	glutCreateWindow("MineTest");

	glutIdleFunc(display);

	glutSetCursor(GLUT_CURSOR_NONE);
	glutPassiveMotionFunc(MouseMove);
	glutMouseFunc(ClickFunc);
	init();
	glLineWidth(4);

	Keyboard::ChangeStateListener(keyboardChange);
	Keyboard::init();


for(int I=0;I<10;I++)
{
	for(int J = 0; J<10;J++)
	{
		bl[15][I][J] =new DirtBlock(I,0,J);
		
		}
	}
	for(int L = 1; L<5; L++){
for(int I=0;I<10;I++)
{
	for(int J = 0; J<10;J++)
	{
		bl[15+L][I][J] =new StoneBlock(I,-L,J);
		}
	}
}
for(int L = 0; L<15; L++){
for(int I=0;I<10;I++)
{
	for(int J = 0; J<10;J++)
	{
		bl[L][I][J] =new AirBlock(I,15-L,J);
		}
	}
}

	glutMainLoop();

	return 0;
	}
