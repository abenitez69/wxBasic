*abStdIO*: Standard Input/Output via console
============================================

Produces input and output through the operating system standard console.


| Library description  | |
|:---------------------|:----------------------------------------------------|
| **Name:**            |  **abStdIO.inc**                                     |
| **Version:**         |  5.0                                                |
| **Type:**            |  &#9673; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9675; Other |
| **Category:**        |  System                                 |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9745; 2.08  &nbsp; &nbsp; &nbsp;  &#9745; 3.2  &nbsp; &nbsp; &nbsp;  &#9745; Console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9745; Linux  &nbsp; &nbsp; &nbsp;  &#9641; macOS  |


 
Syntax
------

* `abStdIO(  commands )      `    Execute a sequence of comma-separated commands.
* `x = abStdIO(  commands )  `    Returns one or more inputs from the standard console.


Commands list
-------------

* `abSTD_PRINT, "text" `  &nbsp; &nbsp;  Writes a text to the system console. 
* `abSTD_CLEAR         `  &nbsp; &nbsp;  Clear the system console. 
* `abSTD_PAUSE         `  &nbsp; &nbsp;  Suspends processing and waits for a key to resume. 
* `abSTD_DELAY, n      `  &nbsp; &nbsp;  Suspends processing and waits n seconds before resuming.
* `abSTD_INPUT, "label"`  &nbsp; &nbsp;  Returns input from the system console.


Remark
------

* `n`    is a decimal integer number; 
* `"n"`  is a string with the number in any other base. If the base is less than or 
         equal to 10, "n" can be a numeric data;
* `base` is an integer with the base to be exchanged. This is an optional parameter,
         default is 16 (hexadecimal numbering). It can be any number less than or equal 
         to 85. If it is less than or equal to 36 (from 0 to Z), it is not case sensitive 
         (letters can be uppercase or lowercase).


Example
-------

```python
Option Explicit
Include "abStdIO.inc"

Dim Name = abStdIO( abSTD_PRINT, "-------------------------",
                    abSTD_PRINT, "  STANDARD INPUT-OUTPUT  ",
                    abSTD_PRINT, "-------------------------",
                    abSTD_PRINT, "",
                    abSTD_PRINT, "Please wait 5 seconds",
                    abSTD_DELAY, 5,
                    abSTD_CLEAR,
                    abSTD_INPUT, "Your name:", "",
                    "Thank you for using this library", "",
                    abSTD_PAUSE )

Print "Your name is "; Name
```
