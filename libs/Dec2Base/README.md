Exchange Between Numbering Systems
==================================

 * `wxDecToBase(  n , base )`      Convert integer decimal number to any other base
 * `wxBaseToDec( "n", base )`      Converts number (as text) from any base to decimal.

**base** parameter is optional, if omitted it uses 16 (hexadecimal). The **base** can be any
number less than or equal to 85 and the digits according to the encoding proposed in RFC 1924:

`0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_&#xB4;{|}~`

If the base is less than or equal to 36 (from 0 to Z), the letters can be either uppercase or
lowercase. 

Constants
---------

**base** can also be a predefined constant:

 * `BASE36`     : Case insensitive [ 0..9A..Z ]
 * `BASE85`     : Full table RFC 1924 [ 0..9A..Za..z!#$%&()*+-;<=>?@^_&#xB4;{|}~ ]
 * `BASE32I`    : Inverted Base32 [ 0123456789ACDEFHIJKMNPQRSTUVWXYZ ]
 * `BASE32`     : Original Base32 [ ABCDEFGHIJKLMNOPQRSTUVWXYZ234567 ]
 * `BASE64`     : MIME Base64 [ A..Za..z0..9+/ ]
 * `ASCII85`    : Ascii85 [ !\"#$%&'()*+,-./0..9:;<=>?@A..Z[\\]^_&#xB4;a..u
