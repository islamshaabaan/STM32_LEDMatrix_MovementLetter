#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_


typedef unsigned char                    u8 ;
typedef unsigned short int               u16 ;
typedef unsigned long int                u32 ;
typedef unsigned long long int           u64 ;

typedef signed char                     s8 ;
typedef signed short int                s16 ;
typedef signed long int                 s32 ;
typedef signed long long int            s64 ;

typedef   float                         f32;
typedef   double                        f64 ;

enum    ErrorState
{
    STD_TYPES_NOK,
    STD_TYPES_OK
}; 

#endif
