use MIME::Base64;

my $BinFile = $ARGV[0];
exit if( $BinFile eq "" );

open( FILE, $BinFile );
    my $BinLst = join( '', <FILE> );
close( FILE );

my $MimeBase64 = encode_base64( $BinLst );
$MimeBase64 =~ s/\n/" &\n\t"/g;
$MimeBase64 = "myVar = \"" . $MimeBase64 . "\"";

open( FILE, ">bin_to_base64.wxb" );
    print FILE $MimeBase64;
close( FILE );




