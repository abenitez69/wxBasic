*JPEGExif*: Get JPEG metadata
=============================

Extract Exif metadata from a JPEG image.


| Library description  | |
|:---------------------|:----------------------------------------------------|
| **Name:**            |  JPEGExif                                           |
| **Version:**         |  1.1                                                |
| **Type:**            |  &#9673; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9675; Other |
| **Category:**        |  Images                                 |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9745; 2.08  &nbsp; &nbsp; &nbsp;  &#9745; 3.2  &nbsp; &nbsp; &nbsp;  &#9745; Console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9745; Linux  &nbsp; &nbsp; &nbsp;  &#9745; macOS  |

 
Syntax
------

* `wxGetImageTitle( FileName )   `    Extract title from image's exif.
* `wxGetImageAuthor( FileName )  `    Extract the photographer's data from image's exif.
* `wxGetCameraMaker( FileName )  `    Extract camera maker from image's exif.
* `wxGetCameraModel( FileName )  `    Extract camera model from image's exif.
* `wxGetXDimension( FileName )   `    Extract the X size of the image.
* `wxGetYDimension( FileName )   `    Extract the Y size of the image.
* `wxGetXPreview( FileName )     `    Extract the X size of the image thumbnail.
* `wxGetYPreview( FileName )     `    Extract the Y size of the image thumbnail.


Remark
------

* `Filename`    is a string with the path and name of JPEG file.


Example
-------

```python
Option Explicit
Include "wxJPEGExif.inc"
Dim FileName = "demo.jpg"

Print "Image title: "; wxGetImageTitle( FileName )
Print "Created by: "; wxGetImageAuthor( FileName )
Print "Taked: "; wxGetImageDate( FileName )
Print "Image size: "; wxGetXDimension( FileName ); " x "; wxGetYDimension( FileName ); " pixels"
Print "Equipment manufacturer: "; wxGetCameraMaker( FileName )
Print "Equipment model: "; wxGetCameraModel( FileName )
Print "Preview size: "; wxGetXPreview( FileName ); " x "; wxGetYPreview( FileName ); " pixels"
