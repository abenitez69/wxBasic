

Function abMD2TEX( mdText )
    Dim mdList = TEXArgType2List( mdText ), myDoc = ""
        For i=2 To mdList.Length()-1
            myDoc = myDoc & TEXParce( mdList[i], mdList[i-1], mdList[i+1] ) & "\n"
        End For
    Return myDoc
End Function


Function abMD2TEXDoc( mdText, Title = "" )
    Dim mdList = TEXArgType2List( mdText ),
        myDoc = "\\documentclass[english]{article}\n\\usepackage[T1]{fontenc}\n\\usepackage[latin1]{inputenc}\n\\usepackage{ulem}\n\\setlength{\\parskip}{\\medskipamount}\n\\setlength{\\parindent}{0pt}\n\\usepackage{babel}\n\\usepackage[colorlinks=true, urlcolor=blue]{hyperref}\n"
        myDoc &= "\\makeatletter\n\\newenvironment{mdcode}\n{\\par\\begin{list}{}{\n \\setlength{\\rightmargin}{\\leftmargin}\n \\setlength{\\listparindent}{0pt}\n \\raggedright\n \\setlength{\\itemsep}{0pt}\n \\setlength{\\parsep}{0pt}\n \\normalfont\\ttfamily}%\n\\item[]}\n{\\end{list}}\n\\makeatother\n"
        myDoc &= "\\begin{document}\n" & abMD2TEX( mdText )
        myDoc = Replace( myDoc, " \\abXYZXYZ", " \\\\" )
        myDoc = Replace( myDoc, "_", "\\_" ) : myDoc = Replace( myDoc, "#", "\\#" ) : myDoc = Replace( myDoc, "&", "\\&" )
        myDoc = Replace( myDoc, "$", "\\$" ) : myDoc = Replace( myDoc, "^", "\\textasciicircum " )
        myDoc = Replace( myDoc, "abAmpSubst", "&" )
        myDoc &= "\\end{document}\n"
    Return myDoc
End Function


///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\

Function TEXArgType2List( mdText )
    Dim mdList = [], i, n
    Select Case LCase( TypeOf( mdText ))
        Case "list"
            mdList = mdText
        Case "string"
            mdText = Replace( mdText, "\r", "" )
            mdList = TEXSplit( "\n", mdText )
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


Function TEXParce( Text, PTxt, NTxt )
    Static fBQ = False, fCB1 = False, fCB2 = False, fUL = False, fULs = False, fOL = False, fT = False
    Dim Out = Text

    If Trim( Text ) = "" Then Return ""

  ' HTML Entity
    //Out = Replace( Out, "&", "&amp;" )  :  Out = Replace( Out, "<", "&lt;" )  :  Out = Replace( Out, ">", "&gt;" )

  ' Open/close comment
    Dim BComm = InStr( Text, "[" ), EComm = InStr( Text, "]: #" )
    If EComm = 0 Then EComm = InStr( Text, "]:#" )
    If BComm=1 And EComm Then Return "% " & Text[BComm+1:EComm-1] & "\n"

  ' Open/close code block 1
    If (TEXLeftTrim( Text, 3 ) = "```" Or TEXLeftTrim( Text, 3 ) = "~~~") And !fCB1 Then : fCB1 = True  : Return "\\begin{mdcode}"   : End If
    If (TEXLeftTrim( Text, 3 ) = "```" Or TEXLeftTrim( Text, 3 ) = "~~~") And fCB1  Then : fCB1 = False : Return "\\end{mdcode}" : End If
    If fCB1  Then Return Out & "\n"

  ' Open/close code block 2
    If Text[1:4] = "    " Or Text[1] = Chr( 9 ) Then fCB2 = True
    If fCB2 Then : Out = TEXFirstReplace( Out, Chr( 9 ), "" ) : Out = TEXFirstReplace( Out, "    ", "" ) : End If
    If fCB2 And Trim( PTxt ) = "" Then : Return "\\begin{mdcode}\n" & Out
       ElseIf fCB2 And Trim( NTxt ) = "" Then : fCB2 = False : Return Out & "\n\\end{mdcode}"
       ElseIf fCB2 Then : Return Out & "\n" : End If

  ' Horizontal line
    If (TEXLeftTrim( Text, 3 ) = "---" Or TEXLeftTrim( Text, 3 ) = "***" Or TEXLeftTrim( Text, 3 ) = "___") And Trim( PTxt ) = "" And Trim( NTxt ) = "" Then Return "\\rule[0.5ex]{1\\columnwidth}{1pt}\n"

  ' Link
    Dim Md = InStr( Out, "](" )
    If Md Then
       Dim Op = RInStr( Md, Out, "[" ),  Cl = InStr( Md, Out, ")" ),
           Ta = Out[1:Op-1],  Tb = Out[Op+1:Md-1],  Tc = Out[Md+2:Cl-1],  Td = Out[Cl+1:Len(Out)]
       Out = Ta & "\\href{" & Tc & "}{\\uline{" & Tb & "}}" & Td
    End If


  ' Titles
    If TEXLeftTrim( Text, 1 ) = "#"      And Text[2] <> "#" Then Return "\\section*{" & TEXStyle( Trim( Replace( Out, "#", "" ))) & "}"
    If TEXLeftTrim( Text, 2 ) = "##"     And Text[3] <> "#" Then Return "\\subsection*{" & TEXStyle( Trim( Replace( Out, "#", "" ))) & "}"
    If TEXLeftTrim( Text, 3 ) = "###"    And Text[4] <> "#" Then Return "\\subsubsection*{" & TEXStyle( Trim( Replace( Out, "#", "" ))) & "}"
    If TEXLeftTrim( Text, 4 ) = "####"   And Text[5] <> "#" Then Return "\\paragraph*{" & TEXStyle( Trim( Replace( Out, "#", "" ))) & "}"
    If TEXLeftTrim( Text, 5 ) = "#####"  And Text[6] <> "#" Then Return "\\subparagraph*{" & TEXStyle( Trim( Replace( Out, "#", "" ))) & "}"
    If TEXLeftTrim( Text, 6 ) = "######" And Text[7] <> "#" Then Return "\\subparagraph*{" & TEXStyle( Trim( Replace( Out, "#", "" ))) & "}"
    If TEXLeftTrim( NTxt, 3 ) = "===" Then Return "\\section*{" & TEXStyle( Trim( Out )) & "}"
    If TEXLeftTrim( Text, 3 ) = "===" And Trim( PTxt ) <> "" Then Return ""
    If TEXLeftTrim( NTxt, 3 ) = "---" Then Return "\\subsection*{" & TEXStyle( Trim( Out )) & "}"
    If TEXLeftTrim( Text, 3 ) = "---" And Trim( PTxt ) <> "" Then Return ""

  ' Open/close table
    If TEXLeftTrim( Text, 1 ) = "|" And Trim( PTxt ) = "" Then
         Out = ""
         For I = 1 To Tally( Text, "|" )+1
             Out &= "l"
         End For
         fT = True
         Return "\\begin{tabular}{" & Out & "}\n\\textbf{" & TEXStyle( Replace( Text, "|", "} abAmpSubst \\textbf{" )) & "}\\\\"
    End If
    If fT And (TEXLeftTrim( Text, 2 ) = "|-" Or TEXLeftTrim( Text, 3 ) = "| -") Then Return "\\hline\n"
    If fT Then
       Out = ""
       If Trim( NTxt ) = "" Then : fT = False : Out = "\n\\end{tabular}" : End If
       Return TEXStyle( Replace( Text, "|", "abAmpSubst" )) & "\\\\" & Out
    End If

  ' Open/close unordered list
    Dim BgnBull = InStr( Text, "* " ) : If !BgnBull Then BgnBull = InStr( Text, "- " ) : If !BgnBull Then BgnBull = InStr( Text, "+ " )
    If (Text[1] = "*" Or Text[1] = "-" Or Text[1] = "+") And Text[2] = " " And Trim( PTxt ) = "" Then fUL = True
    If Text[1] = " " And (TEXLeftTrim( Text, 1 ) = "*" Or TEXLeftTrim( Text, 1 ) = "-" Or TEXLeftTrim( Text, 1 ) = "+") And fUL Then fULs = True
    If fUL Or fULs Then Out = "\\item " & TEXStyle( LTrim( Out[BgnBull+2:Length(Out)] ))
    If fULs And (PTxt[1] = "*" Or PTxt[1] = "-" Or PTxt[1] = "+") Then : Return "\\begin{itemize}\n" & Out
       ElseIf fULs And (NTxt[1] = "*" Or NTxt[1] = "-" Or NTxt[1] = "+") Then : fULs = False : Return Out & "\n\\end{itemize}"
       ElseIf fULs Then : Return Out : End If
    If fUL And Trim( PTxt ) = "" Then : Return "\\begin{itemize}\n" & Out
       ElseIf fUL And Trim( NTxt ) = "" Then : fUL = False : Return Out & "\n\\end{itemize}"
       ElseIf fUL Then : Return Out : End If

  ' Open/close ordered list
    Dim BgnNumb = InStr( Text, "." )
    If Text[1:2] = "1." Then fOL = True
    If fOL Then Out = "\\item " & TEXStyle( LTrim( Out[BgnNumb+1:Length(Out)] ))
    If fOL And Trim( PTxt ) = "" Then : Return "\\begin{enumerate}\n" & Out
       ElseIf fOL And Trim( NTxt ) = "" Then : fOL = False : Return Out & "\n\\end{enumerate}"
       ElseIf fUL Then : Return Out : End If

  ' Open/close paragraph
    If Trim( TEXFirstReplace( PTxt, ">", "" )) = "" Then Out = "" & Out
    If Trim( TEXFirstReplace( NTxt, ">", "" )) = "" Then Out &= " \\abXYZXYZ"

  ' Open/close blockquote
    If TEXLeftTrim( Text, 1 ) = ">"  And Trim( PTxt ) = ""  Then fBQ = True
    If fBQ And Out[1] = ">" Then Out = LTrim( Out[2:Length(Out)] )
    If fBQ And Out[1:4] = "&gt;" Then Out = LTrim( Out[5:Length(Out)] )
    If fBQ And Out[1:4] = "<p>>" Then : Out = LTrim( TEXFirstReplace( Out, "<p>> ", "<p>" )) : Out = LTrim( TEXFirstReplace( Out, "<p>>", "<p>" )) : End If
    If fBQ And Out[1:7] = "<p>&gt;" Then : Out = LTrim( TEXFirstReplace( Out, "<p>&gt; ", "<p>" )) : Out = LTrim( TEXFirstReplace( Out, "<p>&gt;", "<p>" )) : End If
    If fBQ And Trim( PTxt ) = ""  Then Out = "\\hspace{0.05\\columnwidth}\\parbox[t]{0.95\\columnwidth}{%\n" & Out
    If fBQ And Trim( NTxt ) = ""  Then : Out = Out & "}" : fBQ = False : End If

  ' Line break
    If Right( Out, 2 ) = "  " Then Out = RTrim( Out ) & " \\abXYZXYZ"

    Return TEXStyle( Out )
End Function


Function TEXStyle( Text )
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
    Out = Replace( Out, "\\-", "\\symbol{45}" )  :  Out = Replace( Out, "\\`", "\\symbol{96}" )  :  Out = Replace( Out, "\\*", "\\symbol{42}" )
    Out = Replace( Out, "\\_", "\\symbol{95}" )  :  Out = Replace( Out, "\\{", "\\symbol{123}" ) :  Out = Replace( Out, "\\}", "\\symbol{125}" )
    Out = Replace( Out, "\\#", "\\symbol{35}" )  :  Out = Replace( Out, "\\[", "\\symbol{91}" )  :  Out = Replace( Out, "\\]", "\\symbol{93}" )
    Out = Replace( Out, "\\+", "\\symbol{43}" )  :  Out = Replace( Out, "\\(", "\\symbol{40}" )  :  Out = Replace( Out, "\\)", "\\symbol{41}" )
    Out = Replace( Out, "\\.", "\\symbol{46}" )  :  Out = Replace( Out, "\\!", "\\symbol{33}" )  :  Out = Replace( Out, "\\=", "\\symbol{61}" )
    Out = Replace( Out, "\\|", "\\symbol{124}" ) :  Out = Replace( Out, "\\<", "\\symbol{60}" )  :  Out = Replace( Out, "\\>", "\\symbol{62}" )
    Out = Replace( Out, "\\^", "\\symbol{94}" )  :  Out = Replace( Out, "\\~", "\\symbol{126}" )
    Out = Replace( Out, "\\\\", "\\symbol{92}" )

  ' Open/close bold+italic
    For i=1 To MaxRepl
        If !fIB Then Out, fIB = TEXFirstReplace( Out, ["***", "___", "**_", "__*", "_**", "*__"], "\\textbf{\\textit{" )
        If  fIB Then Out, fIB = TEXFirstReplace( Out, ["***", "___", "**_", "__*", "_**", "*__"], "}}", False )
    End For

  ' Open/close bold
    For i=1 To MaxRepl
        If !fB Then Out, fB = TEXFirstReplace( Out, ["**", "__", "*_", "_*"], "\\textbf{" )
        If  fB Then Out, fB = TEXFirstReplace( Out, ["**", "__", "*_", "_*"], "}", False )
    End For

  ' Open/close italic
    For i=1 To MaxRepl
        If !fI Then Out, fI = TEXFirstReplace( Out, ["*", "_"], "\\textit{" )
        If  fI Then Out, fI = TEXFirstReplace( Out, ["*", "_"], "}", False )
    End For

  ' Open/close strikeout
    For i=1 To MaxRepl
        If !fS Then Out, fS = TEXFirstReplace( Out, "~~", "\\sout{" )
        If  fS Then Out, fS = TEXFirstReplace( Out, "~~", "}", False )
    End For

  ' Open/close code
    For i=1 To MaxRepl
        If !fC Then Out, fC = TEXFirstReplace( Out, "`", "\\texttt{" )
        If  fC Then Out, fC = TEXFirstReplace( Out, "`", "}", False )
    End For

  ' Open/close highlight
    For i=1 To MaxRepl
        If !fH Then Out, fH = TEXFirstReplace( Out, "==", "\\uline{" )
        If  fH Then Out, fH = TEXFirstReplace( Out, "==", "}", False )
    End For

  ' Open/close superscript
    For i=1 To MaxRepl
        If !fU Then Out, fU = TEXFirstReplace( Out, "^", "\\textsuperscript{" )
        If  fU Then Out, fU = TEXFirstReplace( Out, "^", "}", False )
    End For

  ' Open/close subscript
    For i=1 To MaxRepl
        If !fD Then Out, fD = TEXFirstReplace( Out, "~", "\\textsubscript{" )
        If  fD Then Out, fD = TEXFirstReplace( Out, "~", "}", False )
    End For

    Return Out
End Function

Function TEXSplit( Pattern, myString )
    Dim TEXSplitList = [], InitPos = 1, EndPos
    For I = 1 To Tally( myString, Pattern )
        EndPos = InStr( InitPos, myString, Pattern )
        If EndPos > InitPos Then TEXSplitList.Append( myString[ InitPos:EndPos-1 ])
        InitPos = EndPos + Len( Pattern )
    End For
    If Len( myString ) > InitPos Then TEXSplitList.Append( myString[ InitPos:Len( myString )])
    Return TEXSplitList
End Function


Function TEXFirstReplace( Text, Pattern, Repl, Bool = True )
    Dim Patt = [], FirstPos = 1000000, FirstText, Pos
    If LCase( TypeOf( Pattern )) = "string" Then : Patt.Append( Pattern ) : Else : Patt = Pattern : End If
    For i=1 To Patt.Length()
       Pos = InStr( Text, Patt[i] )
       If Pos > 0 And Pos < FirstPos Then : FirstPos = Pos : FirstText = Patt[i] : End If
    End For
    If FirstPos = 1000000 Then Return Text, !Bool
    Return Text[1: FirstPos-1] & Repl & Text[FirstPos+Len(FirstText):Len(Text)] , Bool
End Function


Function TEXLeftTrim( Text, Chars )
    Return Left( LTrim( Text ), Chars )
End Function




