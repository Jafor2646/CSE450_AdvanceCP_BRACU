long long binpowrec(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpowrec(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}



long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}