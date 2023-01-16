#include <iostream>
#include <format>
#include <filesystem>
#include <boost/locale.hpp>

namespace fs = std::filesystem;

int main() {
	try
	{
		system("chcp 65001");        // change the current chcp to 65001, that is utf8.
		fs::path p{ R"(E:\Hatsune Miku\music)" };

		for (const auto& e : fs::directory_iterator(p, fs::directory_options::skip_permission_denied)) {
			std::cout << std::format("{}\n", boost::locale::conv::utf_to_utf<char>(e.path().wstring()));
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
