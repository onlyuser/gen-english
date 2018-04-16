#ifndef NOUN_H
#define NOUN_H

#include <string>

class Verb;

class Noun
{
public:
    Noun(std::string name = "", bool pronoun = false, bool plural = false)
        : m_name(name),
          m_pronoun(pronoun),
          m_plural(plural)
    {
    }

    Noun(Verb* verb);

    virtual ~Noun()
    {
    }

    virtual std::string to_string() const;

    bool is_pronoun() const
    {
        return m_pronoun;
    }

    bool is_plural() const
    {
        return m_plural;
    }

private:
    std::string m_name;
    bool        m_pronoun;
    bool        m_plural;
    Verb*       m_verb;
};

#endif
