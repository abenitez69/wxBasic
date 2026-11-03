

Function abMD2RTF( mdText )
    Dim mdList = RTFArgType2List( mdText ), myDoc = ""
        For i=2 To mdList.Length()-1
            myDoc = myDoc & RTFParce( mdList[i], mdList[i-1], mdList[i+1] ) & "\n"
            myDoc = Replace( myDoc, "\\abXXXYYY", "\\*" )
            myDoc = Replace( myDoc, "&nbsp;", " " ) : myDoc = Replace( myDoc, "&#96;", "`" )
        End For
    Return myDoc
End Function


Function abMD2RTFDoc( mdText )
    Dim mdList = RTFArgType2List( mdText ),
        myDoc = "{\\rtf1\\ansi\\deff0\n\n"
        myDoc &= "{\\fonttbl\n{\\f0\\fnil\\fcharset0 Times New Roman;}\n{\\f1\\fmodern Courier New;}\n{\\f2\\ftech Symbol;}\n}\n"
        myDoc &= "{\\colortbl;\n\\red255\\green255\\blue0;\n\\red0\\green0\\blue238;\n}\n"
        myDoc &= abMD2RTF( mdText )
        myDoc &= "}\n"
    Return myDoc
End Function



///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\

Function RTFArgType2List( mdText )
    Dim mdList = [], i, n
    Select Case LCase( TypeOf( mdText ))
        Case "list"
            mdList = mdText
        Case "string"
            mdText = Replace( mdText, "\r", "" )
            mdList = RTFSplit( "\n", mdText )
        Case "array"
            For i=LBound( mdText, 1 ) To UBound( mdText, 1 )
                mdList.Append( mdText[i] )
            End For
        Case "table"
            For Each i, n In mdText
                mdList.Append( n )
            End For
        Case "integer", "number"
            mdList.Append( Str( mdText ))
    End Select
    mdList.Append( " " ) : mdList.Prepend( " " )
    Return mdList
End Function


Function RTFParce( Text, PTxt, NTxt )
    Static fBQ = False, fCB1 = False, fCB2 = False, fUL = False, fULs = False, fOL = False, fT = False
    Dim Out = Text

    If Trim( Text ) = "" Then Return ""

  ' HTML Entity
    //Out = Replace( Out, "&", "&amp;" )  :  Out = Replace( Out, "<", "&lt;" )  :  Out = Replace( Out, ">", "&gt;" )

  ' Open/close comment
    Dim BComm = InStr( Text, "[" ), EComm = InStr( Text, "]: #" )
    If EComm = 0 Then EComm = InStr( Text, "]:#" )
    If BComm=1 And EComm Then Return "{\\comment " & Text[BComm+1:EComm-1] & "}\n"

  ' Open/close code block 1
    If (RTFLeftTrim( Text, 3 ) = "```" Or RTFLeftTrim( Text, 3 ) = "~~~") And !fCB1 Then : fCB1 = True  : Return "{\\f1\\li500 "   : End If
    If (RTFLeftTrim( Text, 3 ) = "```" Or RTFLeftTrim( Text, 3 ) = "~~~") And fCB1  Then : fCB1 = False : Return "} \\par\\par\n" : End If
    If fCB1  Then Return Out & "\\par \n"

  ' Open/close code block 2
    If Text[1:4] = "    " Or Text[1] = Chr( 9 ) Then fCB2 = True
    If fCB2 Then : Out = RTFFirstReplace( Out, Chr( 9 ), "" ) : Out = RTFFirstReplace( Out, "    ", "" ) : End If
    If fCB2 And Trim( PTxt ) = "" Then : Return "{\\f1\\li500 " & Out
       ElseIf fCB2 And Trim( NTxt ) = "" Then : fCB2 = False : Return Out & "} \\par\\par\n"
       ElseIf fCB2 Then : Return Out & "\\par \n" : End If

  ' Horizontal line
    If (RTFLeftTrim( Text, 3 ) = "---" Or RTFLeftTrim( Text, 3 ) = "***" Or RTFLeftTrim( Text, 3 ) = "___") And Trim( PTxt ) = "" And Trim( NTxt ) = "" Then Return "{________________________________________________________________________\\par\\par}\n"

  ' Link
    Dim Md = InStr( Out, "](" )
    If Md Then
       Dim Op = RInStr( Md, Out, "[" ),  Cl = InStr( Md, Out, ")" ),
           Ta = Out[1:Op-1],  Tb = Out[Op+1:Md-1],  Tc = Out[Md+2:Cl-1],  Td = Out[Cl+1:Len(Out)]
       Out = Ta &  " {\\field{\\abXXXYYY\\fldinst HYPERLINK \"" & Tc & "\"}{\\fldrslt{\\ul\\cf2 " & Tb & "}}}" & Td
    End If


  ' Titles
    If RTFLeftTrim( Text, 1 ) = "#"      And Text[2] <> "#" Then Return "{\\pard\\fs40\\b " & RTFStyle( Trim( Replace( Out, "#", "" ))) & " \\par\\par}\n"
    If RTFLeftTrim( Text, 2 ) = "##"     And Text[3] <> "#" Then Return "{\\pard\\fs32\\b " & RTFStyle( Trim( Replace( Out, "#", "" ))) & " \\par\\par}\n"
    If RTFLeftTrim( Text, 3 ) = "###"    And Text[4] <> "#" Then Return "{\\pard\\fs28\\b " & RTFStyle( Trim( Replace( Out, "#", "" ))) & " \\par\\par}\n"
    If RTFLeftTrim( Text, 4 ) = "####"   And Text[5] <> "#" Then Return "<h4>" & RTFStyle( Trim( Replace( Out, "#", "" ))) & "</h4>"
    If RTFLeftTrim( Text, 5 ) = "#####"  And Text[6] <> "#" Then Return "<h5>" & RTFStyle( Trim( Replace( Out, "#", "" ))) & "</h5>"
    If RTFLeftTrim( Text, 6 ) = "######" And Text[7] <> "#" Then Return "<h6>" & RTFStyle( Trim( Replace( Out, "#", "" ))) & "</h6>"
    If RTFLeftTrim( NTxt, 3 ) = "===" Then Return "{\\pard\\fs40\\b " & RTFStyle( Trim( Out )) & " \\par\\par}\n"
    If RTFLeftTrim( Text, 3 ) = "===" And Trim( PTxt ) <> "" Then Return ""
    If RTFLeftTrim( NTxt, 3 ) = "---" Then Return "{\\pard\\fs32\\b " & RTFStyle( Trim( Out )) & " \\par\\par}\n"
    If RTFLeftTrim( Text, 3 ) = "---" And Trim( PTxt ) <> "" Then Return ""

  ' Open/close table
    If RTFLeftTrim( Text, 1 ) = "|" And Trim( PTxt ) = "" Then
         Dim TblInc = 200
         Out = "\\trowd\\cellx200\n"
         For I = 1 To Tally( Text, "|" )-1
             TblInc += 1500
             Out &= "\\cellx"& TblInc &"\n"
         End For
         Out &= "\\cellx"& TblInc+200 &"\n"
         fT = True
         Return Out & "{\\intbl {\\b " & RTFStyle( Replace( Text, "|", "}\\cell\\intbl {\\b " )) & "}\\cell\\row}"
    End If
    If fT And (RTFLeftTrim( Text, 2 ) = "|-" Or RTFLeftTrim( Text, 3 ) = "| -") Then Return ""
    If fT Then
       Out = ""
       If Trim( NTxt ) = "" Then : fT = False : Out = "\n\\par\n" : End If
       Return "{\\intbl " & RTFStyle( Replace( Text, "|", "\\cell\\intbl " )) & "\\cell\\row}" & Out
    End If



  ' Open/close unordered list
    Dim BgnBull = InStr( Text, "* " ) : If !BgnBull Then BgnBull = InStr( Text, "- " ) : If !BgnBull Then BgnBull = InStr( Text, "+ " )
    If (Text[1] = "*" Or Text[1] = "-" Or Text[1] = "+") And Text[2] = " " And Trim( PTxt ) = "" Then fUL = True
    If Text[1] = " " And (RTFLeftTrim( Text, 1 ) = "*" Or RTFLeftTrim( Text, 1 ) = "-" Or RTFLeftTrim( Text, 1 ) = "+") And fUL Then fULs = True
    Dim Bull = "\\u8226*"  : If fULs Then Bull = "-"
    If fUL Or fULs Then Out = "{" & Bull & "\\tab} " & RTFStyle( LTrim( Out[BgnBull+2:Length(Out)] )) & " \\par\n"
    If fULs And (PTxt[1] = "*" Or PTxt[1] = "-" Or PTxt[1] = "+") Then : Return "{\\pard\\li1200\n" & Out
       ElseIf fULs And (NTxt[1] = "*" Or NTxt[1] = "-" Or NTxt[1] = "+") Then : fULs = False : Return Out & "\n}\n"
       ElseIf fULs Then : Return Out : End If
    If fUL And Trim( PTxt ) = "" Then : Return "{\\pard\\li580\n" & Out
       ElseIf fUL And Trim( NTxt ) = "" Then : fUL = False : Return Out & "\n\\par}\n"
       ElseIf fUL Then : Return Out : End If

  ' Open/close ordered list
    Dim BgnNumb = InStr( Text, "." )
    Static cnt
    If Text[1:2] = "1." Then : fOL = True : cnt = 0 : End If
    If fOL Then : cnt += 1 : Out = "{" & cnt & ".\\tab}" & RTFStyle( LTrim( Out[BgnNumb+1:Length(Out)] )) & "\\par" : End If
    If fOL And Trim( PTxt ) = "" Then : Return "{\\pard\\li480\n" & Out
       ElseIf fOL And Trim( NTxt ) = "" Then : fOL = False : Return Out & "\n\\par}\n"
       ElseIf fUL Then : Return Out : End If

  ' Open/close paragraph
    If Trim( RTFFirstReplace( PTxt, ">", "" )) = "" Then Out = "{\\pard\\qj " & Out
    If Trim( RTFFirstReplace( NTxt, ">", "" )) = "" Then Out &= " \\par\\par}\n"

  ' Open/close blockquote
    If RTFLeftTrim( Text, 1 ) = ">"  And Trim( PTxt ) = ""  Then fBQ = True
    If fBQ Then Out = RTFFirstReplace( Out, "> ", "" )
    If fBQ Then Out = RTFFirstReplace( Out, ">", "" )
    If fBQ And Trim( PTxt ) = ""  Then Out = "" & Out
    If fBQ And Trim( NTxt ) = ""  Then : Out = Out & "" : fBQ = False : End If

  ' Line break
    If Right( Out, 2 ) = "  " Then Out = RTrim( Out ) & "\\par\n"

    Return RTFStyle( Out )
End Function


Function RTFStyle( Text )
    Static fB = False, fI = False, fIB= False, fS = False, fC = False, fH = False, fU = False, fD = False
    Const MaxRepl = 20
    Dim Out = Text

  ' UTF-8 to ANSI
    Dim Tbl = [ Chr(226)&Chr(130)&Chr(172), Chr(226)&Chr(130)&Chr(172), Chr(226)&Chr(128)&Chr(156), Chr(198)&Chr(146), Chr(226)&Chr(128)&Chr(158),
    Chr(226)&Chr(128)&Chr(166), Chr(226)&Chr(128)&Chr(160), Chr(226)&Chr(128)&Chr(161), Chr(203)&Chr(134), Chr(226)&Chr(128)&Chr(176), Chr(197)&Chr(160),
    Chr(226)&Chr(128)&Chr(185), Chr(197)&Chr(146), Chr(197)&Chr(146), Chr(197)&Chr(189), Chr(197)&Chr(189), Chr(197)&Chr(189), Chr(226)&Chr(128)&Chr(152),
    Chr(226)&Chr(128)&Chr(153), Chr(226)&Chr(128)&Chr(156), Chr(226)&Chr(128)&Chr(157), Chr(226)&Chr(128)&Chr(162), Chr(226)&Chr(128)&Chr(147),
    Chr(226)&Chr(128)&Chr(148), Chr(203)&Chr(156), Chr(226)&Chr(132)&Chr(162), Chr(197)&Chr(161), Chr(226)&Chr(128)&Chr(186), Chr(197)&Chr(147),
    Chr(197)&Chr(147), Chr(197)&Chr(190), Chr(197)&Chr(184)]
    For i=128 To 159 : Out = Replace( Out, Tbl[i-127], Chr(i) ) : End For
    For i=161 To 191 : Out = Replace( Out, Chr(194)&Chr(i), Chr(i) ) : End For
    For i=192 To 255 : Out = Replace( Out, Chr(195)&Chr(i-64), Chr(i) ) : End For

  ' Markdown escape characteres
    Out = Replace( Out, "\\-", "&#45;" )  :  Out = Replace( Out, "\\`", "&#96;" )  :  Out = Replace( Out, "\\*", "&#42;" )
    Out = Replace( Out, "\\_", "&#95;" )  :  Out = Replace( Out, "\\{", "&#123;" ) :  Out = Replace( Out, "\\}", "&#125;" )
    Out = Replace( Out, "\\#", "&#35;" )  :  Out = Replace( Out, "\\[", "&#91;" )  :  Out = Replace( Out, "\\]", "&#93;" )
    Out = Replace( Out, "\\+", "&#43;" )  :  Out = Replace( Out, "\\(", "&#40;" )  :  Out = Replace( Out, "\\)", "&#41;" )
    Out = Replace( Out, "\\.", "&#46;" )  :  Out = Replace( Out, "\\!", "&#33;" )  :  Out = Replace( Out, "\\=", "&#61;" )
    Out = Replace( Out, "\\|", "&#124;" ) :  Out = Replace( Out, "\\<", "&#60;" )  :  Out = Replace( Out, "\\>", "&#62;" )
    Out = Replace( Out, "\\^", "&#94;" )  :  Out = Replace( Out, "\\~", "&#126;" )
    Out = Replace( Out, "\\\\", "&#92;" ) :  Out = Replace( Out, "&#", "\\u" )

  ' Open/close bold+italic
    For i=1 To MaxRepl
        If !fIB Then Out, fIB = RTFFirstReplace( Out, ["***", "___", "**_", "__*", "_**", "*__"], "{\\b\\i " )
        If  fIB Then Out, fIB = RTFFirstReplace( Out, ["***", "___", "**_", "__*", "_**", "*__"], "}", False )
    End For

  ' Open/close bold
    For i=1 To MaxRepl
        If !fB Then Out, fB = RTFFirstReplace( Out, ["**", "__", "*_", "_*"], "{\\b " )
        If  fB Then Out, fB = RTFFirstReplace( Out, ["**", "__", "*_", "_*"], "}", False )
    End For

  ' Open/close italic
    For i=1 To MaxRepl
        If !fI Then Out, fI = RTFFirstReplace( Out, ["*", "_"], "{\\i " )
        If  fI Then Out, fI = RTFFirstReplace( Out, ["*", "_"], "}", False )
    End For

  ' Open/close strikeout
    For i=1 To MaxRepl
        If !fS Then Out, fS = RTFFirstReplace( Out, "~~", "{\\strike " )
        If  fS Then Out, fS = RTFFirstReplace( Out, "~~", "}", False )
    End For

  ' Open/close code
    For i=1 To MaxRepl
        If !fC Then Out, fC = RTFFirstReplace( Out, "`", "{\\f1 " )
        If  fC Then Out, fC = RTFFirstReplace( Out, "`", "}", False )
    End For

  ' Open/close highlight
    For i=1 To MaxRepl
        If !fH Then Out, fH = RTFFirstReplace( Out, "==", "{\\highlight1" )
        If  fH Then Out, fH = RTFFirstReplace( Out, "==", "}", False )
    End For

  ' Open/close superscript
    For i=1 To MaxRepl
        If !fU Then Out, fU = RTFFirstReplace( Out, "^", "{\\super " )
        If  fU Then Out, fU = RTFFirstReplace( Out, "^", "}", False )
    End For

  ' Open/close subscript
    For i=1 To MaxRepl
        If !fD Then Out, fD = RTFFirstReplace( Out, "~", "{\\sub " )
        If  fD Then Out, fD = RTFFirstReplace( Out, "~", "}", False )
    End For

    Return Out
End Function

Function RTFSplit( Pattern, myString )
    Dim RTFSplitList = [], InitPos = 1, EndPos
    For I = 1 To Tally( myString, Pattern )
        EndPos = InStr( InitPos, myString, Pattern )
        If EndPos > InitPos Then RTFSplitList.Append( myString[ InitPos:EndPos-1 ])
        InitPos = EndPos + Len( Pattern )
    End For
    If Len( myString ) > InitPos Then RTFSplitList.Append( myString[ InitPos:Len( myString )])
    Return RTFSplitList
End Function


Function RTFFirstReplace( Text, Pattern, Repl, Bool = True )
    Dim Patt = [], FirstPos = 1000000, FirstText, Pos
    If LCase( TypeOf( Pattern )) = "string" Then : Patt.Append( Pattern ) : Else : Patt = Pattern : End If
    For i=1 To Patt.Length()
       Pos = InStr( Text, Patt[i] )
       If Pos > 0 And Pos < FirstPos Then : FirstPos = Pos : FirstText = Patt[i] : End If
    End For
    If FirstPos = 1000000 Then Return Text, !Bool
    Return Text[1: FirstPos-1] & Repl & Text[FirstPos+Len(FirstText):Len(Text)] , Bool
End Function


Function RTFLeftTrim( Text, Chars )
    Return Left( LTrim( Text ), Chars )
End Function



