#include <iostream>

void fTask1(double* pMass, int iXSize, int iYSize);
void fTask2(unsigned int* pMass2, int iSize);
void fTask3(int* pMass3);
void fTask4(int* pMass4, int iShift, int iMSize);
bool fTask5(int* pMass5, int iMSize);

int main()
{
    //Task #1
    const int iX = 4, iY = 4;
    double dMass[iX][iY] = { 1.1, 1.2, 1.3, 1.4, 2.1, 2.2, 2.3, 2.4 , 3.1, 3.2, 3.3, 3.4, 4.1, 4.2, 4.3 ,4.4 };
    std::cout << "Task #1:" << std::endl;
    fTask1(&dMass[0][0], iX, iY);

    //Task #2
    unsigned int iMass2[7] = { 1, 0, 0, 0, 1, 1, 0 };
    std::cout << std::endl << "Task #2:" << std::endl;
    fTask2(iMass2, 7);

    //Task #3
    int iMass3[8];
    std::cout << std::endl << "Task #3:" << std::endl;
    fTask3(iMass3);
    for (int i = 0; i < 8; i++) {
        std::cout << iMass3[i] << " ";
    }
    std::cout << std::endl << std::endl;

    //Task #4
    int iMass4[7] = { 1, 2, 3, 4, 5, 6, 7 };
    int iShift;
    std::cout << "Task #4:" << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << iMass4[i] << " ";
    }
    std::cout << std::endl << "Please enter number: " << std::endl;
    std::cin >> iShift;
    fTask4(iMass4, iShift, 7);
    std::cout << std::endl;

    //Task #5
    std::cout << std::endl << "Task #5:" << std::endl;
    int iMass5[5] = { 1, 3, 4, 2, 6 };
    if (fTask5(iMass5, 5)) std::cout << "True";
    else std::cout << "False";
}

void fTask1(double* pMass, int iXSize, int iYSize) {
    for (int i = 0; i < iXSize; i++) {
        for (int j = 0; j < iYSize; j++) {
            std::cout << pMass[j + iYSize * i] << ' ';
        }
        std::cout << std::endl;
    }
}

void fTask2(unsigned int* pMass2, int iSize) {
    for (int i = 0; i < iSize; i++) {
        std::cout << pMass2[i] << ' ';

    }
    std::cout << std::endl;
    for (int i = 0; i < iSize; i++) {

        std::cout << (pMass2[i] ^= (1 << 0)) << ' ';
    }
    std::cout << std::endl;
}

void fTask3(int* pMass3) {
    for (int i = 0; i < 8; i++) {
        pMass3[i] = 1 + i * 3;
    }
}

void fTask4(int* pMass4, int iShift, int iMSize) {
    int iCopy, iNext;
    iShift = iShift % iMSize;
    int j = 0;
    for (int i = 0; j < iMSize; ) {
        if (i == 0) iCopy = pMass4[0];
        iNext = (i - iShift + iMSize) % iMSize;
        pMass4[i] = pMass4[iNext];
        i = iNext;
        j++;
    }
    if (iShift > 0) pMass4[iShift] = iCopy;
    else pMass4[iMSize + iShift] = iCopy;

    for (int i = 0; i < iMSize; i++) {
        std::cout << pMass4[i] << ' ';
    }
}

bool fTask5(int* pMass5, int iMSize) {
    int iSum1 = 0, iSum2 = 0;
    for (int j = 0; j < iMSize - 1; j++) {
        for (int i = 0; i <= j; i++) iSum1 += pMass5[i];
        for (int i = j + 1; i < iMSize; i++) iSum2 += pMass5[i];
        std::cout << iSum1 << ' ' << iSum2 << std::endl;
        if (iSum1 == iSum2) return (true);
        iSum1 = iSum2 = 0;
    }
    return (false);
}
