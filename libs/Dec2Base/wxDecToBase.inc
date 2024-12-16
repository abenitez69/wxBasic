
/////////////////    Encode and decode any integer to any base    \\\\\\\\\\\\\\\\\\\\
/////////////////          wxDecToBase  and  wxBaseToDec          \\\\\\\\\\\\\\\\\\\\

Function wxDecToBase( N, B = 16 )
    Const Digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~"
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
    Const Digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~"
    Dim P = Len( N ), R = 0, J
    If B <= 36 Then N = UCase( N )
    For J = 1 To P
        R += B^(P - J) * ( Instr( Digits, N[J] )-1 )
    End For
    Return R
End Function
