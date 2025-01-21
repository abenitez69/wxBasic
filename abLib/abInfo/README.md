*abInfo*: Get system information
================================

Produces input and output through the operating system standard console.


| Library description  | |
|:---------------------|:----------------------------------------------------|
| **Name:**            |  **abInfo.inc**                                     |
| **Version:**         |  1.5                                                |
| **Type:**            |  &#9673; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9675; Other |
| **Category:**        |  System                                 |
| **wxBasic version:** |  &#9745; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9745; 2.08  &nbsp; &nbsp; &nbsp;  &#9745; 3.2  &nbsp; &nbsp; &nbsp;  &#9745; Console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9745; Linux  &nbsp; &nbsp; &nbsp;  &#9745; macOS  |


 
Syntax
------

* `abGetVersion()    `    Returns the virtual machine version in unified format.
* `abIsWindows()     `    Returns `true` if the operating system is *Microsoft Windows*.
* `abIsConsole()     `    Returns `true` if it is a virtual machine for *CLI*.



Remark
------

* The `WXBASIC_VERSION` constant returns the virtual machine version in different formats.
  In early versions, the 'micro' version number is represented by a letter (for example 
  0.61a or 2.2h). Later, a 4-number system was adopted: 'major.minor.micro.phase' (for 
  example 2.08.01.17 or 3.2.5.52). However, versions 2.8.x.x include a zero in front of 
  the 'minor', 'micro' and 'phase' numbers when they are less than 10.
* The `abGetVersion()` function unifies all these formats and allows numerical comparisons 
  by nesting the functions `Val(abGetVersion())`. In this case it returns a real number 
  as: 'major.minor'


Example
-------

```python
Option Explicit
Include "abInfo.inc"

Print "wxBasic " & abGetVersion()

Print "OS: \t";
If abIsWindows() Then : Print "Microsoft Windows"
                 Else : Print "Linux/UNIX" : End If

Print "UI: \t";
If abIsConsole() Then : Print "CLI"
                 Else : Print "GUI" : End If

Print "Bin: \t";
If abIsConsole() Then : Print "bvmc"; : Else : Print "wxbasic"; : End If
If abIsWindows() Then : Print ".exe"  : Else : Print "" : End If
```
