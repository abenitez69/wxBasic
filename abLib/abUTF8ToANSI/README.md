*abUTF8ToANSI*: Converts From UTF-8 To ANSI Encode
=================================================

Transforms a string as UTF-8 encoding into Windows-1252 encoding (aka *ANSI* code page).


| Library description  | |
|:---------------------|:----------------------------------------------------|
| **Name:**            |  **abUTF8ToANSI.inc**                                   |
| **Version:**         |  1.5                                                |
| **Type:**            |  &#9673; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9675; Other |
| **Category:**        |  String                                 |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9745; 2.08  &nbsp; &nbsp; &nbsp;  &#9745; 3.2  &nbsp; &nbsp; &nbsp;  &#9745; Console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9745; Linux  &nbsp; &nbsp; &nbsp;  &#9745; macOS  |


 
Syntax
------

* `abUTF8ToANSI( StrUTF8 )    `    Returns a string encoded as Windows-1252 (aka ANSI) from a string encoded as UTF-8.


Remark
------

* `StrUTF8`    is a string encoded as UTF-8  

**NOTE:** Although UTF-8 encoding allows the representation of more than 143,000 Unicode characters, 
only the 256 corresponding to Windows-1252 (aka ANSI) encoding are supported.

Due to its similarity to *Windows-1252* encoding, the following codes can be accepted:

* *ISO-8859-1* (aka *Latin 1*)
* *ISO-8859-15* (aka *Latin 9*), €ŠšŽžŒœ


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


