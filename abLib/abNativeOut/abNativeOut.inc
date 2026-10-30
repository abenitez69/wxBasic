'  abNativeOut
'  ===========
'
'  Encodes strings from UTF-8 to the native encoding of the operating system or user interface.
'
'  Library description
'  -------------------
'
'      File name:        abNativeOut.inc
'      Version:          5.8
'      Type:             ( ) Class    (o) Function      ( ) Script
'      wxBasic version:  [ ] 0.6      [x] 2.5      [x] 2.08      [x] 3.2
'      wxBasic UI:       [x] CLI      [x] GUI      [x] CLI & wxWidgets
'      OS:               [x] Windows  [x] Linux    [x] macOS
'
'  Syntax
'  ------
'
'  ```
'    StrNativeOut = abNativeOut( StrUTF8In )
'  ```
'
'  Remark
'  ------
'
'  * `StrUTF8In`     input string encoded as UTF-8;
'  * `StrNativeOut`  output string into the operating system's native encoding.
'
'
'  Example
'  -------
'
'  ```
'  #!/usr/bin/wxbasic
'  Option Explicit
'  Include "abNativeOut.inc"
'  Print abNativeOut( " • Multilingual:" )
'  Print abNativeOut( "\tEspañol:\tÁÉÍÓÚÜÑ áéíóúüñ ¿¡" )
'  Print abNativeOut( "\tDeutsch:\tÄÖÜ äöü ß" )
'  Print abNativeOut( "\tFrançais:\tÀÂÆÉÈÊËÎÏÔÙÛÜÇ àâæéèêëîïôùûüÿç" )
'  Print abNativeOut( "\tSvenska:\tÅÄÖ åäö" )
'  Print abNativeOut( "\tNorsk/Dansk:\tÆØÅ æøå" )
'  Print abNativeOut( "\tÍslenska:\tÁÐÉÍÓÚÝÞÆÖ áðéíóúýþæö" )
'  Print
'  Print abNativeOut( " • Currency:\t $ € ¥ £ ƒ ¢ ¤" )
'  Print abNativeOut( " • Mathemat:\t ±+-·×:÷ ¼ ½ ¾ ° ¹ ² ³ ƒ Ø" )
'  Print abNativeOut( " • Ordinal:\t ª º" )
'  Print abNativeOut( " • Grapheme:\t ¶ (paragraph) § (section) † (footnote)" )
'  ```


Function abNativeOut( Text )
    If abOutIsWindows() Then
        If abOutIsConsole() Then Return abOutUTF8ToCP850( Text )
        Return abOutUTF8ToANSI( Text )
    End If
    Return Text
End Function

Function abOutUTF8ToANSI( Out )
  ' UTF-8 to Windows-1252
    Dim Tbl = [ Chr(226)&Chr(130)&Chr(172), Chr(226)&Chr(130)&Chr(172), Chr(226)&Chr(128)&Chr(156), Chr(198)&Chr(146), Chr(226)&Chr(128)&Chr(158),
                Chr(226)&Chr(128)&Chr(166), Chr(226)&Chr(128)&Chr(160), Chr(226)&Chr(128)&Chr(161), Chr(203)&Chr(134), Chr(226)&Chr(128)&Chr(176),
                Chr(197)&Chr(160), Chr(226)&Chr(128)&Chr(185), Chr(197)&Chr(146), Chr(197)&Chr(146), Chr(197)&Chr(189), Chr(197)&Chr(189),
                Chr(197)&Chr(189), Chr(226)&Chr(128)&Chr(152), Chr(226)&Chr(128)&Chr(153), Chr(226)&Chr(128)&Chr(156), Chr(226)&Chr(128)&Chr(157),
                Chr(226)&Chr(128)&Chr(162), Chr(226)&Chr(128)&Chr(147), Chr(226)&Chr(128)&Chr(148), Chr(203)&Chr(156), Chr(226)&Chr(132)&Chr(162),
                Chr(197)&Chr(161), Chr(226)&Chr(128)&Chr(186), Chr(197)&Chr(147), Chr(197)&Chr(147), Chr(197)&Chr(190), Chr(197)&Chr(184)]
    For i=128 To 159 : Out = Replace( Out, Tbl[i-127], Chr(i) ) : End For
    For i=161 To 191 : Out = Replace( Out, Chr(194)&Chr(i), Chr(i) ) : End For
    For i=192 To 255 : Out = Replace( Out, Chr(195)&Chr(i-64), Chr(i) ) : End For
    Return Out
End Function

Function abOutUTF8ToCP850( Out )
  ' UTF-8 to CP850 (Multilingual)
    Dim Tbl = [ Chr(173), Chr(189), Chr(156), Chr(207), Chr(190), Chr(221), Chr(245), Chr(34), Chr(184), Chr(166), Chr(174), Chr(170), Chr(32), Chr(169), Chr(45),
                Chr(248), Chr(241), Chr(253), Chr(252), Chr(39), Chr(230), Chr(244), Chr(250), Chr(44), Chr(251), Chr(167), Chr(175), Chr(172), Chr(171), Chr(243), Chr(168),
                Chr(183), Chr(181), Chr(182), Chr(199), Chr(142), Chr(143), Chr(146), Chr(128), Chr(212), Chr(144), Chr(210), Chr(211), Chr(222), Chr(214), Chr(215),
                Chr(216), Chr(209), Chr(165), Chr(227), Chr(224), Chr(226), Chr(229), Chr(153), Chr(158), Chr(157), Chr(235), Chr(233), Chr(234), Chr(154), Chr(237),
                Chr(232), Chr(225), Chr(133), Chr(160), Chr(131), Chr(198), Chr(132), Chr(134), Chr(145), Chr(135), Chr(138), Chr(130), Chr(136), Chr(137), Chr(141),
                Chr(161), Chr(140), Chr(139), Chr(208), Chr(164), Chr(149), Chr(162), Chr(147), Chr(228), Chr(148), Chr(246), Chr(155), Chr(151), Chr(163), Chr(150),
                Chr(129), Chr(236), Chr(231), Chr(152)]

    Out = Replace( Out, Chr(226)&Chr(130)&Chr(172), Chr(69) )      : Out = Replace( Out, Chr(226)&Chr(128)&Chr(154), Chr(44) )
    Out = Replace( Out, Chr(198)&Chr(146), Chr(159) )              : Out = Replace( Out, Chr(226)&Chr(128)&Chr(158), Chr(34) )
    Out = Replace( Out, Chr(226)&Chr(128)&Chr(166), Chr(46) )      : Out = Replace( Out, Chr(226)&Chr(128)&Chr(160), Chr(197) )
    Out = Replace( Out, Chr(226)&Chr(128)&Chr(161), Chr(216) )     : Out = Replace( Out, Chr(203)&Chr(134), Chr(94) )
    Out = Replace( Out, Chr(226)&Chr(128)&Chr(176), Chr(37) )      : Out = Replace( Out, Chr(197)&Chr(160), Chr(83) )
    Out = Replace( Out, Chr(226)&Chr(128)&Chr(185), Chr(60) )      : Out = Replace( Out, Chr(197)&Chr(146), Chr(79) )
    Out = Replace( Out, Chr(197)&Chr(189), Chr(90) )               : Out = Replace( Out, Chr(226)&Chr(128)&Chr(152), Chr(39) )
    Out = Replace( Out, Chr(226)&Chr(128)&Chr(153), Chr(39) )      : Out = Replace( Out, Chr(226)&Chr(128)&Chr(156), Chr(34) )
    Out = Replace( Out, Chr(226)&Chr(128)&Chr(157), Chr(34) )      : Out = Replace( Out, Chr(226)&Chr(128)&Chr(162), Chr(250) )
    Out = Replace( Out, Chr(226)&Chr(128)&Chr(147), Chr(45) )      : Out = Replace( Out, Chr(226)&Chr(128)&Chr(148), Chr(196) )
    Out = Replace( Out, Chr(203)&Chr(156), Chr(126) )              : Out = Replace( Out, Chr(226)&Chr(132)&Chr(162), Chr(84) )
    Out = Replace( Out, Chr(197)&Chr(161), Chr(115) )              : Out = Replace( Out, Chr(226)&Chr(128)&Chr(186), Chr(62) )
    Out = Replace( Out, Chr(197)&Chr(147), Chr(111) )              : Out = Replace( Out, Chr(197)&Chr(190), Chr(122) )
    Out = Replace( Out, Chr(197)&Chr(184), Chr(89) )
    For i=161 To 191 : Out = Replace( Out, Chr(194)&Chr(i), Tbl[i-160] ) : End For
    For i=192 To 255 : Out = Replace( Out, Chr(195)&Chr(i-64), Tbl[i-160] ) : End For
    Return Out
End Function

Function abOutIsWindows()
    Return LCase(Right(Command(1), 4)) = ".exe" OR
           LCase(Right(Command(2), 4)) = ".exe"
End Function

Function abOutIsConsole()
    Return InStr(LCase(WXBASIC_VERSION), "console")
End Function
