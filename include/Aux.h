#ifndef AUX_H
#define AUX_H

#include <Verb.h>

class Noun;

class Aux : public Verb
{
public:
    typedef enum
    {
        BE,
        DO,
        HAVE,
        MODAL
    }  type_t;

    Aux(type_t type, Verb* verb, std::string name = "")
        : m_type(type),
          m_verb(verb),
          m_name(name),
          m_subject(NULL),
          m_negate(false),
          m_question(false)
    {
    }

    virtual ~Aux()
    {
    }

    std::string to_string() const;

    Aux* set_subject(Noun* subject)
    {
        m_subject = subject;
        return this;
    }

    Aux* to_tense(tense_t tense)
    {
        m_tense = tense;
        return this;
    }

    Aux* negate()
    {
        m_negate = true;
        return this;
    }

    Aux* to_question()
    {
        m_question = true;
        return this;
    }

private:
    type_t      m_type;
    Verb*       m_verb;
    std::string m_name;
    Noun*       m_subject;
    bool        m_negate;
    bool        m_question;
};

#endif
