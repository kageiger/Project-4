/**
 * Question.cpp
 *
 * Katherine Geiger, Keyaria Walker
 * kageiger, keyariaw
 *
 * EECS 183: Project 4
 *
 * A test program that matches users based on their answers 
 * to a personality quiz
 */

#include "Question.h"


 // TODO: implement constructor, getValueWithinRange, getNumAnswers,
 //       getQuestionPrompt, setQuestionPrompt, getAnswer, addAnswer,
 //       getAttributeOfAnswer


Question::Question() {
    numAnswers = 0;
    questionPrompt = "";
}

int Question::getValueWithinRange(int value, int minValue, int maxValue) {

    if (value < minValue) {
        return minValue;
    }
    if (value > maxValue) {
        return maxValue;
    }

    return value;
}

int Question::getNumAnswers() {
    return numAnswers;
}

string Question::getQuestionPrompt() {
    return questionPrompt;
}

void Question::setQuestionPrompt(string inQuestionPrompt) {

    questionPrompt = inQuestionPrompt;


}

Answer Question::getAnswer(int index) {

    getValueWithinRange(index, 0, (numAnswers - 1));
    if (getValueWithinRange(index, 0, (numAnswers - 1)) != index) {
        return Answer();
    }

    return answers[index];

}
void Question::addAnswer(Answer &inAnswer) {

    answers[numAnswers] = inAnswer;
    numAnswers++;

    //answers[answers.length() - 1] = inAnswer.getAttribute();
}

// After checking validity returns
Attribute Question::getAttributeOfAnswer(int answerNumber) {

    getValueWithinRange(answerNumber, 1, numAnswers);   
    if (getValueWithinRange(answerNumber, 1, 
            numAnswers) != answerNumber) {
        return Attribute();
    }
    answerNumber -= 1;
    return answers[answerNumber].getAttribute();
}


void Question::read(istream &ins) {
    
    int tempNumAnswers;
    ins >> tempNumAnswers;
    
    string tempQuestionPrompt;
    getline(ins, tempQuestionPrompt);
    questionPrompt = tempQuestionPrompt;


    for (int i=0; i < tempNumAnswers; i++) {
        Answer answer;
        answer.read(ins);
        addAnswer(answer);
    }
}


void Question::write(ostream &outs) { 
    Answer ansWrite;
    outs << questionPrompt;

    for (int i=0; i < numAnswers; i++) {

        outs << i + 1 << ") ";
        answers[i].write(outs);
    }
}
