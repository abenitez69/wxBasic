echo="" // & @echo off
cls()
rem="" &
"bvmc.exe" //%0 %0 %1 %2 %3 %4 %5 %6 %7 %8
goto =now()



///////////////////////////////////////////////////////////////////////
//  Begin wxBasic code
///////////////////////////////////////////////////////////////////////

   Print "\nHello World in wxBasic" , WXBASIC_VERSION , "\n\n";

   Print "Script name: \n " , Command(3) , "\n\n";

   If Command(4) Then
       Print "Arguments:\n";
       For i = 4 To 9 : If Command(i) Then Print "   - "; Command(i); "\n"; : End For
       Print "\n";
   End If

   Print "Wait 20 sec: \n";
   For i = 0 To 20  :  Gauge(5*i) : Sleep(1) :  End For

   Print "\n\nPress ENTER key to continue . . .\n";
   Input None : Print



   Sub Gauge( value )
       Dim width = 50, margin = 2, chars = [219, 176]
       Dim bar = Int( width * value/100 )
       Print Chr(13) & Repeat( 32, margin ) & "[" & Repeat( chars[1], bar ) & Repeat( chars[2], width-bar ) & "]";
   End Sub

   Sub Sleep( TimeDelay )
       Dim StartSeconds =  Now() :  While ( Now() - StartSeconds ) < TimeDelay  :  End While
   End Sub



///////////////////////////////////////////////////////////////////////
// End wxBasic script and return to BAT code
///////////////////////////////////////////////////////////////////////

:now()


