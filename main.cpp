#include "Application.hpp"
#include "PowerPoint.hpp"

int main(int argc, char *argv[])
{
    Application::instance(argc,argv);
    PowerPoint w;
    w.show();
    return Application::instance().exec();
}
