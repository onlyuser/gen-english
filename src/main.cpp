#include <Noun.h>
#include <Pronoun.h>
#include <Verb.h>
#include <Aux.h>
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char** argv)
{
    //=========================================================================
    // PRESENT TENSE

    // I do go there.
    // I go there. <<irregular>>
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::DO, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_string();
        std::cout << s << std::endl;
    }

    // I do not go there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::DO, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->negate()->to_string();
        std::cout << s << std::endl;
    }

    // Do I go there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::DO, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_question()->to_string();
        std::cout << s << std::endl;
    }

    // Don't I go there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::DO, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->negate()->to_question()->to_string();
        std::cout << s << std::endl;
    }

    std::cout << std::endl;

    //=========================================================================
    // PAST TENSE

    // I did go there.
    // I went there. <<irregular>>
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::DO, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Aux::PAST)->to_string();
        std::cout << s << std::endl;
    }

    // I did not go there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::DO, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Aux::PAST)->negate()->to_string();
        std::cout << s << std::endl;
    }

    // Did I go there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::DO, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Aux::PAST)->to_question()->to_string();
        std::cout << s << std::endl;
    }

    // Didn't I go there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::DO, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Aux::PAST)->negate()->to_question()->to_string();
        std::cout << s << std::endl;
    }

    std::cout << std::endl;

    //=========================================================================
    // FUTURE TENSE

    // I will go there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::BE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Aux::FUTURE)->to_string();
        std::cout << s << std::endl;
    }

    // I will not go there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::BE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Aux::FUTURE)->negate()->to_string();
        std::cout << s << std::endl;
    }

    // Will I go there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::BE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Aux::FUTURE)->to_question()->to_string();
        std::cout << s << std::endl;
    }

    // Won't I go there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::BE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Aux::FUTURE)->negate()->to_question()->to_string();
        std::cout << s << std::endl;
    }

    std::cout << std::endl;

    //=========================================================================
    // PRESENT PERFECT TENSE

    // I have gone there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PAST_PARTICIPLE);
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_string();
        std::cout << s << std::endl;
    }

    // I have not gone there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PAST_PARTICIPLE);
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->negate()->to_string();
        std::cout << s << std::endl;
    }

    // Have I gone there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PAST_PARTICIPLE);
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_question()->to_string();
        std::cout << s << std::endl;
    }

    // Haven't I gone there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PAST_PARTICIPLE);
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->negate()->to_question()->to_string();
        std::cout << s << std::endl;
    }

    std::cout << std::endl;

    //=========================================================================
    // PAST PERFECT TENSE

    // I had gone there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PAST_PARTICIPLE);
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PAST_PERFECT)->to_string();
        std::cout << s << std::endl;
    }

    // I had not gone there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PAST_PARTICIPLE);
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PAST_PERFECT)->negate()->to_string();
        std::cout << s << std::endl;
    }

    // Had I gone there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PAST_PARTICIPLE);
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PAST_PERFECT)->to_question()->to_string();
        std::cout << s << std::endl;
    }

    // Hadn't I gone there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PAST_PARTICIPLE);
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PAST_PERFECT)->negate()->to_question()->to_string();
        std::cout << s << std::endl;
    }

    std::cout << std::endl;

    //=========================================================================
    // IMPERFECT TENSE

    // I am going there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PROGRESSIVE);
        std::string s = (new Aux(Aux::BE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PRESENT)->to_string();
        std::cout << s << std::endl;
    }

    // I am not going there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PROGRESSIVE);
        std::string s = (new Aux(Aux::BE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PRESENT)->negate()->to_string();
        std::cout << s << std::endl;
    }

    // Am I going there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PROGRESSIVE);
        std::string s = (new Aux(Aux::BE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PRESENT)->to_question()->to_string();
        std::cout << s << std::endl;
    }

    // Am I not going there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PROGRESSIVE);
        std::string s = (new Aux(Aux::BE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PRESENT)->negate()->to_question()->to_string();
        std::cout << s << std::endl;
    }

    std::cout << std::endl;

    //=========================================================================
    // IMPERFECT TENSE #2

    // I have been going there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PROGRESSIVE)->to_passive();
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PRESENT)->to_string();
        std::cout << s << std::endl;
    }

    // I have not been going there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PROGRESSIVE)->to_passive();
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PRESENT)->negate()->to_string();
        std::cout << s << std::endl;
    }

    // Have I been going there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PROGRESSIVE)->to_passive();
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PRESENT)->to_question()->to_string();
        std::cout << s << std::endl;
    }

    // Have I not been going there?
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_tense(Aux::PROGRESSIVE)->to_passive();
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_tense(Verb::PRESENT)->negate()->to_question()->to_string();
        std::cout << s << std::endl;
    }

    std::cout << std::endl;

    //=========================================================================
    // MODAL VERB

    // I can go there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"));
        std::string s = (new Aux(Aux::MODAL, verb, "can"))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_string();
        std::cout << s << std::endl;
    }

    std::cout << std::endl;

    //=========================================================================
    // PASSIVE VOICE

    // I am given it
    {
        Verb* verb = (new Verb("give"))->set_object(new Noun("it"))->to_tense(Verb::PAST_PARTICIPLE);
        std::string s = (new Aux(Aux::BE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_string();
        std::cout << s << std::endl;
    }

    // I have been given it
    {
        Verb* verb = (new Verb("give"))->set_object(new Noun("it"))->to_tense(Verb::PAST_PARTICIPLE)->to_passive();
        std::string s = (new Aux(Aux::HAVE, verb))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_string();
        std::cout << s << std::endl;
    }

    std::cout << std::endl;

    //=========================================================================
    // INFINITIVE RELATED

    // I have to go there.
    // I do have to go there.
    {
        Verb* verb = (new Verb("go"))->set_object(new Noun("there"))->to_infinitive();
        Verb* verb2 = (new Verb("have"))->set_object(new Noun(verb));
        std::string s = (new Aux(Aux::DO, verb2))->set_subject(new Pronoun(Pronoun::FIRST_PERSON))->to_string();
        std::cout << s << std::endl;
    }

    return 0;
}
