abMDParser
=============

Parses Markdown text and converts it to HTML, LaTeX and/or rich text format (RTF) documents.


| Library description   | |
|:---------------------|:----------------------------------------------------|
| **Files name:**      |  **abMD2HTML.inc**                                  |
|                      |  **abMD2RTF.inc**                                   |
|                      |  **abMD2TEX.inc**                                   |           
| **Version:**         |  3.2                                                |
| **Developer:**       | Agustín Benítez Hernández |
| **Type:**            |  &#9673; Functions  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9675; Script |
| **Category:**        |  String                |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9746; 2.5  &nbsp; &nbsp; &nbsp;  &#9746; 2.08  &nbsp; &nbsp; &nbsp;  &#9746; 3.2  |
| **wxBasic UI:** |  &#9746; CLI  &nbsp; &nbsp; &nbsp;  &#9746; GUI  &nbsp; &nbsp; &nbsp;  &#9746; CLI & wxWidgets   |
| **OS:**              |  &#9746; Windows  &nbsp; &nbsp; &nbsp;  &#9746; Linux  &nbsp; &nbsp; &nbsp;  &#9746; macOS  |

 
Syntax
------

Convert only the Markdown text and return:

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
* Aways returns a string, each line separated by `\n`.

**NOTE:** If `MD` is a list or table, one element per MD line; else if `MD` is a string, each line separated by `\n`.


Example
-------

```python
Option Explicit
Include "abMD2HTML.inc"
Include "abMD2RTF.inc"
Include "abMD2TEX.inc"

Dim x = [], fileHandle

fileHandle = fOpen( "demo.md", "r" )
    While Not EoF( fileHandle )
       x.Append( fGets( fileHandle ))
    End While
fClose( fileHandle )

fileHandle = fOpen( "demo1.html", "w" )
    fPuts( fileHandle, abMD2HTMLDoc( x ))
fClose( fileHandle )

fileHandle = fOpen( "demo2.html", "w" )
    fPuts( fileHandle, abMD2HTMLStyledDoc( x ))
fClose( fileHandle )

fileHandle = fOpen( "demo3.rtf", "w" )
    fPuts( fileHandle, abMD2RTFDoc( x ))
fClose( fileHandle )

fileHandle = fOpen( "demo4.tex", "w" )
    fPuts( fileHandle, abMD2TEXDoc( x ))
fClose( fileHandle )
```


