abNativeOut
===========

Encodes strings from UTF-8 to the native encoding of the operating system or user interface.

| Script description   | |
|:---------------------|:----------------------------------------------------|
| **File name:**       |  abNativeOut.inc                                          |
| **Version:**         |  5.8                                                |
| **Developer:**       | Agustín Benítez Hernández |
| **Type:**            |  &#9673; Functions  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9675; Script |
| **Category:**        |  String                |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9746; 2.5  &nbsp; &nbsp; &nbsp;  &#9746; 2.08  &nbsp; &nbsp; &nbsp;  &#9746; 3.2  |
| **wxBasic UI:** |  &#9746; CLI  &nbsp; &nbsp; &nbsp;  &#9746; GUI  &nbsp; &nbsp; &nbsp;  &#9746; CLI & wxWidgets   |
| **OS:**              |  &#9746; Windows  &nbsp; &nbsp; &nbsp;  &#9746; Linux  &nbsp; &nbsp; &nbsp;  &#9746; macOS  |

## Problem

Text output containing extended ASCII characters is encoded in different formats depending on the operating system and user interface on which the wxBasic virtual machine is running:

* GNU Linux/UNIX (GUI or CLI): **UTF-8**
* MS Windows GUI: **Windows-1252** (aka ANSI)
* MS Windows CLI: **Code Page 850** (aka DOS Latin 1)

If a character that is incorrectly encoded in Windows is output, the resulting text is unreadable. On the other hand, if an attempt is made to output a non-UTF8 character on Linux/UNIX, the virtual machine produces a critical error.


## Troubleshooting

Always encode the script as UTF-8, but using only characters that are valid in Windows-1252. Then use the `abNativeOut` function to translate outputs into the operating system's native encoding.

## Syntax
```python
StrNativeOut = abNativeOut( StrUTF8In )
```


