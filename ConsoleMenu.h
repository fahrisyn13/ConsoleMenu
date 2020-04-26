/* Fahri Synyster
Module name:
	ConsoleMenu.h

Summary:
	Membuat pilihan menu dengan menggunakan 'arrow key' sebagai navigasi.

Guide:
	1. Deklarasikan constructor ConsoleMenu
	2. Untuk mengubah warna navigasi gunakan fungsi -> SetCursorColor() [Default: Black, Green]
	3. Untuk Mengatur jarak antar baris gunakan fungsi -> SetPadding() [Default: 1]
	4. Terakhir, tampilkan menu dengan menggunakan fungsi -> Print()

Example:
	Print(short xPos, short yPos);
	+--------------------------------------------------------------+
	| ConsoleMenu ex {                                             |
	|		"Menu 1",                                                  |
	|		"Menu 2",                                                  |
	|		"Menu 3"                                                   |
	|	};                                                           |
	|	ex.SetCursorColor(ConsoleColor::Green, ConsoleColor::Black); |
	|	ex.SetPadding(2);                                            |
	|                                                              |
	|	switch((ex.Print(20, 10))) {                                 |
	|		case 0:                                                    |
	|			...                                                      |
	|			break;                                                   |
	|		case 1:                                                    |
	|			...                                                      |
	|			break;                                                   |
	|		case 2:                                                    |
	|			...                                                      |
	|			break;                                                   |
	|	}                                                            |
	+--------------------------------------------------------------+

	Print(short xPos, short yPos, short& cyPos, short& cIndex);
	+--------------------------------------------------------------+
	|	short yPos = 10;	[sesuaikan dengan cyPos]                   |
	|	short index = 0;	[index harus 0]                            |
	|                                                              |
	| ConsoleMenu ex {                                             |
	|   {                                                          |
	|		  "Menu 1",                                                |
	|		  "Menu 2",                                                |
	|		  "Menu 3"                                                 |
	|   },                                                         |
	|   true                                                       |
	|	};                                                           |
	|	ex.SetCursorColor(ConsoleColor::Green, ConsoleColor::Black); |
	|	ex.SetPadding(2);                                            | 
	|                                                              |
	|	switch((ex.Print(20, 10, yPos, index))) {                    |
	|		case 0:                                                    |
	|			...                                                      |
	|			break;                                                   |
	|		case 1:                                                    |
	|			...                                                      |
	|			break;                                                   |
	|		case 2:                                                    |
	|			...                                                      |
	|			break;                                                   |
	|	}                                                            |
	+--------------------------------------------------------------+

Last changelog:
	9 Apr 2020
		- Perbaikan kode
	6 Apr 2020
		- Perbaikan kode
	5 Apr 2020
		- Module dibuat

Written in Visual Studio 2019
*/

#ifndef CONSOLEMENU_H
#define CONSOLEMENU_H
#include <vector>
#include "Extensions.h"
class ConsoleMenu : private Extensions::Console {
private:
	/* Stored data menu */
	std::vector<std::string> storedMenu;

	/* Default Cusror color */
	Extensions::ConsoleColor bgCurColor = Extensions::ConsoleColor::Black;
	Extensions::ConsoleColor fgCurColor = Extensions::ConsoleColor::Green;

	/* Default padding */
	short padding = 1;

public:
	/*
		Constructor ConsoleMenu
		\param menu adalah menu
		\param fillSpace untuk menyamakan panjang cursor
	*/
	ConsoleMenu(
		std::initializer_list<std::string> menu,
		bool fillSpace = false
		);
	/*
		Mengubah warna cursor
		\param bgColor adalah warna background
		\param fgColor adalah warna foreground
	*/
	void SetCursorColor(
		Extensions::ConsoleColor bgColor,
		Extensions::ConsoleColor fgColor
		);

	/*
		Mengubah jarak antar baris
		\param padding adalah jarak
	*/
	void SetPadding(
		short padding
		);

	/*
		Menampilkan ConsoleMenu
		\param xPos adalah posisi x
		\param yPos adalah posisi y
	*/
	short Print(
		short xPos,
		short yPos
		);

	/*
		Menampilkan ConsoleMenu
		\param xPos adalah posisi x
		\param yPos adalah posisi y
		\param cyPos adalah reference posisi y
		\param cIndex adalah reference index
	*/
	short Print(
		short xPos,
		short yPos,
		short& cyPos,
		short& cIndex
		);
};
#endif // !CONSOLEMENU_H