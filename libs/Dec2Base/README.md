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
         to 85. If it is less than or equal to 36 (from 0 to Z), it is not case sensitive 
		 (letters can be uppercase or lowercase).  
		 The string with the non-decimal digits according to the encoding proposed in 
		 [RFC 1924](https://www.rfc-editor.org/rfc/rfc1924):

`0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_´{|}~`
