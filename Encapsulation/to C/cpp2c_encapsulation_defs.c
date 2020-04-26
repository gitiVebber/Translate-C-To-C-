#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"
char* message=DEF_MSG ;

void void_Box_Box_double(Box* this,double dim)
{
	this->width=dim;
    	this->height=dim;
    	this->length=dim;
	void_print_Box(this);
}

void void_print_Box(Box* this)
{
    printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}

void void_Box_Box_double_double_double(Box* const this, double l, double w, double h)
{
    this->width = w;
    this->height = h;
    this->length = l;
    void_print_Box(this);
}

Box* Box_CopyBox_Box(Box* b,Box* other)
{
    b->width =other->width;
    b->height =other->height;
    b->length = other->length;
    return b; 
}
void void_dis_Box_Box(Box* this)
{
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

Box* Box_operator_equal_mult_Box_double(Box* t, double mult)
{
    t->width *= mult;
    t->height *= mult;
    t->length *= mult;
    return t;
}

Box* Box_operator_equal_(Box* this,const Box* const b)
{
    this->width = b->width;
    this->height = b->height;
    this->length = b->length;
    return this;
}

void void_Shelf_Shelf_(Shelf* this)
{
    Box b1;
    Box b2;
    Box b3;
    void_Box_Box_double(&b1,1);
    void_Box_Box_double(&b2,1);
    void_Box_Box_double(&b3,1);
    this->boxes[0]=b1;
    this->boxes[1]=b2;
    this->boxes[2]=b3;  
}
void void_dis_Shelf_Shelf(Shelf* this)
{
    int i=NUM_BOXES;
    for(;i>0; --i)
	void_dis_Box_Box(&this->boxes[i-1]);
}

void void_setBox_Shelf_int_Box_(Shelf* this,int index, const Box dims)
{
    this->boxes[index] = dims;
}

double double_getVolume_Shelf_(Shelf* this)
{
   double vol = 0;
   int i = 0;
      for (; i < NUM_BOXES; ++i)
           vol += this->boxes[i].width*this->boxes[i].height*this->boxes[i].length;
      return vol;
}

void void_print_Shelf_(Shelf* this) 
{
	printf("%s %f\n", message, double_getVolume_Shelf_(this));
}

