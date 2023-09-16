#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(REG,BITNO) (REG |=  (1<<BITNO))
#define CLR_BIT(REG,BITNO) (REG &= ~(1<<BITNO))
#define TOG_BIT(REG,BITNO) (REG ^= (1<<BITNO) )
#define GET_BIT(REG,BITNO) ((REG >> (BITNO))&1)

#define SET_BITS(REG , VAL)       ((REG) |= (VAL))
#define CLR_BITS(REG , MSK)       ((REG) &= (MSK))
#define TOG_BITS(REG , MSK)       ((REG) ^= (MSK))
#define SET_ALL_BITS(REG)         ((REG) = (0xFFFFFFFF))
#define CLR_ALL_BITS(REG)         ((REG) = (0U) )
#define TOG_ALL_BITS(REG)         ((REG) = ~(REG))

#define NULL_PTR ((void *)0)
#define PUT_ONS(  _FROM_   ,   _TO_   )         ( (  u32  )( ( ( 2 << ( ( _TO_ ) - ( _FROM_ ) ) ) - 1 ) << ( _FROM_ ) ) )
#define PUT_ZEROS(  _FROM_  ,  _TO_ )           ( ~PUT_ONS(  _FROM_   ,   _TO_   )  )

#endif
