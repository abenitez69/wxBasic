#!/usr/bin/python

import sys
import base64

n = len( sys.argv )
if n < 2 :
       print( "\nEncode a binary file in Base64 and return a wxBasic script with a string" )
       print( "variable ready to be used as argument in 'abBase64Bitmap' constructor.\n" )
       print( "Usage:  python bin2b64.py <binfilename> [<b64filename>]\n" )
       print( "   <binfilename>   Name of the binary file to be encoded as Base64." )
       print( "   <b64filename>   Name of the output wxBasic script with the Base64" )
       print( "                   encoded string variable. If omitted, uses" )
       print( "                   '<bin_filename>.wxb'.\n" )
       sys.exit( 0 )

bin_file = sys.argv[1]
b64_file = sys.argv[n-1]
if n < 3 : b64_file = bin_file + ".wxb"

with open( bin_file, "rb" ) as f:
        bin_lst = f.read()

mime_base64 = base64.encodebytes( bin_lst ).decode( "ascii" )
mime_base64 = mime_base64.replace( "\n", "\" &\n\t\"" )
mime_base64 = "myVar = \"" + mime_base64 + "\""

with open( b64_file, "w" ) as f:
    f.write( mime_base64 )

print( "Done.\n" )