#include <iostream>
#include "Application.h"

int main()
{
    int code = 0;
    Application app = Application();
    code = app.startApplication(&app);
    return code;
}

