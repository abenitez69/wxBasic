Shebang Emulator for Windows
============================

A **shebang** is the character sequence `#!` . On Linux (and other Unix-like operating
systems), when a script starts with a shebang, it is used as if it were an executable. 
In wxBasic for Windows this first line is ignored and has no meaning.

*Shebang emulator* is an alternative to create wxBasic executables on Windows without having 
to binary the script.


| Script description   | |
|:---------------------|:----------------------------------------------------|
| **Name:**            |  abShebang                                          |
| **Version:**         |  1.1                                                |
| **Type:**            |  &#9675; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9673; Script |
| **Category:**        |  System                                 |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9745; 2.08  &nbsp; &nbsp; &nbsp;  &#9745; 3.2  &nbsp; &nbsp; &nbsp;  &#9745; Console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9744; Linux  &nbsp; &nbsp; &nbsp;  &#9744; macOS  |


Idea
----

The main idea is to place the wxBasic script code in a Windows batch file (*.CMD or *.BAT) 
using meaningful BASIC codes to the batch file. These codes, common to both scripts, should 
not produce significant changes or console output in wxBasic. Common codes should, first of all, 
allow the Windows command interpreter to execute them with the wxBasic virtual machine. It can 
also clear the screen, avoid echoing on the screen, jump to the end of the program, etc.

 
Syntax
------

```dosbatch =
echo="" // & @echo off
cls()
rem ="" &
"bvmc.exe" //%0 %1 %2 %3 %4 %5 %6 %7 %8
goto =now()

// wxBasic script code

:now()
```

Remarks
-------

* *Line 1:* Used to `ECHO OFF`. For **CMD**, two commands are concatenated on a single line using `&`. 
  First an echo on screen that does not write anything, followed by the command ´@ECHO OFF´. For 
  **wxBasic**, first it is an empty assignment to the string variable `echo` and then a comment.
* *Line 2:* It is used to clear the screen in both **CMD** and **wxBasic**. It is only implemented 
  in wxBasic versions 3.x and higher and in all console versions.   
  **NOTE:** To use this script with GUI versions of wxBasic 2.x, remove this line.
* *Lines 3 and 4:* Used to run the same script with the wxBasic virtual machine. For **CMD**, first 
  a comment is included (necessary to run in wxBasic) and on the next line wxBasic virtual machine 
  is launched (in the example BVMC.EXE) followed by the name and path of the script (`%0`), finally
  the batch arguments are passed. For **wxBasic**, first it is an empty assignment to the string 
  variable `rem` followed by the concatenation operator and on the next line the assignment ends 
  after concatenating the remaining text, followed by a comment.   
  **NOTE 1:** To use this script with GUI versions of wxBasic, change the `bvmc.exe` to `wxbasic.exe`.  
  **NOTE 2:** As in Linux, you can also include the path to the executable; in this case change each 
  backslash to a double backslash in the path. For example: `"D:\\wxBasic\\wxbasic.exe" // %0 %1 %2 %3 %4 %5`
* *Line 5:* It is used to jump to the end of the batch script and ignore the wxBasic code on the 
  following lines. For **CMD** jump to label `NOW()` and for **wxBasic** assigns the current time 
  to the variable `goto`.
* *Last line:* Used to label the last line of the script. For **CMD**, define label `:NOW()`. For **wxBasic** 
  two commands are concatenated on a single line using `:`. Without first command, followed by the call to 
  the procedure `now()`


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

### Linux/UNIX Shebang

```shell-script
#!/usr/bin/wxbasic

wxMessageBox( "Message box:\nMultiline sample", "wxMessageBox Sample", wxICON_INFORMATION )
Print wxGetTextFromUser( "Message\nmultiline:", "wxGetTextFromUser Sample", "Default value" )
Print wxGetPasswordFromUser( "Message\nmultiline:", "wxGetPasswordFromUser Sample", "NONEPASS" )
Print wxGetNumberFromUser( "Message\nmultiline:", "ID =", "wxGetNumberFromUser Sample", 10, 1, 20 )
myColor = wxGetColorFromUser( Nothing, wxColour(0,0,0) )
Print "RGB:", myColor.Red(), myColor.Green(), myColor.Blue()
```
