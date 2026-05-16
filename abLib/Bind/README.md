Bind for Windows
================

The **bind.wxb** utility was created by David Cuny from the early versions of wxBasic.
It allows you to "compile" a wxBasic script into a binary executable file.
There is no actual compilation; the source script is simply linked to the wxBasic virtual machine executable, resulting in a binary file.
The "compilation" can be cross-platform, meaning that executables can be created from Windows for Linux and vice versa.

It is common practice, when creating executables for Windows, to assign a specific icon to the new application. The **bind.bat** script allows you to create the binary file for Windows, including the icon for the new application.


| Script description   | |
|:---------------------|:----------------------------------------------------|
| **Name:**            |  BIND.BAT                                          |
| **Version:**         |  2.0                                                |
| **Type:**            |  &#9675; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9673; Script |
| **Category:**        |  System                                 |
| **wxBasic version:** |  &#9745; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9745; 2.08  &nbsp; &nbsp; &nbsp;  &#9745; 3.2  &nbsp; &nbsp; &nbsp;  &#9745; Console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9744; Linux  &nbsp; &nbsp; &nbsp;  &#9744; macOS  |



 
Syntax
------

&nbsp;&nbsp;&nbsp; `bind <source.wxb> [iconfile.ico]    ` Create a binary for Windows including the icon.



Remarks
-------

* The `source` is a name of file corresponds to the wxBasic script to be "compiled". The extension can be omitted if it is `.wxb`.
* The `iconfile` is the name of the file that corresponds to the icon that will be used in the application. The icon filename is optional. If omitted, two things can happen:
    - If an icon file exists in the same folder as `source` and with the same name, it will be used.

"Shebang" Example
-----------------

```dosbatch
echo="" // & @echo off
rem ="" &
"C:\\Program Files\\wxBasic\\wxbasic.exe" //%0 %1 %2 %3
goto =now()

wxMessageBox( "Message box:\nMultiline sample", "wxMessageBox Sample", wxICON_INFORMATION )
Print wxGetTextFromUser( "Message\nmultiline:", "wxGetTextFromUser Sample", "Default value" )
Print wxGetPasswordFromUser( "Message\nmultiline:", "wxGetPasswordFromUser Sample", "NONEPASS" )
Print wxGetNumberFromUser( "Message\nmultiline:", "ID =", "wxGetNumberFromUser Sample", 10, 1, 20 )
myColor = wxGetColorFromUser( Nothing, wxColour(0,0,0) )
Print "RGB:", myColor.Red(), myColor.Green(), myColor.Blue()

:now()
```

### Real Linux/UNIX Shebang

```shell-script
#!/usr/bin/wxbasic

wxMessageBox( "Message box:\nMultiline sample", "wxMessageBox Sample", wxICON_INFORMATION )
Print wxGetTextFromUser( "Message\nmultiline:", "wxGetTextFromUser Sample", "Default value" )
Print wxGetPasswordFromUser( "Message\nmultiline:", "wxGetPasswordFromUser Sample", "NONEPASS" )
Print wxGetNumberFromUser( "Message\nmultiline:", "ID =", "wxGetNumberFromUser Sample", 10, 1, 20 )
myColor = wxGetColorFromUser( Nothing, wxColour(0,0,0) )
Print "RGB:", myColor.Red(), myColor.Green(), myColor.Blue()
```

