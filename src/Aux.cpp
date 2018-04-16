#include <Aux.h>
#include <Noun.h>
#include <Pronoun.h>
#include <Util.h>
#include <string>
#include <sstream>

std::string Aux::to_string() const
{
    std::string aux;
    switch(m_type) {
        case BE:
            switch(m_tense) {
                case PRESENT:
                    if(m_subject->is_plural()) {
                        aux = "are";
                    } else {
                        if(m_subject->is_pronoun()) {
                            switch(dynamic_cast<Pronoun*>(m_subject)->get_person()) {
                                case Pronoun::FIRST_PERSON:
                                    if(m_negate && m_question) {
                                        aux = "are";
                                    } else {
                                        aux = "am";
                                    }
                                    break;
                                case Pronoun::SECOND_PERSON: aux = "are"; break;
                                case Pronoun::THIRD_PERSON:  aux = "is";  break;
                            }
                        } else {
                            aux = "is"; break;
                        }
                    }
                    break;
                case PAST:            aux = (m_subject->is_plural()) ? "were" : "was"; break;
                case FUTURE:          aux = "will";  break;
                case PRESENT_PERFECT: aux = "_";     break;
                case PAST_PERFECT:    aux = "_";     break;
                case PROGRESSIVE:     aux = "being"; break;
                default: break;
            }
            break;
        case DO:
            switch(m_tense) {
                case PRESENT:
                    if(m_subject->is_plural()) {
                        aux = "do";
                    } else {
                        if(m_subject->is_pronoun()) {
                            switch(dynamic_cast<Pronoun*>(m_subject)->get_person()) {
                                case Pronoun::FIRST_PERSON:  aux = "do";   break;
                                case Pronoun::SECOND_PERSON: aux = "do";   break;
                                case Pronoun::THIRD_PERSON:  aux = "does"; break;
                            }
                        } else {
                            aux = "does"; break;
                        }
                    }
                    break;
                case PAST:            aux = "did";    break;
                case FUTURE:          aux = "_";      break;
                case PRESENT_PERFECT: aux = "_";      break;
                case PAST_PERFECT:    aux = "_";      break;
                case PROGRESSIVE:     aux = "doing";  break;
                default: break;
            }
            break;
        case HAVE:
            switch(m_tense) {
                case PRESENT:
                    if(m_subject->is_plural()) {
                        aux = "have";
                    } else {
                        if(m_subject->is_pronoun()) {
                            switch(dynamic_cast<Pronoun*>(m_subject)->get_person()) {
                                case Pronoun::FIRST_PERSON:  aux = "have"; break;
                                case Pronoun::SECOND_PERSON: aux = "have"; break;
                                case Pronoun::THIRD_PERSON:  aux = "has";  break;
                            }
                        } else {
                            aux = "has"; break;
                        }
                    }
                    break;
                case PAST:            aux = "had";    break;
                case FUTURE:          aux = "_";      break;
                case PRESENT_PERFECT: aux = "have";   break;
                case PAST_PERFECT:    aux = "had";    break;
                case PROGRESSIVE:     aux = "having"; break;
                default: break;
            }
            break;
        case MODAL: aux = m_name; break;
    }

    std::stringstream ss;

    std::string first_part = m_subject->to_string();

    std::string second_part;
    {
        std::stringstream ss;
        ss << aux;
        if(m_negate) {
            if(ss.str().length()) { ss << " "; }
            ss << "not";
        }
        second_part = ss.str();
        second_part = apply_contractions(second_part);
    }

    if(m_question) {
        std::swap(first_part, second_part);
    }
    ss << first_part;
    if(ss.str().length()) { ss << " "; }
    ss << second_part;

    if(m_verb) {
        if(ss.str().length()) { ss << " "; }
        ss << m_verb->to_string();
    }

    if(m_question) {
        ss << "?";
    } else {
        ss << ".";
    }

    return ss.str();
}
