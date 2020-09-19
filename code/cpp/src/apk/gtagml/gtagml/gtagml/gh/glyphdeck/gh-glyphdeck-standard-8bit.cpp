
// licence_cpp

#include "gh-glyphdeck-standard-8bit.h"

GH_Glyphdeck_Standard_8bit::GH_Glyphdeck_Standard_8bit()
{

}

/*

64 accents or - 16?
#ifdef HIDE
0: null
1: _ empty
2: ` // acute
3: ' // grave
4: ^ // circ
5: " // uml
6: ~ // tilde
7: = // macr
8: . // dot
9: u // breve
10: v // caron
11: H // dbl acute   (xml = dblac)
12: b // bar-under    // no xml
13: c // cedil       
14: k // ogon
15: r // ring over ...    (xml = ring)
16: R // ring over (alt), e.g. aa instead of ra ...   (xml = ring)
17: K // stroke      (xml = strok)
18: t // tie-after   // no xml
19: / // slash
20: m // midot
 ... no xml ...
21: g // eng, kgreen, geminated l, ital &  ...
22: G // eng, ital, geminated L, & with more space

23: h // eth, thorn, Thorn 
24: z // eszat i.e. ss ...

25: e // ae, oe
26: E // AE, OE

27: f // fi, fj, fl, ff, FI, FJ, FL, FF 

28: F // fi, ffj, ffl, FFI, FFJ, FFL

29: n // no ligature
30: N // no ligature
31: C // italic correction

32: @ // special circled
33: ) // circled
34: % // circle left
35: o // circle ring
36: O // circle ring (larger)

37: $ // strike
38: - // strike

39: D // dieresis

?40: [
?41: ]
?42: {
?43: }
?44: ,
?45: ;

46: : // elevated

// // multi-character codes: 
 //    + double elevated
 //    > double 
 //    & triple
 //    \ external 
 //   e.g.
 //     |:t (TM as one character)   
 //     |+t (TM as two characters) 
 //     |fl (fl ligature as one character)
 //     |Fl (ffl ligature as one character)
 //     |>fl (fl ligature as two character)
 //     |&Fl (ffl ligature as three characters) 

47: < // inherited
48: + // middle inherited
49: > // double inherited


??
50: 0
51: 1
52: 2
53: 3
54: 4
55: 5
56: 6
57: 7
58: 8
59: 9

60: # // special 
61: * // special 

62: V // (invert)

63: ? // unrec


 static QMap<u1, QString> static_map {

   { 10118, "&inodot;" },  //  _.i
   { 10119, "&inodot;" },  //  _.j

   { 12123, "&eng;" },  //  g.n
   { 12150, "&ENG;" },  //  g.N

   { 12110, "&amp;" },  //  g.a //? &#128629;
   { 12120, "&kgreen;" },  //  g.k
   { 12137, "&amp;" },  //  g.A //? &#128629;
   { 12147, "&kgreen;" },  //  g.K  
  
   { 12223, "&eng;" },  //  G.n  
   { 12250, "&ENG;" },  //  G.N 
 
   { 12210, "&amp;" },  //  G.a ? &#128629;
   { 12220, "&kgreen;" },  //  G.k
   { 12237, "&amp;" },  //  G.A ? &#128629;
   { 12247, "&kgreen;" },  //  G.K  

   { 11610, "&Aring;" },  //  R.a  
   { 11637, "&aring;" },  //  R.A  

   { 14610, "&ordf;" }, // :.a
   { 24610, "&ordf;" }, // :.a
   { 14637, "&ordf;" }, // :.A
   { 24637, "&ordf;" }, // :.A

   { 14624, "&ordm;" }, // :.o
   { 24624, "&ordm;" }, // :.o
   { 14651, "&ordm;" }, // :.O
   { 24651, "&ordm;" }, // :.O

   { 14629, "&trade;" }, // :.t
   { 24629, "&trade;" }, // :.t

   { 14631, "&#8480;" }, // :.v
   { 24631, "&#8480;" }, // :.v

   { 14628, "st" }, // :.s  i.e. 1st ...
   { 24628, "st" }, // :.s
   { 14655, "st" }, // :.S  
   { 24655, "st" }, // :.S

   { 14623, "nd" }, // :.n  i.e. 2nd ...
   { 24623, "n" }, // :.n
   { 14650, "nd" }, // :.N  
   { 24650, "n" }, // :.N

   { 14627, "rd" }, // :.r  i.e. 3rd ...
   { 24627, "rd" }, // :.r
   { 14654, "rd" }, // :.R  
   { 24654, "rd" }, // :.R

   { 14617, "th" }, // :.h  i.e. 4th ...
   { 24617, "th" }, // :.h
   { 14644, "th" }, // :.H  
   { 24644, "th" }, // :.H

   { 12310, "&eth;" },  //  h.d  
   { 12337, "&ETH;" },  //  h.D  
   { 12329, "&thorn;" },  //  h.t  
   { 12356, "&THORN;" },  //  h.T  

   { 12428, "&szlig;" },  //  z.s  
   { 12455, "&szlig;" },  //  z.S  

   { 12510, "&aelig;" },  //  e.a  
   { 12524, "&oelig;" },  //  e.o  
   { 12537, "&AElig;" },  //  e.A
   { 12551, "&OElig;" },  //  e.O
  
   { 12610, "&aelig;" },  //  E.a  
   { 12624, "&oelig;" },  //  E.o  
   { 12637, "&AElig;" },  //  E.A  
   { 12651, "&OElig;" },  //  E.O 

   { 13212, "&copy;" }, // @.c
   { 13227, "&reg;" }, // @.r

   { 13412, "[&copy;]" }, // %.c

   { 13936, "&diaresis;"}, // D._


tex ...

   { 10323, "{\\dianapos}" }, // '.n
   { 10350, "{\\diaNapos}" }, // '.N

   { 20323, "{\\ddianapos" }, // '.n
   { 20350, "{\\ddiaNapos" }, // '.N
 
   { 12119, "{\\diaij}" },  //  g.j
   { 12146, "{\\diaIJ}" },  //  g.J

   { 22118, "{\\ddiaij" },  //  g.i
   { 22145, "{\\ddiaIJ" },  //  g.I

   { 12123, "{\\ng}" },  //  g.n
   { 12150, "{\\NG}" },  //  g.N

   { 12110, "{\\&}" },  //  g.a
   { 12120, "\\textsc{k}" },  //  g.k
   { 12137, "{\\upamp}" },  //  g.A
   { 12147, "{\\Kgreenalt}" },  //  g.K  
  
   { 12223, "{\\ngalt}" },  //  G.n  
   { 12250, "{\\NGalt}" },  //  G.N 
 
   { 12210, "{\\itampalt}" },  //  G.a  
   { 12220, "{\\kGreenalt}" },  //  G.k
   { 12237, "{\\upampalt}" },  //  G.A
   { 12247, "{\\Kgreenalt}" },  //  G.K  

   { 11610, "{\\aa}" },  //  R.a  
   { 11637, "{\\AA}" },  //  R.a  

   { 12310, "{\\dh}" },  //  h.d  
   { 12337, "{\\DH}" },  //  h.D  
   { 12329, "{\\th}" },  //  h.t  
   { 12356, "{\\TH}" },  //  h.T  

   { 12428, "{\\ss}" },  //  z.s  
   { 12455, "{\\sSalt}" },  //  z.S  

   { 12510, "{\\ae}" },  //  e.a  
   { 12524, "{\\oe}" },  //  e.o  
   { 12537, "{\\Aealt}" },  //  e.A
   { 12551, "{\\Oealt}" },  //  e.O
  
   { 12610, "{\\aEalt}" },  //  E.a  
   { 12624, "{\\oEalt}" },  //  E.o  
   { 12637, "{\\AE}" },  //  E.A  
   { 12651, "{\\OE}" },  //  E.O 

   { 13136, "{\\/}" }, // C._

   { 13212, "{\\textcopyright}" }, // @.c
   { 13227, "{\\textregistered}" }, // @.r

   { 13412, "{\\textcopyleft}" }, // %.c

   { 13936, "{\\\"}"}, // D._

   { 14610, "{\\diaordfem}" }, // :.a
   { 24610, "{\\ddiaordfem}" }, // :.a
   { 14637, "{\\diaordfemalt}" }, // :.A
   { 24637, "{\\ddiaordfemalt}" }, // :.A

   { 14624, "{\\diaordmasc}" }, // :.o
   { 24624, "{\\ddiaordmasc}" }, // :.o
   { 14651, "{\\diaordmascalt}" }, // :.O
   { 24651, "{\\ddiaordmascalt}" }, // :.O

   { 14629, "{\\texttrademark}" }, // :.t
   { 24629, "{\\ttrademark" }, // :.t

   { 14631, "{\\textservicemark}" }, // :.v
   { 24631, "{\\tservicemark" }, // :.v

   { 14628, "{\\diaST}" }, // :.s  i.e. 1st ...
   { 24628, "{\\ddiaST}" }, // :.s
   { 14655, "{\\altdiaST}" }, // :.S  
   { 24655, "{\\altddiaST" }, // :.S

   { 14623, "{\\diaND}" }, // :.n  i.e. 2nd ...
   { 24623, "{\\ddiaND}" }, // :.n
   { 14650, "{\\altdiaND}" }, // :.N  
   { 24650, "{\\altddiaND" }, // :.N

   { 14627, "{\\diaRD}" }, // :.r  i.e. 3rd ...
   { 24627, "{\\ddiaRD}" }, // :.r
   { 14654, "{\\altdiaRD}" }, // :.R  
   { 24654, "{\\altddiaRD" }, // :.R

   { 14617, "{\\diaTH}" }, // :.h  i.e. 4th ...
   { 24617, "{\\ddiaTH}" }, // :.h
   { 14644, "{\\altdiaTH}" }, // :.H  
   { 24644, "{\\altddiaTH" }, // :.H



#endif





 case 0: return '0';
 case 1: return '1';
 case 2: return '2';
 case 3: return '3';
 case 4: return '4';
 case 5: return '5';
 case 6: return '6';
 case 7: return '7';
 case 8: return '8';
 case 9: return '9';
 case 10: return 'a';
 case 11: return 'b';
 case 12: return 'c';
 case 13: return 'd';
 case 14: return 'e';
 case 15: return 'f';
 case 16: return 'g';
 case 17: return 'h';
 case 18: return 'i';
 case 19: return 'j';
 case 20: return 'k';
 case 21: return 'l';
 case 22: return 'm';
 case 23: return 'n';
 case 24: return 'o';
 case 25: return 'p';
 case 26: return 'q';
 case 27: return 'r';
 case 28: return 's';
 case 29: return 't';
 case 30: return 'u';
 case 31: return 'v';
 case 32: return 'w';
 case 33: return 'x';
 case 34: return 'y';
 case 35: return 'z';
 case 36: return '_';
 case 37: return 'A';
 case 38: return 'B';
 case 39: return 'C';
 case 40: return 'D';
 case 41: return 'E';
 case 42: return 'F';
 case 43: return 'G';
 case 44: return 'H';
 case 45: return 'I';
 case 46: return 'J';
 case 47: return 'K';
 case 48: return 'L';
 case 49: return 'M';
 case 50: return 'N';
 case 51: return 'O';
 case 52: return 'P';
 case 53: return 'Q';
 case 54: return 'R';
 case 55: return 'S';
 case 56: return 'T';
 case 57: return 'U';
 case 58: return 'V';
 case 59: return 'W';
 case 60: return 'X';
 case 61: return 'Y';
 case 62: return 'Z';
 case 63: return '-';

 //  64
 case 0: return '.';
 case 1: return ',';
 case 2: return ';';
 case 3: return ':';
 case 4: return '(';
 case 5: return ')'; 
 case 6: return '-'; // mdash
 case 7: return ' ';
 case 8: return ' ';  // se
 case 9: return '\\n';

// punc  weak-punc  lit word-repl quasi-let quasi-math  ?serialize
// surround group word-scale code math vis dcode let diacritic-let s-ref-display

//  16 roles   


 case 10: ~   // circa    (word-repl)
 case 11: !   // punc
 case 12: @   // email, handles ...  (lit)
 case 13: #   // number   (lit) or (word-repl)
 case 14: $   // dollars  (lit) or (word-repl)
 case 15: %   // percent  (lit) or (word-repl)
 case 16: &   // part of name  (repl ^)  (lit)
 case 17: &   // not part of name   (word-repl)
 case 18: *   // polite    (quasi-letter)  (lit)
 case 19: (   // surround
 case 20: )   // surround
 case 21: -   // em dash   punc1
 case 22: =   // quasi-math
 case 23: +   // quasi-math
 case 24: [   // punc
 case 25: ]   // punc
 case 26: {   // group
 case 27: }   // group
 case 28: [   // group/surround 
 case 29: ]   // group/surround
 case 30: /   // punc      // case 30: ;
 case 31: /   // non-punc (quasi-let) or (word-scale)  // case 31: :
 case 32: '   // inch     (word-repl)
 case 33: "   // feet     (word-repl)
 case 34: '   // apos     (lit)
 case 35: <   // quasi-math
 case 36: \n  // se          (punc)
 case 37: >   // quasi-math 
 case 38: .   // num lit
 case 39: ?   // weak punc

 case 40: return '!'; // weak punc
 case 41: return '.'; // weak punc
 case 42: return '.'; // abr
 case 43: return '.'; // ell
 case 44: return '.'; // ellpn
 case 45: return '-'; // en dash
 case 46: return '-'; // sml
 case 47: return '-'; // quasi-math (neg)
 case 48: return '-'; // quasi-math (minus)
 case 49: return ','; // num lit
 case 50: return '\''; // print osq
 case 51: return '\'';  // print csq
 case 52: return '\"';  // print odq 
 case 53: return '\"';  // print cdq 
 case 54: return '';
 case 55: return '';
 case 56: return '';
 case 57: return '';
 case 58: return '';
 case 59: return '';
 case 60: return '';
 case 61: return '';
 case 62: return '';
 case 63: return '';

+10

128
  // code, math, vis
 case 0: ~
 case 1: !
 case 2: @
 case 3: #
 case 4: $
 case 5: %
 case 6: ^
 case 7: &
 case 8: *
 case 9: (
 case 10: )
 case 11: -
 case 12: =
 case 13: +
 case 14: [
 case 15: ]
 case 16: {
 case 17: }
 case 18: \
 case 19: |
 case 20: ;
 case 21: :
 case 22: '
 case 23: "
 case 24: ,
 case 25: <
 case 26: .
 case 27: >
 case 28: /
 case 29: ?

 case 30: \r
 case 31: \t

//++ 42

160
 + 32
//or 15 dia = +17 

0 \aaÐ
1 \DH* 
2 \L
3 \o
4 \ss
5 \AA
6 \dh* 
7 \l
8 \O
9 \SS
10 \AE
11 \DJ*
12 \NG*
13 \OE
14 \TH*
15 \ae
16 \dj*
­17 \ng*
18 \oe
19 \th*



192 ...
0: U+00C0 	À 	Latin Capital Letter A with grave 	
1: U+00C1 	Á 	Latin Capital letter A with acute 	
2: U+00C2 	Â 	Latin Capital letter A with circumflex 	
3: U+00C3 	Ã 	Latin Capital letter A with tilde 	
4: U+00C4 	Ä 	Latin Capital letter A with diaeresis 	
5: U+00C5 	Å 	Latin Capital letter A with ring above 	
6: U+00C6 	Æ 	Latin Capital letter AE 	
7: U+00C7 	Ç 	Latin Capital letter C with cedilla 	
8: U+00C8 	È 	Latin Capital letter E with grave 	
9: U+00C9 	É 	Latin Capital letter E with acute 	
10: U+00CA 	Ê 	Latin Capital letter E with circumflex 	
11: U+00CB 	Ë 	Latin Capital letter E with diaeresis 	
12: U+00CC 	Ì 	Latin Capital letter I with grave 	
13: U+00CD 	Í 	Latin Capital letter I with acute 	
14: U+00CE 	Î 	Latin Capital letter I with circumflex 	
15: U+00CF 	Ï 	Latin Capital letter I with diaeresis 	
16: U+00D0 	Ð 	Latin Capital letter Eth 	
17: U+00D1 	Ñ 	Latin Capital letter N with tilde 	
18: U+00D2 	Ò 	Latin Capital letter O with grave 	
19: U+00D3 	Ó 	Latin Capital letter O with acute 	
20: U+00D4 	Ô 	Latin Capital letter O with circumflex 	
21: U+00D5 	Õ 	Latin Capital letter O with tilde 	
22: U+00D6 	Ö 	Latin Capital letter O with diaeresis 	
23: U+00D8 	Ø 	Latin Capital letter O with stroke 	
24: U+00D9 	Ù 	Latin Capital letter U with grave 	
25: U+00DA 	Ú 	Latin Capital letter U with acute 	
26: U+00DB 	Û 	Latin Capital Letter U with circumflex 	
27: U+00DC 	Ü 	Latin Capital Letter U with diaeresis 	
28: U+00DD 	Ý 	Latin Capital Letter Y with acute 	
29: U+00DE 	Þ 	Latin Capital Letter Thorn 	
30: U+00DF 	ß 	Latin Small Letter sharp S 	
31: U+00E0 	à 	Latin Small Letter A with grave 	
32: U+00E1 	á 	Latin Small Letter A with acute 	
33: U+00E2 	â 	Latin Small Letter A with circumflex 	
34: U+00E3 	ã 	Latin Small Letter A with tilde 	
35: U+00E4 	ä 	Latin Small Letter A with diaeresis 	
36: U+00E5 	å 	Latin Small Letter A with ring above 	
37: U+00E6 	æ 	Latin Small Letter AE 	
38: U+00E7 	ç 	Latin Small Letter C with cedilla 	
39: U+00E8 	è 	Latin Small Letter E with grave 	
40: U+00E9 	é 	Latin Small Letter E with acute 	
41: U+00EA 	ê 	Latin Small Letter E with circumflex 	
42: U+00EB 	ë 	Latin Small Letter E with diaeresis 	
43: U+00EC 	ì 	Latin Small Letter I with grave 	
44: U+00ED 	í 	Latin Small Letter I with acute 	
45: U+00EE 	î 	Latin Small Letter I with circumflex 	
46: U+00EF 	ï 	Latin Small Letter I with diaeresis 	
47: U+00F0 	ð 	Latin Small Letter Eth 	
48: U+00F1 	ñ 	Latin Small Letter N with tilde 	
49: U+00F2 	ò 	Latin Small Letter O with grave 	
50: U+00F3 	ó 	Latin Small Letter O with acute 	
51: U+00F4 	ô 	Latin Small Letter O with circumflex 	
52: U+00F5 	õ 	Latin Small Letter O with tilde 	
53: U+00F6 	ö 	Latin Small Letter O with diaeresis 	
54: U+00F8 	ø 	Latin Small Letter O with stroke 	
55: U+00F9 	ù 	Latin Small Letter U with grave 	
56: U+00FA 	ú 	Latin Small Letter U with acute 	
57: U+00FB 	û 	Latin Small Letter U with circumflex 	
58: U+00FC 	ü 	Latin Small Letter U with diaeresis 	
59: U+00FD 	ý 	Latin Small Letter Y with acute 	
60: U+00FE 	þ 	Latin Small Letter Thorn 	
61: U+00FF 	ÿ 	Latin Small Letter Y with diaeresis 	









 case 10: return '.'; // abr
 case 11: return '.'; // dec
 case 12: return '.'; // ell
 case 13: return '.'; // ellpn
 case 14: return '.'; 

 case 15: return '-';
 case 16: return '-';
 case 17: return '-';
 case 18: return '-';
 case 19: return '-';

 case 20: return 'k';
 case 21: return 'l';
 case 22: return 'm';
 case 23: return 'n';
 case 24: return 'o';
 case 25: return 'p';
 case 26: return 'q';
 case 27: return 'r';
 case 28: return 's';
 case 29: return 't';
 case 30: return 'u';
 case 31: return 'v';
 case 32: return 'w';
 case 33: return 'x';
 case 34: return 'y';
 case 35: return 'z';
 case 36: return '_';
 case 37: return 'A';
 case 38: return 'B';
 case 39: return 'C';
 case 40: return 'D';
 case 41: return 'E';
 case 42: return 'F';
 case 43: return 'G';
 case 44: return 'H';
 case 45: return 'I';
 case 46: return 'J';
 case 47: return 'K';
 case 48: return 'L';
 case 49: return 'M';
 case 50: return 'N';
 case 51: return 'O';
 case 52: return 'P';
 case 53: return 'Q';
 case 54: return 'R';
 case 55: return 'S';
 case 56: return 'T';
 case 57: return 'U';
 case 58: return 'V';
 case 59: return 'W';
 case 60: return 'X';
 case 61: return 'Y';
 case 62: return 'Z';
 case 63: return ' ';


*/


u1 GH_Glyphdeck_Standard_8bit::get_basic_char(u1 gp)
{
 gp &= 63;
 switch(gp)
 {
 case 0: return '0';
 case 1: return '1';
 case 2: return '2';
 case 3: return '3';
 case 4: return '4';
 case 5: return '5';
 case 6: return '6';
 case 7: return '7';
 case 8: return '8';
 case 9: return '9';
 case 10: return 'a';
 case 11: return 'b';
 case 12: return 'c';
 case 13: return 'd';
 case 14: return 'e';
 case 15: return 'f';
 case 16: return 'g';
 case 17: return 'h';
 case 18: return 'i';
 case 19: return 'j';
 case 20: return 'k';
 case 21: return 'l';
 case 22: return 'm';
 case 23: return 'n';
 case 24: return 'o';
 case 25: return 'p';
 case 26: return 'q';
 case 27: return 'r';
 case 28: return 's';
 case 29: return 't';
 case 30: return 'u';
 case 31: return 'v';
 case 32: return 'w';
 case 33: return 'x';
 case 34: return 'y';
 case 35: return 'z';
 case 36: return '_';
 case 37: return 'A';
 case 38: return 'B';
 case 39: return 'C';
 case 40: return 'D';
 case 41: return 'E';
 case 42: return 'F';
 case 43: return 'G';
 case 44: return 'H';
 case 45: return 'I';
 case 46: return 'J';
 case 47: return 'K';
 case 48: return 'L';
 case 49: return 'M';
 case 50: return 'N';
 case 51: return 'O';
 case 52: return 'P';
 case 53: return 'Q';
 case 54: return 'R';
 case 55: return 'S';
 case 56: return 'T';
 case 57: return 'U';
 case 58: return 'V';
 case 59: return 'W';
 case 60: return 'X';
 case 61: return 'Y';
 case 62: return 'Z';
 case 63: return ' ';
 default: return '\0'; 
 }
}


u1 Standard_GlyphDeck_8b::get_char_with_diacritic(u1 gp)
{

}


u1 Standard_GlyphDeck_8b::get_non_alphanumeric_char(u1 gp)
{
 gp &= 63;
 switch(gp)
 {
 case 0: return '0';
 case 1: return '1';
 case 2: return '2';
 case 3: return '3';
 case 4: return '4';
 case 5: return '5';
 case 6: return '6';
 case 7: return '7';
 case 8: return '8';
 case 9: return '9';
 case 10: return 'a';
 case 11: return 'b';
 case 12: return 'c';
 case 13: return 'd';
 case 14: return 'e';
 case 15: return 'f';
 case 16: return 'g';
 case 17: return 'h';
 case 18: return 'i';
 case 19: return 'j';
 case 20: return 'k';
 case 21: return 'l';
 case 22: return 'm';
 case 23: return 'n';
 case 24: return 'o';
 case 25: return 'p';
 case 26: return 'q';
 case 27: return 'r';
 case 28: return 's';
 case 29: return 't';
 case 30: return 'u';
 case 31: return 'v';
 case 32: return 'w';
 case 33: return 'x';
 case 34: return 'y';
 case 35: return 'z';
 case 36: return '_';
 case 37: return 'A';
 case 38: return 'B';
 case 39: return 'C';
 case 40: return 'D';
 case 41: return 'E';
 case 42: return 'F';
 case 43: return 'G';
 case 44: return 'H';
 case 45: return 'I';
 case 46: return 'J';
 case 47: return 'K';
 case 48: return 'L';
 case 49: return 'M';
 case 50: return 'N';
 case 51: return 'O';
 case 52: return 'P';
 case 53: return 'Q';
 case 54: return 'R';
 case 55: return 'S';
 case 56: return 'T';
 case 57: return 'U';
 case 58: return 'V';
 case 59: return 'W';
 case 60: return 'X';
 case 61: return 'Y';
 case 62: return 'Z';
 case 63: return ' ';
 default: return '\0'; 
 }
}





QString GH_Glyphdeck_Standard_8bit::get_latex_representation(u1 gp)
{
 return {}; 
}

QString GH_Glyphdeck_Standard_8bit::get_xml_representation(u1 gp)
{
 return {}; 
}

QChar GH_Glyphdeck_Standard_8bit::get_qchar_representation(u1 gp, QString& alternate)
{
 return {}; 
}

QString GH_Glyphdeck_Standard_8bit::get_qstring_representation(u1 gp)
{
 return {}; 
}



