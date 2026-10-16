BMD and wxBMD
================

*Basic Markdown Documentation* (**BMD**) is a lightweight markup language, created by Agustin Benitez in wxBasic, which is used to document the wxBasic programming language, modules, and programs; using Markdown markup language.

**BMD** is designed to be a simple, clean markup language with just enough syntax to be useful. Some of its goals are:

* Easy to parse;
* Easy to convert to other formats, such as Markdown, HTML, Rich Text Format (RTF), or LaTeX (via `Save as` option on right-click menu);
* Easy to incorporate sample code;
* Easy to read without a BMD parser (i.e., in its source-code form);
* Easy to write.


| Script description   | |
|:---------------------|:----------------------------------------------------|
| **File name:**       |  wxBMD.wxb                                          |
| **Version:**         |  3.4                                                |
| **Type:**            |  &#9675; Function  &nbsp; &nbsp; &nbsp;  &#9675; Class  &nbsp; &nbsp; &nbsp;  &#9673; Script |
| **Category:**        |  Utility for wxBasic                                |
| **wxBasic version:** |  &#9744; 0.6  &nbsp; &nbsp; &nbsp;  &#9746; 2.5  &nbsp; &nbsp; &nbsp;  &#9746; 2.08  &nbsp; &nbsp; &nbsp;  &#9746; 3.2  |
| **wxBasic UI:** |  &#9744; CLI  &nbsp; &nbsp; &nbsp;  &#9746; GUI  &nbsp; &nbsp; &nbsp;  &#9744; CLI & wxWidgets   |
| **OS:**              |  &#9746; Windows  &nbsp; &nbsp; &nbsp;  &#9746; Linux  &nbsp; &nbsp; &nbsp;  &#9746; macOS  |


 
wxBMD Syntax
------------

&nbsp;&nbsp;&nbsp; `wxbmd <script.wxb> | <library.inc>   ` Open a wxBasic file with wxBMD parser.

BMD Markup Syntax
-----------------

* The BMD parser assumes that all initial lines beginning with consecutive wxBasic comments (`'` or `//`)  containing BMD documentation.
* BMD documentation ends when the first uncommented line appears. Any subsequent content is ignored by the parser.
* Any indentation to the left of the comment symbol is ignored.
* The indentation to the right of the comment symbol is ignored, if it is the same on all lines. Additional indentation on one or more specific lines is considered part of the Markdown code (in a code blocks or a nest list).
* The first lines containing the Shebang (`#!`) and space are ignored.
* For extended ASCII characters, encode the script as **UTF-8**, but using only characters that are valid in Windows-1252.
* For help with Markdown syntax, run the program without specifying any file.

### Windows-1252 characters

```
	!	"	#	$	%	&	'	(	)	*	+	,	-	.	/   
	0	1	2	3	4	5	6	7	8	9	:	;	<	=	>	?   
	@	A	B	C	D	E	F	G	H	I	J	K	L	M	N	O   
	P	Q	R	S	T	U	V	W	X	Y	Z	[	\	]	^	_   
	`	a	b	c	d	e	f	g	h	i	j	k	l	m	n	o   
	p	q	r	s	t	u	v	w	x	y	z	{	|	}	~   
	
	€	‚	ƒ	„	…	†	‡	ˆ	‰	Š	‹	Œ	Ž	‘	’	“   
	”	•	–	—	~	™	š	›	œ	ž	Ÿ	  
	
	¡	¢	£	¤	¥	¦	§	¨	©	ª	«	¬		®	¯   
	°	±	²	³	´	µ	¶	·	¸	¹	º	»	¼	½	¾	¿   
	À	Á	Â	Ã	Ä	Å	Æ	Ç	È	É	Ê	Ë	Ì	Í	Î	Ï   
	Ð	Ñ	Ò	Ó	Ô	Õ	Ö	×	Ø	Ù	Ú	Û	Ü	Ý	Þ	ß   
	à	á	â	ã	ä	å	æ	ç	è	é	ê	ë	ì	í	î	ï   
	ð	ñ	ò	ó	ô	õ	ö	÷	ø	ù	ú	û	ü	ý	þ	ÿ   
```
