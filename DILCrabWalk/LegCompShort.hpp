/**
*
*	Klasa opisujaca model kr�tkiej sk�adowej nogi kraba
*
*
**/
#ifndef LEGCOMPSHORT_H
#define LEGCOMPSHORT_H

#include "glut.h"
#include "glutFunc.hpp"
#include "Drawable.hpp"

class LegCompShort
{
public:
	LegCompShort();
	~LegCompShort();

	void Draw(GLfloat x, GLfloat y, GLfloat z);
	void CreateList();

private:
	GLfloat w_;
	GLfloat h_;
	GLfloat d_;
};

#endif

