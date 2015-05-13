#include "TriviaSet.h"

TriviaSet::TriviaSet()
{

}

void TriviaSet::addQuestionText(std::string qtex)
{
  questionTexts.push_back(qtex);
}

void TriviaSet::alterQuestion(std::string nqtex, int i)
{
    questionTexts[i] = nqtex;
}

void TriviaSet::addAnswerText(std::string atex)
{
  answerTexts.push_back(atex);
}

void TriviaSet::alterAnswer(std::string natex, int i)
{
    answerTexts[i] = natex;
}

void TriviaSet::setDecade(int ndec)
{
    decade = ndec;
}

std::vector<std::string> TriviaSet::getAnswerVector()
{
    return answerTexts;
}

std::vector<std::string> TriviaSet::getQuestionVector()
{
    return questionTexts;
}

//int TriviaSet::getQuestionVectorSize()
//{
//    return questionTexts.size();
//}
//
//int TriviaSet::getAnswerVectorSize()
//{
//   return answerTexts.size()
//}

int TriviaSet::getDecade()
{
    return decade;
}

