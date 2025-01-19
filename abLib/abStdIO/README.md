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
* `abSTD_DELAY, n      `  &nbsp; &nbsp;  Suspends processing and waits `n` seconds before resuming.
* `abSTD_INPUT, "label"`  &nbsp; &nbsp;  Returns input from the system console.


Remark
------

* True console input and output for operating systems is only available in *CLI* versions of
  wxBasic (BVMC) via `INPUT` and `PRINT` commands. In *GUI* versions the `PRINT` command produces 
  output to a virtual console and the `INPUT` command is disabled. This library enables real 
  system console input and output in any version of wxBasic (*CLI* or *GUI*) on both Windows 
  and Linux OS (not tested on macOS).
* `abSTD_PRINT` Prints a text to the system's standard output. To leave a blank line use 
                an empty text "". It is the default command and can be omitted by placing 
                only the text. The text can also be a variable or a numeric value or any 
                other type of data.
* `abSTD_INPUT` Enter a text via the system's standard input. The label is a mandatory  
                parameter; if you want to omit it, use an empty text "". If a single 
                `abSTD_INPUT` is used in the command list, the function returns a string 
                variable with the entered text. On the other hand, if multiple `abSTD_INPUT` 
                are used in the command list, the function returns a list variable. Each 
                element in the list corresponds to a string variable in the same order in 
                which they were entered.
* Using commands `abSTD_PRINT`, `abSTD_CLEAR`, `abSTD_PAUSE` and `abSTD_DELAY` does not 
  generate any output, which is why `abStdIO` is invoked as a procedure.
* The `abSTD_INPUT` command returns the values ​​entered by the console. If at least one 
  `abSTD_INPUT` appears in the command list, `abStdIO` must be invoked as a function.



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
                    abSTD_INPUT, "Your name:", 
                    "", "Thank you for using this library", "",
                    abSTD_PAUSE )

Print "Your name is "; Name
```
