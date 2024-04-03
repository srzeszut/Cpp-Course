#ifndef MYSORTING_H
#define MYSORTING_H
#define FORMAT_SPEC "%s"
#include "string.h"

#include "myList.h"
template<typename T>
void mySort(MyList<T> &list) {
    if (list.size() <= 2)
        return;
    for (auto i = list.begin(); i != list.end(); i++) {
        for (auto j = i; j != list.end(); j++) {
            if (*j < *i) {
                std::swap(*i, *j);
            }
        }
    }
}

template<size_t N, typename S>
void mySort(S (&array)[N]) {
    std::sort(array, array + N);
}
template<typename T>
void mySort(T& container)
{
    std::sort(container.begin(), container.end());
}

template <size_t M, size_t N>
void mySort(char (&arr)[M][N]) {
    for(size_t i=0;i<M;i++){
        for(size_t j=0;j<M-1;j++){
            char tmp1[N],tmp2[N];
            for (size_t k = 0; k < N && arr[j][k] != '\0'; k++) {
                tmp1[k] = toupper(arr[j][k]);
            }
            tmp1[N] = '\0';

            for (size_t k = 0; k < N && arr[j+1][k] != '\0'; k++) {
                tmp2[k] = toupper(arr[j+1][k]);
            }
            tmp2[N] = '\0';
            if(strcmp(tmp1,tmp2)>0){
                std::swap(arr[j],arr[j+1]);
            }
        }

    }

}





#endif // MYSORTING_H