#include "Crab.hpp"

#include <iostream>
using namespace std;

extern bool anim_toggle;

Crab::Crab() : w_(20.0f), h_(3.0f), d_(8.0f)
{	
	// Stworz liste
	CreateList();
	CreateStaticList();
	// Dodaj nogi do korpusu
	leg_sh = new LegShort();
	leg_for_even = new LegNormal(FRONT_EVEN);
	leg_for_odd = new LegNormal(FRONT_ODD);
	leg_back_even = new LegNormal(REAR_EVEN);
	leg_back_odd = new LegNormal(REAR_ODD);

	for(int i = 0; i < 2; i++)
		legs.push_back(leg_sh);
	for(int i = 0; i < 2; i++){
		legs.push_back(leg_for_even);
		legs.push_back(leg_back_even);
		legs.push_back(leg_for_odd);
		legs.push_back(leg_back_odd);
	}
 	cout << "Crab stworzony!" << endl;
	
}

Crab::~Crab()
{
	delete leg_sh;
	delete leg_for_even;
	delete leg_for_odd;
	delete leg_back_even;
	delete leg_back_odd;

	legs.clear();
	
}

void Crab::sharedCrabList()
{
				//prawa strona
				glBegin(GL_TRIANGLE_STRIP);				
					glNormal3f(0.0f, 0.0f, -1.0f);
					glTexCoord2f(0.6f, 1.0f); glVertex3f(-w_/2,h_/2,d_/2); 
					glTexCoord2f(0.5f, 1.0f); glVertex3f(-w_/2,-h_/2,d_/2); 
					glTexCoord2f(0.6f, 0.0f); glVertex3f(w_/2,h_/2,d_/2); 
					glTexCoord2f(0.5f, 0.0f); glVertex3f(w_/2,-h_/2,d_/2); 
				glEnd();
				//dol
				glBegin(GL_TRIANGLE_STRIP);
					glNormal3f(0.0f, -1.0f, 0.0f);
					glTexCoord2f(1.0f, 1.0f); glVertex3f(w_/2,-h_/2,d_/2);
					glTexCoord2f(0.7f, 1.0f); glVertex3f(-w_/2,-h_/2,d_/2);
					glTexCoord2f(1.0f, 0.0f); glVertex3f(w_/2,-h_/2,-d_/2);
					glTexCoord2f(0.7f, 0.0f); glVertex3f(-w_/2,-h_/2,-d_/2);	
				glEnd();
				//lewa strona
				glBegin(GL_TRIANGLE_STRIP);
					glNormal3f(0.0f, 0.0f, 1.0f);
					glTexCoord2f(0.6f, 1.0f); glVertex3f(-w_/2,-h_/2,-d_/2);				
					glTexCoord2f(0.5f, 1.0f); glVertex3f(-w_/2,h_/2,-d_/2);
					glTexCoord2f(0.6f, 0.0f); glVertex3f(w_/2,-h_/2,-d_/2);
					glTexCoord2f(0.5f, 0.0f); glVertex3f(w_/2,h_/2,-d_/2);
				glEnd();	
				//przod
				glBegin(GL_TRIANGLE_STRIP);
					glNormal3f(-1.0f, 0.0f, 0.0f);
					glTexCoord2f(0.7f, 1.0f); glVertex3f(-w_/2,h_/2,-d_/2);				
					glTexCoord2f(0.6f, 1.0f); glVertex3f(-w_/2,-h_/2,-d_/2);
					glTexCoord2f(0.7f, 0.5f); glVertex3f(-w_/2,h_/2,d_/2);
					glTexCoord2f(0.6f, 0.5f); glVertex3f(-w_/2,-h_/2,d_/2);
				glEnd();	
				//tyl
				glBegin(GL_TRIANGLE_STRIP);
					glNormal3f(1.0f, 0.0f, 0.0f);
					glTexCoord2f(0.7f, 0.5f); glVertex3f(w_/2,h_/2,d_/2);				
					glTexCoord2f(0.6f, 0.5f); glVertex3f(w_/2,-h_/2,d_/2);
					glTexCoord2f(0.7f, 0.0f); glVertex3f(w_/2,h_/2,-d_/2);
					glTexCoord2f(0.6f, 0.0f); glVertex3f(w_/2,-h_/2,-d_/2);
				glEnd();	

}

void Crab::CreateList()
{

	glNewList(CRAB, GL_COMPILE);
		GLfloat no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
    	GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
    	GLfloat mat_ambient_color[] = {0.8f, 0.8f, 0.2f, 1.0f};
    	GLfloat mat_diffuse[] = {0.6f, 0.6f, 0.6f, 1.0f};
    	GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    	GLfloat no_shininess = 0.0f;
    	GLfloat low_shininess = 5.0f;
    	GLfloat high_shininess = 100.0f;
    	
   
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
        glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);



				glBindTexture(GL_TEXTURE_2D, 1);
				//gora
				for(int x=0; x<w_/4; x++) {
					for(int y=0; y<d_/4; y++) {			
					glBegin(GL_TRIANGLE_STRIP);				
						glNormal3f(0.0f, 1.0f, 0.0f);				
						glTexCoord2f(0.5f-0.25f*(y), 1.0f-0.2*(x)); glVertex3f((w_/2)-4.f*(x), h_/2, (d_/2)-4.f*(y)); 
						glTexCoord2f(0.5f-0.25f*(y+1), 1.0f-0.2*(x)); glVertex3f((w_/2)-4.f*(x),h_/2, (d_/2)-4.f*(y+1));
						glTexCoord2f(0.5f-0.25f*(y), 1.0f-0.2*(x+1)); glVertex3f((w_/2)-4.f*(x+1), h_/2, (d_/2)-4.f*(y)); 
						glTexCoord2f(0.5f-0.25f*(y+1), 1.0f-0.2*(x+1)); glVertex3f((w_/2)-4.f*(x+1), h_/2, (d_/2)-4.f*(y+1)); 
					glEnd();
					}
				}
				sharedCrabList();
		glEndList();

		cout << "Lista CRAB stworzona" << endl;
}

void Crab::CreateStaticList()
{
	glNewList(STATIC_CRAB, GL_COMPILE);
			GLfloat no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
    		GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
    		GLfloat mat_ambient_color[] = {0.8f, 0.8f, 0.2f, 1.0f};
    		GLfloat mat_diffuse[] = {0.6f, 0.6f, 0.6f, 1.0f};
    		GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    		GLfloat no_shininess = 0.0f;
    		GLfloat low_shininess = 5.0f;
    		GLfloat high_shininess = 100.0f;
	    	
	   
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
			glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
			glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);



			glBindTexture(GL_TEXTURE_2D, 4);
			//gora
			glBegin(GL_TRIANGLE_STRIP);					
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.5f, 1.0f); glVertex3f(w_/2,h_/2,d_/2); 
				glTexCoord2f(0.0f, 1.0f); glVertex3f(w_/2,h_/2,-d_/2);
				glTexCoord2f(0.5f, 0.0f); glVertex3f(-w_/2,h_/2,d_/2); 
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-w_/2,h_/2,-d_/2); 
			glEnd();
				
			sharedCrabList();
		glEndList();

		cout << "Lista STATIC CRAB stworzona" << endl;

}

void Crab::DrawLegs()
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


void Crab::StaticDrawLegs()
{
	static GLfloat leg_interval = w_/5.0f;
	
	for(int a = -2, i = 0; i < 10; a++, i++ )
	{
		glPushMatrix();
		glTranslatef(leg_interval*a,-h_/4, d_/2);
		glRotatef(-90.0f, 0.0, 1.0, 0.0);
		legs[i++]->StaticDraw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(leg_interval*a,-h_/4, -d_/2);
		glRotatef(90.0f, 0.0, 1.0, 0.0);
		legs[i]->StaticDraw();
		glPopMatrix();
	}	
}

void Crab::toggleAnim()
{

}

void Crab::Draw(GLfloat x, GLfloat y, GLfloat z)
{
	if(anim_toggle)
	{
		leg_for_even->animToggle();
		anim_toggle = false;
	}
	GLfloat cube_diffuse[]   = { 0.0, 0.7, 0.7, 1.0 };
		
	// Wyrysuj korpus ukladu 
	glPushMatrix();
				glTranslatef( x, y, z );
				glCallList(CRAB);
				glPushMatrix();
					// Wyrysuj nogi
					DrawLegs();	
				glPopMatrix();
	glPopMatrix();
}

void Crab::StaticDraw(GLfloat x, GLfloat y, GLfloat z, GLfloat roty)
{
	if(anim_toggle)
	{
		leg_for_even->animToggle();
		anim_toggle = false;
	}
	GLfloat cube_diffuse[]   = { 0.0, 0.7, 0.7, 1.0 };
		
	// Wyrysuj korpus ukladu 
	glPushMatrix();
				glRotatef(180.f, 1.0f, 0.0f, 0.0f);
				glTranslatef( -x, -y - 2.5f, -z );
				glRotatef(roty, 0.0f, 1.0f, 0.0f);
				glCallList(STATIC_CRAB);
				glPushMatrix();
					// Wyrysuj nogi
					StaticDrawLegs();	
				glPopMatrix();
	glPopMatrix();
}
