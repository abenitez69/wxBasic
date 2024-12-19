*Dec2Base*: Converts From/To Any Base
=====================================

Transforms a numerical value from one number system to another.


| Library description  | |
|:---------------------|:----------------------------------------------------|
| **Name:**            |  Dec2Base                                           |
| **Version:**         |  3.2                                                |
| **Type:**            |  &#9673; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9675; Other |
| **Category:**        |  Numeric and string                                 |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9745; 2.8  &nbsp; &nbsp; &nbsp;  &#9745; 3.5  &nbsp; &nbsp; &nbsp;  &#9745; console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9745; Linux  &nbsp; &nbsp; &nbsp;  &#9745; MacOS  |


 
Syntax
------

* `wxDecToBase(  n , base )    `    Returns a string in any numeric base from a number in decimal base.
* `wxBaseToDec( "n", base )    `    Returns a decimal number from a string in any number base.


Remark
------

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

```python
Option Explicit
Include "wxDecToBase.inc"

Print "Hexadecimal base (default base):"
Print wxDecToBase( 255 )
Print wxBaseToDec( "fF" )

Print "Octal base:"
Print wxDecToBase( 477, 8 )
Print wxBaseToDec( 735, 8 )

Print "Thirty-six base (top for not case sensitive):"
Print wxDecToBase( 46655, 36 )
Print wxBaseToDec( "ZzZ", 36 )

Print "Eighty-five base (largest possible base):"
Print wxDecToBase( 51998524, 85 )
Print wxBaseToDec( "~v2S", 85 )
