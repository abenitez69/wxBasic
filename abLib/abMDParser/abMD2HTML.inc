

Function abMD2HTML( mdText )
    Dim mdList = HTMLArgType2List( mdText ), myDoc = ""
        For i=2 To mdList.Length()-1
            myDoc = myDoc & HTMLParce( mdList[i], mdList[i-1], mdList[i+1] ) & "\n"
        End For
    Return myDoc
End Function


Function abMD2HTMLDoc( mdText, Title = "" )
    Dim mdList = HTMLArgType2List( mdText ),
        myDoc = "<!DOCTYPE html>\n<html>\n<head>\n  <meta charset=\"iso-8859-1\">\n  <title>" & Title & "</title>\n</head>\n<body text=#000000>\n"
        myDoc &= wxBasicSyntaxHighlight( abMD2HTML( mdText ))
        myDoc &= "</body>\n</html>"
    Return myDoc
End Function


Function abMD2HTMLStyledDoc( mdText, Title = "" )
    Dim mdList = HTMLArgType2List( mdText ),
        myDoc = "<!DOCTYPE html>\n<html>\n<head>\n  <meta charset=\"iso-8859-1\">\n  <title>" & Title & "</title>\n"
        myDoc &= "  <style type=\"text/css\">\n"
        myDoc &= "    html { margin: 0; height: inherit; } \n"
        myDoc &= "    body { font-family: Gill, Helvetica, sans-serif } \n"
        myDoc &= "    table { border-collapse: collapse; border: 1px solid black; } \n"
        myDoc &= "    td { padding: 5px; } \n"
        myDoc &= "    tr:nth-child(odd) {background-color: #f2f2f2;} \n"
        myDoc &= "    thead { background-color: #04AA6D; color: white; font-weight: bold; } \n"
        myDoc &= "    code { font-size: 15px; } \n"
        myDoc &= "  </style>\n"
        myDoc &= "</head>\n<body text=#000000>\n"
        myDoc &= wxBasicSyntaxHighlight( abMD2HTML( mdText ))
        myDoc &= "</body>\n</html>"
    Return myDoc
End Function

///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\

Function HTMLArgType2List( mdText )
    Dim mdList = [], i, n
    Select Case LCase( TypeOf( mdText ))
        Case "list"
            mdList = mdText
        Case "string"
            mdText = Replace( mdText, "\r", "" )
            mdList = HTMLSplit( "\n", mdText )
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


Function HTMLParce( Text, PTxt, NTxt )
    Static fBQ = False, fCB1 = False, fCB2 = False, fUL = False, fULs = False, fOL = False, fT = False
    Dim Out = Text

    If Trim( Text ) = "" Then Return ""

  ' HTML Entity
    //Out = Replace( Out, "&", "&amp;" )  :  Out = Replace( Out, "<", "&lt;" )  :  Out = Replace( Out, ">", "&gt;" )

  ' Open/close comment
    Dim BComm = InStr( Text, "[" ), EComm = InStr( Text, "]: #" )
    If EComm = 0 Then EComm = InStr( Text, "]:#" )
    If BComm=1 And EComm Then Return "<!-- " & Text[BComm+1:EComm-1] & " -->\n"

  ' Open/close code block 1
    If (HTMLLeftTrim( Text, 3 ) = "```" Or HTMLLeftTrim( Text, 3 ) = "~~~") And !fCB1 Then : fCB1 = True  : Return "<pre><code><!--wxBasic-->"   : End If
    If (HTMLLeftTrim( Text, 3 ) = "```" Or HTMLLeftTrim( Text, 3 ) = "~~~") And fCB1  Then : fCB1 = False : Return "</code></pre>" : End If
    If fCB1  Then Return Out

  ' Open/close code block 2
    If Text[1:4] = "    " Or Text[1] = Chr( 9 ) Then fCB2 = True
    If fCB2 Then : Out = HTMLFirstReplace( Out, Chr( 9 ), "" ) : Out = HTMLFirstReplace( Out, "    ", "" ) : End If
    If fCB2 And Trim( PTxt ) = "" Then : Return "<pre><code>\n" & Out
       ElseIf fCB2 And Trim( NTxt ) = "" Then : fCB2 = False : Return Out & "\n</code></pre>"
       ElseIf fCB2 Then : Return Out : End If

  ' Horizontal line
    If (HTMLLeftTrim( Text, 3 ) = "---" Or HTMLLeftTrim( Text, 3 ) = "***" Or HTMLLeftTrim( Text, 3 ) = "___") And Trim( PTxt ) = "" And Trim( NTxt ) = "" Then Return "<hr>"

  ' Link
    Dim Md = InStr( Out, "](" )
    If Md Then
       Dim Op = RInStr( Md, Out, "[" ),  Cl = InStr( Md, Out, ")" ),
           Ta = Out[1:Op-1],  Tb = Out[Op+1:Md-1],  Tc = Out[Md+2:Cl-1],  Td = Out[Cl+1:Len(Out)]
       Out = Ta & "<a href=\"" & Tc & "\">" & Tb & "</a>" & Td
    End If


  ' Titles
    If HTMLLeftTrim( Text, 1 ) = "#"      And Text[2] <> "#" Then Return "<h1>" & HTMLStyle( Trim( Replace( Out, "#", "" ))) & "</h1>"
    If HTMLLeftTrim( Text, 2 ) = "##"     And Text[3] <> "#" Then Return "<h2>" & HTMLStyle( Trim( Replace( Out, "#", "" ))) & "</h2>"
    If HTMLLeftTrim( Text, 3 ) = "###"    And Text[4] <> "#" Then Return "<h3>" & HTMLStyle( Trim( Replace( Out, "#", "" ))) & "</h3>"
    If HTMLLeftTrim( Text, 4 ) = "####"   And Text[5] <> "#" Then Return "<h4>" & HTMLStyle( Trim( Replace( Out, "#", "" ))) & "</h4>"
    If HTMLLeftTrim( Text, 5 ) = "#####"  And Text[6] <> "#" Then Return "<h5>" & HTMLStyle( Trim( Replace( Out, "#", "" ))) & "</h5>"
    If HTMLLeftTrim( Text, 6 ) = "######" And Text[7] <> "#" Then Return "<h6>" & HTMLStyle( Trim( Replace( Out, "#", "" ))) & "</h6>"
    If HTMLLeftTrim( NTxt, 3 ) = "===" Then Return "<h1>" & HTMLStyle( Trim( Out )) & "</h1>"
    If HTMLLeftTrim( Text, 3 ) = "===" And Trim( PTxt ) <> "" Then Return ""
    If HTMLLeftTrim( NTxt, 3 ) = "---" Then Return "<h2>" & HTMLStyle( Trim( Out )) & "</h2>"
    If HTMLLeftTrim( Text, 3 ) = "---" And Trim( PTxt ) <> "" Then Return ""

  ' Open/close table
    If HTMLLeftTrim( Text, 1 ) = "|" And Trim( PTxt ) = "" And !fT Then fT = True
    If fT And (HTMLLeftTrim( Text, 2 ) = "|-" Or HTMLLeftTrim( Text, 3 ) = "| -") Then Return "</thead>\n<tbody>"
    If fT Then Out = "<tr><td>" & HTMLStyle(Replace( Out, "|", "</td><td>" )) & "</td></tr>"
    If fT And Trim( PTxt ) = "" Then Out = "<table>\n<thead>\n<tr class=\"header\">\n" & Out
    If fT And Trim( NTxt ) = "" Then : fT = False : Out &= "\n</tbody>\n</table>" : End If

  ' Open/close unordered list
    Dim BgnBull = InStr( Text, "* " ) : If !BgnBull Then BgnBull = InStr( Text, "- " ) : If !BgnBull Then BgnBull = InStr( Text, "+ " )
    If (Text[1] = "*" Or Text[1] = "-" Or Text[1] = "+") And Text[2] = " " And Trim( PTxt ) = "" Then fUL = True
    If Text[1] = " " And (HTMLLeftTrim( Text, 1 ) = "*" Or HTMLLeftTrim( Text, 1 ) = "-" Or HTMLLeftTrim( Text, 1 ) = "+") And fUL Then fULs = True
    If fUL Or fULs Then Out = "<li>" & HTMLStyle( LTrim( Out[BgnBull+2:Length(Out)] )) & "</li>"
    If fULs And (PTxt[1] = "*" Or PTxt[1] = "-" Or PTxt[1] = "+") Then : Return "<ul>\n" & Out
       ElseIf fULs And (NTxt[1] = "*" Or NTxt[1] = "-" Or NTxt[1] = "+") Then : fULs = False : Return Out & "\n</ul>"
       ElseIf fULs Then : Return Out : End If
    If fUL And Trim( PTxt ) = "" Then : Return "<ul>\n" & Out
       ElseIf fUL And Trim( NTxt ) = "" Then : fUL = False : Return Out & "\n</ul>"
       ElseIf fUL Then : Return Out : End If

  ' Open/close ordered list
    Dim BgnNumb = InStr( Text, "." )
    If Text[1:2] = "1." Then fOL = True
    If fOL Then Out = "<li>" & HTMLStyle( LTrim( Out[BgnNumb+1:Length(Out)] )) & "</li>"
    If fOL And Trim( PTxt ) = "" Then : Return "<ol>\n" & Out
       ElseIf fOL And Trim( NTxt ) = "" Then : fOL = False : Return Out & "\n</ol>"
       ElseIf fUL Then : Return Out : End If

  ' Open/close paragraph
    If Trim( HTMLFirstReplace( PTxt, ">", "" )) = "" Then Out = "<p>" & Out
    If Trim( HTMLFirstReplace( NTxt, ">", "" )) = "" Then Out &= "</p>"

  ' Open/close blockquote
    If HTMLLeftTrim( Text, 1 ) = ">"  And Trim( PTxt ) = ""  Then fBQ = True
    If fBQ And Out[1] = ">" Then Out = LTrim( Out[2:Length(Out)] )
    If fBQ And Out[1:4] = "&gt;" Then Out = LTrim( Out[5:Length(Out)] )
    If fBQ And Out[1:4] = "<p>>" Then : Out = LTrim( HTMLFirstReplace( Out, "<p>> ", "<p>" )) : Out = LTrim( HTMLFirstReplace( Out, "<p>>", "<p>" )) : End If
    If fBQ And Out[1:7] = "<p>&gt;" Then : Out = LTrim( HTMLFirstReplace( Out, "<p>&gt; ", "<p>" )) : Out = LTrim( HTMLFirstReplace( Out, "<p>&gt;", "<p>" )) : End If
    If fBQ And Trim( PTxt ) = ""  Then Out = "<blockquote>\n" & Out
    If fBQ And Trim( NTxt ) = ""  Then : Out = Out & "\n</blockquote>" : fBQ = False : End If

  ' Line break
    If Right( Out, 2 ) = "  " Then Out = RTrim( Out ) & "<br>"

    Return HTMLStyle( Out )
End Function


Function HTMLStyle( Text )
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
    Out = Replace( Out, "\\\\", "&#92;" )

  ' Open/close bold+italic
    For i=1 To MaxRepl
        If !fIB Then Out, fIB = HTMLFirstReplace( Out, ["***", "___", "**_", "__*", "_**", "*__"], "<i><b>" )
        If  fIB Then Out, fIB = HTMLFirstReplace( Out, ["***", "___", "**_", "__*", "_**", "*__"], "</b></i>", False )
    End For

  ' Open/close bold
    For i=1 To MaxRepl
        If !fB Then Out, fB = HTMLFirstReplace( Out, ["**", "__", "*_", "_*"], "<b>" )
        If  fB Then Out, fB = HTMLFirstReplace( Out, ["**", "__", "*_", "_*"], "</b>", False )
    End For

  ' Open/close italic
    For i=1 To MaxRepl
        If !fI Then Out, fI = HTMLFirstReplace( Out, ["*", "_"], "<i>" )
        If  fI Then Out, fI = HTMLFirstReplace( Out, ["*", "_"], "</i>", False )
    End For

  ' Open/close strikeout
    For i=1 To MaxRepl
        If !fS Then Out, fS = HTMLFirstReplace( Out, "~~", "<s>" )
        If  fS Then Out, fS = HTMLFirstReplace( Out, "~~", "</s>", False )
    End For

  ' Open/close code
    For i=1 To MaxRepl
        If !fC Then Out, fC = HTMLFirstReplace( Out, "`", "<code>" )
        If  fC Then Out, fC = HTMLFirstReplace( Out, "`", "</code>", False )
    End For

  ' Open/close highlight
    For i=1 To MaxRepl
        If !fH Then Out, fH = HTMLFirstReplace( Out, "==", "<mark>" )
        If  fH Then Out, fH = HTMLFirstReplace( Out, "==", "</mark>", False )
    End For

  ' Open/close superscript
    For i=1 To MaxRepl
        If !fU Then Out, fU = HTMLFirstReplace( Out, "^", "<sup>" )
        If  fU Then Out, fU = HTMLFirstReplace( Out, "^", "</sup>", False )
    End For

  ' Open/close subscript
    For i=1 To MaxRepl
        If !fD Then Out, fD = HTMLFirstReplace( Out, "~", "<sub>" )
        If  fD Then Out, fD = HTMLFirstReplace( Out, "~", "</sub>", False )
    End For

    Return Out
End Function

Function HTMLSplit( Pattern, myString )
    Dim HTMLSplitList = [], InitPos = 1, EndPos
    For I = 1 To Tally( myString, Pattern )
        EndPos = InStr( InitPos, myString, Pattern )
        If EndPos > InitPos Then HTMLSplitList.Append( myString[ InitPos:EndPos-1 ])
        InitPos = EndPos + Len( Pattern )
    End For
    If Len( myString ) > InitPos Then HTMLSplitList.Append( myString[ InitPos:Len( myString )])
    Return HTMLSplitList
End Function


Function HTMLFirstReplace( Text, Pattern, Repl, Bool = True )
    Dim Patt = [], FirstPos = 1000000, FirstText, Pos
    If LCase( TypeOf( Pattern )) = "string" Then : Patt.Append( Pattern ) : Else : Patt = Pattern : End If
    For i=1 To Patt.Length()
       Pos = InStr( Text, Patt[i] )
       If Pos > 0 And Pos < FirstPos Then : FirstPos = Pos : FirstText = Patt[i] : End If
    End For
    If FirstPos = 1000000 Then Return Text, !Bool
    Return Text[1: FirstPos-1] & Repl & Text[FirstPos+Len(FirstText):Len(Text)] , Bool
End Function


Function HTMLLeftTrim( Text, Chars )
    Return Left( LTrim( Text ), Chars )
End Function


///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\///\\\


Function wxBasicSyntaxHighlight( mdText )
   Static fCB = False
   Dim mdList = HTMLArgType2List( mdText ), Doc = "", Txt
   For i=1 To mdList.Length()
      Txt = mdList[i]
      If LCase( Txt[1:25] ) = "<pre><code><!--wxbasic-->"   Then fCB = True
      If LCase( Txt[1:13] ) = "</code></pre>" Then fCB = False
      If !fCB Then
         Doc &= Txt & "\n"
      Else
         Doc &= SyntaxHighlight( Txt ) & "\n"
      End If
   End For
   Return Doc
End Function

Function SyntaxHighlight( Text )
    Dim myList = [], Doc = Text

  ' Comments
    If InStr( Text, "'" ) Then
      myList = HTMLSplit( "'", Text )
      If myList.Length() = 1 Then
         Return "<font color=#006400><i>'" & myList[1] & "</i></font>"
      Else
         Return KeysSyntaxHighlight( myList[1] ) & "<font color=#006400><i>'" & myList[2] & "</i></font>"
      End if
    End If
    If InStr( Text, "//" ) Then
      myList = HTMLSplit( "//", Text )
      If myList.Length() = 1 Then
         Return "<font color=#006400><i>//" & myList[1] & "</i></font>"
      Else
         Return KeysSyntaxHighlight( myList[1] ) & "<font color=#006400><i>//" & myList[2] & "</i></font>"
      End if
    End If

  ' Strings
    If InStr( Text, "\"" ) Then
       Doc = ""
       myList = HTMLSplit( "\"", Text )
       For i=1 To myList.Length() Step 2
         Doc &= KeysSyntaxHighlight( myList[i] )
         If i < myList.Length() Then Doc &= "<font color=#800080>\"" & myList[i+1] & "\"</font>"
       End For
       Return Doc
    End If
    Return KeysSyntaxHighlight( Doc )
End Function

Function KeysSyntaxHighlight( Text )
    Dim Key
    Const Key1 = ["Dim ","Constant","Const ","Print","Input","Then","Else","End If","End While","End For","While","String","Integer","Number",
                  "DateTime","Object","Array","Option Explicit","End Select","Select","Next","For Each","Exit For","Break","Continue",
                  "Finally","End Try",
                  "Catch","Redo","Try","Table","Case","List","End","For","New","If ","As ","In ","Is ","To "]
    Const Key2 = ["True","False","Nothing"]
    For Each Key In Key1
       Text = Replace( Text, Key, "<font color=#000090>" & Key & "</font>" )
       Text = Replace( Text, LCase( Key ), "<font color=#000090>" & LCase( Key ) & "</font>" )
       Text = Replace( Text, UCase( Key ), "<font color=#000090>" & UCase( Key ) & "</font>" )
    End For
    For Each Key In Key2
       Text = Replace( Text, Key, "<font color=#900000>" & Key & "</font>" )
       Text = Replace( Text, LCase( Key ), "<font color=#900000>" & LCase( Key ) & "</font>" )
       Text = Replace( Text, UCase( Key ), "<font color=#900000>" & UCase( Key ) & "</font>" )
    End For

    Return Text
End Function

