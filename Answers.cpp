/**
 * Answer.cpp
 *
 * Katherine Geiger, Keyaria Walker
 * kageiger, keyariaw
 *
 * EECS 183: Project 4
 *
 * This program matches people based on their 
 *  answers to a personalily test
 */

#include "Answer.h"

Answer::Answer() {
    Attribute();
    text = " ";
}

Attribute Answer::getAttribute() {
    return attribute;
}

void Answer::setAttribute(Attribute &inAttribute) {
    attribute = inAttribute;
}

string Answer::getText() {
    return text;
}

void Answer::setText(string inText) {
    text = inText;
}

// DONE WRITING: getAttribute, setAttribute, getText, setText


void Answer::read(istream &ins) {
    attribute.read(ins);
    getline(ins, text);
}


void Answer::write(ostream &outs) {
    outs << text;
}
