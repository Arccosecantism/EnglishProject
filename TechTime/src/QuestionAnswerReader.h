#pragma once
#include "ofMain.h"

class QuestionAnswerReader
{
  public:
  QuestionAnswerReader(std::string filename);
  std::vector<std::string> getQASet(int i);
  private:
  std::vector<std::vector<std::string>> QuestionAnswerSetsText;
};
