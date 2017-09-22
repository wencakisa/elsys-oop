int main() {
    const int size = 42;

    int iarr[size];
    iarr[0] = 1;
    iarr[1] = 2;
    iarr[41] = 42;
    // iarr[42] = 43; *Error!*

    int two_dimensional[size][size];

    int seq[4] = {1, 2, 3, 4};
    char carr[7] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    char hello[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'}; // No need of size specifying

    int v[4] = {1, 2}; // same as: v[] = {1, 2, 0, 0};

    return 0;
}
