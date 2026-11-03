Bind for Windows
================

Allows for the creation of binary executable files for Windows with custom icons.

| Script description   | |
|:---------------------|:----------------------------------------------------|
| **File name:**       |  BIND.BAT                                          |
| **Version:**         |  2.0                                                |
| **Developer:**       |  Agustín Benítez Hernández                          |
| **Type:**            |  &#9675; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9673; Script |
| **Category:**        |  Development tool for wxBasic                        |
| **wxBasic version:** |  &#9746; 0.6  &nbsp; &nbsp; &nbsp;  &#9746; 2.5  &nbsp; &nbsp; &nbsp;  &#9746; 2.08  &nbsp; &nbsp; &nbsp;  &#9746; 3.2  |
| **wxBasic UI:** |  &#9746; CLI  &nbsp; &nbsp; &nbsp;  &#9746; GUI  &nbsp; &nbsp; &nbsp;  &#9746; CLI & wxWidgets   |
| **OS:**              |  &#9746; Windows  &nbsp; &nbsp; &nbsp;  &#9744; Linux  &nbsp; &nbsp; &nbsp;  &#9744; macOS  |

## Problem

The **bind.wxb** utility was created by David Cuny from the early versions of wxBasic.
It allows you to compile<sup>1</sup> a wxBasic script into a binary executable file.
It is common practice, when creating executables for Windows, to assign a specific icon to the new application. However, the **bind.wxb** utility retains the icon of the wxBasic virtual machine.

> <sup>1</sup> <sub>There is no actual compilation; the source script is simply linked to the wxBasic virtual machine executable, resulting in a binary file. The "compilation" can be cross-platform, meaning that executables can be created from Windows for Linux and vice versa.</sub>

## Troubleshooting

The **bind.bat** script allows you to create the binary file for Windows, including the custom icon for the new application.

Syntax
------

```
bind <source.wxb> [<iconfile.ico>]
```



Remarks
-------

* The `source.wxb` is a name of file corresponds to the wxBasic script to be "compiled". The extension can be omitted.
* The `iconfile.ico` is the name of the file that corresponds to the icon that will be used in the application. The icon filename is optional. If omitted, two things can happen:
    - If an icon file exists in the same folder as `source.wxb` and with the same name, it will be used.
    - Otherwise, the executable retains the wxBasic virtual machine default icon.

NOTE:
-----
This script requires some programs, which must be stored in the same folder:
* `WXBASIC.EXE` or `BVMC.EXE` or `WXBC.EXE`
* `BIND.WXB`
* `RESHACK.EXE` or `RESHACKFX.EXE`
* `UPX.EXE`

The first one corresponds to one of the *wxBasic virtual machines*, which is used to perform the binding and to run the `bind.wxb` program. The second is the script (written by David Cuny in *wxBasic*) responsible for performing the **bind**.
*Resource Hacker* is a free resource developed by Angus Johnson used to replace icon. Last program is *Ultimate Packer for eXecutables*, a free and open source executable packer used for decompress/compress the *wxBasic virtual machines*.

**VERY IMPORTANT NOTE:**

Each version of *wxBasic* requires that these programs be compatible with the architecture used by the virtual machine. This folder includes (as ZIP files) all the programs necessary to use **bind.bat** for *wxBasic* versions `0.6`, `2.5`, `2.08.12.43`, and `3.2.5.52`.

