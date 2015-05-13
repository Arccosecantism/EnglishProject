#pragma once
#include "ofMain.h"

class TriviaSet
{
  public:
    TriviaSet();
    void addQuestionText(std::string qtex);
    void alterQuestion(std::string nqtex, int i);

    void addAnswerText(std::string atex);
    void alterAnswer(std::string natex, int i);

    void setDecade(int ndec);

    std::vector<std::string> getQuestionVector();
    std::vector<std::string> getAnswerVector();
//    int getQuestionVectorSize();
//    int getAnswerVectorSize();
    int getDecade();

  private:
    std::vector<std::string> questionTexts;
    std::vector<std::string> answerTexts;
    int decade;
};
