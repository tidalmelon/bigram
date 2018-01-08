#include<fstream>
#include<cstring>
#include<math.h>
#include<iostream>
#include<boost/algorithm/string/classification.hpp>
#include<boost/algorithm/string/split.hpp>
#include<boost/lexical_cast.hpp>

#include "pos.h"
#include "wordtoken.h"

class Tagger {

public:

    Tagger() {
        memset(typeFreq, 0, sizeof(typeFreq));
        memset(transFreq, 0, sizeof(transFreq));
    }

    void loadModel(char fname[]) {
        std::ifstream in(fname);
        std::string line;

        getline(in, line);
        //std::cout << line << std::endl;
        int frqCount = boost::lexical_cast<int>(line);
        for (int m=0; m<frqCount; m++) {
            getline(in, line);
            std::vector<std::string> dest;
            boost::split(dest, line, boost::is_any_of(":"), boost::token_compress_on);
            std::wstring posname = s2ws(dest.at(0));
            int freq = boost::lexical_cast<int>(dest.at(1));
            typeFreq[m] = freq;

            //std::wcout << posname << ":" << freq << std::endl;
        }

        int i = 0; //转移概率x
        while (getline(in, line)) {
            std::vector<std::string> dest;
            boost::split(dest, line, boost::is_any_of(" "), boost::token_compress_on);

            std::vector<std::string>::iterator iter;
            int j = 0; //转移概率y
            for (iter=dest.begin(); iter!=dest.end(); iter++) {
                //std::cout << *iter << " " << std::endl;
                transFreq[i][j] = boost::lexical_cast<int>(*iter);
                j++;
            }
            i++;
        }
    }

    double getTransProb(int curState, int toTranState) {
        return log(double(transFreq[curState][toTranState] + 1) / (typeFreq[curState] + 49));
    }

    void hmm(std::deque<WordToken*> ret) {
        WordTypes* starttypes = new WordTypes(1);
        starttypes->insert(0, Pos::start, 1);
        WordToken* starttoken = new WordToken(-1, 0, L"Start", starttypes);
        ret.push_front(starttoken);

        WordTypes* endtypes = new WordTypes(1);
        endtypes->insert(0, Pos::end, 100);
        WordToken* endtoken = new WordToken(-1, 0, L"End", endtypes);
        ret.push_back(endtoken);

        int stagelength = ret.size();
        double prob[stagelength][49];
        for (int i=0; i<stagelength; i++) {
            for (int j=0; j<49; j++) {
                prob[i][j] = -DBL_MAX;
            }
        }

        int bestpre[stagelength][49];
        for (int i=0; i<stagelength; i++) {
            for (int j=0; j<49; j++) {
                bestpre[i][j] = Pos::unknow;
            }
        }

        prob[0][Pos::start] = 1;

        //viterbi 解码
        for (int stage=1; stage<stagelength; stage++) {

            WordToken* nextoken = ret.at(stage);
            if (nextoken->data == NULL) {
                continue;
            }

            for(size_t nxtidx=0; nxtidx < nextoken->data->len_arr; ++nxtidx) {
                WordToken* pretoken = ret.at(stage-1);
                if (pretoken->data == NULL) {
                    continue;
                }

                int nextPos = nextoken->data->keys[nxtidx];
                double nextPosFreq = nextoken->data->vals[nxtidx];
                double emiprob = log(nextPosFreq / (typeFreq[nextPos] + 49));

                for (size_t preidx=0; preidx < pretoken->data->len_arr; ++preidx) {
                    int prevPos = pretoken->data->keys[preidx];
                    double transProb = getTransProb(prevPos, nextPos);
                    double preProb = prob[stage-1][prevPos];
                    double currentProb = preProb + transProb + emiprob;
                    if (prob[stage][nextPos] <= currentProb) {
                        prob[stage][nextPos] = currentProb;
                        bestpre[stage][nextPos] = prevPos;
                    }
                }
            }
        }
        
        int tmpTag = Pos::end;
        int bestTag[stagelength];
        memset(bestTag, 0, sizeof(bestTag));
        for (int i=(stagelength-1); i>1; i--) {
            bestTag[i-1] = bestpre[i][tmpTag];
            tmpTag = bestTag[i-1];
        }
        int *resultTag = new int[stagelength-2]; 
        for (int i=1; i< (stagelength-1); i++) {
            //std::wcout << "[" << bestTag[i] << " : " << Pos::names[bestTag[i]] << "]";
            ret.at(i)->p = bestTag[i];
            ret.at(i)->pn = Pos::names[bestTag[i]];
        }
        //std::wcout << std::endl;
        
    }


    void pp() {
        for (int i=0; i<49; i++) {
            std::wcout << typeFreq[i] << L" ";
        }
        std::wcout << "-----" <<  std::endl;
        for (int i=0; i<49; i++) {
            for (int j=0; j<49; j++) {
                std::wcout << transFreq[i][j] << L" ";
            }
            std::wcout << "-----" <<  std::endl;
        }
    }

private:
std::wstring s2ws(const std::string& str) {
    if (str.empty()) {
        return L"";
    }
    unsigned len = str.size() + 1;
    setlocale(LC_CTYPE, "en_US.UTF-8");
    wchar_t *p = new wchar_t[len];
    mbstowcs(p, str.c_str(), len);
    std::wstring w_str(p);
    delete [] p;
    return w_str;
}

private:
    int typeFreq[49];
    int transFreq[49][49];

};

//int main() {
//    Tagger tagger;
//
//    char fname[] = "../dic/TransProbility_u.txt";
//    tagger.loadModel(fname);
//    tagger.pp();
//
//    return 0;
//}
