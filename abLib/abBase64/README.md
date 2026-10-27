abBase64
=========

Encode to MIME Base64 and decode from MIME Base64.


| Script description   | |
|:---------------------|:----------------------------------------------------|
| **File name:**       |  abBase64.inc                                          |
| **Version:**         |  2.0                                                |
| **Type:**            |  &#9673; Functions  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9675; Script |
| **Category:**        |  Numeric (byte) and string (Base 64)                 |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9746; 2.5  &nbsp; &nbsp; &nbsp;  &#9746; 2.08  &nbsp; &nbsp; &nbsp;  &#9746; 3.2  |
| **wxBasic UI:** |  &#9746; CLI  &nbsp; &nbsp; &nbsp;  &#9746; GUI  &nbsp; &nbsp; &nbsp;  &#9746; CLI & wxWidgets   |
| **OS:**              |  &#9746; Windows  &nbsp; &nbsp; &nbsp;  &#9746; Linux  &nbsp; &nbsp; &nbsp;  &#9746; macOS  |
| **Developer:**       | Agustín Benítez Hernández |

 
Syntax
------

* `TextBase64 = abBase64Encode( ByteList )    `    Returns a string coded as Base64 from binary byte list.
* `ByteList = abBase64Decode( TextBase64 )    `    Returns a binary byte list from string coded as Base64.


Remark
------

* `ByteList`    is a list of binary bytes; 
* `TextBase64`  is a string coded as Base64;

The string Base64 Data Encodings according to the encoding proposed in 
[RFC 3548](https://www.rfc-editor.org/rfc/rfc3548) and [RFC 4648](https://www.rfc-editor.org/rfc/rfc4648):

`ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/`


Example
-------

```python
Option Explicit
Include "abBase64.inc"

Dim BinLst = [],
H = fOpen( "demo.jpg", "r" )
     For i=1 To Lof( H )
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

