x = 5;
y = 7;
array z[1,2] = 3;
func test(a,b,c[]) {
    puti(a);
    puti(b);
    puti(c);
    puti(x);
    @y = @y + 6;
    puti(y);
    return x;
};
y = 9;
test(x,y,z);