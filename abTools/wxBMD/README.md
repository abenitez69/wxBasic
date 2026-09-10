BMD and wxBMD
================

*Basic Markdown Documentation* (**BMD**) is a lightweight markup language used to document the wxBasic programming 
language, modules, and programs; using Markdown markup language.

BMD is designed to be a simple, clean markup language with just enough syntax to be useful. Some of its goals are:

* Easy to parse;
* Easy to convert to other formats, such as Markdown, HTML, Rich Text Format (RTF), or LaTeX, through `Save as` option on right-click menu
* Easy to incorporate sample code;
* Easy to read without a BMD parser (i.e., in its source-code form);
* Easy to write.


| Script description   | |
|:---------------------|:----------------------------------------------------|
| **Name:**            |  wxBMD.wxb                                          |
| **Version:**         |  3.4                                                |
| **Type:**            |  &#9675; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9673; Script |
| **Category:**        |  System                                 |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9745; 2.08  &nbsp; &nbsp; &nbsp;  &#9745; 3.2  &nbsp; &nbsp; &nbsp;  &#9744; Console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9745; Linux  &nbsp; &nbsp; &nbsp;  &#9745; macOS  |



 
wxBMD Syntax
------------

&nbsp;&nbsp;&nbsp; `wxBMD <script.wxb> | <library.inc>   ` Open a wxBasic file.

BMD Syntax
----------

* The BMD parser assumes that all initial lines beginning with consecutive wxBasic comments (`'` or `//`)  containing BMD documentation.
* BMD documentation ends when the first uncommented line appears. Any subsequent content is ignored by the parser.
* Any indentation to the left of the comment symbol is ignored.
* The indentation to the right of the comment symbol is ignored, if it is the same on all lines. Additional indentation on one or more specific lines is considered part of the Markdown code (in a code blocks or a nest list).


Remarks
-------

* The `source` is a name of file corresponds to the wxBasic script to be "compiled". The extension can be omitted.
* The `iconfile` is the name of the file that corresponds to the icon that will be used in the application. The icon filename is optional. If omitted, two things can happen:
    - If an icon file exists in the same folder as `source` and with the same name, it will be used.
    - Otherwise, the executable retains the wxBasic virtual machine default icon.

