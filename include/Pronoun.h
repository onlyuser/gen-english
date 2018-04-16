#ifndef PRONOUN_H
#define PRONOUN_H

#include <Noun.h>
#include <string>

class Pronoun : public Noun
{
public:
    typedef enum
    {
        FIRST_PERSON,
        SECOND_PERSON,
        THIRD_PERSON
    } person_t;

    typedef enum
    {
        SUBJECT_CASE,
        OBJECT_CASE
    } case_t;

    typedef enum
    {
        UNKNOWN_GENDER,
        MALE_GENDER,
        FEMALE_GENDER
    } gender_t;

    Pronoun(person_t person, bool plural = false, case_t _case = SUBJECT_CASE, gender_t gender = UNKNOWN_GENDER)
        : Noun("", true, plural),
          m_person(person),
          m_case(_case),
          m_gender(gender)
    {
    }

    virtual ~Pronoun()
    {
    }

    std::string to_string() const;

    person_t get_person() const
    {
        return m_person;
    }

    case_t get_case() const
    {
        return m_case;
    }

    gender_t get_gender() const
    {
        return m_gender;
    }

private:
    person_t m_person;
    case_t   m_case;
    gender_t m_gender;
};

#endif
