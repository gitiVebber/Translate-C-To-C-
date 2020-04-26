#include <stdio.h>
#include "cpp2c_inheritance_defs.h"

const char* ptrChar_getName_Types_(enum Types type)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    return names[type];
}
void init_Material_t_Material_t_Types_(Material_t* this,enum Types mat)
{
	this->material=mat;
    printf("Material created, set to %s\n", ptrChar_name_Material_t(this));
}

void copyMaterial_t_Material_t_Material_t_(Material_t* this,Material_t* other)
{
	other->material=this->material;
}
const char* ptrChar_name_Material_t(Material_t* this) 
{ 
	return ptrChar_getName_Types_(this->material); 
}

void void_PhysicalBox_PhysicalBox_double_double_double_(PhysicalBox* this,double l, double w, double h)
{
	void_PhysicalBox_PhysicalBox_double_double_double_Types_(this,l,w,h,OTHER);
}

void void_PhysicalBox_PhysicalBox_double_double_double_Types_(PhysicalBox* this,double l, double w, double h,enum Types t)
{
	void_Box_Box_double_double_double(&this->box,l,w,h);
    init_Material_t_Material_t_Types_(&this->material,t);
    void_printp_ptrPhysicalBox(this);
}

void void_PhysicalBox_PhysicalBox_Materials(PhysicalBox* this,enum Types t)
{
   init_Material_t_Material_t_Types_(&this->material,t);
   void_Box_Box_double(&this->box,1);
   void_printp_ptrPhysicalBox(this);
}

PhysicalBox* ptrPhysicalBox_copyPhysicalBox_PhysicalBox_(PhysicalBox* this,PhysicalBox* other)
{
	copyMaterial_t_Material_t_Material_t_(&this->material,&other->material);
    Box_CopyBox_Box(&this->box,&other->box);
    return this;
}

PhysicalBox* PhysicalBox_operator_equal_(PhysicalBox* this,PhysicalBox* const other)
{
	ptrPhysicalBox_copyPhysicalBox_PhysicalBox_(this,other);
    return this;
}

void void_des_PhysicalBox_PhysicalBox_(PhysicalBox* this)
{
	printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->box.length, this->box.width, this->box.height, ptrChar_name_Material_t(&this->material));
    void_dis_Box_Box(&this->box);
}

void void_printp_ptrPhysicalBox(PhysicalBox* this)
{
	printf("PhysicalBox, made of %s; ", ptrChar_name_Material_t(&this->material));
	void_print_Box(&this->box);	
}
