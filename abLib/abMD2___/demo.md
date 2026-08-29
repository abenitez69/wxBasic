
BASIC MARKDOWN SYNTAX
=====================

> __NOTE:__ For a full Markdown guide see: 
> **CONE, M. (2020)** [___The Markdown Guide___](https://dl.icdst.org/pdfs/files3/c79990b0b853932d36ddc117ce2503e3.pdf). 83 pages. ISBN 979-8656504492.  


------------------------------------------------------------------------------------------------

#  Characters and Fonts

## Characters Encodings

The characters of MD text can be encoded, preferably, as:

* *Windows-1252* encoding (aka *ANSI* code page)
* *UTF-8* encoding

**NOTE:** Although UTF-8 encoding allows the representation of more than 143,000 Unicode characters, 
only the 256 corresponding to ANSI encoding are supported here.

Due to its similarity to *Windows-1252* encoding, the following codes are also accepted:

* *ISO-8859-1* (aka *Latin 1*)
* *ISO-8859-15* (aka *Latin 9*)

**Example:**

ANSI encoding:  ¡ … Õ ” ⁄ ‹ — · È Ì Û ˙ ¸ Ò ° ø  
UTF-8 encoding: √Å √â √ç √ì √ö √ú √ë √° √© √≠ √≥ √∫ √º √± ¬° ¬ø


## Escaping Characters

To display a literal character that would otherwise be used to format text in a Markdown document, 
add a *backslash* (\\) in front of the character. You can use a *backslash* to escape the following characters:

* ` \\\\ ` 	Backslash
* ` \\\` ` 	Backtick
* ` \\\* ` 	Asterisk
* ` \\\_ ` 	Underscore
* ` \\\{ ` 	Open curly braces
* ` \\\} ` 	Close curly braces
* ` \\\[ ` 	Open brackets
* ` \\\] ` 	Close brackets
* ` \\\< ` 	Open angle brackets
* ` \\\> ` 	Close angle brackets
* ` \\\( ` 	Open parentheses
* ` \\\) ` 	Close parentheses
* ` \\\# ` 	Number sign
* ` \\\+ ` 	Plus sign
* ` \\\- ` 	Minus sign (hyphen)
* ` \\\. ` 	Dot
* ` \\\! ` 	Exclamation mark
* ` \\\| ` 	Pipe
* ` \\\= ` 	Equals sign
* ` \\\^ ` 	Caret
* ` \\\~ ` 	Tilde


## Bold

To bold text, add *two asterisks* (\*\*) or *two underscores* (\_\_) before and after a word or phrase. To bold the middle of a word for emphasis, add *two asterisks without spaces* around the letters.

**Example:**

```
  I just love **bold text**.
  I just love __bold text__.
  IJust**LoveBold**Text.
```

**Result:**

I just love **bold text**.   
I just love __bold text__.   
IJust**LoveBold**Text.


## Italic

To italicize text, add *one asterisk* (\*) or *one underscore* (\_) before and after a word or phrase. To italicize the middle of a word for emphasis, add *one asterisk without spaces* around the letters.

**Example:**

```
  Italicized text is the *cat¥s meow*.
  Italicized text is the _cat¥s meow_.
  Italicized*TextIsThe*Cat¥sMeow.
```

**Result:**

Italicized text is the *cat's meow*.  
Italicized text is the _cat's meow_.  
Italicized*TextIsThe*Cat&#39;sMeow.


## Bold and Italic

To emphasize text with bold and italics at the same time, add *three asterisks* (\*\*\*) or *three underscores* (\_\_\_) or any combination of these before and after a word or phrase. To bold and italicize the middle of a word for emphasis, add three asterisks without spaces around the letters.

**Example:**

```
  Text ***really important***.
  Text ___really important___.
  Text __*really important*__.
  Text **_really important_**.
  Text *__really important__*.
  Text _**really important**_.
  Text***Really***Important.
```

**Result:**

Text ***really important***.   
Text ___really important___.   
Text __*really important*__.   
Text **_really important_**.   
Text *__really important__*.   
Text _**really important**_.   
Text***Really***Important.


## Code

To denote a word or phrase as code, enclose it in *backticks* (\`).

**Example:**

```
  At the command prompt, type: `ATTRIB -R -H *.* /S/D`
```

**Result:**

At the command prompt, type: `ATTRIB -R -H \*.\* /S/D`


## Highlight

To highlight words, use *two equal signs* (\=\=) before and after the words.

**Example:**

```
  I need to highlight these ==very important words==.
```

**Result:**

I need to highlight these ==very important words==.


## Subscript

To create a subscript, use *one tilde symbol* (\~) before and after the characters.

**Example:**

```
  H~2~SO~4~ : sulfuric acid
```

**Result:**

H~2~SO~4~ : sulfuric acid


## Superscript

To create a superscript, use *one caret symbol* (\^) before and after the characters.

**Example:**

```
  y = 2x^3^ + 6x^2^ - x + 5  : a polynomial equation
```

**Result:**

y = 2x^3^ \+ 6x^2^ \- x \+ 5  : a polynomial equation


------------------------------------------------------------------------------------------------

# Paragraphs and Headings

## Headings

To create a heading, add *number signs* (\#) in front of a phrase. For compatibility, always put a space between the *number signs* (\#) and the heading name. The number of *number signs* you use should correspond to the title level:

```
  #  Heading level 1
  ##  Heading level 2
  ###  Heading level 3
  ####  Heading level 4
  #####  Heading level 5
  ######  Heading level 6
```

### Heading Alternate Syntax

Alternatively, on the line below the text, underline with any number of \=\= characters for heading level 1
or \-\- characters for heading level 2.

```
  Heading level 1
  ===============
  Heading level 2
  ---------------
```


## Paragraphs

To create paragraphs, use a *blank line* to separate one or more lines of text. Don't indent paragraphs with spaces or tabs.


## Line Breaks

To create a line break or new line,   
end a line with *two or more spaces*, and then type return.


## Blockquotes

To create a blockquote, add a *greater than sign* (>) in front of a paragraph. For compatibility, put blank lines before and after blockquotes.

**Example:**

```
  > Dorothy followed her through many of the beautiful rooms in her castle.
```

**Result:**

> Dorothy followed her through many of the beautiful rooms in her castle.

### Blockquotes with Multiple Paragraphs

Blockquotes can contain multiple paragraphs. Add a greater than sign (>) on the blank lines between the paragraphs.

**Example:**

```
  > Dorothy followed her through many of the beautiful rooms in her castle.
  >
  > The Witch bade her clean the pots and kettles and sweep the floor and keep the fire fed with wood.
```

**Result:**

> Dorothy followed her through many of the beautiful rooms in her castle.
>
> The Witch bade her clean the pots and kettles and sweep the floor and keep the
fire fed with wood.


## Links

To create a link, enclose the link text in brackets and then follow it immediately with the URL in
parentheses.

**Example:**

`Use &#91;Google&#93;(http://www.google.com/) to find.`

**Result:**

Use [Google](http://www.google.com/) to find.


## Horizontal Rules

To create a horizontal rule, use three or more *asterisks* (\*\*\*), *dashes* (\-\-\-), or 
*underscores* (\_\_\_) on a line by themselves.

**Example:**

`\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-`

**Result:**
  
------------------------------------------------------------------------------------------------


# Lists

You can organize items into ordered and unordered lists.

## Unordered Lists

To create an unordered list, add *dashes* (\-), *asterisks* (\*), or *plus signs* (\+) in front of line items.
Always use a blank space after the symbol to avoid confusing it with the emphasized fonts. 
A blank line after the last item indicates the end of the list.

**Example:**

```
   - First item
   * Second item
   + Third item
   - Fourth item
```

**Result:**

- First item
* Second item
+ Third item
- Fourth item 


## Nested Unordered Lists

To create an nested unordered list indent one or more items before *dashes* (\-), *asterisks* (\*), or *plus signs* (\+).

**Example:**

```
   * First item
     - First subitem
     - Second subitem
   * Second item
   * Third item
```

**Result:**

* First item
  - First subitem
  - Second subitem
* Second item
* Third item


## Ordered Lists

To create an ordered list, add line items with *numbers followed by periods*. The numbers don't have to be in numerical order, and the numbers may even be repeated, but the list should **start with the number one**.

**Example:**

```
   1.  First item
   15. Second item
   15. Third item
   8.  Fourth item
```

**Result:**

1.  First item
15. Second item
15. Third item
8.  Fourth item 


------------------------------------------------------------------------------------------------

# Tables and Blocks

## Tables

To add a table, use *pipes* (\|) to separate each column. Use three o more *hyphens* (\-) to create
column's header.

**Example:**

```
  | Syntax    | Description |
  |-----------|-------------|
  | Header    | _Title_     |
  | Paragraph | `Text`      |
  | Body      | Close       |
```

**Result:**

| Syntax    | Description |
|-----------|-------------|
| Header    | _Title_     |
| Paragraph | `Text`      |
| Body      | Close       |


## Code Blocks

To create code blocks, ident every line of the block by at least four spaces or one tab.

**Example:**

```
    COPY /V /Y /B image.jpeg d:\
    DIR /L /C /X d:\
    DEL /F /Q image.jpeg
```

**Result:**

    COPY /V /Y /B image.jpeg d:\
    DIR /L /C /X d:\
    DEL /F /Q image.jpeg


## Fenced Code Blocks

Markdown allows you to create code blocks using *fenced code blocks*. Use *three tick marks*
(&#96;&#96;&#96;) or *three tildes* (&#126;&#126;&#126;) on the lines before and after the code block. Syntax
highlighting for *wxBasic* is done automatically.

**Example:**

    &#96;&#96;&#96;
      'ANSI BASIC Style
      INPUT "Enter value: ", X
      IF X<10 THEN PRINT "Ans: ", X, " is a small number"
	'
      //wxWidgets Style
      Dim y = wxGetTextFromUser( "Enter value:", "Data" ) 
      If y < 10 Then
         Dim Dialog = New wxFrame( Nothing, -1, "Ans: " & y & " is a small number" )
         Dialog.Show( True )
      End If
    &#96;&#96;&#96;

**Result:**

```
  'ANSI BASIC Style
  INPUT "Enter value: ", X
  IF X<10 THEN PRINT "Ans: ", X, " is a small number"
  ' 
  //wxWidgets Style
  Dim y = wxGetTextFromUser( "Enter value:", "Data" ) 
  If y < 10 Then
     Dim Dialog = New wxFrame( Nothing, -1, "Ans: " & y & " is a small number" )
     Dialog.Show( True )
  End If	 
```


## Comments

To add a comment, place text *inside brackets* followed by a *colon, a space, and a pound sign* (e.g., `[comment]:&nbsp;#`).
You should put blank lines before and after a comment.

**Example:**

```
    Here¥s a paragraph that will be visible. 

    [This is a comment that will be hidden.]:&nbsp;# 

    And here¥s another paragraph that¥s visible. 
```
	
**Result:**

Here's a paragraph that will be visible.

[This is a comment that will be hidden.]: # 

And here's another paragraph that's visible.


_________________________________________________

^Copyleft (c) 2026 by Agustin Benitez Hernandez^
