x = 5;
y = 7;
func test(a,b,c) {
    puti(a);
    puti(b);
    puti(c);
    puti(x);
    @y = @y + 6;
    puti(y);
    return x;
};
y = 9;