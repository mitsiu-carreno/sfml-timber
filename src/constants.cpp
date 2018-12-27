struct WindowSize{
    int width;
    int height;
};

//Variable with size widow for all the scales and sizes calculations
static WindowSize windowSize = {1280, 800};

// Encapsulate access to var
int getWindowHeight(){
    return windowSize.height;
}

int getWindowWidth(){
    return windowSize.width;
}