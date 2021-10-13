#include "Model.h"
#include "Controller.h"
#include "View.h"

int main()
{
    Model model(660, 440);
    View view(model);
    Controller controller(model);
    controller.LifeCycle();
    return 0;
}