/**
*
*	Klasa opisujaca model kraba
*
*
**/
#ifndef BONE_H
#define BONE_H

#include <iostream>
#include <string>
#include "glut.h"
#include "glutFunc.hpp"

#include "Drawable.hpp"

enum{ FOR_ODD, BACK_ODD, FOR_EVEN, BACK_EVEN };
enum{ AN_IDLE, AN_UP_FRONT, AN_UP_REAR, AN_DOWN, AN_MOVE };

using namespace std;
class Bone
{
public:
	
	Bone(Bone* root, GLfloat x, GLfloat y, GLfloat a, int flag , Drawable *mesh, string name);
	~Bone();
	
	void boneAddChild(GLfloat a, int flag, Drawable *mesh, string name);
	void Draw();
	void animate(); 
	
	void animUpFront();
	void animUpRear();
	void animDown();
	void animMove();

	void anim_step_end();
	void anim_step_start();
	void anim_rear_step_start();
	void anim_rear_step_end();
	void animIdle();

private:
	Bone();

	GLfloat offsetA_;
	GLfloat childOffsetA_;
	GLfloat off_;

	GLfloat x_;
	GLfloat y_;

	GLfloat a_;
	GLfloat l_;

	int flag_;
	int animFlag_;
	//ROBOCZE
	static bool oddHit_;

	std::string name_;

	Bone *father_;
	Bone *child_;
	Drawable *mesh_;
	
};

#endif