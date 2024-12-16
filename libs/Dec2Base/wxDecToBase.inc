Const wxDecToBase_Base_36  = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",
      wxDecToBase_Base_85  = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~",      '(https://datatracker.ietf.org/doc/html/rfc1924)
      wxDecToBase_Base_32I = "0123456789ACDEFHIJKMNPQRSTUVWXYZ",
      wxDecToBase_Base_64  = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",
      wxDecToBase_Base_32  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567",
      wxDecToBase_Ascii_85 = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstu"

Const BASE36 = -1, BASE85 = -2, BASE32I = -3, BASE32 = -4, BASE64 = -5, ASCII85 = -6

/////////////////    Code and uncode    \\\\\\\\\\\\\\\\\\\\
///////////   wxDecToBase  and  wxBaseToDec   \\\\\\\\\\\\\\

Function wxDecToBase( N, B = 16 )
    Dim Digits = wxDecToBase_Base_36
    If B > 36 Then B = BASE85
    Select Case B
       Case BASE36   : B = 36   : Digits = wxDecToBase_Base_36
       Case BASE85   : B = 85   : Digits = wxDecToBase_Base_85
       Case BASE32I  : B = 32   : Digits = wxDecToBase_Base_32I
       Case BASE32   : B = 32   : Digits = wxDecToBase_Base_32
       Case BASE64   : B = 64   : Digits = wxDecToBase_Base_64
       Case ASCII85  : B = 85   : Digits = wxDecToBase_Ascii_85
    End Select
    Dim D = N, P = 0, R = "", I, J
    While Int( D/(B^P) ) > 0  : P += 1 :  End While
    For J = P-1 To 0 Step -1
        I = Int( D/(B^J) )
        D = D - I*(B^J)
        R &= Digits[I+1]
    End For
    Return R
End Function

Function wxBaseToDec( N, B = 16 )
    Dim Digits = wxDecToBase_Base_36
    If B > 36 Then B = BASE85
    Select Case B
       Case BASE36   : B = 36   : Digits = wxDecToBase_Base_36
       Case BASE85   : B = 85   : Digits = wxDecToBase_Base_85
       Case BASE32I  : B = 32   : Digits = wxDecToBase_Base_32I
       Case BASE32   : B = 32   : Digits = wxDecToBase_Base_32
       Case BASE64   : B = 64   : Digits = wxDecToBase_Base_64
       Case ASCII85  : B = 85   : Digits = wxDecToBase_Ascii_85
    End Select
    If UCase( B ) = "BASE64" Or UCase( B ) = "BASE 64" Or UCase( B ) = "BASE-64" Or UCase( B ) = "BASE_64" Then Digits = wxDecToBase_Base_64
    Dim P = Len( N ), R = 0, J
    If B <= 36 Then N = UCase( N )
    For J = 1 To P
        R += B^(P - J) * ( Instr( Digits, N[J] )-1 )
    End For
    Return R
End Function
