#include <stdio.h>




void render() {
    printf("\r\e[0m\e[K");  // go to beginning of line and clear
    printf("\e[30;44mHello world, this is thing2");
}



int main(void)
{
    render();
    render();
    render();
    return 0;
}
