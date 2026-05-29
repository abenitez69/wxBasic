
  ///////////   abBase64Bitmap   \\\\\\\\\\\\\\


Function abBase64Bitmap( MimeImage )
    Dim myTmpObject = wxFileName( "" ),
        TempFile  = myTmpObject.CreateTempFileName( "" )
    B64BMPBase64Decode( MimeImage, TempFile )
    myTmpObject.Finalize()
    Dim ImageObj = wxEmptyBitmap( 0, 0 )
    ImageObj.LoadFile( TempFile, wxBITMAP_TYPE_ANY )
    wxRemoveFile( TempFile )
    Return( ImageObj )
End Function



Function B64BMPBase64Decode( Mime, TmpFile )
    Mime = Replace( Mime, "\n", "" )  :  Mime = Replace( Mime, "\r", "" )
    Dim MimeLen=Len(Mime)-4, Decoded=[], SubMime,
    H = fOpen( TmpFile, "w" )
       For i = 1 To MimeLen Step 4
           SubMime = B64BMPDec2Bin( B64BMPAsc( Mid( Mime, i, 1 )), 6 ) & B64BMPDec2Bin( B64BMPAsc( Mid( Mime, i+1, 1 )), 6 ) &
                     B64BMPDec2Bin( B64BMPAsc( Mid( Mime, i+2, 1 )), 6 ) & B64BMPDec2Bin( B64BMPAsc( Mid( Mime, i+3, 1 )), 6 )
           writeByte( H, B64BMPBin2Dec( SubMime[1:8] )) : writeByte( H, B64BMPBin2Dec( SubMime[9:16] )) : writeByte( H, B64BMPBin2Dec( SubMime[17:24] ))
       End For
       If Right( Mime, 2 ) = "==" Then
          SubMime = B64BMPDec2Bin( B64BMPAsc( Mid( Mime, MimeLen+1, 1 )), 6 ) & B64BMPDec2Bin( B64BMPAsc( Mid( Mime, MimeLen+2, 1 )), 6 )
          writeByte( H, B64BMPBin2Dec( SubMime[1:8] ))
       Else If Right( Mime, 1 ) = "=" Then
          SubMime = B64BMPDec2Bin( B64BMPAsc( Mid( Mime, MimeLen+1, 1 )), 6 ) & B64BMPDec2Bin( B64BMPAsc( Mid( Mime, MimeLen+2, 1 )), 6 ) &
                    B64BMPDec2Bin( B64BMPAsc( Mid( Mime, MimeLen+3, 1 )), 6 )
          writeByte( H, B64BMPBin2Dec( SubMime[1:8] )) : writeByte( H, B64BMPBin2Dec( SubMime[9:16] ))
       End If
    fClose( H )
End Function

Function B64BMPDec2Bin( Deci=0, Leng=8 )
    Dim Bina = Bin( Deci )
    While Len( Bina ) < Leng  :  Bina = "0" & Bina  :  End While
    Return Bina
End Function

Function B64BMPBin2Dec( Bina="0" )
    While Len( Bina ) < 8  :  Bina = "0" & Bina  :  End While
    Bina = Right( Bina, 8 )
    Return 128*Bina[1]+64*Bina[2]+32*Bina[3]+16*Bina[4]+8*Bina[5]+4*Bina[6]+2*Bina[7]+Bina[8]
End Function

Function B64BMPAsc( Ch )
    Dim Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
    Return InStr( Base64, Ch )-1
End Function

