#ifndef CALCULATOR_H
#define CALCULATOR_H

#ifdef __cplusplus
extern "C" {
#endif

    // ��������
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    // ������ͽ׳�
    double power(double base, double exponent);
    double factorial(int n);

    // ƽ�����;���ֵ
    double sqrtCalc(double num);
    double absolute(double num);

    // ����
    double logarithm(double num, double base);

    // ���Ǻ���
    double sine(double angle);
    double cosine(double angle);
    double tangent(double angle);

    // �����Ǻ���
    double arcsine(double value);
    double arccosine(double value);
    double arctangent(double value);

    // �ȽϺ�ͳ��
    double max(double a, double b);
    double min(double a, double b);
    double average(double a, double b);

    // ����
    int isPrime(int num);
    int fibonacci(int n);

    // ��������
    double** matrixAdd(double** matrixA, double** matrixB, int rows, int cols);
    double** matrixSubtract(double** matrixA, double** matrixB, int rows, int cols);
    double** matrixMultiply(double** matrixA, double** matrixB, int rowsA, int colsA, int colsB);
    double** matrixTranspose(double** matrix, int rows, int cols);
    void freeMatrix(double** matrix, int rows);

    // ��������
    typedef struct {
        double real;
        double imag;
    } Complex;

    Complex complexAdd(Complex a, Complex b);
    Complex complexSubtract(Complex a, Complex b);
    Complex complexMultiply(Complex a, Complex b);
    Complex complexDivide(Complex a, Complex b);
    double complexMagnitude(Complex c);
    double complexPhase(Complex c);

    // ����ʽ����
    typedef struct {
        int degree;
        double* coefficients;
    } Polynomial;

    Polynomial polynomialAdd(Polynomial a, Polynomial b);
    Polynomial polynomialSubtract(Polynomial a, Polynomial b);
    Polynomial polynomialMultiply(Polynomial a, Polynomial b);
    double polynomialEvaluate(Polynomial p, double x);
    void freePolynomial(Polynomial p);

    // ���Դ���
    double** matrixInverse(double** matrix, int size);
    double** matrixDeterminant(double** matrix, int size);

    // ��ֵ����
    double trapezoidalRule(double (*func)(double), double a, double b, int n);
    double simpsonsRule(double (*func)(double), double a, double b, int n);

    // ��ֵ΢��
    double forwardDifference(double (*func)(double), double x, double h);
    double centralDifference(double (*func)(double), double x, double h);

    // �Ż��㷨
    double goldenSectionSearch(double (*func)(double), double a, double b, double tol);

    // ��������������ƽ��
    double square(double x);
    double cube(double x);
    double quartic(double x);
    double quintic(double x);
    double sextic(double x);
    double septic(double x);
    double octic(double x);
    double nonic(double x);
    double decic(double x);

    // �ַ�������
    void reverseString(char* str);
    void toUpperCase(char* str);
    void toLowerCase(char* str);
    int findSubstring(const char* str, const char* substr);
    void replaceSubstring(char* str, const char* old, const char* replacement);
    int customStrlen(const char* str);
    void charFrequency(const char* str, int* freq);
    void removeCharFromString(char* str, char charToRemove);
    void reverseStringRecursiveWrapper(char* str);
    void concatenateStrings(char* destination, const char* source);
    int strcmpIgnoreCase(const char* str1, const char* str2);
    void splitString(const char* str, char delimiter, char** tokens, int* tokenCount);

    // ��ѧ���߼�����
    int gcd(int a, int b);
    int lcm(int a, int b);
    int fibonacciOptimized(int n);
    int sumOfDigits(int num);
    int productOfDigits(int num);
    int sumOfSquaresOfDigits(int num);
    int sumOfCubesOfDigits(int num);
    int isPalindrome(int num);
    int factorialRecursive(int n);
    int factorialIterative(int n);
    void toBinary(int num, char* binary);
    void toHexadecimal(int num, char* hex);
    void toOctal(int num, char* octal);
    int reverseDigits(int num);
    int reverseDigitsRecursive(int num);
    int reverseDigitsIterative(int num);
    int reverseDigitsString(int num);
    int reverseDigitsBitwise(int num);
    int reverseDigitsMath(int num);
    int reverseDigitsGeneral(int num);
    int reverseDigitsWithNegative(int num);
    double reverseDigitsFloat(double num);
    double reverseDigitsFloatRecursive(double num);
    double reverseDigitsFloatIterative(double num);
    double reverseDigitsFloatString(double num);
    double reverseDigitsFloatBitwise(double num);
    double reverseDigitsFloatMath(double num);
    double reverseDigitsFloatGeneral(double num);
    int sumOfQuarticOfDigits(int num);
    int sumOfQuinticOfDigits(int num);
    int sumOfSexticOfDigits(int num);
    int sumOfSepticOfDigits(int num);
    int sumOfOcticOfDigits(int num);
    int sumOfNonicOfDigits(int num);
    int sumOfDecicOfDigits(int num);
    int isArmstrongNumber(int num);
    int isPerfectNumber(int num);
    int isMersennePrime(int num);
    void removeDuplicateChars(char* str);
    void removeWhitespace(char* str);
    void removeNonDigits(char* str);
    void removeNonLetters(char* str);
    void removeCharsFromSet(char* str, const char* charSet);
    void removeCharsFromSetIgnoreCase(char* str, const char* charSet);
    // �����������ж�һ�����Ƿ�Ϊ��˹����
    int isGaussianPrime(int real, int imag);

    // �������������������������Լ������������
    void gcdFactors(int a, int b, int* factors, int* count);

    // �����������ж�һ�����Ƿ�Ϊŷ����
    int isEulerNumber(int num);

    // �����������ж�һ�����Ƿ�Ϊ��������
    int isFermatPrime(int num);

    // �����������ж�һ�����Ƿ�Ϊƽ����
    int isPerfectSquare(int num);

    // �����������ж�һ�����Ƿ�Ϊ������
    int isPerfectCube(int num);

    // �����������ж�һ�����Ƿ�Ϊ��ȫƽ��������ȫ������
    int isPerfectSquareAndCube(int num);

    // ������ѧ����
    double circleArea(double radius);
    double circleCircumference(double radius);
    double rectangleArea(double width, double height);
    double rectanglePerimeter(double width, double height);
    double triangleArea(double a, double b, double c);
    double trianglePerimeter(double a, double b, double c);
    double sphereSurfaceArea(double radius);
    double sphereVolume(double radius);
    double cylinderSurfaceArea(double radius, double height);
    double cylinderVolume(double radius, double height);
    double coneSurfaceArea(double radius, double height);
    double coneVolume(double radius, double height);
    double cubeSurfaceArea(double side);
    double cubeVolume(double side);
    double cuboidSurfaceArea(double length, double width, double height);
    double cuboidVolume(double length, double width, double height);
    double trapezoidArea(double base1, double base2, double height);
    double trapezoidPerimeter(double base1, double base2, double side1, double side2);
    double ellipseArea(double a, double b);
    double ellipsePerimeter(double a, double b);
    double regularPolygonArea(int sides, double sideLength);
    double regularPolygonPerimeter(int sides, double sideLength);
    double annulusArea(double outerRadius, double innerRadius);
    double annulusPerimeter(double outerRadius, double innerRadius);
    double sectorArea(double radius, double angle);
    double sectorPerimeter(double radius, double angle);
    double segmentArea(double radius, double angle);
    double segmentPerimeter(double radius, double angle);
    double chordLength(double radius, double angle);
    double arcLength(double radius, double angle);
    double tangentLength(double radius, double distance);
    double secantLength(double radius, double distance);
    double circumscribedPolygonSideLength(double radius, int sides);
    double inscribedPolygonSideLength(double radius, int sides);
    double circumscribedPolygonArea(double radius, int sides);
    double inscribedPolygonArea(double radius, int sides);
    double circumscribedPolygonPerimeter(double radius, int sides);
    double inscribedPolygonPerimeter(double radius, int sides);
    int circumscribedPolygonSides(double radius, double sideLength);
    int inscribedPolygonSides(double radius, double sideLength);
    // �ȽϺ���������qsort
    int compareDouble(const void* a, const void* b);
    // ����ͳ�ƹ���
    double mean(const double* data, int size);
    double variance(const double* data, int size);
    double standardDeviation(const double* data, int size);
    double correlationCoefficient(const double* x, const double* y, int size);
    double covariance(const double* x, const double* y, int size);
    double median(double* data, int size);
    double mode(const double* data, int size);
    double skewness(const double* data, int size);
    double kurtosis(const double* data, int size);
    // ��������ͳ�ƹ���
    double normalCDF(double x, double mean, double stddev);
    double normalPDF(double x, double mean, double stddev);
    double binomialPMF(int k, int n, double p);
    double poissonPMF(int k, double lambda);
    double sampleSkewness(const double* data, int size);
    double sampleKurtosis(const double* data, int size);
    double quantile(double* data, int size, double q);
    double firstQuartile(double* data, int size);
    double thirdQuartile(double* data, int size);
    double interquartileRange(double* data, int size);
    void detectOutliers(double* data, int size, double* outliers, int* outlierCount);
    // ����ʽϵ��
    double binomialCoefficient(int n, int k);
    // KMP�㷨
    int KMP(const char* text, const char* pattern);

    // Rabin-Karp�㷨
    int RabinKarp(const char* text, const char* pattern);

    // �򵥵�������ʽƥ��
    int isMatch(const char* s, const char* p);

    // �ַ����༭����
    int editDistance(const char* str1, const char* str2);
#ifdef __cplusplus
}
#endif

#endif // CALCULATOR_H