
// licence_cpp

#include "gh-glyphdeck-standard-8bit.h"

GH_Glyphdeck_Standard_8bit::GH_Glyphdeck_Standard_8bit()
{

}

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



