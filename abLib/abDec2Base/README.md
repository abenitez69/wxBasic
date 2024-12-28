*abDec2Base*: Converts From/To Any Base
=======================================

Transforms a numerical value from one number system to another.


| Library description  | |
|:---------------------|:----------------------------------------------------|
| **Name:**            |  **abDec2Base.inc**                                     |
| **Version:**         |  3.2                                                |
| **Type:**            |  &#9673; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9675; Other |
| **Category:**        |  Numeric and string                                 |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9745; 2.08  &nbsp; &nbsp; &nbsp;  &#9745; 3.2  &nbsp; &nbsp; &nbsp;  &#9745; Console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9745; Linux  &nbsp; &nbsp; &nbsp;  &#9745; macOS  |


 
Syntax
------

* `abDecToBase(  n , base )    `    Returns a string in any numeric base from a number in decimal base.
* `abBaseToDec( "n", base )    `    Returns a decimal number from a string in any number base.


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
Include "abDecToBase.inc"

Print "Hexadecimal base (default base):"
Print abDecToBase( 255 )
Print abBaseToDec( "fF" )

Print "Octal base:"
Print abDecToBase( 477, 8 )
Print abBaseToDec( 735, 8 )

Print "Thirty-six base (top for not case sensitive):"
Print abDecToBase( 46655, 36 )
Print abBaseToDec( "ZzZ", 36 )

Print "Eighty-five base (largest possible base):"
Print abDecToBase( 51998524, 85 )
Print abBaseToDec( "~v2S", 85 )

