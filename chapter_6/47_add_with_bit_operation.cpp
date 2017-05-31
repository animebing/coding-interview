int add(int a, int b) {
    int res, carry;
    do {
        res = a ^ b;
        carry = a & b;
        
        a = res;
        b = carry << 1;
    } while (b);
    
    return a;
}
