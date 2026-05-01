SlideShow Windows Screensaver
=============================

Show photos randomly and includes the metadata (EXIF) text:
  * Title (in upper right of screen) and,
  * Author/date (in the lower right).


| Script description   | |
|:---------------------|:----------------------------------------------------|
| **Name:**            |  SlideShow                                          |
| **Version:**         |  4.2                                                |
| **Type:**            |  &#9675; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9673; Script |
| **Category:**        |  System / Images                                |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9745; 2.5  &nbsp; &nbsp; &nbsp;  &#9744; 2.08  &nbsp; &nbsp; &nbsp;  &#9744; 3.2  &nbsp; &nbsp; &nbsp;  &#9744; Console  |
| **OS:**              |  &#9745; Windows  &nbsp; &nbsp; &nbsp;  &#9744; Linux  &nbsp; &nbsp; &nbsp;  &#9744; macOS  |


Remarks
-------

Images can be stored in a local folder (relative or absolute path), e.g.:
  * ./pictutes
  * C:\Users\Agustin\Pictures
or shared from an HTTP or FTP server, e.g.:

Optionally, the image folder can contain several subfolders named WxH (e.g., 1600x1200, 1920x1080, etc.), specifying the width and height of the images in each. The program automatically selects the folder with the aspect ratio and resolution closest to the computer screen and then adjusts the image to full screen. This allows manual "pan & scan", without affecting the image composition.

If the resolution subfolders are omitted and the photos are not the same resolution as the screen, the program performs "pan & scan" automatically.
myColor = wxGetColorFromUser( Nothing, wxColour(0,0,0) )
Print "RGB:", myColor.Red(), myColor.Green(), myColor.Blue()
```

