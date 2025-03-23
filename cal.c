#include "cal.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 基本运算
double add(double a, double b) 
{
    return a + b;
}

double subtract(double a, double b) 
{
    return a - b;
}

double multiply(double a, double b) 
{
    return a * b;
}

double divide(double a, double b) 
{
    if (b == 0) 
    {
        printf("除数不能为零！\n");
        return -1; // 返回特殊值表示错误
    }
    return a / b;
}

// 幂运算和阶乘
double power(double base, double exponent) 
{
    return pow(base, exponent);
}

double factorial(int n) 
{
    if (n < 0) 
    {
        printf("负数没有阶乘。\n");
        return -1; // 返回特殊值表示错误
    }
    double result = 1;
    for (int i = 1; i <= n; i++) 
    {
        result *= i;
    }
    return result;
}

// 平方根和绝对值
double sqrtCalc(double num) 
{
    if (num < 0) 
    {
        printf("负数没有实数平方根。\n");
        return -1; // 返回特殊值表示错误
    }
    return sqrt(num);
}

double absolute(double num) 
{
    return fabs(num);
}

// 对数
double logarithm(double num, double base) 
{
    if (num <= 0 || base <= 0 || base == 1) 
    {
        printf("无效的对数参数。\n");
        return -1; // 返回特殊值表示错误
    }
    return log(num) / log(base);
}

// 三角函数
double sine(double angle) 
{
    return sin(angle);
}

double cosine(double angle) 
{
    return cos(angle);
}

double tangent(double angle) 
{
    return tan(angle);
}

// 反三角函数
double arcsine(double value) 
{
    if (value < -1 || value > 1) 
    {
        printf("反正弦函数的输入必须在 [-1, 1] 范围内。\n");
        return -1; // 返回特殊值表示错误
    }
    return asin(value);
}

double arccosine(double value) 
{
    if (value < -1 || value > 1) 
    {
        printf("反余弦函数的输入必须在 [-1, 1] 范围内。\n");
        return -1; // 返回特殊值表示错误
    }
    return acos(value);
}

double arctangent(double value) 
{
    return atan(value);
}

// 比较和统计
double max(double a, double b) 
{
    return (a > b) ? a : b;
}

double min(double a, double b) 
{
    return (a < b) ? a : b;
}

double average(double a, double b) 
{
    return (a + b) / 2;
}

// 数论
int isPrime(int num) 
{
    if (num <= 1) 
    {
        return 0; // 不是素数
    }
    for (int i = 2; i <= sqrt(num); i++) 
    {
        if (num % i == 0) 
        {
            return 0; // 不是素数
        }
    }
    return 1; // 是素数
}

int fibonacci(int n) 
{
    if (n <= 0) 
    {
        printf("输入必须为正整数。\n");
        return -1; // 返回特殊值表示错误
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) 
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// 矩阵运算
double** matrixAdd(double** matrixA, double** matrixB, int rows, int cols) 
{
    double** result = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) 
    {
        result[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}

double** matrixSubtract(double** matrixA, double** matrixB, int rows, int cols) 
{
    double** result = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) 
    {
        result[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return result;
}

double** matrixMultiply(double** matrixA, double** matrixB, int rowsA, int colsA, int colsB) 
{
    double** result = (double**)malloc(rowsA * sizeof(double*));
    for (int i = 0; i < rowsA; i++) 
    {
        result[i] = (double*)malloc(colsB * sizeof(double));
        for (int j = 0; j < colsB; j++) 
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) 
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

double** matrixTranspose(double** matrix, int rows, int cols) 
{
    double** result = (double**)malloc(cols * sizeof(double*));
    for (int i = 0; i < cols; i++) 
    {
        result[i] = (double*)malloc(rows * sizeof(double));
        for (int j = 0; j < rows; j++) 
        {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}


void freeMatrix(double** matrix, int rows) 
{
    for (int i = 0; i < rows; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);
}

// 复数运算
Complex complexAdd(Complex a, Complex b) 
{
    return (Complex){a.real + b.real, a.imag + b.imag};
}

Complex complexSubtract(Complex a, Complex b) 
{
    return (Complex){a.real - b.real, a.imag - b.imag};
}

Complex complexMultiply(Complex a, Complex b) 
{
    return (Complex)
    {
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

Complex complexDivide(Complex a, Complex b) 
{
    double denominator = b.real * b.real + b.imag * b.imag;
    if (denominator == 0) 
    {
        printf("复数除法的分母不能为零。\n");
        return (Complex){-1, -1}; // 返回特殊值表示错误
    }
    return (Complex)
    {
        (a.real * b.real + a.imag * b.imag) / denominator,
        (a.imag * b.real - a.real * b.imag) / denominator
    };
}

double complexMagnitude(Complex c) 
{
    return sqrt(c.real * c.real + c.imag * c.imag);
}

double complexPhase(Complex c) 
{
    return atan2(c.imag, c.real);
}

// 多项式运算
Polynomial polynomialAdd(Polynomial a, Polynomial b) 
{
    int maxDegree = (a.degree > b.degree) ? a.degree : b.degree;
    Polynomial result = {maxDegree, (double*)malloc((maxDegree + 1) * sizeof(double))};
    for (int i = 0; i <= maxDegree; i++) 
    {
        result.coefficients[i] = (i <= a.degree ? a.coefficients[i] : 0) + (i <= b.degree ? b.coefficients[i] : 0);
    }
    return result;
}

Polynomial polynomialSubtract(Polynomial a, Polynomial b) 
{
    int maxDegree = (a.degree > b.degree) ? a.degree : b.degree;
    Polynomial result = {maxDegree, (double*)malloc((maxDegree + 1) * sizeof(double))};
    for (int i = 0; i <= maxDegree; i++) 
    {
        result.coefficients[i] = (i <= a.degree ? a.coefficients[i] : 0) - (i <= b.degree ? b.coefficients[i] : 0);
    }
    return result;
}

Polynomial polynomialMultiply(Polynomial a, Polynomial b) 
{
    int maxDegree = a.degree + b.degree;
    Polynomial result = {maxDegree, (double*)calloc(maxDegree + 1, sizeof(double))};
    for (int i = 0; i <= a.degree; i++) 
    {
        for (int j = 0; j <= b.degree; j++)
        {
            result.coefficients[i + j] += a.coefficients[i] * b.coefficients[j];
        }
    }
    return result;
}

double polynomialEvaluate(Polynomial p, double x) 
{
    double result = 0;
    for (int i = 0; i <= p.degree; i++) 
    {
        result += p.coefficients[i] * pow(x, i);
    }
    return result;
}

void freePolynomial(Polynomial p) 
{
    free(p.coefficients);
}



// 数值积分
double trapezoidalRule(double (*func)(double), double a, double b, int n) 
{
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));
    for (int i = 1; i < n; i++) 
    {
        sum += func(a + i * h);
    }
    return sum * h;
}

double simpsonsRule(double (*func)(double), double a, double b, int n) 
{
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    for (int i = 1; i < n; i++) 
    {
        sum += (i % 2 == 0 ? 2 : 4) * func(a + i * h);
    }
    return sum * h / 3;
}

// 数值微分
double forwardDifference(double (*func)(double), double x, double h) 
{
    return (func(x + h) - func(x)) / h;
}

double centralDifference(double (*func)(double), double x, double h) 
{
    return (func(x + h) - func(x - h)) / (2 * h);
}

// 优化算法
double goldenSectionSearch(double (*func)(double), double a, double b, double tol) 
{
    const double goldenRatio = (sqrt(5) - 1) / 2;
    double c = b - (b - a) * goldenRatio;
    double d = a + (b - a) * goldenRatio;
    while (fabs(b - a) > tol) 
    {
        if (func(c) < func(d)) 
        {
            b = d;
            d = c;
            c = b - (b - a) * goldenRatio;
        } else 
        {
            a = c;
            c = d;
            d = a + (b - a) * goldenRatio;
        }
    }
    return (a + b) / 2;
}

// 辅助函数：计算平方
double square(double x) 
{
    return x * x;
}

// 辅助函数：计算立方
double cube(double x) 
{
    return x * x * x;
}

// 辅助函数：计算四次方
double quartic(double x) 
{
    return x * x * x * x;
}

// 辅助函数：计算五次方
double quintic(double x) 
{
    return x * x * x * x * x;
}

// 辅助函数：计算六次方
double sextic(double x) 
{
    return x * x * x * x * x * x;
}

// 辅助函数：计算七次方
double septic(double x) 
{
    return x * x * x * x * x * x * x;
}

// 辅助函数：计算八次方
double octic(double x) 
{
    return x * x * x * x * x * x * x * x;
}

// 辅助函数：计算九次方
double nonic(double x) 
{
    return x * x * x * x * x * x * x * x * x;
}

// 辅助函数：计算十次方
double decic(double x) 
{
    return x * x * x * x * x * x * x * x * x * x;
}
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
// 字符串反转
void reverseString(char* str) 
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// 字符串大小写转换
void toUpperCase(char* str) 
{
    for (int i = 0; str[i]; i++) 
    {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char* str) 
{
    for (int i = 0; str[i]; i++) 
    {
        str[i] = tolower(str[i]);
    }
}

// 字符串查找
int findSubstring(const char* str, const char* substr) 
{
    return strstr(str, substr) != NULL;
}

// 字符串替换
void replaceSubstring(char* str, const char* old, const char* replacement) 
{
    char buffer[1024];
    char* insertPoint = &buffer[0];
    const char* tmp = str;
    size_t replacementLen = strlen(replacement);
    size_t oldLen = strlen(old);

    while (1) 
    {
        const char* p = strstr(tmp, old);
        if (p == NULL) 
        {
            strcpy(insertPoint, tmp);
            break;
        }
        memcpy(insertPoint, tmp, p - tmp);
        insertPoint += p - tmp;
        memcpy(insertPoint, replacement, replacementLen);
        insertPoint += replacementLen;
        tmp = p + oldLen;
    }
    strcpy(str, buffer);
}

// 计算字符串长度（不使用 strlen）
int customStrlen(const char* str) 
{
    int len = 0;
    while (str[len] != '\0') 
    {
        len++;
    }
    return len;
}

// 计算字符串中字符的频率
void charFrequency(const char* str, int* freq) 
{
    while (*str) 
    {
        freq[tolower(*str)]++;
        str++;
    }
}

// 数学计算
// 计算两个数的最大公约数
int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 计算两个数的最小公倍数
int lcm(int a, int b) 
{
    return (a / gcd(a, b)) * b;
}

// 计算斐波那契数列的第 n 项（优化版）
int fibonacciOptimized(int n) 
{
    if (n <= 0) 
    {
        printf("输入必须为正整数。\n");
        return -1;
    }
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) 
    {
        int temp = a;
        a = b;
        b = temp + b;
    }
    return b;
}

// 计算一个数的各位数字之和
int sumOfDigits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// 计算一个数的各位数字的乘积
int productOfDigits(int num) 
{
    int product = 1;
    while (num > 0) 
    {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

// 计算一个数的各位数字的平方和
int sumOfSquaresOfDigits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

// 计算一个数的各位数字的立方和
int sumOfCubesOfDigits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        int digit = num % 10;
        sum += digit * digit * digit;
        num /= 10;
    }
    return sum;
}

// 判断一个数是否为回文数
int isPalindrome(int num) 
{
    int reversed = 0, original = num;
    while (num > 0) 
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

// 计算一个数的阶乘（递归版）
int factorialRecursive(int n) 
{
    if (n < 0) 
    {
        printf("负数没有阶乘。\n");
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

// 计算一个数的阶乘（迭代版）
int factorialIterative(int n) 
{
    if (n < 0) 
    {
        printf("负数没有阶乘。\n");
        return -1;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) 
    {
        result *= i;
    }
    return result;
}

// 计算一个数的二进制表示
void toBinary(int num, char* binary) 
{
    int index = 0;
    while (num > 0) 
    {
        binary[index++] = (num % 2) + '0';
        num /= 2;
    }
    binary[index] = '\0';
    reverseString(binary);
}

// 计算一个数的十六进制表示
void toHexadecimal(int num, char* hex) 
{
    char hexDigits[] = "0123456789ABCDEF";
    int index = 0;
    while (num > 0) 
    {
        hex[index++] = hexDigits[num % 16];
        num /= 16;
    }
    hex[index] = '\0';
    reverseString(hex);
}

// 计算一个数的八进制表示
void toOctal(int num, char* octal) 
{
    int index = 0;
    while (num > 0) 
    {
        octal[index++] = (num % 8) + '0';
        num /= 8;
    }
    octal[index] = '\0';
    reverseString(octal);
}

// 计算一个数的各位数字的逆序数
int reverseDigits(int num) 
{
    int reversed = 0;
    while (num > 0) 
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

// 计算一个数的各位数字的逆序数（递归版）
int reverseDigitsRecursive(int num) 
{
    if (num < 10) 
    {
        return num;
    }
    return (num % 10) * pow(10, (int)log10(num)) + reverseDigitsRecursive(num / 10);
}

// 计算一个数的各位数字的逆序数（迭代版）
int reverseDigitsIterative(int num) 
{
    int reversed = 0;
    while (num > 0) 
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

// 计算一个数的各位数字的逆序数（字符串版）
int reverseDigitsString(int num) 
{
    char str[32];
    sprintf(str, "%d", num);
    reverseString(str);
    return atoi(str);
}

// 计算一个数的各位数字的逆序数（位运算版）
int reverseDigitsBitwise(int num) 
{
    int reversed = 0;
    while (num > 0) 
    {
        reversed = (reversed << 3) + (reversed << 1) + (num & 1);
        num >>= 1;
    }
    return reversed;
}

// 计算一个数的各位数字的逆序数（数学版）
int reverseDigitsMath(int num) 
{
    int reversed = 0;
    while (num > 0) 
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}
// 字符串操作
// 删除字符串中的特定字符
void removeCharFromString(char* str, char charToRemove) 
{
    int index = 0, k = 0;
    while (str[index] != '\0') 
    {
        if (str[index] != charToRemove) 
        {
            str[k++] = str[index];
        }
        index++;
    }
    str[k] = '\0';
}

// 字符串反转（递归版）
void reverseStringRecursive(char* str, int start, int end) 
{
    if (start >= end) 
    {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseStringRecursive(str, start + 1, end - 1);
}

// 字符串反转（调用递归版）
void reverseStringRecursiveWrapper(char* str) 
{
    int len = strlen(str);
    reverseStringRecursive(str, 0, len - 1);
}

// 字符串拼接
void concatenateStrings(char* destination, const char* source) 
{
    int destLen = strlen(destination);
    int sourceLen = strlen(source);
    for (int i = 0; i < sourceLen; i++) 
    {
        destination[destLen + i] = source[i];
    }
    destination[destLen + sourceLen] = '\0';
}

// 字符串比较（忽略大小写）
int strcmpIgnoreCase(const char* str1, const char* str2) 
{
    while (*str1 && *str2) 
    {
        if (tolower(*str1) != tolower(*str2)) 
        {
            return tolower(*str1) - tolower(*str2);
        }
        str1++;
        str2++;
    }
    return tolower(*str1) - tolower(*str2);
}
//字符串分割
void splitString(const char* str, char delimiter, char** tokens, int* tokenCount) 
{
    char* temp = strdup(str); // 创建一个可修改的副本
    *tokenCount = 0;

    char* token = strtok(temp, &delimiter);
    while (token != NULL) 
    {
        tokens[*tokenCount] = strdup(token); // 为每个 token 分配内存
        (*tokenCount)++;
        token = strtok(NULL, &delimiter);
    }

    free(temp); // 释放临时副本
}

// 数学和逻辑功能
// 计算一个数的各位数字的四次方和
int sumOfQuarticOfDigits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        int digit = num % 10;
        sum += digit * digit * digit * digit;
        num /= 10;
    }
    return sum;
}

// 计算一个数的各位数字的五次方和
int sumOfQuinticOfDigits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        int digit = num % 10;
        sum += digit * digit * digit * digit * digit;
        num /= 10;
    }
    return sum;
}

// 计算一个数的各位数字的六次方和
int sumOfSexticOfDigits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        int digit = num % 10;
        sum += digit * digit * digit * digit * digit * digit;
        num /= 10;
    }
    return sum;
}

// 计算一个数的各位数字的七次方和
int sumOfSepticOfDigits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        int digit = num % 10;
        sum += digit * digit * digit * digit * digit * digit * digit;
        num /= 10;
    }
    return sum;
}

// 计算一个数的各位数字的八次方和
int sumOfOcticOfDigits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        int digit = num % 10;
        sum += digit * digit * digit * digit * digit * digit * digit * digit;
        num /= 10;
    }
    return sum;
}

// 计算一个数的各位数字的九次方和
int sumOfNonicOfDigits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        int digit = num % 10;
        sum += digit * digit * digit * digit * digit * digit * digit * digit * digit;
        num /= 10;
    }
    return sum;
}

// 计算一个数的各位数字的十次方和
int sumOfDecicOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit * digit * digit * digit * digit * digit * digit * digit * digit;
        num /= 10;
    }
    return sum;
}

// 判断一个数是否为阿姆斯特朗数
int isArmstrongNumber(int num) {
    int original = num;
    int sum = 0;
    int digits = 0;
    while (original > 0) {
        digits++;
        original /= 10;
    }
    original = num;
    while (original > 0) {
        int digit = original % 10;
        sum += pow(digit, digits);
        original /= 10;
    }
    return num == sum;
}

// 计算一个数的各位数字的逆序数（通用版）
int reverseDigitsGeneral(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

// 判断一个数是否为完全数
int isPerfectNumber(int num) {
    if (num < 2) {
        return 0;
    }
    int sum = 1;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return sum == num;
}
// 判断一个数是否为梅森数
int isMersennePrime(int num) {
    if (num <= 1) {
        return 0;
    }
    int p = 0;
    while ((1 << p) - 1 < num) {
        p++;
    }
    if ((1 << p) - 1 != num) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
// 新增功能：删除字符串中的重复字符
void removeDuplicateChars(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] == str[j]) {
                for (int k = j; k < len - 1; k++) {
                    str[k] = str[k + 1];
                }
                len--;
                j--;
            }
        }
    }
}
// 新增功能：删除字符串中的空白字符
void removeWhitespace(char* str) {
    int index = 0, k = 0;
    while (str[index] != '\0') {
        if (!isspace(str[index])) {
            str[k++] = str[index];
        }
        index++;
    }
    str[k] = '\0';
}
// 新增功能：删除字符串中的非数字字符
void removeNonDigits(char* str) {
    int index = 0, k = 0;
    while (str[index] != '\0') {
        if (isdigit(str[index])) {
            str[k++] = str[index];
        }
        index++;
    }
    str[k] = '\0';
}
// 新增功能：删除字符串中的非字母字符
void removeNonLetters(char* str) {
    int index = 0, k = 0;
    while (str[index] != '\0') {
        if (isalpha(str[index])) {
            str[k++] = str[index];
        }
        index++;
    }
    str[k] = '\0';
}
// 新增功能：删除字符串中的特定字符集
void removeCharsFromSet(char* str, const char* charSet) {
    int index = 0, k = 0;
    while (str[index] != '\0') {
        if (strchr(charSet, str[index]) == NULL) {
            str[k++] = str[index];
        }
        index++;
    }
    str[k] = '\0';
}
// 新增功能：删除字符串中的特定字符集（忽略大小写）
void removeCharsFromSetIgnoreCase(char* str, const char* charSet) {
    int index = 0, k = 0;
    while (str[index] != '\0') {
        if (strchr(charSet, tolower(str[index])) == NULL) {
            str[k++] = str[index];
        }
        index++;
    }
    str[k] = '\0';
}


// 新增功能：计算两个数的最大公约数的所有因子
void gcdFactors(int a, int b, int* factors, int* count) {
    int gcdValue = gcd(a, b); // 使用已有的 gcd 函数
    *count = 0;
    for (int i = 1; i <= gcdValue; i++) {
        if (gcdValue % i == 0) {
            factors[(*count)++] = i;
        }
    }
}
// 新增功能：判断一个数是否为欧拉数
int isEulerNumber(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (gcd(i, num) == 1) {
            sum++;
        }
    }
    return sum == num / 2;
}

// 新增功能：判断一个数是否为费马素数
int isFermatPrime(int num) {
    if (num < 3 || num % 2 == 0) return 0;
    int n = 0;
    while ((1 << (1 << n)) <= num) {
        n++;
    }
    n--;
    return (1 << (1 << n)) == num;
}

// 新增功能：判断一个数是否为平方数
int isPerfectSquare(int num) {
    int root = (int)sqrt(num);
    return root * root == num;
}

// 新增功能：判断一个数是否为立方数
int isPerfectCube(int num) {
    int root = (int)round(cbrt(num));
    return root * root * root == num;
}

// 新增功能：判断一个数是否为完全平方数和完全立方数
int isPerfectSquareAndCube(int num) {
    return isPerfectSquare(num) && isPerfectCube(num);
}

// 计算圆的面积
double circleArea(double radius) {
    if (radius < 0) {
        printf("半径不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return M_PI * radius * radius;
}

// 计算圆的周长
double circleCircumference(double radius) {
    if (radius < 0) {
        printf("半径不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return 2 * M_PI * radius;
}

// 计算矩形的面积
double rectangleArea(double width, double height) {
    if (width < 0 || height < 0) {
        printf("矩形的宽和高不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return width * height;
}

// 计算矩形的周长
double rectanglePerimeter(double width, double height) {
    if (width < 0 || height < 0) {
        printf("矩形的宽和高不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return 2 * (width + height);
}

// 计算三角形的面积（已知三边）
double triangleArea(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        printf("无效的三角形边长。\n");
        return -1; // 返回特殊值表示错误
    }
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// 计算三角形的周长
double trianglePerimeter(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        printf("无效的三角形边长。\n");
        return -1; // 返回特殊值表示错误
    }
    return a + b + c;
}

// 计算球体的表面积
double sphereSurfaceArea(double radius) {
    if (radius < 0) {
        printf("半径不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return 4 * M_PI * radius * radius;
}

// 计算球体的体积
double sphereVolume(double radius) {
    if (radius < 0) {
        printf("半径不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return (4.0 / 3.0) * M_PI * radius * radius * radius;
}

// 计算圆柱的表面积
double cylinderSurfaceArea(double radius, double height) {
    if (radius < 0 || height < 0) {
        printf("半径和高不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return 2 * M_PI * radius * (radius + height);
}

// 计算圆柱的体积
double cylinderVolume(double radius, double height) {
    if (radius < 0 || height < 0) {
        printf("半径和高不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return M_PI * radius * radius * height;
}

// 计算圆锥的表面积
double coneSurfaceArea(double radius, double height) {
    if (radius < 0 || height < 0) {
        printf("半径和高不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    double slantHeight = sqrt(radius * radius + height * height);
    return M_PI * radius * (radius + slantHeight);
}

// 计算圆锥的体积
double coneVolume(double radius, double height) {
    if (radius < 0 || height < 0) {
        printf("半径和高不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return (1.0 / 3.0) * M_PI * radius * radius * height;
}

// 计算立方体的表面积
double cubeSurfaceArea(double side) {
    if (side < 0) {
        printf("边长不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return 6 * side * side;
}

// 计算立方体的体积
double cubeVolume(double side) {
    if (side < 0) {
        printf("边长不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return side * side * side;
}

// 计算长方体的表面积
double cuboidSurfaceArea(double length, double width, double height) {
    if (length < 0 || width < 0 || height < 0) {
        printf("长、宽、高不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return 2 * (length * width + length * height + width * height);
}

// 计算长方体的体积
double cuboidVolume(double length, double width, double height) {
    if (length < 0 || width < 0 || height < 0) {
        printf("长、宽、高不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return length * width * height;
}

// 计算梯形的面积
double trapezoidArea(double base1, double base2, double height) {
    if (base1 < 0 || base2 < 0 || height < 0) {
        printf("梯形的底和高不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return 0.5 * (base1 + base2) * height;
}

// 计算梯形的周长
double trapezoidPerimeter(double base1, double base2, double side1, double side2) {
    if (base1 < 0 || base2 < 0 || side1 < 0 || side2 < 0) {
        printf("梯形的边长不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return base1 + base2 + side1 + side2;
}

// 计算椭圆的面积（近似公式）
double ellipseArea(double a, double b) {
    if (a < 0 || b < 0) {
        printf("椭圆的半轴不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    return M_PI * a * b;
}

// 计算椭圆的周长（近似公式）
double ellipsePerimeter(double a, double b) {
    if (a < 0 || b < 0) {
        printf("椭圆的半轴不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    double h = ((a - b) * (a - b)) / ((a + b) * (a + b));
    return M_PI * (a + b) * (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));
}

// 计算正多边形的面积
double regularPolygonArea(int sides, double sideLength) {
    if (sides < 3) {
        printf("多边形的边数必须大于等于 3。\n");
        return -1; // 返回特殊值表示错误
    }
    if (sideLength <= 0) {
        printf("边长必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    return (sides * sideLength * sideLength) / (4 * tan(M_PI / sides));
}

// 计算正多边形的周长
double regularPolygonPerimeter(int sides, double sideLength) {
    if (sides < 3) {
        printf("多边形的边数必须大于等于 3。\n");
        return -1; // 返回特殊值表示错误
    }
    if (sideLength <= 0) {
        printf("边长必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    return sides * sideLength;
}

// 计算圆环的面积
double annulusArea(double outerRadius, double innerRadius) {
    if (outerRadius <= 0 || innerRadius <= 0 || outerRadius <= innerRadius) {
        printf("外半径必须大于内半径且两者都必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    return M_PI * (outerRadius * outerRadius - innerRadius * innerRadius);
}

// 计算圆环的周长（外圆周长 + 内圆周长）
double annulusPerimeter(double outerRadius, double innerRadius) {
    if (outerRadius <= 0 || innerRadius <= 0 || outerRadius <= innerRadius) {
        printf("外半径必须大于内半径且两者都必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    return 2 * M_PI * (outerRadius + innerRadius);
}

// 计算圆的扇形面积
double sectorArea(double radius, double angle) {
    if (radius < 0) {
        printf("半径不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    if (angle < 0 || angle > 360) {
        printf("角度必须在 0 到 360 度之间。\n");
        return -1; // 返回特殊值表示错误
    }
    return 0.5 * radius * radius * (angle * M_PI / 180);
}

// 计算圆的扇形周长
double sectorPerimeter(double radius, double angle) {
    if (radius < 0) {
        printf("半径不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    if (angle < 0 || angle > 360) {
        printf("角度必须在 0 到 360 度之间。\n");
        return -1; // 返回特殊值表示错误
    }
    return 2 * radius + (angle * M_PI / 180) * radius;
}

// 计算圆的弓形面积
double segmentArea(double radius, double angle) {
    if (radius < 0) {
        printf("半径不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    if (angle <= 0 || angle >= 360) {
        printf("角度必须在 0 到 360 度之间且不能为 0 或 360。\n");
        return -1; // 返回特殊值表示错误
    }
    double area = sectorArea(radius, angle) - 0.5 * radius * radius * sin(angle * M_PI / 180);
    return area;
}

// 计算圆的弓形周长
double segmentPerimeter(double radius, double angle) {
    if (radius < 0) {
        printf("半径不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    if (angle <= 0 || angle >= 360) {
        printf("角度必须在 0 到 360 度之间且不能为 0 或 360。\n");
        return -1; // 返回特殊值表示错误
    }
    double chordLength = 2 * radius * sin(angle * M_PI / 360);
    double arcLength = (angle * M_PI / 180) * radius;
    return chordLength + arcLength;
}

// 计算圆的弦长
double chordLength(double radius, double angle) {
    if (radius < 0) {
        printf("半径不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    if (angle <= 0 || angle >= 360) {
        printf("角度必须在 0 到 360 度之间且不能为 0 或 360。\n");
        return -1; // 返回特殊值表示错误
    }
    return 2 * radius * sin(angle * M_PI / 360);
}

// 计算圆的弧长
double arcLength(double radius, double angle) {
    if (radius < 0) {
        printf("半径不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    if (angle <= 0 || angle >= 360) {
        printf("角度必须在 0 到 360 度之间且不能为 0 或 360。\n");
        return -1; // 返回特殊值表示错误
    }
    return (angle * M_PI / 180) * radius;
}

// 计算圆的切线长度（从圆外一点到切点）
double tangentLength(double radius, double distance) {
    if (radius < 0 || distance < 0) {
        printf("半径和距离不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    if (distance <= radius) {
        printf("距离必须大于半径。\n");
        return -1; // 返回特殊值表示错误
    }
    return sqrt(distance * distance - radius * radius);
}

// 计算圆的割线长度（从圆外一点到割点）
double secantLength(double radius, double distance) {
    if (radius < 0 || distance < 0) {
        printf("半径和距离不能为负数。\n");
        return -1; // 返回特殊值表示错误
    }
    if (distance <= radius) {
        printf("距离必须大于半径。\n");
        return -1; // 返回特殊值表示错误
    }
    return distance + sqrt(distance * distance - radius * radius);
}

// 计算圆的外切正多边形的边长
double circumscribedPolygonSideLength(double radius, int sides) {
    if (sides < 3) {
        printf("多边形的边数必须大于等于 3。\n");
        return -1; // 返回特殊值表示错误
    }
    if (radius <= 0) {
        printf("半径必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    return 2 * radius * tan(M_PI / sides);
}

// 计算圆的内接正多边形的边长
double inscribedPolygonSideLength(double radius, int sides) {
    if (sides < 3) {
        printf("多边形的边数必须大于等于 3。\n");
        return -1; // 返回特殊值表示错误
    }
    if (radius <= 0) {
        printf("半径必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    return 2 * radius * sin(M_PI / sides);
}

// 计算圆的外切正多边形的面积
double circumscribedPolygonArea(double radius, int sides) {
    if (sides < 3) {
        printf("多边形的边数必须大于等于 3。\n");
        return -1; // 返回特殊值表示错误
    }
    if (radius <= 0) {
        printf("半径必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    double sideLength = circumscribedPolygonSideLength(radius, sides);
    return 0.5 * sides * sideLength * radius;
}

// 计算圆的内接正多边形的面积
double inscribedPolygonArea(double radius, int sides) {
    if (sides < 3) {
        printf("多边形的边数必须大于等于 3。\n");
        return -1; // 返回特殊值表示错误
    }
    if (radius <= 0) {
        printf("半径必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    double sideLength = inscribedPolygonSideLength(radius, sides);
    return 0.5 * sides * sideLength * radius;
}

// 计算圆的外切正多边形的周长
double circumscribedPolygonPerimeter(double radius, int sides) {
    if (sides < 3) {
        printf("多边形的边数必须大于等于 3。\n");
        return -1; // 返回特殊值表示错误
    }
    if (radius <= 0) {
        printf("半径必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    double sideLength = circumscribedPolygonSideLength(radius, sides);
    return sides * sideLength;
}

// 计算圆的内接正多边形的周长
double inscribedPolygonPerimeter(double radius, int sides) {
    if (sides < 3) {
        printf("多边形的边数必须大于等于 3。\n");
        return -1; // 返回特殊值表示错误
    }
    if (radius <= 0) {
        printf("半径必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    double sideLength = inscribedPolygonSideLength(radius, sides);
    return sides * sideLength;
}

// 计算圆的外切正多边形的边数
int circumscribedPolygonSides(double radius, double sideLength) {
    if (radius <= 0 || sideLength <= 0) {
        printf("半径和边长必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    int sides = (int)(M_PI / asin(sideLength / (2 * radius)));
    return sides;
}

// 计算圆的内接正多边形的边数
int inscribedPolygonSides(double radius, double sideLength) {
    if (radius <= 0 || sideLength <= 0) {
        printf("半径和边长必须为正数。\n");
        return -1; // 返回特殊值表示错误
    }
    int sides = (int)(M_PI / asin(sideLength / (2 * radius)));
    return sides;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 计算均值
double mean(const double* data, int size) {
    if (size <= 0) {
        printf("数据集大小必须大于0。\n");
        return -1; // 返回特殊值表示错误
    }
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}
// 计算方差
double variance(const double* data, int size) {
    if (size <= 0) {
        printf("数据集大小必须大于0。\n");
        return -1; // 返回特殊值表示错误
    }
    double meanValue = mean(data, size);
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += (data[i] - meanValue) * (data[i] - meanValue);
    }
    return sum / size;
}
// 计算标准差
double standardDeviation(const double* data, int size) {
    return sqrt(variance(data, size));
}
// 计算相关系数
double correlationCoefficient(const double* x, const double* y, int size) {
    if (size <= 0) {
        printf("数据集大小必须大于0。\n");
        return -1; // 返回特殊值表示错误
    }
    double meanX = mean(x, size);
    double meanY = mean(y, size);
    double sumXY = 0.0, sumX = 0.0, sumY = 0.0;
    for (int i = 0; i < size; i++) {
        sumXY += (x[i] - meanX) * (y[i] - meanY);
        sumX += (x[i] - meanX) * (x[i] - meanX);
        sumY += (y[i] - meanY) * (y[i] - meanY);
    }
    return sumXY / sqrt(sumX * sumY);
}
// 计算协方差
double covariance(const double* x, const double* y, int size) {
    if (size <= 0) {
        printf("数据集大小必须大于0。\n");
        return -1; // 返回特殊值表示错误
    }
    double meanX = mean(x, size);
    double meanY = mean(y, size);
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += (x[i] - meanX) * (y[i] - meanY);
    }
    return sum / size;
}
// 比较函数，用于qsort
int compareDouble(const void* a, const void* b) {
    double da = *(const double*)a;
    double db = *(const double*)b;
    return (da > db) - (da < db);
}

// 计算中位数
double median(double* data, int size) {
    if (size <= 0) {
        printf("数据集大小必须大于0。\n");
        return -1; // 返回特殊值表示错误
    }
    qsort(data, size, sizeof(double), compareDouble);
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    } else {
        return data[size / 2];
    }
}

// 计算众数
double mode(const double* data, int size) {
    if (size <= 0) {
        printf("数据集大小必须大于0。\n");
        return -1; // 返回特殊值表示错误
    }
    int maxCount = 0;
    double modeValue = data[0];
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (data[i] == data[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            modeValue = data[i];
        }
    }
    return modeValue;
}
// 计算偏度
double skewness(const double* data, int size) {
    if (size <= 0) {
        printf("数据集大小必须大于0。\n");
        return -1; // 返回特殊值表示错误
    }
    double meanValue = mean(data, size);
    double stdDev = standardDeviation(data, size);
    if (stdDev == 0) {
        printf("标准差不能为0。\n");
        return -1; // 返回特殊值表示错误
    }
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow((data[i] - meanValue) / stdDev, 3);
    }
    return sum / size;
}
// 计算峰度
double kurtosis(const double* data, int size) {
    if (size <= 0) {
        printf("数据集大小必须大于0。\n");
        return -1; // 返回特殊值表示错误
    }
    double meanValue = mean(data, size);
    double stdDev = standardDeviation(data, size);
    if (stdDev == 0) {
        printf("标准差不能为0。\n");
        return -1; // 返回特殊值表示错误
    }
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow((data[i] - meanValue) / stdDev, 4);
    }
    return (sum / size) - 3.0;
}
// 正态分布的累积分布函数（CDF）
double normalCDF(double x, double mean, double stddev) {
    return 0.5 * (1.0 + erf((x - mean) / (stddev * sqrt(2.0))));
}
// 正态分布的概率密度函数（PDF）
double normalPDF(double x, double mean, double stddev) {
    return (1.0 / (stddev * sqrt(2.0 * M_PI))) * exp(-0.5 * pow((x - mean) / stddev, 2));
}
// 二项式系数
double binomialCoefficient(int n, int k) {
    if (k > n - k) {
        k = n - k;
    }
    double result = 1.0;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

// 二项分布的概率质量函数（PMF）
double binomialPMF(int k, int n, double p) {
    return binomialCoefficient(n, k) * pow(p, k) * pow(1 - p, n - k);
}
// 泊松分布的概率质量函数（PMF）
double poissonPMF(int k, double lambda) {
    return exp(-lambda) * pow(lambda, k) / factorial(k);
}
// 计算样本的偏度
double sampleSkewness(const double* data, int size) {
    double meanValue = mean(data, size);
    double stdDev = standardDeviation(data, size);
    if (stdDev == 0) {
        printf("标准差不能为0。\n");
        return -1; // 返回特殊值表示错误
    }
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow((data[i] - meanValue) / stdDev, 3);
    }
    return sum / size;
}

// 计算样本的峰度
double sampleKurtosis(const double* data, int size) {
    double meanValue = mean(data, size);
    double stdDev = standardDeviation(data, size);
    if (stdDev == 0) {
        printf("标准差不能为0。\n");
        return -1; // 返回特殊值表示错误
    }
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow((data[i] - meanValue) / stdDev, 4);
    }
    return (sum / size) - 3.0;
}
// 计算样本的四分位数
double quantile(double* data, int size, double q) {
    if (size <= 0 || q < 0.0 || q > 1.0) {
        printf("数据集大小必须大于0，且q必须在[0, 1]范围内。\n");
        return -1; // 返回特殊值表示错误
    }
    qsort(data, size, sizeof(double), compareDouble);
    int index = (int)(q * (size - 1));
    return data[index];
}

// 计算样本的第一四分位数（Q1）
double firstQuartile(double* data, int size) {
    return quantile(data, size, 0.25);
}

// 计算样本的第三四分位数（Q3）
double thirdQuartile(double* data, int size) {
    return quantile(data, size, 0.75);
}
// 计算样本的四分位距（IQR）
double interquartileRange(double* data, int size) {
    double q1 = firstQuartile(data, size);
    double q3 = thirdQuartile(data, size);
    return q3 - q1;
}
// 计算样本的异常值检测
void detectOutliers(double* data, int size, double* outliers, int* outlierCount) {
    double q1 = firstQuartile(data, size);
    double q3 = thirdQuartile(data, size);
    double iqr = q3 - q1;
    double lowerBound = q1 - 1.5 * iqr;
    double upperBound = q3 + 1.5 * iqr;
    *outlierCount = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] < lowerBound || data[i] > upperBound) {
            outliers[(*outlierCount)++] = data[i];
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
// KMP算法：计算部分匹配表
void computeLPSArray(const char* pattern, int M, int* lps) {
    int len = 0; // lps的长度
    lps[0] = 0; // lps[0]总是0
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } 
        else 
        {
            if (len != 0) 
            {
                len = lps[len - 1];
            } 
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP算法：字符串匹配
int KMP(const char* text, const char* pattern) {
    int M = strlen(pattern);
    int N = strlen(text);
    int* lps = (int*)malloc(M * sizeof(int));
    computeLPSArray(pattern, M, lps);
    int i = 0; // 文本索引
    int j = 0; // 模式索引
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == M) {
            free(lps);
            return i - j; // 找到匹配
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) 
            {
                j = lps[j - 1];
            } 
            else 
            {
                i++;
            }
        }
    }
    free(lps);
    return -1; // 未找到匹配
}
#define d 256 // 字符集大小
// Rabin-Karp算法：字符串匹配
int RabinKarp(const char* text, const char* pattern) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0; // 模式串的哈希值
    int t = 0; // 文本串的哈希值
    int h = 1;
    int prime = 101; // 一个质数

    // 计算 h = d^(M-1) % prime
    for (i = 0; i < M - 1; i++) {
        h = (h * d) % prime;
    }

    // 计算模式串和文本串前M个字符的哈希值
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % prime;
        t = (d * t + text[i]) % prime;
    }

    // 滑动文本串
    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j]) 
                {
                    break;
                }
            }
            if (j == M) 
            {
                return i; // 找到匹配
            }
        }
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % prime;
            if (t < 0) 
            {
                t = t + prime;
            }
        }
    }
    return -1; // 未找到匹配
}

// 简单的正则表达式匹配：支持 '.' 和 '*'
int isMatch(const char* s, const char* p) {
    if (*p == '\0') {
        return *s == '\0';
    }
    int first_match = *s != '\0' && (*s == *p || *p == '.');
    if (*(p + 1) == '*') {
        return isMatch(s, p + 2) || (first_match && isMatch(s + 1, p));
    } else {
        return first_match && isMatch(s + 1, p + 1);
    }
}
// 计算字符串编辑距离（Levenshtein距离）
int editDistance(const char* str1, const char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j; // 删除所有字符
            } else if (j == 0) {
                dp[i][j] = i; // 插入所有字符
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // 无操作
            } else {
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                // 删除、插入、替换
            }
        }
    }
    return dp[m][n];
}







