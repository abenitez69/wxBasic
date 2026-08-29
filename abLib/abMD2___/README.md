*abMD2___*: Parse From Markdown To Other...
=========================================

Parse from Markdown and convert to HTML, LaTeX and/or Rich Text Format (RTF).


| Library description  | |
|:---------------------|:----------------------------------------------------|
| **Names:**           |  **abMD2HTML.inc**                                  |
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

* `abMD2HTMLDoc( MD )        `    Return basic HTML document.
* `abMD2HTMLStyledDoc( MD )  `    Return styled HTML document.
* `abMD2RTFDoc( MD )         `    Return LaTeX document.
* `abMD2TEXDoc( MD )         `    Return Rich Text Format (RTF) document.


Remark
------

* `MD`    is a string, list, or table containing text in Markdown markup language.  

**NOTE:** If `MD` is a list or table, one element per MD line; else if `MD` is a string, each line separated by `\n`.


Example
-------

```python
Option Explicit
Include "abUTF8ToANSI.inc"

Print abUTF8ToANSI("ÁÉÍÓÚÜÑ áéíóúüñ ¿¡")
```


