*abMD2___*: Parse From Markdown To Other...
=========================================

Transforms a string as UTF-8 encoding into Windows-1252 encoding (aka *ANSI* code page).


| Library description  | |
|:---------------------|:----------------------------------------------------|
| **Names:**            |  **abMD2HTML.inc**                                  |
|                      |  **abMD2RTF.inc**                                   |
|                      |  **abMD2TEX.inc**                                   |
| **Version:**         |  3.2                                                |
| **Type:**            |  &#9673; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9675; Other |
| **Category:**        |  String                                 |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9745; 2.08  &nbsp; &nbsp; &nbsp;  &#9745; 3.2  &nbsp; &nbsp; &nbsp;  &#9745; Console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9745; Linux  &nbsp; &nbsp; &nbsp;  &#9745; macOS  |


 
Syntax
------

Convert only the Markdown text an return:

* `abMD2HTML( MD )        `    to HTML.
* `abMD2TEX( MD )         `    to LaTeX.
* `abMD2RTF( MD )         `    to Rich Text Format (RTF).

or it generates a full document, including headers or preambles with font and color definitions, necessary packages, styles, and character encoding type:

* `abMD2HTMLDoc( MD )        `    basic HTML document.
* `abMD2HTMLStyledDoc( MD )  `    styled HTML document.
* `abMD2RTFDoc( MD )         `    LaTeX document.
* `abMD2TEXDoc( MD )         `    Rich Text Format (RTF) document.


Remark
------

* `StrUTF8`    is a string encoded as UTF-8  

**NOTE:** Although UTF-8 encoding allows the representation of more than 143,000 Unicode characters, 
only the 256 corresponding to Windows-1252 (aka ANSI) encoding are supported.

Due to its similarity to *Windows-1252* encoding, the following codes can be accepted:

* *ISO-8859-1* (aka *Latin 1*)
* *ISO-8859-15* (aka *Latin 9*), except for the characters: €, Š, š, Ž, ž, Œ, and œ


Example
-------

```python
Option Explicit
Include "abUTF8ToANSI.inc"

Print abUTF8ToANSI("ÁÉÍÓÚÜÑ áéíóúüñ ¿¡")
```


