#include <Pronoun.h>
#include <string>

std::string Pronoun::to_string() const
{
    switch(m_person) {
        case FIRST_PERSON:
            if(is_plural()) {
                switch(get_case()) {
                    case SUBJECT_CASE: return "we";
                    case OBJECT_CASE:  return "us";
                }
            } else {
                switch(get_case()) {
                    case SUBJECT_CASE: return "I";
                    case OBJECT_CASE:  return "me";
                }
            }
            break;
        case SECOND_PERSON: return "you";
        case THIRD_PERSON:
            if(is_plural()) {
                switch(get_case()) {
                    case SUBJECT_CASE: return "they";
                    case OBJECT_CASE:  return "them";
                }
            } else {
                switch(get_gender()) {
                    case MALE_GENDER:
                        switch(get_case()) {
                            case SUBJECT_CASE: return "he";
                            case OBJECT_CASE:  return "him";
                        }
                        break;
                    case FEMALE_GENDER:
                        switch(get_case()) {
                            case SUBJECT_CASE: return "she";
                            case OBJECT_CASE:  return "her";
                        }
                        break;
                    case UNKNOWN_GENDER: return "it";
                }
            }
            break;
    }
    return "";
}
