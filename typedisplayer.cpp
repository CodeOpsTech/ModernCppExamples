template<typename T> 
class TD;

int x = 10;
int *y = &x;
TD<decltype(x)> xType;
TD<decltype(y)> yType;

