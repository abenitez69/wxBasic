
/////////////////    Encode to and Decode from MIME Base64    \\\\\\\\\\\\\\\\\\\\
////////////////      abBase64Encode  and  abBase64Decode      \\\\\\\\\\\\\\\\\\\


Function abBase64Encode( BtLst = [] )
    Dim BtLen=(BtLst.Length()\3)*3,  BtRst=BtLst.Length()-btLen,  Coded="",  i, SubBin, c=0
    For i = 1 To BtLen Step 3
        SubBin = mimeDec2Bin( BtLst[i] ) & mimeDec2Bin( BtLst[i+1] ) & mimeDec2Bin( BtLst[i+2] )
        Coded = Coded & mimeChr( mimeBin2Dec( SubBin[1:6] )) & mimeChr( mimeBin2Dec( SubBin[7:12] )) &
                        mimeChr( mimeBin2Dec( SubBin[13:18] )) & mimeChr( mimeBin2Dec( SubBin[19:24] ))
        c+=4 : If c = 76 Then : Coded = Coded & "\r\n" : c = 0 : End If
    End For
    If btRst=1 Then
        SubBin = mimeDec2Bin( BtLst[BtLen+1] ) & "0000"
        Coded = Coded & mimeChr( mimeBin2Dec( SubBin[1:6] )) & mimeChr( mimeBin2Dec( SubBin[7:12] )) & "=="
    Else If btRst=2 Then
        SubBin = mimeDec2Bin( BtLst[BtLen+1] ) & mimeDec2Bin( BtLst[BtLen+2] ) & "00"
        Coded = Coded & mimeChr( mimeBin2Dec( SubBin[1:6] )) & mimeChr( mimeBin2Dec( SubBin[7:12] )) & mimeChr( mimeBin2Dec( SubBin[13:18] )) & "="
    End If
    Return Coded & "\r\n"
End Function

Function abBase64Decode( Mime = "=" )
    Mime = Replace( Mime, "\n", "" )  :  Mime = Replace( Mime, "\r", "" )
    Dim MimeLen=Len(Mime)-4, Decoded=[], SubMime
    For i = 1 To MimeLen Step 4
        SubMime = mimeDec2Bin( mimeAsc( Mid( Mime, i, 1 )), 6 ) & mimeDec2Bin( mimeAsc( Mid( Mime, i+1, 1 )), 6 ) &
                  mimeDec2Bin( mimeAsc( Mid( Mime, i+2, 1 )), 6 ) & mimeDec2Bin( mimeAsc( Mid( Mime, i+3, 1 )), 6 )
        Decoded.Append( mimeBin2Dec( SubMime[1:8] )) : Decoded.Append( mimeBin2Dec( SubMime[9:16] )) : Decoded.Append( mimeBin2Dec( SubMime[17:24] ))
    End For
    If Right( Mime, 2 ) = "==" Then
       SubMime = mimeDec2Bin( mimeAsc( Mid( Mime, MimeLen+1, 1 )), 6 ) & mimeDec2Bin( mimeAsc( Mid( Mime, MimeLen+2, 1 )), 6 )
       Decoded.Append( mimeBin2Dec( SubMime[1:8] ))
    Else If Right( Mime, 1 ) = "=" Then
       SubMime = mimeDec2Bin( mimeAsc( Mid( Mime, MimeLen+1, 1 )), 6 ) & mimeDec2Bin( mimeAsc( Mid( Mime, MimeLen+2, 1 )), 6 ) &
                 mimeDec2Bin( mimeAsc( Mid( Mime, MimeLen+3, 1 )), 6 )
       Decoded.Append( mimeBin2Dec( SubMime[1:8] )) : Decoded.Append( mimeBin2Dec( SubMime[9:16] ))
    End If
    Return Decoded
End Function




Function mimeDec2Bin( Deci=0, Leng=8 )
    Dim Bina = Bin( Deci )
    While Len( Bina ) < Leng  :  Bina = "0" & Bina  :  End While
    Return Bina
End Function

Function mimeBin2Dec( Bina="0" )
    While Len( Bina ) < 8  :  Bina = "0" & Bina  :  End While
    Bina = Right( Bina, 8 )
    Return 128*Bina[1]+64*Bina[2]+32*Bina[3]+16*Bina[4]+8*Bina[5]+4*Bina[6]+2*Bina[7]+Bina[8]
End Function

Function mimeChr( Bt )
    Dim Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
    Return Base64[ 1 + Bt ]
End Function

Function mimeAsc( Ch )
    Dim Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
    Return InStr( Base64, Ch )-1
End Function

