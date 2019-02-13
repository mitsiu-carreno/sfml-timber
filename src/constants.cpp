struct WindowSize{
    int width;
    int height;
};

//Variable with size widow for all the scales and sizes calculations
static WindowSize windowSize;

void setWindowHeight(int height)
{
    windowSize.height = height;
}

void setWindowWidth(int width)
{
    windowSize.width = width;
}

// Encapsulate access to var
int getWindowHeight(){
    return windowSize.height;
}

int getWindowWidth(){
    return windowSize.width;
}