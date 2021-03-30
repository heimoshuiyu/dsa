#include <stdio.h>
#include <stdlib.h>

#include "uncompress.h"

int main() {
	Uncompress(NULL, stdout);
	Uncompress("", stdout);
	Uncompress("abc", stdout);
	Uncompress("a1(b)c", stdout);
	Uncompress("a11(c)d", stdout);
	Uncompress("3(a)2(bc)", stdout);
	Uncompress("3(a2(c))", stdout);
	Uncompress("2(abb3(cd))ef", stdout);
	return 0;
}
