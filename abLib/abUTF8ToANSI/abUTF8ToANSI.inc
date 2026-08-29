
  ///////////     abUTF8ToANSI     \\\\\\\\\\\\\\

Function abUTF8ToANSI( Out As String )
  ' UTF-8 to ANSI
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


