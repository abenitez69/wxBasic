Function abGetVersion()
    Dim pun = InStr(WXBASIC_VERSION, "."),
        ini = RInStr(pun, WXBASIC_VERSION, " ")+1,
        fin = InStr(pun, WXBASIC_VERSION, " ")-ini,
        ver = Mid(WXBASIC_VERSION, ini, fin)
        ver = Replace(ver, ".0.", ".00.")
    Return Replace(ver, ".0", ".")
End Function

Function abIsWindows()
    Return LCase(Right(Command(1), 4)) = ".exe" OR
           LCase(Right(Command(2), 4)) = ".exe"
End Function

Function abIsConsole()
    Return InStr(LCase(WXBASIC_VERSION), "console")
End Function

