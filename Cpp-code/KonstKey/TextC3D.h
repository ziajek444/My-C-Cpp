#pragma once
// textC3d is use to cripting whole signs from keyboard  at the expens of longer cript text.
#include "Cezar3d.h"

using namespace std;

namespace textc3d
{
	const int parametr = 10;
}

// a:z (26) 0:9 (10) : ; < (3)     where:  : is alt  ; is shift  < is special
// 39
string textToC3D(string);
string c3dToText(string);
string itextToC3D(string,const int);
string ic3dToText(string,const int);

/// Use that function to convert regular text to 'Cezarable' text // TEXT TO C3D
string textToC3D(string text_in)
{
	string converted_text = "";
	unsigned char sign;

	for (int i = 0; i < text_in.length(); i++)
	{
		sign = text_in[i];

		// : #1
		if (sign >= 0 && sign <= 9) { converted_text += ':'; converted_text += static_cast<char>('0' + sign); }
		else if (sign >= 10 && sign <= 35) { converted_text += ':'; converted_text += static_cast<char>('a' + (static_cast<int>(sign)-10)); }

		// ; #2
		else if (sign >= 36 && sign <= 45) { converted_text += ';'; converted_text += static_cast<char>('0' + (static_cast<int>(sign) - 36)); }
		else if (sign >= 46 && sign <= 47) { converted_text += ';'; converted_text += static_cast<char>('a' + (static_cast<int>(sign) - 46)); }
		else if ((sign >= 48 && sign <= 57) || (sign >= 97 && sign <= 122)) { converted_text += sign; } // Average
		else if (sign >= 58 && sign <= 81) { converted_text += ';'; converted_text += static_cast<char>('c' + (static_cast<int>(sign) - 58)); }

		// < #3
		else if (sign >= 82 && sign <= 91) { converted_text += '<'; converted_text += static_cast<char>('0' + (static_cast<int>(sign) - 82)); }
		else if (sign >= 92 && sign <= 96) { converted_text += '<'; converted_text += static_cast<char>('a' + (static_cast<int>(sign) - 92)); }
		else if (sign >= 123 && sign <= 142) { converted_text += '<'; converted_text += static_cast<char>('f' + (static_cast<int>(sign) - 123)); }

		// :: #4
		else if (sign >= 143 && sign <= 152) { converted_text += ':'; converted_text += ':'; converted_text += static_cast<char>('0' + (static_cast<int>(sign) - 143)); }
		else if (sign >= 153 && sign <= 178) { converted_text += ':'; converted_text += ':'; converted_text += static_cast<char>('a' + (static_cast<int>(sign) - 153)); }

		// :; #5
		else if (sign >= 179 && sign <= 188) { converted_text += ':'; converted_text += ';'; converted_text += static_cast<char>('0' + (static_cast<int>(sign) - 179)); }
		else if (sign >= 189 && sign <= 214) { converted_text += ':'; converted_text += ';'; converted_text += static_cast<char>('a' + (static_cast<int>(sign) - 189)); }

		// :< #6
		else if (sign >= 215 && sign <= 224) { converted_text += ':'; converted_text += '<'; converted_text += static_cast<char>('0' + (static_cast<int>(sign) - 215)); }
		else if (sign >= 225 && sign <= 250) { converted_text += ':'; converted_text += '<'; converted_text += static_cast<char>('a' + (static_cast<int>(sign) - 225)); }
		
		// ;: #7
		else if (sign >= 251 && sign <= 255) { converted_text += ';'; converted_text += ':'; converted_text += static_cast<char>('0' + (static_cast<int>(sign) - 251)); }
		// 5:9 are reserved
		// a:z are reserved
		// ;; , ;< , <: , <; , <<  are reserved

		else cout << "IMPOSIBLE\n";
	}

	// raw converted_text is only 0:9 and a:z

	return converted_text;
}

/// Use that function to convert 'Cezarable' text to regular text // C3D TO TEXT
string c3dToText(string text_in)
{
	string ireconverted_text = "";
	unsigned char sign;
	char conv[3];
	memset(conv, 0, 3 * sizeof(char));
	int choose = 0;

	//if ((sign >= '0' && sign <= '9') || (sign >= 'a' && sign <= 'z'))
	
	int i = 0;
	int j = 0;
	sign = text_in[i++];
	
	while (sign != '\0')
	{
		if (sign >= ':' && sign <= '<')
		{

			while (sign >= ':' && sign <= '<')
			{
				conv[j++] = sign;
				sign = text_in[i++];
			}

			choose = 0;

			if (!strcmp(conv, ":")) choose = 1;
			else if (!strcmp(conv, ";")) choose = 2;
			else if (!strcmp(conv, "<")) choose = 3;
			else if (!strcmp(conv, "::")) choose = 4;
			else if (!strcmp(conv, ":;")) choose = 5;
			else if (!strcmp(conv, ":<")) choose = 6;
			else if (!strcmp(conv, ";:")) choose = 7;
			else cout << "Wrong inputed text to decode\n";

			switch (choose)
			{
				case 1:
					if (sign >= '0' && sign <= '9') ireconverted_text += sign - '0';
					else if (sign >= 'a' && sign <= 'z') ireconverted_text += sign - 'a' + 10;
					else cout << "Wrong inputed text to decode\n";
					break;
				case 2:
					if (sign >= '0' && sign <= '9') ireconverted_text += sign - '0' + 36;
					else if (sign >= 'a' && sign <= 'b') ireconverted_text += sign - 'a' + 46;
					else if (sign >= 'c' && sign <= 'z') ireconverted_text += sign - 'c' + 58;
					else cout << "Wrong inputed text to decode\n";
					break;
				case 3:
					if (sign >= '0' && sign <= '9') ireconverted_text += sign - '0' + 82;
					else if (sign >= 'a' && sign <= 'e') ireconverted_text += sign - 'a' + 92;
					else if (sign >= 'f' && sign <= 'z') ireconverted_text += sign - 'f' + 123;
					else cout << "Wrong inputed text to decode\n";
					break;
				case 4:
					if (sign >= '0' && sign <= '9') ireconverted_text += sign - '0' + 143;
					else if (sign >= 'a' && sign <= 'z') ireconverted_text += sign - 'a' + 153;
					else cout << "Wrong inputed text to decode\n";
					break;
				case 5:
					if (sign >= '0' && sign <= '9') ireconverted_text += sign - '0' + 179;
					else if (sign >= 'a' && sign <= 'z') ireconverted_text += sign - 'a' + 189;
					else cout << "Wrong inputed text to decode\n";
					break;
				case 6:
					if (sign >= '0' && sign <= '9') ireconverted_text += sign - '0' + 215;
					else if (sign >= 'a' && sign <= 'z') ireconverted_text += sign - 'a' + 225;
					else cout << "Wrong inputed text to decode\n";
					break;
				case 7:
					if (sign >= '0' && sign <= '4') ireconverted_text += sign - '0' + 251;
					else cout << "Wrong inputed text to decode\n";
					break;
				default:
					cout << "Not special sign\n";
					break;
			}

			j = 0;
			memset(conv, 0, 3 * sizeof(char));
		}
		else if ((sign >= '0' && sign <= '9') || (sign >= 'a' && sign <= 'z'))
		{
			ireconverted_text += sign;
		}
		else cout << "Wrong inputed text to decode\n";

		sign = text_in[i++];
	}

	return ireconverted_text;
}

/// Use that function to convert regular text to encrypted 'Cezarable' text // improved REGULAR TEXT TO C3D
string itextToC3D(string text_in, const int t = textc3d::parametr)
{
	string iconverted_text = "";

	iconverted_text = textToC3D(text_in);
	iconverted_text = iCezar3D_Encrypt(iconverted_text, c3d::KEYTAB, t);

	return iconverted_text;
}

/// Use that function to convert encrypted 'Cezarable' text to regular text (making decrypting) // improved C3D TO REGULAR TEXT
string ic3dToText(string text_in, const int t = textc3d::parametr)
{
	string ireconverted_text = "";

	ireconverted_text = iCezar3D_Decrypt(text_in, c3d::KEYTAB, t);
	ireconverted_text = c3dToText(ireconverted_text);

	return ireconverted_text;
}


