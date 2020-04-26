#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__
#endif
#include <stdbool.h>
#define NUM_BOXES 3
#define DEF_MSG "The total volume held on the shelf is"
extern char*  message;


typedef struct 
{
double width;
double height;
double length;
}Box;
void void_Box_Box_double(Box* this,double dim);
void void_Box_Box_double_double_double(Box* const this, double l, double w, double h);
Box* Box_CopyBox_Box(Box* b ,Box* o);
void void_print_Box(Box* this);
void void_dis_Box_Box(Box* this);
Box* Box_operator_equal_mult_Box_double(Box* t,double mult);
Box* Box_operator_equal_(Box* this,const Box* const b);

typedef struct
{
Box boxes[NUM_BOXES];
}Shelf;
void void_Shelf_Shelf_(Shelf* this);
void void_dis_Shelf_Shelf(Shelf* this);
void void_setBox_Shelf_int_Box_(Shelf* this,int index, const Box dims);
double double_getVolume_Shelf_(Shelf* this);
void void_print_Shelf_(Shelf* this);







