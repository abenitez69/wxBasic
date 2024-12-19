

///////////   wxGetImageTitle    &   wxGetImageAuthor   \\\\\\\\\\\\\\
///////////   wxGetImageDate   \\\\\\\\\\\\\\
///////////   wxGetCameraMaker   &   wxGetCameraModel   \\\\\\\\\\\\\\
///////////   wxGetPreviewX      &   wxGetPreviewY      \\\\\\\\\\\\\\


Function wxGetImageTitle( fName )
    If Not FileExists( fName ) Then Return ""
    Dim B0,
        fHandle = fOpen( fName, "r" )
           If Not IsJPG( fHandle ) Then Return ""
           If Not IsExif( fHandle ) Then Return ""
           Dim ExifLength = ExifLen( fHandle )
           For I = 1 To 6 : B0 = ReadByte( fHandle ) : End For  ' Read "Exif00" label
           Dim ExifString = ReadExifString ( fHandle, 0x01, 0x0E )   ' Description marker
        fClose( fHandle )
    Return ExifString
End Function

Function wxGetImageAuthor( fName )
    If Not FileExists( fName ) Then Return ""
    Dim B0,
        fHandle = fOpen( fName, "r" )
           If Not IsJPG( fHandle ) Then Return ""
           If Not IsExif( fHandle ) Then Return ""
           Dim ExifLength = ExifLen( fHandle )
           For I = 1 To 6 : B0 = ReadByte( fHandle ) : End For  ' Read "Exif00" label
           Dim ExifString = ReadExifString ( fHandle, 0x01, 0x3B )   ' Artist marker
        fClose( fHandle )
    Return ExifString
End Function

Function wxGetImageDate( fName, AsString = False )
    If Not FileExists( fName ) Then Return ""
    Dim B0,
        fHandle = fOpen( fName, "r" )
           If Not IsJPG( fHandle ) Then Return ""
           If Not IsExif( fHandle ) Then Return ""
           Dim ExifLength = ExifLen( fHandle )
           For I = 1 To 6 : B0 = ReadByte( fHandle ) : End For  ' Read "Exif00" label
           Dim ExifString = ReadExifString ( fHandle, 0x90, 0x03 )   ' DateTimeOriginal marker
        fClose( fHandle )
    If ExifString = "" Then
        fHandle = fOpen( fName, "r" )
           If Not IsJPG( fHandle ) Then Return ""
           If Not IsExif( fHandle ) Then Return ""
           ExifLength = ExifLen( fHandle )
           For I = 1 To 6 : B0 = ReadByte( fHandle ) : End For  ' Read "Exif00" label
           ExifString = ReadExifString ( fHandle, 0x90, 0x04 )   ' DateTimeDigitized marker
        fClose( fHandle )
    End If
    If Not AsString Then
       Dim StrDate = Mid( ExifString, 6, 2 ) & " " & Mid( ExifString, 9, 2 ) & ", " & Left( ExifString, 4 ) & " " & Right( ExifString, 8 )
       ExifString = TimeValue( StrDate )
    End If
    Return ExifString
End Function

Function wxGetCameraMaker( fName )
    If Not FileExists( fName ) Then Return ""
    Dim B0,
        fHandle = fOpen( fName, "r" )
           If Not IsJPG( fHandle ) Then Return ""
           If Not IsExif( fHandle ) Then Return ""
           Dim ExifLength = ExifLen( fHandle )
           For I = 1 To 6 : B0 = ReadByte( fHandle ) : End For  ' Read "Exif00" label
           Dim ExifString = ReadExifString ( fHandle, 0x01, 0x0F )   ' CameraMaker marker
        fClose( fHandle )
    Return ExifString
End Function

Function wxGetCameraModel( fName )
    If Not FileExists( fName ) Then Return ""
    Dim B0,
        fHandle = fOpen( fName, "r" )
           If Not IsJPG( fHandle ) Then Return ""
           If Not IsExif( fHandle ) Then Return ""
           Dim ExifLength = ExifLen( fHandle )
           For I = 1 To 6 : B0 = ReadByte( fHandle ) : End For  ' Read "Exif00" label
           Dim ExifString = ReadExifString ( fHandle, 0x01, 0x10 )   ' CameraModel marker
        fClose( fHandle )
    Return ExifString
End Function

Function wxGetXDimension( fName )
    If Not FileExists( fName ) Then Return 0
    Dim B0,
        fHandle = fOpen( fName, "r" )
           If Not IsJPG( fHandle ) Then Return 0
           If Not IsExif( fHandle ) Then Return wxGetXPreview( fName )
           Dim ExifLength = ExifLen( fHandle )
           For I = 1 To 6 : B0 = ReadByte( fHandle ) : End For  ' Read "Exif00" label
           Dim PixelDim = ReadPixelDimension ( fHandle, 0xA0, 0x02 )   ' PixelXDimension marker
        fClose( fHandle )
        If PixelDim = 0 Or PixelDim > 100000 Then PixelDim = wxGetXPreview( fName )
    Return PixelDim
End Function

Function wxGetYDimension( fName )
    If Not FileExists( fName ) Then Return 0
    Dim B0,
        fHandle = fOpen( fName, "r" )
           If Not IsJPG( fHandle ) Then Return 0
           If Not IsExif( fHandle ) Then Return wxGetYPreview( fName )
           Dim ExifLength = ExifLen( fHandle )
           For I = 1 To 6 : B0 = ReadByte( fHandle ) : End For  ' Read "Exif00" label
           Dim PixelDim = ReadPixelDimension ( fHandle, 0xA0, 0x03 )   ' PixelYDimension marker
        fClose( fHandle )
    If PixelDim = 0 Or PixelDim > 100000 Then PixelDim = wxGetYPreview( fName )
    Return PixelDim
End Function

Function wxGetXPreview( fName )
    If Not FileExists( fName ) Then Return 0
    Dim B0, B1,
        fHandle = fOpen( fName, "r" )
           If Not IsJPG( fHandle ) Then Return 0
           If Not IsSOF0( fHandle ) Then Return 0
           Dim SOF0Length = SOF0Len( fHandle )
           B0 = ReadByte( fHandle )
           B0 = ReadByte( fHandle ) : B1 = ReadByte( fHandle )
           B0 = ReadByte( fHandle ) : B1 = ReadByte( fHandle )
           Dim X = 256*B0 + B1
        fClose( fHandle )
    Return X
End Function

Function wxGetYPreview( fName )
    If Not FileExists( fName ) Then Return 0
    Dim B0, B1,
        fHandle = fOpen( fName, "r" )
           If Not IsJPG( fHandle ) Then Return 0
           If Not IsSOF0( fHandle ) Then Return 0
           Dim SOF0Length = SOF0Len( fHandle )
           B0 = ReadByte( fHandle )
           B0 = ReadByte( fHandle ) : B1 = ReadByte( fHandle )
           Dim Y = 256*B0 + B1
        fClose( fHandle )
    Return Y
End Function





////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
///////////////////////////////    INTERNAL  FUNCTIONS    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


Function IsJPG( fHandle )
    Dim Tmp0 = ReadByte( fHandle ),
        Tmp1 = ReadByte( fHandle )
    If UCase( Hex( Tmp0 ) & Hex( Tmp1 )) = "FFD8" Then Return True  ' Start Of Image (SOI) marker
    Return False
End Function


// Exif functions

Function IsExif( fHandle )
    // Exif: Exchangeable image file format
    Seek( fHandle, 1 )
    Dim Tmp0 = ReadByte( fHandle ),
        Tmp1 = ReadByte( fHandle ),
        N = 0
    While UCase( Hex( Tmp0 ) & Hex( Tmp1 )) <> "FFE1"  ' Exif (APP1) marker
       Tmp0 = Tmp1
       Tmp1 = ReadByte( fHandle )
       N += 1
       If N >= 10000 Then Return False
    End While
    Return N
End Function

Function ExifLen( fHandle )
    Dim Tmp0 = ReadByte( fHandle ),
        Tmp1 = ReadByte( fHandle )
    Return Tmp1 + 256 * Tmp0
End Function

Function ExifByteOrder( fHandle )
    // Byte Order: Written as either 0x4949 ("II" from Intel) for little endian or
    //             0x4D4D ("MM" from Motorola) for big endian, depending on the CPU
    //             of the machine doing the recording.
    Dim Tmp0 = ReadByte( fHandle ),
        Tmp1 = ReadByte( fHandle )
    If UCase( Hex( Tmp0 ) & Hex( Tmp1 )) = "4D4D" Then Return False  ' Motorola byte order
    Return True  ' Intel byte order
End Function

Function ReadExifString ( fHandle, N0, N1 )
     Dim B0, B1, B2, B3,
     ByteOrder = ExifByteOrder( fHandle )
     If ByteOrder Then : B0 = N1 : N1 = N0 : N0 = B0 : End If
     Dim N = 0
     While Not( B0 = N0 And B1 = N1 )  ' Tag ID marker
        B0 = B1
        B1 = ReadByte( fHandle )
        N += 1
        If N >= 10000 Then Return ""
     End While

     B0 = ReadByte( fHandle ) : B1 = ReadByte( fHandle )   ' Read type
     Dim ExifType = 256*B0 + B1
     If ByteOrder Then ExifType = 256*B1 + B0

     B0 = ReadByte( fHandle ) : B1 = ReadByte( fHandle )   ' Read string length
     B2 = ReadByte( fHandle ) : B3 = ReadByte( fHandle )
     Dim StrLength = 16777216*B0 + 65536*B1 + 256*B2 + B3
     If ByteOrder Then StrLength = 16777216*B3 + 65536*B2 + 256*B1 + B0

     B0 = ReadByte( fHandle ) : B1 = ReadByte( fHandle )   ' Read string offset
     B2 = ReadByte( fHandle ) : B3 = ReadByte( fHandle )
     Dim StrOfset = 16777216*B0 + 65536*B1 + 256*B2 + B3                   +11
     If ByteOrder Then StrOfset = 16777216*B3 + 65536*B2 + 256*B1 + B0     +11

     Seek( fHandle, 1 )
     Seek( fHandle, StrOfset + IsExif( fHandle ))
     Dim Label = ""
     For I = 1 To StrLength
         B0 = ReadByte( fHandle )
         Label = Label & Chr( B0 )
     End For
     Return Label
End Function

Function ReadPixelDimension ( fHandle, N0, N1 )
     Dim B0, B1, B2, B3,
     ByteOrder = ExifByteOrder( fHandle )
     If ByteOrder Then : B0 = N1 : N1 = N0 : N0 = B0 : End If
     Dim N = 0
     While Not( B0 = N0 And B1 = N1 )  ' Tag ID marker
        B0 = B1
        B1 = ReadByte( fHandle )
        N += 1
        If N >= 10000 Then Return 0
     End While

     B0 = ReadByte( fHandle ) : B1 = ReadByte( fHandle )   ' Read type
     Dim ExifType = 256*B0 + B1
     If ByteOrder Then ExifType = 256*B1 + B0

     B0 = ReadByte( fHandle ) : B1 = ReadByte( fHandle )   ' Read data length
     B2 = ReadByte( fHandle ) : B3 = ReadByte( fHandle )
     Dim StrLength = 16777216*B0 + 65536*B1 + 256*B2 + B3
     If ByteOrder Then StrLength = 16777216*B3 + 65536*B2 + 256*B1 + B0

     B0 = ReadByte( fHandle ) : B1 = ReadByte( fHandle )   ' Read data
     B2 = ReadByte( fHandle ) : B3 = ReadByte( fHandle )
     Dim PixelDim = 16777216*B0 + 65536*B1 + 256*B2 + B3
     If ByteOrder Then PixelDim = 16777216*B3 + 65536*B2 + 256*B1 + B0
     Return PixelDim
End Function



// SOF0 functions

Function IsSOF0( fHandle )
    Seek( fHandle, 1 )
    Dim Tmp0 = ReadByte( fHandle ),
        Tmp1 = ReadByte( fHandle ),
        N = 0
    While UCase( Hex( Tmp0 ) & Hex( Tmp1 )) <> "FFC0"  ' SOF0 marker
       Tmp0 = Tmp1
       Tmp1 = ReadByte( fHandle )
       N += 1
       If N >= 10000 Then Return False
    End While
    Return N
End Function

Function SOF0Len( fHandle )
    Dim Tmp0 = ReadByte( fHandle ),
        Tmp1 = ReadByte( fHandle )
    Return Tmp1 + 256 * Tmp0
End Function
