#include <Verb.h>
#include <Noun.h>

std::string Verb::to_string() const
{
    std::stringstream ss;

    std::string verb;
    if(m_name == "go") {
        switch(m_tense) {
            case PRESENT:         verb = "go"; break;
            case PAST:            verb = "went"; break;
            case FUTURE:          verb = "go"; break;
            case PAST_PARTICIPLE: verb = "gone"; break;
            case PRESENT_PERFECT: verb = "gone"; break;
            case PAST_PERFECT:    verb = "gone"; break;
            case PROGRESSIVE:     verb = "going"; break;
        }
    } else if(m_name == "give") {
        switch(m_tense) {
            case PRESENT:         verb = "give"; break;
            case PAST:            verb = "gave"; break;
            case FUTURE:          verb = "give"; break;
            case PAST_PARTICIPLE: verb = "given"; break;
            case PRESENT_PERFECT: verb = "given"; break;
            case PAST_PERFECT:    verb = "given"; break;
            case PROGRESSIVE:     verb = "giving"; break;
        }
    } else {
        verb = m_name;
    }

    if(m_infinitive) {
        ss << "to";
    } else if(m_passive) {
        ss << "been";
    }

    {
        if(ss.str().length()) { ss << " "; }
        ss << verb;
    }

    if(m_object) {
        if(ss.str().length()) { ss << " "; }
        ss << m_object->to_string();
    }

    return ss.str();
}
