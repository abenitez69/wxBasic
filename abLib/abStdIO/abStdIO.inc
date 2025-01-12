Const abSTD_PRINT = 8392704, abSTD_INPUT = 8392705, abSTD_PAUSE = 8392706,
      abSTD_DELAY = 8392707, abSTD_CLEAR = 8392708

Function abStdIO( ... )
   If ArgC()=0 Then Return
   Dim IsWindows = LCase( Right( Command(1), 4 )) = ".exe" Or LCase( Right( Command(2), 4 )) = ".exe"
   Dim I, Arg, Action = abSTD_PRINT, CommLine = "", InpC = 0
   For I = 1 To ArgC()
        Arg = ArgV( I )
        If Arg = abSTD_PRINT Then : Action = Arg : Continue : End If
        If Arg = abSTD_INPUT Then : Action = Arg : Continue : End If
        If Arg = abSTD_DELAY Then : Action = Arg : Continue : End If
        If Arg = abSTD_PAUSE Then : Action = Arg : End If
        If Arg = abSTD_CLEAR Then : Action = Arg : End If
        If IsWindows Then
            Select Case Action
                Case abSTD_PRINT
                    If Trim( Arg ) = "" Then : CommLine &= "ECHO. & "
                                        Else : CommLine &= "ECHO " & Arg & " & "  : End If
                Case abSTD_INPUT
                    InpC += 1 : If InpC < 10 Then InpC = "0" & InpC
                    CommLine &= "SET /P abSTD" & InpC & "=" & Arg & " & "
                    Action = abSTD_PRINT
                Case abSTD_DELAY
                    CommLine &= "PING.EXE -n " & Arg & " 127.0.0.1 > NUL & "
                    Action = abSTD_PRINT
                Case abSTD_PAUSE
                    CommLine &= "PAUSE & "
                    Action = abSTD_PRINT
                Case abSTD_CLEAR
                    CommLine &= "CLS & "
                    Action = abSTD_PRINT
            End Select
        Else
            Select Case Action
                Case abSTD_PRINT
                    CommLine &= "echo '" & Arg & "' ; "
                Case abSTD_INPUT
                    InpC += 1 : If InpC < 10 Then InpC = "0" & InpC
                    CommLine &= "read -p '" & Arg & " ' none ; export abSTD" & InpC & "=$none ; "
                    Action = abSTD_PRINT
                Case abSTD_DELAY
                    CommLine &= "sleep " & Arg & " ; "
                    Action = abSTD_PRINT
                Case abSTD_PAUSE
                    CommLine &= "read -p 'Press ENTER to continue...' none ; "
                    Action = abSTD_PRINT
                Case abSTD_CLEAR
                    CommLine &= "clear ; "
                    Action = abSTD_PRINT
            End Select
        End If
   End For
   If Val( InpC ) = 0 Then : Shell( CommLine ) : Return : End If
   If IsWindows Then : Shell( CommLine & "SET > envlst.txt" )
                Else : Shell( CommLine & "printenv > envlst.txt" ) : End If

   Dim EnvStr, Inp = []
   Dim fileHandle= fOpen( "envlst.txt", "r" )
       While Not EoF( fileHandle )
          EnvStr = fGets( fileHandle )
          If UCase( Left( EnvStr, 5 )) = "ABSTD" Then Inp.Append( Right( EnvStr, Len( EnvStr ) - 8 ))
       End While
   fClose( fileHandle )
   Kill( "envlst.txt" )
   While Inp.Count() < Val( InpC ) : Inp.Append( "" ) : End While
   If Inp.Count() = 1 Then : Return Inp[1] : Else : Return Inp : End If
End Function
