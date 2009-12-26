#include "LegShort.hpp"

LegShort::LegShort()//(GLfloat x, GLfloat y, GLfloat a, GLfloat b)
{	
	compShort0 = new LegCompShort();
	compShort1 = new LegCompShort();
	bone = new Bone(NULL, 0.f, 0.f, 0.f, 0, compShort0, "compShort0");
	
	bone->boneAddChild(0.f, 0, compShort1 , "compShort1 " );
	cout << "LegShort has been created!" << endl;
	
}

LegShort::~LegShort()
{
	delete compShort0;
	delete compShort1;
	delete bone;
	compShort0 = NULL;
	compShort1 = NULL;
	bone = NULL;
}
void LegShort::Draw()
{
	bone->animate(); ///////////////////////
	//	bone->animate_child(); ///////////////////////
	bone->Draw();
}


	