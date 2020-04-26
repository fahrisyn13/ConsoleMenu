#include "ConsoleMenu.h"
#include <iostream>
#include <windows.h>
ConsoleMenu::ConsoleMenu(
	std::initializer_list<std::string> menu,
	bool fillSpace
	) {
	if (fillSpace) {
		unsigned short maxLength = 0;

		for (std::string data : menu)
			if (data.length() > maxLength)
				maxLength = static_cast<unsigned short>(data.length());
		for (std::string data : menu) {
			std::string sChar;

			for (unsigned short i = 0; i < (maxLength - data.length()); i++)
				sChar += ' ';
			storedMenu.push_back(data + sChar);
		}
	}
	else
		for (std::string data : menu)
			storedMenu.push_back(data);
}

void ConsoleMenu::SetCursorColor(
	Extensions::ConsoleColor bgColor,
	Extensions::ConsoleColor fgColor
	) {
	bgCurColor = bgColor;
	fgCurColor = fgColor;
}

void ConsoleMenu::SetPadding(
	short padding
	) {
	this->padding += padding;
}

short ConsoleMenu::Print(
	short xPos,
	short yPos
	) {
	short
		x = xPos,
		y = yPos,
		curPos = yPos,
		begPos = yPos,
		endPos = 0,
		cIndex = 0,
		lIndex = static_cast<unsigned short>(storedMenu.size()) - 1,
		cColor = GetDefaultColor();

	Extensions::Console::ShowConsoleCursor(false);
	for (std::string data : storedMenu) {
		Extensions::Console::SetCursorPosition(x, y); std::cout << data;;
		y += padding;
	}
	endPos = y - padding;

	while (true) {
		Extensions::Console::SetCursorPosition(x, curPos);
		Extensions::Console::PrintTextColor(bgCurColor, fgCurColor, storedMenu[cIndex]);
		system("pause>nul");
		Extensions::Console::SetCursorPosition(x, curPos);
		Extensions::Console::SetTextColor(cColor); std::cout << (storedMenu[cIndex]);

		if (GetAsyncKeyState(VK_DOWN)) {
			if (curPos != endPos) {
				curPos += padding;
				cIndex++;
			}
			else {
				curPos = begPos;
				cIndex = 0;
			}
		}
		else if (GetAsyncKeyState(VK_UP)) {
			if (curPos != begPos) {
				curPos -= padding;
				cIndex--;
			}
			else {
				curPos = endPos;
				cIndex = lIndex;
			}
		}
		else if (GetAsyncKeyState(VK_RETURN)) {
			Extensions::Console::ShowConsoleCursor(true);
			return cIndex;
		}
	}
}

short ConsoleMenu::Print(
	short xPos,
	short yPos,
	short& cyPos,
	short& cIndex
	) {
	short
		x = xPos,
		y = yPos,
		curPos = cyPos,
		begPos = yPos,
		endPos = 0,
		cInd = cIndex,
		lIndex = static_cast<unsigned short>(storedMenu.size()) - 1,
		cColor = GetDefaultColor();

	Extensions::Console::ShowConsoleCursor(false);
	for (std::string data : storedMenu) {
		Extensions::Console::SetCursorPosition(x, y); std::cout << data;
		y += padding;
	}
	endPos = y - padding;

	while (true) {
		Extensions::Console::SetCursorPosition(x, curPos);
		Extensions::Console::PrintTextColor(bgCurColor, fgCurColor, storedMenu[cInd]);
		system("pause>nul");
		Extensions::Console::SetCursorPosition(x, curPos);
		Extensions::Console::SetTextColor(cColor); std::cout << (storedMenu[cInd]);

		if (GetAsyncKeyState(VK_DOWN)) {
			if (curPos != endPos) {
				curPos += padding;
				cInd++;
			}
			else {
				curPos = begPos;
				cInd = 0;
			}
		}
		else if (GetAsyncKeyState(VK_UP)) {
			if (curPos != begPos) {
				curPos -= padding;
				cInd--;
			}
			else {
				curPos = endPos;
				cInd = lIndex;
			}
		}
		else if (GetAsyncKeyState(VK_RETURN)) {
			cyPos = curPos;
			cIndex = cInd;
			Extensions::Console::ShowConsoleCursor(true);
			return cIndex;
		}
	}
}