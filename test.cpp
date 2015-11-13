/**
 * test.cpp
 *
 * EECS 183, Fall 2015
 * Project 4: EECS Harmony Test Suite
 *
 * Katherine Geiger, Keyaria Walker
 * kageiger, keyariaw
 *
 * A program designed to match people based on their answers to a quiz
 */

#include <iostream>
#include "Personality.h"
#include "Question.h"
#include "Answer.h"
#include "Attribute.h"
// Test functions written for us: (DONE)
void test_Attribute_construct_default();
void test_Attribute_construct_2param();
void test_Attribute_setIndex();

//Test functions for Attribute.cpp: (DONE)
void test_Attribute_setPoints();
void test_Attribute_read(); 


//Test functions for Answer.cpp: (DONE)
void test_Answer_construct_default(); 
void test_Answer_setAttribute();
void test_Answer_getText();

//Test functions for Personality.cpp:(DONE)
void test_Personality_reset(); 
void test_Personality_adjustPersonality();



//Test functions for Question.cpp: TO DO
void test_Question_addAnswer();
void test_Question_getNumAnswers();
void test_Question_getValueWithinRange();
void test_Question_setQuestionPrompt();




/**
 * Declare more test functions here
 * It is a good idea to test all constructors
 * It is a good idea to test all member functions that modify member variables
 * It is a good idea to test read() and write()
 */

int main() {
     test_Attribute_construct_default();
     test_Attribute_construct_2param();
     test_Attribute_setIndex();
     test_Attribute_setPoints();
     test_Answer_construct_default();
     test_Answer_setAttribute();
     test_Answer_getText();
     test_Personality_adjustPersonality();
     test_Personality_reset();
     test_Question_addAnswer();
     test_Question_getNumAnswers();
     test_Question_setQuestionPrompt();


    // Add calls to test functions that you create here

    return 0;
}


void test_Attribute_construct_default() {
    Attribute att;

    if (att.getIndex() != 0) {
        cout << "bug in Attribute default constructor" << endl;
    }

    if (att.getPoints() != 0) {
        cout << "bug in Attribute default constructor" << endl;
    }
}


void test_Attribute_construct_2param() {
    // Test good values
    Attribute att1(4, 5);
    if (att1.getIndex() != 4) {
        cout << "bug in Attribute non-default constructor" << endl;
    }

    if (att1.getPoints() != 5) {
        cout << "bug in Attribute non-default constructor" << endl;
    }

    // Test invalid index, low
    Attribute att2(-1, 5);
    if (att2.getIndex() != 0) {
        cout << "bug in Attribute non-default constructor" << endl;
    }

    if (att2.getPoints() != 5) {
        cout << "bug in Attribute non-default constructor" << endl;
    }

    // Test invalid index, high
    Attribute att3(MAX_NUM_ATTRIBUTES, 5);
    if (att3.getIndex() != (MAX_NUM_ATTRIBUTES - 1)) {
        cout << "bug in Attribute non-default constructor" << endl;
    }

    if (att3.getPoints() != 5) {
        cout << "bug in Attribute non-default constructor" << endl;
    }
}

void test_Attribute_setIndex() {
    Attribute att(4, 5);

    att.setIndex(0);
if (att.getIndex() != 0) {
    cout << "bug in Attribute::setIndex()" << endl;
}

if (att.getPoints() != 5) {
    cout << "bug in Attribute::setIndex()" << endl;
}

// Test invalid index, low
att.setIndex(-1);
if (att.getIndex() != 0) {
    cout << "bug in Attribute::setIndex()" << endl;
}

if (att.getPoints() != 5) {
    cout << "bug in Attribute::setIndex()" << endl;
}

// Test invalid index, high
att.setIndex(MAX_NUM_ATTRIBUTES);
if (att.getIndex() != (MAX_NUM_ATTRIBUTES - 1)) {
    cout << "bug in Attribute::setIndex()" << endl;
}

if (att.getPoints() != 5) {
    cout << "bug in Attribute::setIndex()" << endl;
}
}

void test_Attribute_setPoints() {
    Attribute att(4, 5);

    att.setPoints(0);
    if (att.getPoints() != 0) {
        cout << "bug in Attribute::setPoints()" << endl;
    }

    // Test negative points
    att.setPoints(-1);
    if (att.getPoints() != (-1)) {
        cout << "bug in Attribute::setPoints()" << endl;
    }

    // Test really big points
    att.setPoints(500);
    if (att.getPoints() != 500) {
        cout << "bug in Attribute::setPoints()" << endl;
    }

}

void test_Attribute_read() {
    Attribute att;
    cout << "Enter Attribute: ";
    att.read(cin);
    att.write(cout);
}

void test_Answer_construct_default() {
    Answer ans;

    ans.getAttribute().getIndex();


    if (ans.getAttribute().getIndex() != 0) {
        cout << "bug in Answer default constructor" << endl;
    }

    if (ans.getAttribute().getPoints() != 0) {
        cout << "bug in Answer default constructor" << endl;
    }

    if (ans.getText() != "") {
        cout << "bug in Answer default constructor" << endl;
    }
}

void test_Answer_setAttribute() {

    Answer ans;
    Attribute temp;

    ans.setAttribute(temp);
    if (temp.getIndex() != ans.getAttribute().getIndex()) {
        cout << "bug in Answer::setAttribute()" << endl;
    }


    if (temp.getPoints() != ans.getAttribute().getPoints()) {
        cout << "bug in Answer::setAttribute()" << endl;
    }

}

void test_Answer_getText() {
    Answer ans;
    string temp = "cats";
    ans.setText(temp);
    if (ans.getText() != temp){
        cout << "bug in Answer::getText()" << endl;
    }
}


void test_Personality_reset() {
    // Test going over max points
    Attribute att1(1, 11);
    Personality kate;
    kate.write(cout);
    kate.adjustPersonality(att1);
    kate.write(cout); 
    kate.reset();
    kate.write(cout);
    cout << endl << endl;

}

void test_Personality_adjustPersonality() {
    
    // Test going over max points
    Attribute att1(1, 11);
    Personality kate;
    kate.write(cout);
    kate.adjustPersonality(att1);
    kate.write(cout);
    cout << endl << endl;

    // Test too few points
    Attribute att2(1, -11);
    Personality jon;
    jon.write(cout);
    jon.adjustPersonality(att2);
    jon.write(cout);
    cout << endl << endl;

    // Where nothing changes
    Attribute att3(1, 3);
    Personality dog;
    dog.write(cout);
    dog.adjustPersonality(att3);
    dog.write(cout);
    cout << endl << endl;
}



void test_Question_addAnswer() {
 
    Question ans;
    Answer a;
    string temp = "cat";
    a.setText(temp);
    int place = ans.getNumAnswers();
    ans.addAnswer(a);

    Answer j = ans.getAnswer(place);
    j.write(cout);
    
}


void test_Question_getNumAnswers() {
    Question que;
    Answer a;
    if (que.getNumAnswers() != 0) {
        cout << "bug in Question::getNumAnswers" << endl;
    }
    que.addAnswer(a);
    if (que.getNumAnswers() != 1) {
        cout << "bug in Question::getNumAnswers" << endl;
    }
    Answer b;
    que.addAnswer(b);
    if (que.getNumAnswers() != 2) {
        cout << "bug in Question::getNumAnswers" << endl;
    }
}


void test_Question_getValueWithinRange() {
   
    /*// Test going over max value
    Answer ans1;
    Question que;
    que.write(cout);
    que.getValueWithinRange();
    que.write(cout);
    cout << endl << endl;
    */
}

void test_Question_setQuestionPrompt() {

    Question que;
    string temp = "cat";

    que.setQuestionPrompt(temp);
    if (que.getQuestionPrompt() != temp) {
        cout << "bug in Answer::setQuestionPrompt()" << endl;
    }

}







// define more test functions here
