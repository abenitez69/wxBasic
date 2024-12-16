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
* `"n"`  is a string with the number in any other base;
* `base` is an integer with the base to be exchanged. This is an optional parameter,
         default is 16 (hexadecimal numbering). It can be any number less than or equal 
         to 85 and the digits according to the encoding proposed in RFC 1924:


`0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_´{|}~`

> If `base` is less than or equal to 36 (from 0 to Z), is case insensitive (the letters can be 
either uppercase or lowercase). 
