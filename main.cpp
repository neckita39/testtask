#include "GameLogic/Model.h"
#include "GameLogic/Controller.h"
#include "View/View.h"

int main()
{
    Model model(660, 440);
    View view(model);
    Controller controller(model);
    controller.LifeCycle();
    return 0;
}