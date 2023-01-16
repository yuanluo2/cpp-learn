#include <boost/locale.hpp>

std::string from_locale(const std::string& localeStr) {
    boost::locale::generator g;
    g.locale_cache_enabled(true);
    std::locale loc = g(boost::locale::util::get_system_locale());
    return boost::locale::conv::to_utf<char>(localeStr, loc);
}

std::string to_locale(const std::string& utf8Str) {
    boost::locale::generator g;
    g.locale_cache_enabled(true);
    std::locale loc = g(boost::locale::util::get_system_locale());
    return boost::locale::conv::from_utf<char>(utf8Str, loc);
}

string utf8_to_gbk(const string & str){
    return boost::locale::conv::between(str, "GBK", "UTF-8");
}

string gbk_to_utf8(const string & str){
    return boost::locale::conv::between(str, "UTF-8", "GBK");
}

wstring utf8_to_wide(const string & str){
    return boost::locale::conv::to_utf<wchar_t>(str, "UTF-8");
}

string wide_to_utf8(const wstring& wstr){
    return boost::locale::conv::from_utf(wstr, "UTF-8");
}

wstring gbk_to_wide(const string & str){
    return boost::locale::conv::to_utf<wchar_t>(str, "GBK");
}

string wide_to_gbk(wstring wstr){
    return boost::locale::conv::from_utf(wstr, "GBK");
}
