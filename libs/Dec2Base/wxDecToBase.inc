
/////////////////    Encode and decode any integer to any base    \\\\\\\\\\\\\\\\\\\\
/////////////////          wxDecToBase  and  wxBaseToDec          \\\\\\\\\\\\\\\\\\\\

Function wxDecToBase( N, B = 16 )
    If B > 85 Then : Print "ERROR: The base cannot exceed 85" : Return : End If
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
    If B > 85 Then : Print "ERROR: The base cannot exceed 85" : Return : End If
    If (LCase( TypeOf( N )) = "integer" Or LCase( TypeOf( N )) = "number" ) And B <= 10 Then N = Str( N )
    Const Digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~"
    Dim P = Len( N ), R = 0, J
    If B <= 36 Then N = UCase( N )
    For J = 1 To P
        If Not Instr( Left( Digits, B ), N[J] ) Then : Print "ERROR: digit "& N[J] &" not valid for base " & B : Return : End If
        R += B^(P - J) * ( Instr( Digits, N[J] )-1 )
    End For
    Return R
End Function
