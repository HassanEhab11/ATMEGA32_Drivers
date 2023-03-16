
/*-------------------> BITMATH <-------------------*/
/*-------------------> SETTERS AND GETEERS <-------------------*/


#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

#define SET_BIT(VAR,BIT_NO)     (VAR|=(1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO)     (VAR&=(~(1<<BIT_NO)))
#define TOGGLE_BIT(VAR,BIT_NO)  (VAR^=(1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO)     ((VAR>>BIT_NO)&1)


#endif