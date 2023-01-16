#include <boost/locale.hpp>

string utf8_to_gbk(const string & str){
    return boost::locale::conv::between(str, "GBK", "UTF-8");
}

string gbk_to_utf8(const string & str){
    return boost::locale::conv::between(str, "UTF-8", "GBK");
}
