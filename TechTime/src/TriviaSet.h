#pragma once

class TriviaSet
{
  public:
    TriviaSet();
    void addQuestion(std::string qtex);
    void alterQuestion(std::string nqtex, int i);
    
    void addAnswer(std::string atex);
    void alterAnswer(std::string natex, int i);
    
    void setDecade(int ndec);
    
    void getQuestionsVector();
    void getAnswerVector();
    void getDecade();
    
  private:
    std::vector<std::string> questionTexts;
    std::vector<std::string> answerTexts;
    int decade;
}
