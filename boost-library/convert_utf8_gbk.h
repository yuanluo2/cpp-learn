#include <boost/locale.hpp>
#include <string>

std::string utf8_to_gbk(const std::string& str){
    return boost::locale::conv::between(str, "GBK", "UTF-8");
}

std::string gbk_to_utf8(const std::string& str){
    return boost::locale::conv::between(str, "UTF-8", "GBK");
}
