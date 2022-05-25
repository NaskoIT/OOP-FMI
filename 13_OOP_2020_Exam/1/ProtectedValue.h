#ifndef EXAM_2020_PROTECTEDVALUE_H
#define EXAM_2020_PROTECTEDVALUE_H

#include <stdexcept>

using namespace std;

template<typename T>
class ProtectedValue {
private:
    T value;
    unsigned int code;

public:
    ProtectedValue(const T &initValue = T(), const unsigned int code = 0) : value(initValue), code(code) {}

    T getValue(int userCode) {
        if (code != userCode) {
            throw invalid_argument("The code is invalid! Please, pass valid code to get the value.");
        }

        return value;
    }
};

#endif //EXAM_2020_PROTECTEDVALUE_H
