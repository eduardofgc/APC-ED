#include <stdio.h>
#include <windows.h>

int main(){
    MessageBox(
        NULL,
        "Hello, world!",
        "My Message Box",
        MB_OK //messagebox type
    );

    return 0;
}