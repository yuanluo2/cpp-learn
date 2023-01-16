#include <iostream>
#include <windows.h>

// only works on windows.
int main() {
	auto pressed = [](int vkey) {                  // virtual key: see https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
		return GetAsyncKeyState(vkey) & 0x0001;      // GetAsyncKeyState(): see https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getasynckeystate
	};

	for (;;) {
		if (pressed(VK_UP))
			std::cout << "up.\n";

		if (pressed(VK_DOWN))
			std::cout << "down.\n";

		if (pressed(VK_LEFT))
			std::cout << "left.\n";

		if (pressed(VK_RIGHT))
			std::cout << "right.\n";
	}
}
