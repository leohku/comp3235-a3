array M[3, 3] = -1;
array sub[6] = 0;
puts("Please enter a 3x3 matrix:");
for(i = 0; i < 3; i = i + 1;) {
    for (j = 0; j < 3; j = j + 1;) {
        puts_("enter M[");
        puti_(i);
        puts_(", ");
        puti_(j);
        puts_("]: ");
        geti(M[i, j]);
    }
}
puts("The matrix you entered:");
for(i = 0; i < 3; i = i + 1;) {
    puts_("[");
    for (j = 0; j < 3; j = j + 1;) {
        puti_(M[i, j]);
        if (j != 2) puts_(" ");
    }
    puts("]");
}
sub[0] = M[0, 0] * M[1, 1] * M[2, 2];
sub[1] = M[0, 1] * M[1, 2] * M[2, 0];
sub[2] = M[0, 2] * M[1, 0] * M[2, 1];
sub[3] = M[0, 2] * M[1, 1] * M[2, 0];
sub[4] = M[0, 0] * M[1, 2] * M[2, 1];
sub[5] = M[0, 1] * M[1, 0] * M[2, 2];
det = sub[0] + sub[1] + sub[2] - sub[3] - sub[4] - sub[5];
puts_("The determinant of this matrix is: ");
puti(det);