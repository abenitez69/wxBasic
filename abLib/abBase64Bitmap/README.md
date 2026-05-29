*abBase64Bitmap*: Bitmap image from MIME Base64
===============================================

Encode to MIME Base64 and decode from MIME Base64.


| Library description  | |
|:---------------------|:----------------------------------------------------|
| **Name:**            |  **abBase64Bitmap**                                 |
| **Version:**         |  1.3                                                |
| **Type:**            |  &#9675; Function  &nbsp; &nbsp; &nbsp;  &#9673; Class  &nbsp; &nbsp; &nbsp;  &#9675; Other |
| **Category:**        |  wxBitmap and string (Base64)                        |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9745; 2.08  &nbsp; &nbsp; &nbsp;  &#9745; 3.2  &nbsp; &nbsp; &nbsp;  &#9744; Console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9745; Linux  &nbsp; &nbsp; &nbsp;  &#9745; macOS  |


 
Syntax
------

* `abBase64Bitmap( ImageBase64 )   `    Constructor to creates a bitmap from a Base64 text.


Remark
------

* `ImageBase64`  is a string coded as Base64.

The string Base64 Data Encodings according to the encoding proposed in 
[RFC 3548](https://www.rfc-editor.org/rfc/rfc3548) and [RFC 4648](https://www.rfc-editor.org/rfc/rfc4648):

`ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/`


Example
-------

```python
Option Explicit
Include "abBase64.inc"

Dim H = fOpen( "demo.jpg", "r" ),
            SizeJPG = Lof( H ),
            BinLst = []
            For i=1 To SizeJPG
                BinLst.Append( readByte( H ))
            End For
        fClose( H )

Dim MimeBase64 = abBase64Encode( BinLst )

H = fOpen( "to_base64.txt", "w" )
        fPuts( H, MimeBase64 )
    fClose( H )

Dim Binar = abBase64Decode( MimeBase64 )

H = fOpen( "from_base64.jpg", "w" )
       For i = 1 To Binar.Length()
          writeByte( H, Binar[i] )
       End For
    fClose( H )
```


