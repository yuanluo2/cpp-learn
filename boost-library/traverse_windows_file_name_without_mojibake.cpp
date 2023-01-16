#include <iostream>
#include <format>
#include <filesystem>
#include <boost/locale.hpp>

namespace fs = std::filesystem;

// Prevent mojibake under Windows's console.
int main() {
	try
	{
		fs::path p{ R"(E:\Hatsune Miku\music)" };

		for (const auto& e : fs::directory_iterator(p, fs::directory_options::skip_permission_denied)) {
			std::cout << std::format("{}\n", boost::locale::conv::from_utf(e.path().wstring(), "gbk"));
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
