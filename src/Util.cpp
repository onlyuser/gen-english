#include <Util.h>

#include <string>

std::string replace(std::string &s, std::string find_string, std::string replace_string)
{
    if(s.empty() || find_string.empty()) {
        return s;
    }
    std::string _s(s);
    for(size_t p = 0; (p = _s.find(find_string, p)) != std::string::npos; p += replace_string.length()) {
         _s.replace(p, find_string.length(), replace_string);
    }
    return _s;
}

std::string apply_contractions(std::string &s)
{
    std::string _s(s);
    _s = replace(_s, "I am",       "I'm");
    _s = replace(_s, "we are",     "we're");
    _s = replace(_s, "is not",     "isn't");
    _s = replace(_s, "are not",    "aren't");
    _s = replace(_s, "does not",   "doesn't");
    _s = replace(_s, "do not",     "don't");
    _s = replace(_s, "has not",    "hasn't");
    _s = replace(_s, "have not",   "haven't");
    _s = replace(_s, "had not",    "hadn't");
    _s = replace(_s, "he is",      "he's");
    _s = replace(_s, "she is",     "she's");
    _s = replace(_s, "they are",   "they're");
    _s = replace(_s, "can not",    "can't");
    _s = replace(_s, "will not",   "won't");
    _s = replace(_s, "would not",  "wouldn't");
    _s = replace(_s, "should not", "shouldn't");
    return _s;
}
