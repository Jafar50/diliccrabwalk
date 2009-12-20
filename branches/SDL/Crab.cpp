#include "Crab.hpp"

#include <iostream>
using namespace std;
//extern GLfloat nRange;

Crab::Crab() : w_(20.0f), h_(2.0f), d_(8.0f)
{	
	CreateList();

	LegShort* leg_sh = new LegShort();
	LegNormal* leg_nor = new LegNormal();
	for(int i = 0; i < 2; i++)
		legs.push_back(leg_sh);
	for(int i = 0; i < 8; i++)
		legs.push_back(leg_nor);

	cout << "Crab has been created!" << endl;
	
}

void Crab::CreateList()
{
		GLfloat cube_diffuse[]   = { 0.0, 0.7, 0.7, 1.0 };
				glMaterialfv( GL_FRONT, GL_DIFFUSE, cube_diffuse );

	glNewList(CRAB, GL_COMPILE);
				glBegin(GL_TRIANGLE_STRIP);
					//upper
					glVertex3f(w_/2,h_/2,d_/2);
					glVertex3f(w_/2,h_/2,-d_/2);
					glVertex3f(-w_/2,h_/2,d_/2);
					glVertex3f(-w_/2,h_/2,-d_/2);
				glEnd();
				glBegin(GL_TRIANGLE_STRIP);				
					//front
					glVertex3f(-w_/2,h_/2,d_/2);
					glVertex3f(-w_/2,-h_/2,d_/2);
					glVertex3f(w_/2,h_/2,d_/2);
					glVertex3f(w_/2,-h_/2,d_/2);
				glEnd();
					//bottom
				glBegin(GL_TRIANGLE_STRIP);
					glVertex3f(w_/2,-h_/2,d_/2);
					glVertex3f(-w_/2,-h_/2,d_/2);
					glVertex3f(w_/2,-h_/2,-d_/2);
					glVertex3f(-w_/2,-h_/2,-d_/2);	
				glEnd();
				glBegin(GL_TRIANGLE_STRIP);
					//rear
					glVertex3f(-w_/2,-h_/2,-d_/2);				
					glVertex3f(-w_/2,h_/2,-d_/2);
					glVertex3f(w_/2,-h_/2,-d_/2);
					glVertex3f(w_/2,h_/2,-d_/2);
				glEnd();	
				glBegin(GL_TRIANGLE_STRIP);
					//left
					glVertex3f(-w_/2,h_/2,-d_/2);				
					glVertex3f(-w_/2,-h_/2,-d_/2);
					glVertex3f(-w_/2,h_/2,d_/2);
					glVertex3f(-w_/2,-h_/2,d_/2);
				glEnd();	
				glBegin(GL_TRIANGLE_STRIP);
					//right
					glVertex3f(w_/2,h_/2,d_/2);				
					glVertex3f(w_/2,-h_/2,d_/2);
					glVertex3f(w_/2,h_/2,-d_/2);
					glVertex3f(w_/2,-h_/2,-d_/2);
				glEnd();	
		glEndList();

		cout << "List CRAB created" << endl;
}

void Crab::drawLegs()
{
	static GLfloat leg_interval = w_/5.0f;
	
	for(int a = -2, i = 0; i < 10; a++, i++ )
	{
		glPushMatrix();
		glTranslatef(leg_interval*a,-h_/4, d_/2);
		glRotatef(-90.0f, 0.0, 1.0, 0.0);
		legs[i++]->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(leg_interval*a,-h_/4, -d_/2);
		glRotatef(90.0f, 0.0, 1.0, 0.0);
		legs[i]->Draw();
		glPopMatrix();
	}	
	

}

void Crab::Draw(GLfloat x, GLfloat y, GLfloat z)
{
//	int x=0,y=0,z =0;
	GLfloat cube_diffuse[]   = { 0.0, 0.7, 0.7, 1.0 };
	//  Show when are displaying an object
	cout << "Displaying object...\n" << endl;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//begin drawing crab torso
	glPushMatrix();
				glTranslatef( x, y, z );
				glCallList(CRAB);
				glPushMatrix();
					drawLegs();	
				glPopMatrix();
	glPopMatrix();
}
