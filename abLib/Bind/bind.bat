@echo off
set WXFILE="%~d1%~p1%~n1.wxb"
if not exist %WXFILE% goto help
set BINFILE="%~d0%~p0wxbasic.exe"
if not exist %BINFILE% set BINFILE= "%~d0%~p0bvmc.exe"
if not exist %BINFILE% goto help
set BINDFILE="%~d0%~p0bind.wxb"
if not exist %BINDFILE% goto help
set RESHACKERFILE="%~d0%~p0reshacker.exe"
if not exist %RESHACKERFILE% set RESHACKERFILE= "%~d0%~p0reshackerfx.exe"
if not exist %RESHACKERFILE% goto noneicon
set UPXFILE="%~d0%~p0upx.exe"
if not exist %UPXFILE% goto noneicon

copy /y %BINFILE% temp.exe
ping -n 2 127.0.0.1 > NUL
set ICOFILE= %2
if "%2"=="" set ICOFILE= %~n1.ico
if not exist %ICOFILE% set ICOFILE= %ICOFILE%.ico
if not exist %ICOFILE% goto noneicon
%UPXFILE% temp.exe -d
ping -n 2 127.0.0.1 > NUL
%RESHACKERFILE% -addoverwrite temp.exe, temp.exe, %ICOFILE%, ICONGROUP, MAINICON, 0
%RESHACKERFILE% -addoverwrite temp.exe, temp.exe, %ICOFILE%, ICONGROUP, AAAAAAAA, 0
ping -n 2 127.0.0.1 > NUL
%UPXFILE% --compress-icons=0 temp.exe
ping -n 2 127.0.0.1 > NUL
:noneicon
%BINFILE% %BINDFILE% "%~d1%~p1temp.exe" %WXFILE% "%~d1%~p1%~n1.exe"
set BINFILE=
set BINDFILE=
set RESHACKERFILE=
set UPXFILE=
set ICOFILE=
del /Q /F temp.exe
if exist "%~d0%~p0ResHacker.log" del /Q "%~d0%~p0ResHacker.log"
if exist "%~d0%~p0ResHacker.ini" del /Q "%~d0%~p0ResHacker.ini"
if exist "%~d0%~p0ResHackerFX.log" del /Q "%~d0%~p0ResHackerFX.log"
if exist "%~d0%~p0ResHackerFX.ini" del /Q "%~d0%~p0ResHackerFX.ini"
goto exit

:help
echo Bind a source file to wxBasic executable.
echo.
echo BIND sourcefile [iconfile]
echo.
echo   sourcefile    wxBasic source file to "compile" into binary executable.
echo   iconfile      Icon file (.ICO) to assign to the binary executable.
echo                 The iconfile can be omitted. If an icon file with the
echo                 same name as the sourcefile appears in the folder, it
echo                 will be used.
echo.
echo NOTE: For proper functioning, place a copy of these programs in the same
echo       folder as this script:
echo       - WXBASIC.EXE                      - To run and bind
echo       - BIND.WXB                         - The bind utility
echo       - UPX.EXE                          - To (de)compress wxBasic
echo       - RESHACKER.EXE or RESHACKERFX.EXE - To icon change
echo.
pause
:exit
