#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<float.h>
#include<math.h>
#include<deque>

#include "pos.h"
#include "tst.h"
#include "wordtype.h"
#include "wordtoken.h"
#include <exception>
#include "ngram.h"

Ngram::Ngram() {
    this->dict = new TernarySearchTrie();
    char fname[] = "../dic/coredict.txt";
    this->dict->loadBaseDict(fname);

    char fname1[] = "../dic/bigramdict_u.txt";
    this->dict->loadBigramDict(fname1);

    this->tagger = new Tagger();
    char fname2[] = "../dic/transprobility.txt";
    this->tagger->loadModel(fname2);

    this->lambda1 = 0.3;
    this->lambda2 = 0.7;
}

Ngram::~Ngram() {
    if (dict != NULL) {
        delete dict;
    }
}

int Ngram::getBigramFreq(WordType *prev, WordType *next) {
    int freq = 0;
    if (next->biEntry != NULL && prev->biEntry != NULL) {
        freq = next->biEntry->getfreq(prev->biEntry->id);
        //std::wcout << prev->biEntry->id << " freq:" << freq << std::endl;
    }
    if (freq < 0) {
        return 0;
    }
    return freq;
}

void Ngram::split(std::wstring sentence) {
    this->_len = sentence.size() + 1;

    int prevNode[_len];
    double prob[_len];
    WordType* preCnToken[_len];
    for(int i=0; i<_len; i++) {
        preCnToken[i] = NULL;
    }

    WordTypes* types = new WordTypes(1);
    types->insert(0, Pos::start, 1000);
    WordType* start_word = new WordType(L"start", types, NULL);

    preCnToken[0] = start_word;

    std::vector<WordType*> wordMatch;
    for(size_t i=1; i<this->_len; i++) {
        double maxProb = -DBL_MAX / 2;
        size_t maxPrev = -1;
        WordType *preToken = NULL;

        this->dict->matchAll(sentence, i-1, &wordMatch);
        std::vector<WordType*>::iterator iter;
        for (iter=wordMatch.begin(); iter!=wordMatch.end(); iter++) {

            WordType *t1 = *iter;
            size_t start = i - t1->word.size();
            WordType *t2 = preCnToken[start];
            //std::wcout << "t1 is :" << t1->tostring() << std::endl;
            //std::wcout << "t2 is :" << t2->tostring() << std::endl;


            int bigramFreq = this->getBigramFreq(t2, t1);
            double wordProb = lambda1 * (t1->pos->total) / dict->n + lambda2 * (bigramFreq / t2->pos->total);

            double nodeProb = prob[start] + log(wordProb);

            //std::wcout << nodeProb << ": " << maxProb << std::endl;

            if (nodeProb > maxProb) {
                maxPrev = start;
                maxProb = nodeProb;
                preToken = t1;
            }
            prob[i] = maxProb;
            prevNode[i] = maxPrev;
            preCnToken[i] = preToken;
        }
    }

    std::deque<WordToken*> tokens;
    int start1 = 0;
    for (int end=this->_len-1; end>0; end=start1) {
        start1 = prevNode[end];

        //WordType* t = this->preCnToken[end];
        //std::wcout << "----->end:" << end << " word: " << t->word << std::endl;

        WordToken* token = new WordToken(start1, end, preCnToken[end]->word, preCnToken[end]->pos);
        tokens.push_front(token);
    }

    //词性标注
    this->tagger->hmm(tokens);

    std::deque<WordToken*>::iterator it;
    for (it=tokens.begin(); it != tokens.end(); it++) {
        std::wcout << (*it)->tostring() << std::endl;
    }
    std::wcout << L"#####################" << std::endl;

}

