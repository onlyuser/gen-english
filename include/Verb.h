#ifndef VERB_H
#define VERB_H

#include <string>
#include <sstream>

class Noun;

class Verb
{
public:
    typedef enum
    {
        PRESENT,
        PAST,
        FUTURE,
        PAST_PARTICIPLE,
        PRESENT_PERFECT,
        PAST_PERFECT,
        PROGRESSIVE
    }  tense_t;

    typedef enum
    {
        ASSERTIVE,
        PASSIVE
    }  voice_t;

    Verb(std::string name = "")
        : m_name(name),
          m_tense(PRESENT),
          m_passive(false),
          m_infinitive(false)
    {
    }

    virtual ~Verb()
    {
    }

    virtual std::string to_string() const;

    Verb* set_object(Noun* object)
    {
        m_object = object;
        return this;
    }

    Verb* to_tense(tense_t tense)
    {
        m_tense = tense;
        return this;
    }

    Verb* to_passive()
    {
        m_passive = true;
        return this;
    }

    Verb* to_infinitive()
    {
        m_infinitive = true;
        return this;
    }

    bool is_infinitive() const
    {
        return m_infinitive;
    }

    bool is_gerund() const
    {
        return m_tense == PROGRESSIVE;
    }

private:
    std::string m_name;

protected:
    tense_t m_tense;

private:
    Noun* m_object;
    bool  m_passive;
    bool  m_infinitive;
};

#endif
