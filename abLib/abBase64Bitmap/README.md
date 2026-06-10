*abBase64Bitmap*: Bitmap image from MIME Base64
===============================================

The *wxBitmap* class includes several constructors (*wxBitmap*, *wxEmptyBitmap*, *wxCopyBitmap*, etc.), but they all load the image from an external file.
In small (single-file) projects, it is convenient to include the images within the script itself.

**abBase64Bitmap** is a constructor for the *wxBitmap* class that allows loading the image from a Base64 encoded string variable.


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
Include "abBase64Bitmap.inc"

Dim myVar = "iVBORw0KGgoAAAANSUhEUgAAAEAAAAAgCAYAAACinX6EAAAABmJLR0QAAAAAAAD5Q7t/AAAACXBI" &
            "WXMAAA50AAAOdAFrJLPWAAAAB3RJTUUH6gYKEAYI31ELRAAAAtxJREFUaN7tWD9oU2EQ//1qoIJC" &
            "hQoVMrTgUIeCDoIOgkgj7eAgGHB1cBBcCnZwFTsILjqJmEHQoaDgIljRouDSQaFDhBYFCwpmsJRQ" &
            "RaWFc8g9eb7cfS9J2+RJcnDDu7vv3nf3fffvo4igk0CyoxvIbffmRYTN6vHOgASsAyIJa0ntxzbH" &
            "09OHLoeeA3oO6Dmg54Cuhtz/unF2swO85o1kLwS2xQEkh0jeJPmBpJBcI3mP5FATXeJhks9I/iS5" &
            "TvIFyfFMXqc4ApgAsKY9ZRK/AhhVOYsvyhsHsO7IXE/8L7mFv6j6GoaafjEQvnxiMycBbHjGKX4C" &
            "MBDgDweMj/DyVhwQ1t2cAxglFJKDAMoADjRwcR4DKDq8OQCTKet/ATgiIsskpZVhCK+MBae2NgzN" &
            "NGg8AsajAeMBYDeAG5lJgprcLhj870rfqziltDR4C+CojsYFABVD5izJ4aw0QkU9lbpNish87Ps2" &
            "ySW95h58AzApIqsa4PMkCwAWjb6jmJUyWDB4swnjo6rxHMDDgM5bkfGxNe8BlAzZE218eapDEWHk" &
            "gDFjzf2AvlKA99Shzxq0sTYVewNrL1qRA0acOA7FuAdLDn3RoI10sAP6JwRyxlVfDTRPPwK83w69" &
            "msVZpC8QM7sCvMEAb49D78/i/Bg5YMXgHQpoOx7geXFt6fvSLuNrjRBdB5StEhjQeLGFJumMQSu3" &
            "kr13IgQWDN40ybyxofMpzrlE8qARMlOG7EJ4UHM6+x1wgFWi9gF4TXKCZD/JAZJXUnoAaMc4F42+" &
            "JEe1NO53ZorOZobYMPQk5WS3G16KyOnQMOSHBZochqIkKHW0eBW4qlNaI1BKmRTTYFP/1/a675ZB" &
            "EVl24jQJKwCmUxLkxxQdMyLyLnNPYiJyV52w6chXdNCpBhqhqmb8SmBWuNZ502k/iWlAHgPwKPY0" &
            "9hnAHQB59/mmXkcewAN9HdoA8AbAOUNOOoUigj+EzziRzx0f6wAAAABJRU5ErkJggg=="

Dim myImage As wxBitmap = abBase64Bitmap( myVar ),
    myFrame As wxFrame = New wxFrame( Nothing, -1, "", wxPoint(10,10), wxSize( myImage.GetWidth() + 40, myImage.GetHeight() + 60 )),
    myBitmap As wxBitmapButton = New wxBitmapButton( myFrame, -1 , myImage, wxPoint(-1, -1), wxSize(-1, -1), wxNO_BORDER )
myFrame.Centre()
myFrame.Show( TRUE )
```


