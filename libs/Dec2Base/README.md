ENCODE AND DECODE TO ANY BASE
=============================

Exchange between any numbering systems.

 
Fuctions
--------

* `wxDecToBase(  n , base )`      Converts an integer decimal to any other base.
* `wxBaseToDec( "n", base )`      Converts a number (as string) from any base to decimal.


Arguments
---------

* `n`    is a decimal integer number; 
* `"n"`  is a string with the number in any other base. If the base is less than or 
         equal to 10, "n" can be a numeric data;
* `base` is an integer with the base to be exchanged. This is an optional parameter,
         default is 16 (hexadecimal numbering). It can be any number less than or equal 
         to 85. If it is less than or equal to 36 (from 0 to Z), it is not case sensitive 
         (letters can be uppercase or lowercase).

The string with the non-decimal digits according to the encoding proposed in 
[RFC 1924](https://www.rfc-editor.org/rfc/rfc1924):

`0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_´{|}~`


Example
-------

        Option Explicit
        Include "wxDecToBase.inc"
        
        Print "Decimal base:"
        Print wxDecToBase( 1999, 10 )
        Print wxBaseToDec( 1999, 10 )
        Print
        Print "Hexadecimal base (default base):"
        Print wxDecToBase( 255 )
        Print wxBaseToDec( "fF" )
        Print
        Print "Octal base:"
        Print wxDecToBase( 477, 8 )
        Print wxBaseToDec( 735, 8 )
        Print
        Print "Thirty-six base (top for not case sensitive):"
        Print wxDecToBase( 46655, 36 )
        Print wxBaseToDec( "ZzZ", 36 )
        Print
        Print "Eighty-five base (largest possible base):"
        Print wxDecToBase( 51998524, 85 )
        Print wxBaseToDec( "~v2S", 85 )
