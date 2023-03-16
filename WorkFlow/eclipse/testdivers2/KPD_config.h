/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : HAL        *********************/
/******************    SWC(Driver): KPD        *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


#define KPD_ROW_PORT   DIO_u8PORTB
#define KPD_COL_PORT   DIO_u8PORTB

#define KPD_ARR_VAL       {{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'c',0,'=','+'}}

#define KPD_ROW_0_PIN    DIO_u8PIN0
#define KPD_ROW_1_PIN    DIO_u8PIN1
#define KPD_ROW_2_PIN    DIO_u8PIN2
#define KPD_ROW_3_PIN    DIO_u8PIN3

#define KPD_COL_0_PIN    DIO_u8PIN4
#define KPD_COL_1_PIN    DIO_u8PIN5
#define KPD_COL_2_PIN    DIO_u8PIN6
#define KPD_COL_3_PIN    DIO_u8PIN7


#endif
