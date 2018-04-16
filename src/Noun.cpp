#include <Noun.h>
#include <Verb.h>
#include <string>

Noun::Noun(Verb* verb)
    : m_name(""),
      m_pronoun(false),
      m_plural(false),
      m_verb(verb)
{
    if(!verb->is_infinitive() && !verb->is_gerund()) {
        throw "Error: Verb as noun must be either infinitive or gerund!";
    }
}

std::string Noun::to_string() const
{
    if(m_verb) {
        return m_verb->to_string();
    }
    return m_name;
}
