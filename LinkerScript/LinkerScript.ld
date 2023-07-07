/*
    @file   LinkerScript.ld
    @author Hassan Ehab
    @brief  Linker script for STM32F401x Device from STM32F4 series
*/

/* Highest address of the user mode stack */
_estack = ORIGIN(SRAM) + LENGTH(SRAM); /* End of "RAM" Ram type memory */

_Min_Heap_Size = 0x200 ;  /* Required amount of heap */
_Min_Stack_Size = 0x400 ; /* Required amount of stack */

MEMORY
{
    SRAM  (xrw) : ORIGIN = 0x20000000, LENGTH = 64K
    FLASH (rw)  : ORIGIN = 0x08000000, LENGTH = 256K
}

SECTIONS
{
    /* The startup code into "FLASH" Rom type memory */
     .isr_vector :
     {
       . = ALIGN(4);
       *(.isr_vector)
       . = ALIGN(4);
     } >FLASH

    .text :
    {
        . = ALIGN(4);
          _stext = .;
        *(.text)
        *(.text*)
        . = ALIGN(4);
        _etext = .;
    } >FLASH

     .rodata :
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
        _erodata = .;
    } >FLASH

     _sidata = LOADADDR(.data); /* to know the address of .data section in flash or i can use _erodata*/
    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _edata = .;
        
    } >SRAM AT>FLASH

        .bss :
    {
        . = ALIGN(4);
        _sbss = .;                  /* Define a global symbol at bss start */
        *(.bss)
        *(.bss*)
        . = ALIGN(4);
        _ebss = .;                  /* Define a global symbol at bss end */
    } >SRAM

   

    /*** I DON'T ANDERSTAND THIS SECTION **********/
    /* .User_heap_stack section, used to check that there is enough "RAM" Ram  type memory left */
  ._user_heap_stack :
  {
    . = ALIGN(8);
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
  } >SRAM

 

}

