#ifndef SIGN_H
#define SIGN_H

template <typename T> int sign(T val) {
    return (T(0) < val) - (val < T(0));
}

#endif // SIGN_H
