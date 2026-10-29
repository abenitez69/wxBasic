abNativeOut
===========

Encodes strings from UTF-8 to the native encoding of the operating system or user interface.

## Problem

Text output containing extended ASCII characters is encoded in different formats depending on the operating system and user interface on which the wxBasic virtual machine is running:

* GNU Linux/UNIX (GUI or CLI): **UTF-8**
* MS Windows GUI: **Windows-1252** (aka ANSI)
* MS Windows CLI: **Code Page 850** (aka DOS Latin 1)

If a character that is incorrectly encoded in Windows is output, the resulting text is unreadable. On the other hand, if an attempt is made to output a non-UTF8 character on Linux/UNIX, the virtual machine produces a critical error.


## Troubleshooting

Always encode the script as UTF-8 and use the `abNativeOut` function to translate outputs into the operating system's native encoding.

## Syntax

```
StrNativeOut = abNativeOut( StrUTF8In )
```


