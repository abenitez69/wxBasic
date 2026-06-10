#!/usr/bin/perl

use MIME::Base64;

my $n = @ARGV;
if( $n < 1 ) {
      print "\nEncode a binary file in Base64 and return a wxBasic script with a string\n";
      print "variable ready to be used as argument in 'abBase64Bitmap' constructor.\n\n";
      print "Usage:  perl bin2b64.pl <binfilename> [<b64filename>]\n\n";
      print "   <binfilename>   Name of the binary file to be encoded as Base64.\n";
      print "   <b64filename>   Name of the output wxBasic script with the Base64\n";
      print "                   encoded string variable. If omitted, uses\n";
      print "                   '<bin_filename>.wxb'.\n\n";
      exit;  }

my $bin_file = $ARGV[0];
my $b64_file = $ARGV[$n-1];
$b64_file = $bin_file . ".wxb" if( $n < 2 );

open( FILE, $bin_file );
    binmode( FILE );
    my $bin_lst = join( '', <FILE> );
close( FILE );

my $mime_base64 = encode_base64( $bin_lst );
$mime_base64 =~ s/\n/" &\n\t"/g;
$mime_base64 = "myVar = \"" . $mime_base64 . "\"";

open( FILE, ">$b64_file" );
    print FILE $mime_base64;
close( FILE );

print( "Done.\n\n" );

