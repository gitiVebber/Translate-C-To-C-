#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__
#endif

#include "cpp2c_encapsulation_defs.h"


typedef struct
{
    enum Types
   {
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
   }t;
char dami;
}Materials;

typedef struct
{
   Materials materials;
   enum Types material;
} Material_t;
const char* ptrChar_getName_Types_(enum Types type);

void init_Material_t_Material_t_Types_(Material_t* this,enum Types mat);
void copyMaterial_t_Material_t_Material_t_(Material_t* this,Material_t* other);
const char* ptrChar_name_Material_t(Material_t* this);

typedef struct 
{
  Box box;
  Material_t material;
}PhysicalBox;

void void_PhysicalBox_PhysicalBox_double_double_double_(PhysicalBox* this,double l, double w, double h);
void void_PhysicalBox_PhysicalBox_double_double_double_Types_(PhysicalBox* this,double l, double w, double h,enum Types t);
void void_PhysicalBox_PhysicalBox_Materials(PhysicalBox* this,enum Types t);
PhysicalBox* ptrPhysicalBox_copyPhysicalBox_PhysicalBox_(PhysicalBox* this,PhysicalBox* other);
void void_printp_ptrPhysicalBox(PhysicalBox* this);
void void_des_PhysicalBox_PhysicalBox_(PhysicalBox* this);
PhysicalBox* PhysicalBox_operator_equal_(PhysicalBox* this,PhysicalBox* const other);
