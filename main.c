#include <ctype.h>
#include <stdio.h>
#include <string.h>

void cleanInput() {
    while (getchar() != '\n')
        ;
}

void inputStr(char* str, char customMessage[]) {
    if (customMessage) {
        printf("%s", customMessage);

    } else {
        printf("Mời nhập chuỗi: ");
    }

    scanf(" %[^\n]", str);
};

void inputIntNumber(int* inputAddress, char message[]) {
reInput:
    printf("%s: ", message);
    if (!scanf(" %d", inputAddress)) {
        cleanInput();
        goto reInput;
    } else {
        cleanInput();
    }
}

void inputFloatNumber(float* inputAddress, char message[]) {
reInput:
    printf("%s: ", message);
    if (!scanf(" %f", inputAddress)) {
        cleanInput();
        goto reInput;
    };
}

void bai1() {
    int len, i, iRevert = 0, j;
    float maxNumber;

    inputIntNumber(&len, "Nhập độ dài cuả mảng:");
    float numberArr[len];
    float numberArrRevert[len];

    for (i = 0; i < len; i++) {
        inputFloatNumber(&numberArr[i], " ");
    }

    for (j = len - 1; j >= 0; j--) {
        numberArrRevert[iRevert] = numberArr[j];
        iRevert++;
    }

    for (int a = 0; a < len; a++) {
        printf("%g \n", numberArrRevert[a]);
    }

    int iMax;

    maxNumber = numberArr[0];
    for (iMax = 1; iMax < len; iMax++) {
        if (numberArr[iMax] > maxNumber) {
            maxNumber = numberArr[iMax];
        }
    }

    printf("Số lớn nhất là: %g\n", maxNumber);
};
void bai2() {
    int len, smallLen, i, iSort, jSort, iPrint, iCalc;
    float total;

    inputIntNumber(&len, "Nhập độ dài cuả mảng:");
    float numberArr[len];
    smallLen = len / 2;

    for (i = 0; i < len; i++) {
        inputFloatNumber(&numberArr[i], " ");
    }

    for (iSort = 0; iSort < len; iSort++) {

        for (jSort = iSort; jSort < len; jSort++) {
            if (numberArr[jSort] > numberArr[iSort]) {
                float temp = numberArr[iSort];

                numberArr[iSort] = numberArr[jSort];
                numberArr[jSort] = temp;
            }
        }
    }

    for (iCalc = 0; iCalc <= smallLen; iCalc++) {
        total += numberArr[iCalc];
    }

    for (iPrint = 0; iPrint < len; iPrint++) {
        printf("%g \n", numberArr[iPrint]);
    }

    printf("Tổng nửa mảng là: %g \n", total);
};

void bai3() {
    int len, i, j, iPrint, n = 0, p = 0;
    char nguyenAm[5] = {'a', 'e', 'i', 'o', 'u'};

    inputIntNumber(&len, "Nhập độ dài cuả mảng:");
    char charArr[len];

    for (i = 0; i < len; i++) {
        printf("Nhập ký tự: ");
        scanf(" %c", &charArr[i]);
    }

    for (iPrint = 0; iPrint < len; iPrint++) {
        printf("%c \n", charArr[iPrint]);
    }

    for (j = 0; j < len; j++) {
        int tempN = n, iN;
        char currentChar = tolower(charArr[j]);

        if (isalpha(currentChar)) {
            for (iN = 0; iN < sizeof(nguyenAm); iN++) {
                if (currentChar == nguyenAm[iN]) {
                    n++;
                    break;
                }
            }
            if (tempN == n) {
                p++;
            }
        }
    }

    printf("Số nguyên âm là: %d\n", n);
    printf("Số phụ âm là: %d\n", p);
};

void bai4() {
    int len, i;
    char userName[32];
    char password[32];

    inputIntNumber(&len, "Nhập số lượng user muốn thêm:");
    char charArr[2][len];

    for (i = 0; i < len; i++) {
        char tempUserName[32];
        char tempPassword[32];

        inputStr(&tempUserName, "Nhập tên tài khoản: ");
        inputStr(&tempPassword, "Nhập password: ");

        strcpy(charArr[0][i], tempUserName);
        strcpy(charArr[1][i], tempPassword);
    }

    for (int iPrint = 0; iPrint < len; iPrint++) {
        printf("%s \n", charArr[0][i]);
        printf("%s \n", charArr[1][i]);
    }
}

int main() {
    int input;

    printf("Chọn chương trình!\n");
    printf("[1] Bài 1\n");
    printf("[2] Bài 2\n");
    printf("[3] Bài 3\n");
    printf("[4] Bài 4\n");
    printf("[5] Thoát\n");

reInput:
    printf("Nhập số bài muốn chọn\n");

    if (scanf("%d", &input) && input <= 4 && input > 0) {
    } else {
        cleanInput();
        goto reInput;
    }

    switch (input) {
    case 1: {
        bai1();
        break;
    }
    case 2: {
        bai2();
        break;
    }
    case 3: {
        bai3();
        break;
    }
    case 4: {
        bai4();
        break;
    }
    case 5: {
        return 0;
        break;
    }
    default:
    }
    return 0;
};